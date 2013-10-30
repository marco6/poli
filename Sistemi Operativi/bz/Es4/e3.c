#include <stdio.h>
#include <unistd.h>

#define N 1 << 

typedef int (*func)();

#define E(name) int name() { puts("Sono il processo " #name ); sleep(1); }

E(P1)
E(P1L)
E(P1R)
E(P2)
E(P2L)
E(P2R)
E(P3)

#undef E
int main(int argc, char**argv){
  //Creo l'albero di precedenze, dal basso verso l'alto
  int i, j, st;
  func tree[] = { P1, P1R, P1L, P2, P2R, P2L, P3 };
  int idx[] = { 1, 3, 4, 6, 7 };
  for(i = 0, j=0; i < sizeof(idx)/sizeof(int); i++){
    for(;j<idx[i];j++){
      if(fork() == 0){
	tree[j]();
	return 0;
      }
    }
    //DA rivedere..
    while( wait(&st) != -1 ) ; 
  }
  return 0;
}
