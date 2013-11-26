#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAXPATH 4096

#define USE_EXEC 1

#define NENDLINE 0


char**argSplit(char*);

int main(int argc, char **argv){
  FILE*f;
  char buf[MAXPATH], **v;
  if(argc < 2){
    puts("Utilizzo: esegui <file>");
    return 0;
  }
  if(( f = fopen(argv[1], "r") ) == NULL ){
    puts("Impossibile aprire il file.");
    return -1;
  }
  while(!feof(f)){


#if USE_EXEC

    if(fork() == 0){
      
#if NENDLINE
      v = argGet(f, buf);
#else
      fgets(buf, MAXPATH, f);
      v = argSplit(buf);
#endif
      //Questo funge ma non soddisfa...
      //execl("/bin/sh", "sh",  "-c", buf,  (char*)NULL);
      execvp(v[0], v);
    }
    else{
      wait(NULL);
      sleep(3);
    }
#else
    fgets(buf, MAXPATH, f);
    system(buf);
    sleep(3);
#endif
    
  }
  return 0;
}
int p() {
  return 1;
}

//Ok ammetto che sta qui è un po' insana... però a mia discolpa c'è l'assembly che mi ha abituato allo stack..
char** argSplit(char*str) {
  //In questa versione, NON allochiamo memoria a caso. Solo a fine elaborazione.
  static char **r;
  static int i = 0;
  //Separiamo il passo precedente.
  if(str == NULL){
    //ORA alloco!
    r = malloc((i+1)  * sizeof(char**));
    r[i] = NULL;
    return r;
  }
  
  if(i){
    *str= '\0';
    str++;
  }
  
  //Eliminiamo i caratteri vuoti.
  while(*str == ' ')
    str++;

  //Se sono arrivato alla fine della linea o della stringa, anche in questo caso devo allocare
  if(*str == '\n' || *str == '\0'){
    //ORA alloco!
    *str = '\0';
    r = malloc((i+1)  * sizeof(char**));
    r[i] = NULL;
    return r;
  }

  i++;
  //Ora cerchiamo il prossimo spazio e diamolo in pasto alla ricorsione
  (void)argSplit(strchr(str, ' '));
  i--;

  r[i] = str;
  return r;
}

char ** argGet(FILE*f, char*buf){
  static char**r;
  static int i = 0;
  int n;
  fscanf(f, "%s%n", buf, &n);
  if(strcmp("end", buf)){
    r = malloc(i * sizeof(char*));
  }  
  i++;
  (void)argGet(f, buf+n+1);
  i--;
  r[i] = buf;
  return r;
}
