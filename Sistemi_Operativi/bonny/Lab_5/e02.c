#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
  FILE *file;
  char string[200];

  file = fopen(argv[1], "r");

  /* while(feof(file)==0)  */
  /* {  */
  /*    fgets(string,200,file); */
  /*    system(string);  */
  /*  }  */
 
  while(feof(file==0){
      fgets(string,200,file);
      pid = fork();
      if(pid==0){
	execlp("/bin/sh", "comando", "-c", string, NULL);
      }else (wait(NULL), sleep(3));
  }
  return 0;
}
