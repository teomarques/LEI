#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint(int signum) {
  char option[2];
  printf("\n ^C pressed. Do you want to abort? ");

  scanf("%1s", option);
  if (option[0] == 'y') {
    printf("Ok, bye bye!\n");
    exit(0);
  }
}

int main()
{
  // Redirects SIGINT to sigint()
  signal(SIGINT, sigint);

  sigset_t block_ctrlc;
  sigemptyset (&block_ctrlc);
  sigaddset (&block_ctrlc, SIGINT);

  // Do some work!
  while (1) {
    
    sigprocmask (SIG_BLOCK, &block_ctrlc, NULL);
    printf("Doing some work...\n");
    sleep(5);
    printf("End of job.\n");
    sigprocmask (SIG_UNBLOCK, &block_ctrlc, NULL);
  }
  return 0;
}
