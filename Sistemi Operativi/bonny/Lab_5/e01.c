#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

  pid_t pid;

  printf("P1 pid: %d\n", getpid());
  pid = fork();
  sleep(1);
  if(pid==0)
    {
      printf("P3 pid: %d\n", getpid());
      pid = fork();
      sleep(1);
      if(pid==0) {
	printf("P6 pid: %d\n", getpid());
	exit(1);
      }
      else {
	wait(NULL);
	printf("P8 pid: %d\n", getpid());
	exit(1);
      }
    }
  else{
    printf("P2 pid: %d\n", getpid());
    pid = fork();
    sleep(1);
    if(pid==0){
      printf("P5 pid: %d\n", getpid());
      exit(1);
    }
    else{
      printf("P4 pid: %d\n", getpid());
      wait(NULL);
      printf("P7 pid: %d\n", getpid());
    }
  }
  printf("P9 pid: %d\n", getpid());
  return 0;
}
