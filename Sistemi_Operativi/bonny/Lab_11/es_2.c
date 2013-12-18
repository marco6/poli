#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

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

void* A (void*);
void* B (void*);
void* C (void*);
void* D (void*);
void* E (void*);
void* F (void*);
void* G (void*);
void* H (void*);
void* I (void*);

sem_t S_1,S_2,S_3,S_4,S_5,S_6;

int main(){
 
  pthread_t tid_A,tid_B,tid_C,tid_D,tid_E,tid_F,tid_H,tid_G,tid_I;
  
  sem_init(&S_6,0,1);
  sem_init(&S_1,0,0);
  sem_init(&S_2,0,0);
  sem_init(&S_3,0,0);
  sem_init(&S_4,0,0);
  sem_init(&S_5,0,0);
  
  while(1){
  sem_wait(&S_6);
  pthread_create(&tid_A,NULL,A,NULL);
  pthread_create(&tid_B,NULL,B,NULL);
  pthread_create(&tid_C,NULL,C,NULL);
  pthread_create(&tid_D,NULL,D,NULL);
  pthread_create(&tid_E,NULL,E,NULL);
  pthread_create(&tid_F,NULL,F,NULL);
  pthread_create(&tid_G,NULL,G,NULL);
  pthread_create(&tid_H,NULL,H,NULL);
  pthread_create(&tid_I,NULL,I,NULL);
  }

  return 0;
}


void* A (void* x){ //figlio A
  int i;
  //...
  printf("Sono il figlio A\n");
  //...
  for(i=0;i<3;i++) sem_post(&S_1);
  pthread_exit(NULL);
}
    
void* B (void* x){ //figlio B
  sem_wait(&S_1);
  //...
  printf("Sono il figlio B\n");
  sem_post(&S_5);
  pthread_exit(NULL);
}
    
void* C (void* x){ //figlio C
  sem_wait(&S_1);
  //...
  printf("Sono il figlio C\n");
  sem_post(&S_2);
  sem_post(&S_2);
  pthread_exit(NULL);
}
    
void* D (void* x){//figlio D
  sem_wait(&S_1);
  printf("Sono il figlio D\n");
  //...
  sem_post(&S_4);
  pthread_exit(NULL);
}
void* E (void* x){//figlio E
  sem_wait(&S_2);
  printf("Sono il figlio E\n");
  //...
  sem_post(&S_3);
  pthread_exit(NULL);
}
    
void* F (void* x){ //figlio F
  sem_wait(&S_2);
  printf("Sono il figlio F\n");
  //...
  sem_post(&S_3);
  pthread_exit(NULL);
}
    
void* G (void * x){ //figlio G
  sem_wait(&S_3);
  sem_wait(&S_3);
  printf("Sono il figlio G\n");
  //...
  sem_post(&S_5);
  pthread_exit(NULL);
}
   
void* H (void* x){//figlio H
  sem_wait(&S_4);
  printf("Sono il figlio H\n");
  //...
  sem_post(&S_5);
  pthread_exit(NULL);
}

void* I (void* x){//figlio I
  int i;
  for(i=0;i<3;i++) sem_wait(&S_5);
  printf("Sono il figlio I\n");
  //... 
  sem_post(&S_6);
  pthread_exit(NULL);
}
