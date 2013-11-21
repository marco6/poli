#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>

#define N 200

void consume(pid_t, int *vett_pipe);
void produce(pid_t, int *vett_pipe);
void handle(int signal);

int main(){
  pid_t consumatore, produttore;
  int vett_pipe[2];
  char stringa_tmp[N];
  
  setbuf(stdout,NULL);

  signal(SIGUSR1, handle);
  signal(SIGUSR2, handle);

  if(pipe(vett_pipe)) printf("Errore creazione della pipe");
  
  if((produttore=fork())){
    if((consumatore=fork())){
      //Padre scrive il pid del secondo figlio
      close(vett_pipe[0]);
      sprintf(stringa_tmp,"%d",consumatore);
      write(vett_pipe[1],stringa_tmp,N);
      wait(NULL);
      wait(NULL);
    }
    else{
      //figlio consumatore
      //consumo
      consume(produttore, vett_pipe);
    }
  }else
    { 
      //figlio Produttore
      //qua prendo il pid del fratello
      sleep(1);	
      read(vett_pipe[0],stringa_tmp,N);
      consumatore = atoi(stringa_tmp);
      //Produco
      produce(consumatore, vett_pipe);
    }

  return 0;
}

void handle(int signal){
  if(signal==SIGUSR1){printf("Catturato segnale USR1\n");
  }
  else
    if(signal==SIGUSR2){printf("Catturato segnale USR2\n");
    }
    else printf("Catturato segnale non valido\n");
  return;
}

void produce(pid_t consumatore, int *vett_pipe)
{
  char stringa_tmp[N];
  
  //Chiudo il terminale di lettura della pipe
  close(vett_pipe[0]);

  while(1){
    printf("Dammi una parola: ");
    gets(stringa_tmp);
    write(vett_pipe[1],stringa_tmp,N);
    sleep(1);
    printf("produttore ----> consumatore\n");
    kill(consumatore, SIGUSR2);
    pause();
    printf("produttore: ricevuto segnale\n");
  }
  return;
}

void consume(pid_t produttore, int *vett_pipe)
{
  char stringa_tmp[N];
  int l, i;
  
  close(vett_pipe[1]);
  while(1){
    pause();
    printf("consumatore: ricevuto segnale\n");
    read(vett_pipe[0],stringa_tmp,N);
    l=strlen(stringa_tmp);
    for(i=0; i<l; i++)stringa_tmp[i]=toupper(stringa_tmp[i]);
    printf("La stringa maiuscolata e': %s\n",stringa_tmp);
    sleep(1);
    printf("consumatore ----> produttore\n");
    kill(produttore, SIGUSR1);
  }
  return;
}
