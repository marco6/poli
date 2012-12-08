
/*
#include <stdio.h>
#include <stdlib.h>

void conta(char *v, char *a);

int main()
{
  int N,i;
  char *vett;

  printf("Inserisci quanti bit: ");
  scanf("%d",&N);

  vett=(char*)malloc((sizeof(char)*N)+1);

  vett[N]='\0';
  for(i=0;i<N;i++) vett[i]='0';

  printf("%s",vett);
  printf("\n");

  for(i=0; i<((1<<N)-1);i++)
  {
    conta(vett, (vett+N-1));

    printf("%s",vett);
    printf("\n");
  }

  free(vett);
  return 0;
}

void conta(char *v, char *a)
{
	if((*a)=='0')
	    (*a) = '1';
	else
	{
	  *a='0';
	  if(a > v)
	  conta(v, a-1);
    }
}

*/

#include <stdio.h>
#include <stdlib.h>

void bin(char *vett, int N, int i);

int main()
{
  int N;
  char *vett;

  printf("Inserisci quanti bit: ");
  scanf("%d",&N);

  vett=(char*)malloc((sizeof(char)*N)+1);

  vett[N]='\0';

  bin(vett,N,0);

  free(vett);

  return 0;
}

void bin(char *vett, int N, int i)
{
	if(i<N)
	{
		vett[i]='0';
		bin(vett, N, i+1);
		vett[i]='1';
		bin(vett, N, i+1);
		}
		else
		printf("%s\n", vett);
	}


