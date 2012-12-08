#include <stdio.h>
#include <stdlib.h>

typedef char elem[5];

typedef struct {
	int size;
	elem *mem;
} array;

void funz(char *c, int size, int i, elem * mat);

int main()
{
  FILE *file;
  char *c;
  array a;
  a.mem = NULL;
  a.size = 0;
  void *punt_tmp=NULL;

  file=fopen("totocalcio", "r");

  while(feof(file)==0)
  {
		a.size++;
		punt_tmp=realloc(a.mem, a.size*sizeof(elem));
		if(punt_tmp!=NULL){
			a.mem=(elem*)punt_tmp;
			fscanf(file,"%s ", a.mem[a.size-1]);
		}
	  else{
		  printf("Errore con la realloc");
		  exit(1);
	  }
  }
  fclose(file);

  c=(char*)malloc(sizeof(char)*a.size + 1);
  c[a.size]='\0';
  funz(c, a.size, 0, a.mem);

  return 0;
}

void funz(char *c, int size, int i, elem *mat)
{
	if(i<size){
		c[i]=mat[i][0];
		funz(c, size, i+1, mat);
		if(mat[i][1]!='\0'){
		    c[i]=mat[i][1];
		    funz(c, size, i+1, mat);
		  if(mat[i][2]!='\0'){
		    c[i]=mat[i][2];
		    funz(c, size, i+1, mat);
		}
            }
	}
	else
		printf("%s\n", c);
}
