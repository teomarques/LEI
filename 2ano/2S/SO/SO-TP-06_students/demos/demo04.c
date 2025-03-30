// Operating Systems - University of Coimbra
// Vasco Pereira 2017
//
// Demo - testing ^C to a group of processes
// Compile as: gcc -Wall demo04.c -o procs
// execute as: ./procs
// Test1: Type ^C and watch all processes catching the signal
// Test2: Send a signal to the processes created using kill (from other terminal)


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


void sigint(int signum){
  printf("I (PID=%ld received signal!!\n",(long)getpid());
  }

int main(void) {
  pid_t childpid;
  int i;

  signal(SIGINT,sigint);
  printf("Father started - I am :%ld\n",(long)getpid());
  for(i=1;i<=5;i++){
    childpid = fork();
    if (childpid == 0) {
      printf("Son %d created - I am :%ld\n", i,(long)getpid());
      pause(); // wait for a signal
      exit(0);
    }
  }
  for(i=0;i<10;i++){
    wait(NULL); //wait for all
    }
  return 0;
}
