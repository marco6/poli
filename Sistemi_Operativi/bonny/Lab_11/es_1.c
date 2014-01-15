#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define pipe_1 pipes[0]
#define pipe_2 pipes[1]
#define pipe_3 pipes[2]
#define pipe_4 pipes[3]
#define pipe_5 pipes[4]
#define pipe_6 pipes[5]

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
  
  int pipes[6][2];
  char c = 'f';
  int i;
  
  for(i=0;i<6;i++) pipe(pipes[i]);

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


