/************************************************************************************
* FILE: count.c
* Compile as : gcc count_solution.c -lpthread -D_REENTRANT -Wall -o count
* DESCRIPTION:
*   NUM_WORKER_THREADS threads increase a counter a random number of times between 2 and 5
*   1 monitor thread watches the end of each worker thread
*   When all threads finish, the monitor thread prints the counter and leaves
*************************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUM_WORKER_THREADS  5

int count = 0; // common counter value
int exited_threads=0; // number of threads that have exited

/* initialize count_mutex and count_threshold_cv condition variable */

/*insert code here - mutex and condition variable*/
/**** BEGIN SOLUTION ****/

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t count_threshold_cv = PTHREAD_COND_INITIALIZER;

/**** END SOLUTION ****/

void *increment_count(void *t)
{
  long my_id = (long)t;
  int loops,i;

  loops=rand()%4+2; // increments a number between 2 and 5 times
  printf("Thread %ld started incrementing counter - will do it %d times\n", my_id,loops);

  /*insert code here - increment counter and wait 1 sec between each change*/
  /**** BEGIN SOLUTION ****/

  for(i=0;i<loops;i++)
  {
    pthread_mutex_lock(&count_mutex);     // lock the mutex before changing the value of the counter
    count++;                              // increment the counter
    printf("Thread %ld: count = %d\n", my_id, count);    // print the counter value after incremented
    pthread_mutex_unlock(&count_mutex);   // unlock the mutex after changing the value of the counter
    sleep(1);
  }

  /**** END SOLUTION ****/

  /*insert code here - notify monitor thread before leaving*/
  /**** BEGIN SOLUTION ****/

  pthread_mutex_lock(&count_mutex);     // lock the mutex before changing the value of the counter
  exited_threads++;                      // increment the number of threads that have exited
  pthread_cond_signal(&count_threshold_cv);  // signal the monitor thread that a thread has exited after condition of exiting has been met
  pthread_mutex_unlock(&count_mutex);   // unlock the mutex after changing the value of the counter

  /**** END SOLUTION ****/


  printf("Thread %ld leaving!\n", my_id);
  pthread_exit(NULL);
}

void *watch_threads(void *t)
{
  long my_id = (long)t;

  printf("Thread %ld started watching threads\n", my_id);

  /*insert code here - when all threads leave print the counter*/
  /**** BEGIN SOLUTION ****/

  pthread_mutex_lock(&count_mutex);     // lock the mutex before changing the value of the counter
  while(exited_threads < NUM_WORKER_THREADS)  // while the number of threads that have exited is less than the number of worker threads
  {
    pthread_cond_wait(&count_threshold_cv, &count_mutex);  // wait for the signal from the worker threads that they have exited
  }
  pthread_mutex_unlock(&count_mutex);   // unlock the mutex after changing the value of the counter

  /**** END SOLUTION ****/

  pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
  int i;
  long id[NUM_WORKER_THREADS+1];
  pthread_t threads[NUM_WORKER_THREADS+1];

  srand(time(NULL));
  
  /*insert code here - create threads*/
  /**** BEGIN SOLUTION ****/
    
  // create watcher (monitor) thread at index 0
  pthread_create(&threads[0], NULL, watch_threads, (void*)&id[0]);  // the MONITOR thread is assigned the function to "watch_threads", and calls it from the code above

  for(i = 0; i < NUM_WORKER_THREADS; i++)
  {
    id[i] = i;
    pthread_create(&threads[i], NULL, increment_count, (void*)&id[i]);  // the worker threads are assigned the function to "increment_count", and calls it from the code above
  }

  /**** END SOLUTION ****/

  /*insert code here - wait for all threads to complete*/
  /**** BEGIN SOLUTION ****/

  for(i = 0; i < NUM_WORKER_THREADS+1; i++)
  {
    pthread_join(threads[i], NULL);
  }

  /**** END SOLUTION ****/

  /*insert code here - clean up and exit*/
  /**** BEGIN SOLUTION ****/

  pthread_exit(NULL);

  /**** END SOLUTION ****/

}
