#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  pid_t pid;
  printf("\nsolo P1\n");
  pid=fork();
  
  if(pid == 0){
    printf("\nP1R termina\n");
    exit(1);
  }
  else wait((int *) 0);
  
  printf("\nsolo P2\n");
  pid=fork();
  
  if(pid == 0){
    printf("\nP2R termina\n");
    exit(2);
  }
  else wait((int *) 0);
  
  printf("\nsolo P3\n");
  return 0;
}
