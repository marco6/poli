#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char**argv) {
  int n, i;
  if(argc < 2)
    return -1;
  n = atoi(argv[1]);
  for(i = 1; i <= n; i++){
    sleep(1);
    printf("Siamo a %d\n", i);
  }
  return 0;
}
