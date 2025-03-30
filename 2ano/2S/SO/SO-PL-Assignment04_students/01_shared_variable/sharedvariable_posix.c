//compile with: gcc -Wall -pthread sharedvariable_posix.c -o svar
//using POSIX named semaphores

#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h> // include POSIX semaphores

/*insert here the other libraries needed*/


int * shared_var;
int shmid;
sem_t *mutex;

void worker()
	{
	usleep(1000000 + rand()%11*100000); //uses microseconds sleep and waits 1 to 2 seconds in periods of 0.1 secs
	
	/*insert code here*/
  for (int i = 0; )
	
	}

int main(int argc, char *argv[])
	{
	int i, n_procs;

	if(argc!=2) {
		printf("Wrong number of parameters\n");
		exit(0);
		}

	n_procs=atoi(argv[1]);

	// Create shared memory
	/*insert code here*/

	// Attach shared memory
	/*insert code here*/
	
	// Create semaphore
	/*insert code here*/

	// initialize variable in shared memory
	/*insert code here*/

	// Create worker processes
	/*insert code here*/
	
	// Wait for all worker processes
	/*insert code here*/
	
	// print final result
	/*insert code here*/

	// remove resources (shared memory and semaphore)
	/*insert code here*/	

	exit(0);
}
