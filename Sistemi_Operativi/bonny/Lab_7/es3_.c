#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>

#define N 1024

void consume();
void produce();

pid_t consumatore, produttore;
int vett_pipe[2];
char stringa_tmp[N];

int main(){
  
  setbuf(stdout,NULL);

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
      close(vett_pipe[1]);
      //consumo
      signal(SIGUSR2, consume);
    }
  }else
    { 
      //figlio Produttore
      //qua prendo il pid del fratello
      sleep(1);	
      read(vett_pipe[0],stringa_tmp,N);
      consumatore = atoi(stringa_tmp);
      //Produco
      signal(SIGUSR1, produce);
      raise(SIGUSR1); 
    }
  while(1) pause();

  return 0;
}

void produce()
{ 
    printf("Dammi una parola: ");
    gets(stringa_tmp);
    write(vett_pipe[1],stringa_tmp,N);
    sleep(1);
    printf("produttore ----> consumatore\n");
    kill(consumatore, SIGUSR2);
    printf("produttore: ricevuto segnale\n");
    return;
}

void consume()
{
  int l, i;

    printf("consumatore: ricevuto segnale\n");
    read(vett_pipe[0],stringa_tmp,N);
    l=strlen(stringa_tmp);
    for(i=0; i<l; i++)stringa_tmp[i]=toupper(stringa_tmp[i]);
    printf("La stringa maiuscolata e': %s\n",stringa_tmp);
    sleep(1);
    printf("consumatore ----> produttore\n");
    kill(produttore, SIGUSR1);
 
  return;
}
