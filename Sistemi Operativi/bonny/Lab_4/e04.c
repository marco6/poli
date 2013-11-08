#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
  int n, i;
  int *vett;
  pid_t pid;
  
  n = atoi(argv[1]);
 
  vett = (int*) malloc(sizeof(int)*n);
 
  for(i=0; i<n; i++) scanf("%d", &vett[i]);
  
  for(i=0; i<(n-1); i++){
    pid = fork();
    if(pid!=0) { 
      wait((int *) 0);
      printf("\n%d", vett[i]);
      exit(1);
    }
  }
  printf("\n%d", vett[n-1]);
  return 0;
}
