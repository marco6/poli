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

void file_copy(int fdf, int fdt){
  static char buff[4096];
  int r;
  while((r = read(fdf, buff, 4096))){
    write(fdt, buff, r);
  }
  close(fdf);
  close(fdt);
}

void dir_copy_r(struct dirent *de, int bk){
  DIR*d;
  struct dirent *drb;
  struct stat st;
  int nln;
  if(strcmp(de->d_name, ".") && strcmp(de->d_name, "..")){
    if(lstat(de->d_name, &st) < 0){
      puts("Errore");
      exit(1);
    }//if

    //Per la ricorsione concateno le stringhe.. ovviamente in modo furbo visto che ho già la lunghezza!
    pathBuf[bk] = '/';
    pathBuf[bk+1]='\0';
            
    strcpy(pathBuf + bk + 1, de->d_name);
      
    if(S_ISDIR(st.st_mode)){
      //creo la nuova cartella con i permessi uguali a quelli dell'originale
      mkdir(pathBuf, st.st_mode);
      //Mi calcolo la lunghezza di nln
      nln = strlen(de->d_name);

      //entro nella cartella
      chdir(de->d_name);
      //e la apro
      d = opendir(".");
      //Ora leggo e copio
      while(( drb = readdir(d) )) {
	dir_copy_r(drb, bk + nln+1);
      }//while
      closedir(d);
      chdir("..");
    }//if
    else
      file_copy(open(de->d_name, O_RDONLY), open( pathBuf, O_WRONLY | O_CREAT | O_TRUNC, st.st_mode ));
    pathBuf[bk] = '\0';
  }//if
}//dir_copy_r

void dir_copy(const char*from, const char*to){
  DIR*d;
  struct dirent * de;
  //Questo mi serve per tornare indietro nel path dopo la ricorsione..
  int bk;

  //e imposto la destinazione
  realpath(to, pathBuf);
  bk = strlen(pathBuf);
  
  //Solito chdir per evitare di portarmi dietro il nome
  chdir(from);
  //E ora leggo la radice
  d = opendir(".");
  
  while(( de = readdir(d) )) {
    //per ogni elemento, copio.
    dir_copy_r(de, bk);
  }//while
}//dir_copy
