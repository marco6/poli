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

sem_t S_1,S_2,S_3,S_4,S_5,S_6,S_7,S_8,S_9;

int main(){
 
  pthread_t tid;
  
  sem_init(&S_6,0,0);
  sem_init(&S_1,0,0);
  sem_init(&S_2,0,0);
  sem_init(&S_3,0,0);
  sem_init(&S_4,0,0);
  sem_init(&S_5,0,0);
  sem_init(&S_7,0,0);
  sem_init(&S_8,0,0);
  sem_init(&S_9,0,1);
  
  pthread_create(&tid,NULL,A,NULL);
  pthread_create(&tid,NULL,B,NULL);
  pthread_create(&tid,NULL,C,NULL);
  pthread_create(&tid,NULL,D,NULL);
  pthread_create(&tid,NULL,E,NULL);
  pthread_create(&tid,NULL,F,NULL);
  pthread_create(&tid,NULL,G,NULL);
  pthread_create(&tid,NULL,H,NULL);
  pthread_create(&tid,NULL,I,NULL);
  
  pthread_join(tid, NULL);

  return 0;
}

void* A (void* x){ //figlio A
  while(1){
    sem_wait(&S_9);
    printf("\n A");
    //...
    sem_post(&S_3);
    sem_post(&S_2);
    sem_post(&S_1);}
  pthread_exit(NULL);
}
    
void* B (void* x){ //figlio B
  while(1){
    sem_wait(&S_1);
    //...
    printf(" B");
    sem_post(&S_8);}
  pthread_exit(NULL);
}
    
void* C (void* x){ //figlio C
  while(1){
    sem_wait(&S_2);
    //...
    printf(" C");
    sem_post(&S_4);
    sem_post(&S_5);}
  pthread_exit(NULL);
}
    
void* D (void* x){//figlio D
  while(1){
    sem_wait(&S_3);
    printf(" D");
    //...
    sem_post(&S_7);}
  pthread_exit(NULL);
}
void* E (void* x){//figlio E
  while(1){
    sem_wait(&S_4);
    printf(" E");
    //...
    sem_post(&S_6);}
  pthread_exit(NULL);
}
    
void* F (void* x){ //figlio F
  while(1){
    sem_wait(&S_5);
    printf(" F");
    //...
    sem_post(&S_6);}
  pthread_exit(NULL);
}
    
void* G (void * x){ //figlio G
  while(1){
    sem_wait(&S_6);
    sem_wait(&S_6);
    printf(" G");
    //...
    sem_post(&S_8);}
  pthread_exit(NULL);
}
   
void* H (void* x){//figlio H
  while(1){
    sem_wait(&S_7);
    printf(" H");
    //...
    sem_post(&S_8);}
  pthread_exit(NULL);
}

void* I (void* x){//figlio I
  int i;
  while(1){
    for(i=0;i<3;i++) sem_wait(&S_8);
    printf(" I");
    //... 
    sem_post(&S_9);}
  pthread_exit(NULL);
}
