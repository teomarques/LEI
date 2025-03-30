/******************************************************************************
* FILE: shop.c
* DESCRIPTION:
*   A shop has several moneyiers and one foreman, each represented by a thread. 
*   The threads are created by the main thread.
*   - Some threads represent the shop employees that sell items for 10 eur
*     and put the money in a common safe.
*   - One thread represents the foreman that watches the value of the money. When it 
*     reaches a predefined limit (CASH_LIMIT), he removes an amount of CASH_LIMIT
*     money from the safe, for security reasons.
*   - The program ends after NSALES
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS  8	// Total number of threads (>1)
#define NSALES 30	// Max number of sales made by all employees
#define CASH_LIMIT 50	// Limit of the 'count' variable before it is reset 

int   sales = 0;
int		money = 0;

/* initialize money_mutex and money_amount_cv condition variable */

// -------- MY CODE --------
pthread_mutex_t money_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t money_amount_cv = PTHREAD_COND_INITIALIZER;

void *employee(void *t)
{
  int my_id = *((int *)t);
  
  printf("Starting employee(): thread %d\n", my_id);

  while (1) 
  {

	/* If sales < NSALES make a sell and put money in the safe
	   else exits thread */

    // ---------- MY CODE ----------

    pthread_mutex_lock(&money_mutex);
    if (sales < NSALES) 
    {
      sales++;      // increment number of sales
      money += 10;  // add 10 eur to the safe
      // signal the foreman that there has been movement in the safe
      pthread_cond_signal(&money_amount_cv);
      printf("Employee %d: sale %d, money in safe = %d\n", my_id, sales, money);
    } 
    else 
    {
      pthread_mutex_unlock(&money_mutex);
      break;
    }
    pthread_mutex_unlock(&money_mutex);
	}

  pthread_exit(NULL);
}

void *foreman(void *t) 
{
  int my_id = *((int *)t);

  printf("Starting foreman(): thread %d\n", my_id);

  while (1) {

	/* wait if money<CASH_LIMIT and sales<NSALES
	   when sales >= NSALES exit thread */
 	
	// ---------- MY CODE ----------

    /* SEMPRE O MESMO TEMPLATE:
        1. lock mutex
        2. while (condicao) wait
        3. fazer o que tem a fazer
        4. unlock mutex
    */
    pthread_mutex_lock(&money_mutex);
    while (money < CASH_LIMIT && sales < NSALES) 
    {
      // wait for the employees to put money in the safe. The pthread_cond_wait will temporarily unlock the mutex, wait for a signal and, when signaled, will return and relock the mutex
      pthread_cond_wait(&money_amount_cv, &money_mutex);
    }
    if (sales >= NSALES) 
    {
      pthread_mutex_unlock(&money_mutex);
      break;
    }
    money -= CASH_LIMIT;
    printf("Foreman %d: money in safe = %d\n", my_id, money);
    pthread_mutex_unlock(&money_mutex);

	}
 
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  int i; 
  int id[NUM_THREADS];
  pthread_t threads[NUM_THREADS];

  /* Create threads */

  // -------- MY CODE --------
  for (i = 0; i < NUM_THREADS; i++) {
    id[i] = i;
    if (i == 0) {
      pthread_create(&threads[i], NULL, foreman, (void *)&id[i]);
      // foreman is the MONITOR THREAD
    } else {
      pthread_create(&threads[i], NULL, employee, (void *)&id[i]);
      // employees are the WORKER THREADs
    }
  } 


  /* Wait for all threads to complete */

  // ...... insert code here .......

  // -------- MY CODE --------
  for (i = 0; i < NUM_THREADS; i++) {
    // use pthread_join to wait for the threads to finish !
    pthread_join(threads[i], NULL);
  }

  printf ("Main(): Waited and joined with %d threads. Final money in safe = %d. Done!\n", 
          NUM_THREADS, money);

  /* Clean up and exit */

  // -------- MY CODE --------
  pthread_exit(NULL);
  return 0;
}
