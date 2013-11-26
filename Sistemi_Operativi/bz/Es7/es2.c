#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <sys/wait.h>

FILE*f;
pid_t p1, p2;

void produci(int);
void consuma(int);

int main() {
  setbuf(stdout, NULL);
  //Ora forko
  if( (p1 = fork()) && (p2 = fork()) ){
    f = fopen("temp-orale", "w+");
    fprintf(f, "%d", p2);
    fclose(f);
    wait(NULL);
    wait(NULL);
    return 0;
  }
  sleep(1);
  f = fopen("temp-orale", "r+");
  setbuf(f, NULL);
  //E qui abbiamo il pid2
  fscanf(f, "%d", &p2);

  //Ora diamoci da fare...
  //Registriamo l'evento
  sleep(1);
  if(p1){
    signal(SIGUSR1, produci);
    raise(SIGUSR1);
  }
  else
    signal(SIGUSR1, consuma);
  while(1) {
    pause();
  }
  return 0;
}

void consuma(int a) {
  static char buf[1024];
  int i;
  printf("Ricevuto:");
  fgets(buf, 1024, f); 
  for(i=0; buf[i]; i++)
    buf[i] = toupper(buf[i]);
  printf("%s\n", buf);
  sleep(1);
  kill(p2, SIGUSR1);
}

void produci(int b) {
  char buf[1024];
  printf("Inserisci la stringa>");
  gets(buf);
  fprintf(f, "%s", buf);
  sleep(1);
  kill(p1, SIGUSR1);
}
