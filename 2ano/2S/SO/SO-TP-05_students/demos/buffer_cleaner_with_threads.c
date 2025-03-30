// Vasco Pereira 2021 (vasco@dei.uc.pt)
// Buffer Cleaner with threads and condition variables
// Finish with ^C
// Compile as: gcc -Wall -pthread buffer_cleaner_with_threads.c -o bufferc


#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define PRODUCERS 5
#define N 5

void* cleaner(void *arg);
void* producer(void *id);

int write_pos=0;
int buf[N];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t is_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t go_on = PTHREAD_COND_INITIALIZER;

int id[PRODUCERS];


int main(int argc, char *argv[]) {
  int i;
  pthread_t thr[PRODUCERS+1];
  
  pthread_create(&thr[0], NULL, cleaner, NULL);

  for (i = 0; i < PRODUCERS; i++) {
    id[i] = i;
    pthread_create(&thr[i+1], NULL, producer, &id[i]);
  } 
  pthread_exit(NULL);
  return 0;
}

void* producer(void *id) {
  int my_id = *((int*) id);

  while (1) {
    pthread_mutex_lock(&mutex);
    
    // if buffer is full notify CLEANER
    while (write_pos == N) {
      pthread_cond_signal(&is_full);
      pthread_cond_wait(&go_on,&mutex);
      }
    
    printf("[PRODUCER %3d] Writing %d into the buffer\n", my_id, my_id);
    buf[write_pos] = my_id;
    write_pos++;

    pthread_mutex_unlock(&mutex);
    sleep(1);
  }
}

void* cleaner(void *arg) {
  while (1) {
    pthread_mutex_lock(&mutex);

	// Wait until it is full
    while (write_pos != N) {
      pthread_cond_wait(&is_full,&mutex);
      }
      
    printf("[CLEANER] Cleaning buffer: ");
    for(int i=0;i<N;i++) printf("[%d]",buf[i]);
    printf("\n");
    write_pos=0;
    
	//notify everyone that is waiting in the condition variable
    pthread_cond_broadcast(&go_on);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}
