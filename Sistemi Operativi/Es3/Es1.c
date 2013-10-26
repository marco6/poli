#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

#define MAX_PATH 4096

void dir_copy(const char*from, const char*to);

int main(int argc, char *argv[]){
  if(argc < 3){
    puts("Utilizzo: copy <from> <to>");
    return 0;
  }
  dir_copy(argv[1], argv[2]);
  return 0;
}


//Funzioni/variabili nascoste al main e in generale utili solo all'implementazione
char pathBuf[MAX_PATH] = {0};

void file_copy(int fdf, int fdt);

void dir_copy_r(struct dirent *de, int bk){
  DIR*d;
  struct stat st;
  int nln;
  if(strcmp(de->d_name, ".") && strcmp(de->d_name, "..")){
    if(lstat(de->d_name, &st) < 0){
      puts("Errore");
      exit(1);
    }//if
    if(S_ISDIR(st.st_mode)){
      //Per la ricorsione concateno le stringhe.. ovviamente in modo furbo visto che ho già la lunghezza!
      strcat(pathBuf + bk, de->d_name);
      
      pathBuf[bk] = '/';
      pathBuf[bk+1]='\0';
      
      //creo la nuova cartella con i permessi uguali a quelli dell'originale
      mkdir(pathBuf, st.st_mode);
      //Mi calcolo la lunghezza di nln
      nln = strlen(de->d_name);
      //entro nella cartella
      chdir(de->d_name);
      //e la apro
      d = opendir(".");
      //Ora leggo e copio
      while(( de = readdir(d) )) {
	dir_copy_r(de, bk + nln+1);
      }
      closedir(d);
      chdir("..");
      pathBuf[bk] = '\0';
    }
  }//if
}//dir_copy_r

void dir_copy(const char*from, const char*to){
  DIR*d;
  struct dirent * de;
  //Questo mi serve per tornare indietro nel path dopo la ricorsione..
  int bk = strlen(to);
  //Solito chdir per evitare di portarmi dietro il nome
  chdir(from);
  //E ora leggo la radice
  d = opendir(".");
  
  //e imposto la destinazione
  strcpy(pathBuf, to);

  pathBuf[bk] = '/';
  pathBuf[++bk]='\0';

  while(( de = readdir(d) )) {
    //per ogni elemento, copio.
    dir_copy_r(de, bk);
  }//while
}//dir_copy
