#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char**argv){
  int *arr, n, i;
  printf("Quanti?>");
  scanf("%d", &n);
  arr = malloc(sizeof(int)*n);
  for(i = 0; i < n; i++){
    printf("Spara!>");
    scanf("%d", arr + i);
  }
  for(i=0;i < n; i++) {
    if(fork()) {
      wait(NULL);
      printf("%d\n", arr[i]);
      break;
    }
  }
  return 0;
}
