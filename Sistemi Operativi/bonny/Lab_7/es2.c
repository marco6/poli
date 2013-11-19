#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>

void handle(int signal);

int main(){
  int l, i;
  char stringa_tmp[200];
  pid_t consumatore, produttore;
  FILE* file;

  setbuf(stdout,NULL);

  signal(SIGUSR1, handle);
  signal(SIGUSR2, handle);

  if((produttore=fork())){
    if((consumatore=fork())){
      //Padre scrive il pid del secondo figlio
        file=fopen("file_passaggio_dati","w");
	fprintf(file,"%d",consumatore);
	fclose(file);
	wait(NULL);
	wait(NULL);
      }
    else{
      //figlio consumatore
      file=fopen("file_passaggio_dati","r");
      //consumo
      while(1){
	pause();
	printf("consumatore: ricevuto segnale\n");
	fscanf(file,"%s", stringa_tmp);
	l=strlen(stringa_tmp);
	for(i=0; i<l; i++)stringa_tmp[i]=toupper(stringa_tmp[i]);
	printf("La stringa maiuscolata e': %s\n",stringa_tmp);
	sleep(1);
	printf("consumatore ----> produttore\n");
	kill(produttore, SIGUSR1);
      }
    }
  }else
    { 
      //figlio Produttore
      //qua prendo il pid del fratello
      sleep(1);
      file=fopen("file_passaggio_dati","r");	
      fscanf(file,"%d", &consumatore);
      fclose(file);
      //Apro di nuovo il file dall'inizio
      file=fopen("file_passaggio_dati","w");
      setbuf(file,NULL);
      //Produco
      while(1){
	printf("Dammi una parola: ");
	scanf("%s",stringa_tmp);
	fprintf(file,"%s",stringa_tmp);
	sleep(1);
	printf("produttore ----> consumatore\n");
	kill(consumatore, SIGUSR2);
	pause();
	printf("produttore: ricevuto segnale\n");
      }
    }
  
  fclose(file);

  return 0;
}

void handle(int signal){
  if(signal==SIGUSR1){//printf("Catturato segnale USR1\n");
  }
  else
    if(signal==SIGUSR2){// printf("Catturato segnale USR2\n");
    }
    else printf("Catturato segnale non valido\n");
  return;
}
