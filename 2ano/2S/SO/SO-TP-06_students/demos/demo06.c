// Operating Systems - University of Coimbra
// Vasco Pereira 2021
//
// Demo - testing changing of handler and use of kill - using "sigaction"
// Compile as: gcc -Wall demo06.c -o demo06
// Open two terminals
// Run demo06 in Terminal 1
// Press ^C in Terminal 1 (both processes will catch it)
// Press ^Z in Terminal 1 to toggle between handler and SIG_IGN
// Use Terminal 2 to send a SIGUSR1 signal to each process: kill -SIGUSR1 {pid}

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t pid_son;
struct sigaction new_action, old_action;
sigset_t block_set;

void termination_handler(int signum) {
  if(signum == SIGINT){
    printf("\n[Proc %d] ^C pressed. Going away!\n",getpid());
    exit(0);
  }
  if(signum == SIGTSTP){
    printf("\n[Proc %d] SIGTSTP received. Changing SIGINT signal response!\n",getpid());

    sigaction(SIGINT, NULL, &old_action);
    if (old_action.sa_handler == SIG_IGN) new_action.sa_handler = &termination_handler;
      else new_action.sa_handler = SIG_IGN;
    sigaction(SIGINT, &new_action,NULL);
  }
  if(signum == SIGUSR1){
    printf("\n[Proc %d] SIGUSR1 received. Terminate son with SIGKILL!\n",getpid());
    kill(pid_son,SIGKILL);
    wait(NULL);
  }
}

void process_son (){
  // if the previous action was to ignore the signal SIGINT, keep it; othrewise set it to termination_handler
  signal(SIGUSR1,SIG_IGN);
  printf("[Proc %d] I am the son!\n",getpid());
  while(1) {
    printf("[Proc %d] Waiting for a signal...\n",getpid());
    pause();
  }
}

int main() {

  sigfillset(&block_set); // will have all possible signals blocked when our handler is called

  //define a handler for SIGINT, SIGTSTP and SIGUSR1; when entered all possible signals are blocked
  new_action.sa_flags = 0;
  new_action.sa_mask = block_set;
  new_action.sa_handler = &termination_handler;

  sigaction(SIGINT,&new_action,NULL);
  sigaction(SIGTSTP,&new_action,NULL);
  sigaction(SIGUSR1,&new_action,NULL);

  printf("[Proc %d] I am the father!\n",getpid());
  pid_son = fork();
  if(pid_son == 0){
    process_son();
    exit(0);
  }

  // Do some work!
  while (1) {
    printf("[Proc %d] Waiting for a signal...\n",getpid());
    pause();
  }
  return 0;
}
