#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char*argv[]){
  int n, t, r, i;
  if(argc < 3){
    puts("Usage: e2 <n> <t>");
    return 0;
  }

  n = atoi(argv[1]);
  t = atoi(argv[2]);

  for(i = 1, r = 1; i <= n && (r = r && fork()); i++);

  if(r)
    return 0;
  printf("#Figlio %d sta per andare in letargo.\n", i);
  sleep(i*t);
  printf("#FIglio %d si è svegliato e va a fare colazione.\n", i);
  return 0;
}
