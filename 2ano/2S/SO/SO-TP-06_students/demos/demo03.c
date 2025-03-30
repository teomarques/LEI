#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void master(pid_t pid_son)
{
  printf("Master sleeping for a while...\n");
  sleep(3);
  printf("Master says: Hello son!\n");
  kill(pid_son, SIGUSR1);
}

void daddy_call(int signum) 
{
  printf("Daddy has just called in!\n");
}

void worker() 
{
  int i;
  // Redirect "user signal 1" to a handler routine
  signal(SIGUSR1, daddy_call);

  // Do some work
  printf("Child process, life is good...\n");

  for (i=0; i<10; i++) 
  {
    printf("Child doing some work\n");
    sleep(1);
  }
  
  printf("Child saying bye bye!\n");
}

int main() {
  pid_t son;

  // Creates a worker process
  if ((son=fork()) == 0) {
    worker();
    exit(0);
  }
  
  // The master
  master(son);
  wait(NULL);
  
  return 0;
}
