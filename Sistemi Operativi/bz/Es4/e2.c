#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argv, char**argc){
  int n;
  if(argv < 3)
    return -1;
  for(n = atoi(argc[1]); n>0 && !(fork() && fork()); n--);
  if( n == 0 )
    {
      sleep(atoi(argc[2]));
      printf("#Child %d just woke up.\n", getpid());
    }
  return 0;
}
