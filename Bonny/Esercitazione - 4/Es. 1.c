#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void all_to_lower(char *s);

int main()
{
 struct diz{
     char parola[20];
     int occorrenze;
     };
 struct diz *dizionario;
 int n,i,trovato;
 FILE *file1, *file2;
 char str_tmp[20];

 file1=fopen("file1","r");
 fscanf(file1,"%d",&n);

 dizionario= malloc(sizeof(struct diz)*n);

 for(i=0;i<20;i++){
  fscanf(file1,"%s",dizionario[i].parola);
  dizionario[i].occorrenze=0;
  }
 fclose(file1);

 file2=fopen("file2","r");

 while(feof(file2)==0)
 {
    trovato=0;
    fscanf(file2,"%s",str_tmp);

    all_to_lower(str_tmp);

    for(i=0;i<n && trovato==0; i++)
     if(strcmp(str_tmp,dizionario[i].parola)==0)
        {
            trovato=1;
            dizionario[i].occorrenze ++;
            }
     }
 fclose(file2);

 for(i=0; i<n; i++)
  printf("%s - %d occorrenza/e\n", dizionario[i].parola, dizionario[i].occorrenze);

free(dizionario);

 return 0;
}

void all_to_lower(char *s)
{
    int lung, i;
    lung=strlen(s);
    for(i=0;i<lung;i++)
    {
        if((s[i]>64)&&(s[i]<91))
        {
            s[i] += 32;
        }
    }
}
