#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


static pid_t pid;

void sH (int s){
  //USER1 è "SVEGLIA!!"
  //E qui devo dire che è più realistico che sia il processo mamma a mandarlo sto segnale più che quello figlio...
  if(s == SIGUSR1){
    printf("Child Woke-up\n");
    //Qui aspettiamo 1 secondo che il padre dorma
    sleep(1);
    kill(pid, SIGUSR2);
  }
  else {
    printf("Father woke up\n");
    sleep(1);
    kill(pid, SIGUSR1);
  }
}

int main() {
  setbuf(stdout, NULL);
  if( (pid = fork()) ){
    sleep(1);
    kill(pid, SIGUSR1);
  }
  else
    pid = getppid();
  signal(SIGUSR1, sH);
  signal(SIGUSR2, sH);
  while(1)
    pause();
  return 0;
}
