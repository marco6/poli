#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle(int signal);

int main(){
 
  pid_t pid;
  
  setbuf(stdout,NULL);

  signal(SIGUSR1, handle);
  //  printf("1\n");
  signal(SIGUSR2, handle);

  if((pid=fork())){
    //printf("1\n");
    while(1){
      pause();
      printf("father woke up\n");
      sleep(1);
      kill(pid,SIGUSR1);
    }
  }else
    {
      //printf("2\n");
      while(1){
	printf("child woke up\n");
	sleep(1);
	kill(getppid(), SIGUSR2);
	pause();
      }
    }
  return 0;
}

void handle(int signal){
  if(signal==SIGUSR1){//printf("Catturato segnale USR1");
  }
  else
    if(signal==SIGUSR2){// printf("Catturato segnale USR2");
    }
    else printf("Catturato segnale non valido");
  return;
}
