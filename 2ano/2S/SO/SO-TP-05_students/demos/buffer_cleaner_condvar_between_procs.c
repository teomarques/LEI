// Vasco Pereira 2021 (vasco@dei.uc.pt)
// Buffer Cleaner with processes, condition variables and mutex
// Condition variables (and mutex) default attributes have to be changed and shared memory used
// The cleaner only works a fixed number of times
// Compile as: gcc -Wall -pthread buffer_cleaner_condvar_between_procs.c -o bufferc


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PRODUCERS 5
#define N 5
#define CLEANER_ROUNDS 10

void cleaner();
void producer();

int shmid;

typedef struct {
	int buf[N];
	int write_pos;
	pthread_mutex_t mutex;
	pthread_cond_t is_full;
	pthread_cond_t go_on; 
	int finish;
	} rec_struct;

rec_struct* shared_rec;

int main() {
  pthread_mutexattr_t attrmutex;
  pthread_condattr_t attrcondv;
  int i;
 
  if ((shmid = shmget(IPC_PRIVATE, sizeof(rec_struct), IPC_CREAT | 0766)) < 0) {
		perror("Error in shmget with IPC_CREAT\n");
		exit(1);
  }

  if ((shared_rec = (rec_struct *) shmat(shmid, NULL, 0)) == (rec_struct*)-1) {
		perror("Shmat error!");
		exit(1);
  }
  
  /* Initialize attribute of mutex. */
  pthread_mutexattr_init(&attrmutex);
  pthread_mutexattr_setpshared(&attrmutex, PTHREAD_PROCESS_SHARED);

  /* Initialize attribute of condition variable. */
  pthread_condattr_init(&attrcondv);
  pthread_condattr_setpshared(&attrcondv, PTHREAD_PROCESS_SHARED);
  
  /* Initialize mutex. */
  pthread_mutex_init(&shared_rec->mutex, &attrmutex);
  
  /* Initialize condition variables. */
  pthread_cond_init(&shared_rec->is_full, &attrcondv);
  pthread_cond_init(&shared_rec->go_on, &attrcondv);
  
  shared_rec->write_pos=0;
  shared_rec->finish=0;
  
  if(fork()==0){
    printf("Cleaner %d created!\n",getpid());
    cleaner();
    printf("Cleaner %d leaving!\n",getpid());
    exit(0);
    }
  for(i=0;i<PRODUCERS;i++){
	if(fork()==0){
	  printf("Producer %d created!\n",getpid());
	  producer();
      printf("Producer %d leaving!\n",getpid());
	  exit(0);
	  }
	}

  for(i=0;i<PRODUCERS+1;i++) wait(NULL); // parent waits for all children
  
  // remove resources
  pthread_mutex_destroy(&shared_rec->mutex);
  pthread_mutexattr_destroy(&attrmutex); 
  pthread_cond_destroy(&shared_rec->is_full);
  pthread_cond_destroy(&shared_rec->go_on);
  pthread_condattr_destroy(&attrcondv);

  
  shmdt(shared_rec);
  shmctl(shmid,IPC_RMID,NULL);
  exit(0);
}

void producer() {
  int my_id = getpid();

  while (1) {
    pthread_mutex_lock(&shared_rec->mutex);
    
    // if buffer is full notify CLEANER
    while (shared_rec->write_pos == N) {
      pthread_cond_signal(&shared_rec->is_full);
      pthread_cond_wait(&shared_rec->go_on,&shared_rec->mutex);
      }
    if(shared_rec->finish==1) {
    	pthread_mutex_unlock(&shared_rec->mutex);
    	break;
    	}
    
    printf("[PRODUCER %3d] Writing %d into the buffer\n", my_id, my_id);
    shared_rec->buf[shared_rec->write_pos] = my_id;
    shared_rec->write_pos++;

    pthread_mutex_unlock(&shared_rec->mutex);
    sleep(1);
  }
}

void cleaner() {
  int rounds=0;
  
  while (rounds<=CLEANER_ROUNDS) {
    pthread_mutex_lock(&shared_rec->mutex);

	// Wait until it is full
    while (shared_rec->write_pos != N) {
      pthread_cond_wait(&shared_rec->is_full,&shared_rec->mutex);
      }
      
    printf("[CLEANER] Cleaning buffer: ");
    for(int i=0;i<N;i++) printf("[%d]",shared_rec->buf[i]);
    printf("\n");
    shared_rec->write_pos=0;
    rounds++;
    if(rounds>CLEANER_ROUNDS) shared_rec->finish=1;
    
	//notify everyone that is waiting in the condition variable
    pthread_cond_broadcast(&shared_rec->go_on);
    pthread_mutex_unlock(&shared_rec->mutex);
  }
}
