#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

typedef void (*func)();

#define E(name) void name() { printf("Sono il processo " #name " di pid: %d\n", getpid() ); sleep(rand() % 5); }

E(P1)
E(P2)
E(P3)
E(P4)
E(P5)
E(P6)
E(P7)
E(P8)
E(P9)

#undef E

int main(int argc, char**argv){
  //Creo l'albero di precedenze, dal basso verso l'alto
  int i, j, st;
  func tree[] = { P1, P2, P3, P4, P5, P6, P7, P8, P9 };
  int idx[] = { 1, 3, 6, 8, 9 };
  for(i = 0, j=0; i < sizeof(idx)/sizeof(int); i++){
    for(;j<idx[i];j++){
      if(fork() == 0){
        tree[j]();
        return 0;
      }
    }
    //DA rivedere..
    while( wait(&st) != -1 ) ;
    if(ECHILD != errno){
      fprintf(stderr, "C'è stato un errore.\n");
      return -1;
    }
  }
  return 0;
}
