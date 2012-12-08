#include <stdio.h>
#include "date.h"

int main()
{
 FILE *file;
 Data recente,remota,tmp;

 file=fopen("Esempio.txt","r");

 recente=remota=prendi_data(file);

 while(feof(file)==0)
 {
  tmp=prendi_data(file);
  if(confronta_data(tmp,recente)) recente=tmp;
  else
  if(confronta_data(remota,tmp)) remota=tmp;
 }

 fclose(file);

 printf("La data piu remota e: ");

 stampa_data(remota);

 printf("\nLa data piu recente e: ");
 stampa_data(recente);

 tmp=diff_date(recente,remota);

 printf("\nLa differenza tra le date e: ");
 stampa_data(tmp);

 return 0;
}
