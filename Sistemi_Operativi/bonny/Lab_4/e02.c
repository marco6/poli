#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  int i, n, t, count;
  pid_t pid;

  n = atoi(argv[1]);
  t = atoi(argv[2]);
  for(i=0; i<n; i++){
    while(count<2){
      pid = fork();
      if(!pid) count++;
    }
  }
  if(!pid) exit(1);
  else{
    sleep(t);
    printf("figlio terminato.");
  }
  return 0;
}
