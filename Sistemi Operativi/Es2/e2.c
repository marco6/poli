#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_dir_s(const char*dir);
void print_dir_d(const struct dirent*d, int lv);
int count;

int main(int argc, char**argv){
  int i;
  if(argc == 1)
    print_dir_s(".");
  for(i = 1; i < argc; i++)
    print_dir_s(argv[i]);
  count = 0;
  return 0;
}

void print_dir_s(const char*dir){
  DIR* d = opendir(dir);
  struct dirent *de;
  if(d == NULL){
    if(errno == ENOTDIR)
      printf("File %s\n", dir);
    else
      puts("Impossibile aprire la cartella");
    return;
  }
  chdir(dir);
  while((de = readdir(d))){
    print_dir_d(de, 0);
  }
  closedir(d);
}

void print_dir_d(const struct dirent*d, int lv) {
  
  static struct stat stbuff;
  DIR*dr;
  struct dirent *de;
  int i;


  for(i = 0; i < lv; i++)
    putchar('+');
  putchar(' ');
  if(strcmp(d->d_name, ".") == 0){
    printf("Dir %.2d: .\n", count++);
    return;
  }
  else if(strcmp(d->d_name, "..") == 0){
    printf("Dir %.2d: ..\n", count++);
    return;
  }

  if(lstat(d->d_name, &stbuff) < 0){
    puts("Errore\n");
    exit(1);
  }
  if(S_ISDIR(stbuff.st_mode)){
    printf("Dir %.2d: %s\n", count++, d->d_name);
    dr = opendir(d->d_name);
    if(dr == NULL) {
      printf("Impossibile aprire la cartella %s\n", d->d_name);
      return;
    }
    chdir(d->d_name);
    while((de = readdir(dr))) {
      print_dir_d(de, lv+1);
    }
    chdir("..");
  }
  else
    printf("File %.2d: %s\n", count++, d->d_name);
}
