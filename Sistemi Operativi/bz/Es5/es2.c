#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAXPATH 4096

#define USE_EXEC 1

#define NENDLINE 0


int main(int argc, char **argv){
  FILE*f;
  char buf[MAXPATH];
  execlp("ls -laR", "my", "/home", (char*)NULL);
  if(argc < 2){
    puts("Utilizzo: esegui <file>");
    return 0;
  }
  if(( f = fopen(argv[1], "r") ) == NULL ){
    puts("Impossibile aprire il file.");
    return -1;
  }
  while(!feof(f)){

#if NENDLINE
    //TODO
#else
    fgets(buf, MAXPATH, f);
#endif

#if USE_EXEC
    if(fork() == 0)
      execl("/bin/sh", "sh",  "-c", buf,  (char*)NULL);
    else{
      wait(NULL);
      sleep(3);
    }
#else
    system(buf);
#endif

  }
  return 0;
} 

