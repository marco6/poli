#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define WORD 20

void cerca (char *key, int dim);

typedef struct
{
    int occor;
    char key[WORD+1];
} parole;

parole *word;

int main()
{
    int dim, j;
    char testo[WORD+1];

    FILE *f1, *f2;

    f1=fopen("parole.txt", "r");
    fscanf(f1,"%d",&dim);
    word=(parole*)malloc(dim*sizeof(parole));

    for(j=0; fscanf(f1,"%s",word[j].key)!=EOF; j++)
        word[j].occor=0;

    f2=fopen("testo.txt", "r");

    while(fscanf(f2,"%s",testo)!=EOF)
    {
        cerca(testo, dim);
    }

    fclose(f1);
    fclose(f2);
    free(word);

    for(j=0;j<dim;j++)
        printf("%s = %d occorrenza/e\n", word[j].key, word[j].occor);
    return 0;
}//main


void cerca (char *testo, int dim)
{
    int i;
    for (i=0; i<dim; i++)
    {
        if(strcmpi(testo,word[i].key)==0)
        {
            word[i].occor++;
            break;
        }//if
    }//for
}//void
