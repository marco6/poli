#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*      A  <-------- */
/*   /  |  \       ^ */
/*  /   |   \      | */
/* B    C    D     | */
/* |   / \   |     | */
/* |  /   \  |     | */
/* | E    F  |     | */
/* |  \   /  |     | */
/* |   \ /   |     | */
/* |    G    H     | */
/*  \   |   /      | */
/*   \  |  /       | */
/*      I  --------- */

int main(){
  
  int pipe_1[2],pipe_2[2],pipe_3[2],pipe_4[2],pipe_5[2],pipe_6[2];
  char c = 'f';
  int i;
  
  pipe(pipe_1);
  pipe(pipe_2);
  pipe(pipe_3);
  pipe(pipe_4);
  pipe(pipe_5);
  pipe(pipe_6);

  write(pipe_6[1],&c,1);
  
  while(1){
    read(pipe_6[0],&c,1);
    //padre
    if(!fork()){ //figlio A
      //...
      printf("Sono il figlio A\n");
      //...
      for(i=0;i<3;i++) write(pipe_1[1],&c,1);
      exit(1);
    }
    // padre
    if(!fork()){ //figlio B
      read(pipe_1[0],&c,1);
      //...
      printf("Sono il figlio B\n");
      write(pipe_5[1],&c,1);
      exit(1);
    }
    //padre
    if(!fork()){ //figlio C
      read(pipe_1[0],&c,1);
      //...
      printf("Sono il figlio C\n");
      for(i=0; i<2; i++) write(pipe_2[1],&c,1);
      exit(1);
    }
    //padre
    if(!fork()){//figlio D
      read(pipe_1[0],&c,1);
      printf("Sono il figlio D\n");
      //...
      write(pipe_4[1],&c,1);
      exit(1);
    }
    if(!fork()){//figlio E
      read(pipe_2[0],&c,1);
      printf("Sono il figlio E\n");
      //...
      write(pipe_3[1],&c,1);
      exit(1);
    }
    //padre
    if(!fork()){ //figlio F
      read(pipe_2[0],&c,1);
      printf("Sono il figlio F\n");
      //...
      write(pipe_3[1],&c,1);
      exit(0);
    }
    //padre
    if(!fork()){ //figlio G
      for(i=0;i<2;i++) read(pipe_3[0],&c,1);
      printf("Sono il figlio G\n");
      //...
      write(pipe_5[1],&c,1);
      exit(1);
    }
    //padre
    if(!fork()){//figlio H
      read(pipe_4[0],&c,1);
      printf("Sono il figlio H\n");
      //...
      write(pipe_5[1],&c,1);
      exit(1);
    }
    if(!fork()){// figlio I
      for(i=0;i<3;i++) read(pipe_5[0],&c,1);
      printf("Sono il figlio I\n");
      //... 
      write(pipe_6[1],&c,1);
      exit(1);
    }
    for(i=0;i<9;i++) wait(NULL);
  }
  return 0;
}


