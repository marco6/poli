#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define _(a,b) [(b+(n*a))]

void trova_collegamenti_indiretti(int)

typedef struct info{
  float costo;
  float durata;
}info;

typedef struct Citta{
  char nome[20];
	int visitato;
}Citta;

info *voli;
Citta *citta; 
int NC;

int main()
{
 FILE *file;
 char tmp_partenza[20], tmp_arrivo[20];
 int i, j, n, citta_mem=0, partenza_trovata, arrivo_trovato, trovata;
 float costo, durata;
 
 file=fopen("Dati", "r");
 fscanf(file, "%d", &NC);
 
 voli=malloc(sizeof(info)*NC*NC);
 citta=malloc(sizeof(Citta)*NC);
 
 for(i=0; i<NC; i++){
   citta[i].visitato=0; 
   for(j=0; j<NC; j++)
     voli_(i,j).costo==0;
 }
 
 for(i=0; i<NC; i++)
 {
   fscanf(file, "%d", n);
   
   for(k=0; k<n; k++){
	   
   partenza_trovata=arrivo_trovato=-1;
   fscanf(file, "%s %s %d %d", tmp_partenza, tmp_arrivo, &costo, &durata);
   
   for(j=0; j<citta_mem || (partenza_trovata!=-1 && arrivo_trovato!=-1); j++)
   {
	 if(strcmp(tmp_partenza,citta[j].nome)==0)
		 partenza_trovata=j;
		 
	 if(strcmp(tmp_arrivo,citta[j].nome)==0)
		 arrivo_trovato=j;
   }
   if(partenza_trovata==-1){
     strcpy(citta[citta_mem].nome,tmp_partenza);
     citta_mem ++;
     partenza_trovata=citta_mem;
   }
   
   if(arrivo_trovato==-1){
     strcpy(citta[citta_mem].nome,tmp_arrivo);
	 citta_mem ++;
	 arrivo_trovato=citta_mem;
   }
   voli_(partenza_trovata,arrivo_trovato).costo=costo;
   voli_(partenza_trovata,arrivo_trovato).durata=durata;
  } //fine mem di voli in partenza dalla stessa citta
 } //fine memorizzazione
 
 printf("Inserisci un a citta di partenza (prima lettera maiuscola): ");
 scanf("%s", tmp_partenza);
 
 partenza_trovata=0;
 for(i=0; i<NC && partenza_trovata==0; i++){
  if(strcmp(tmp_partenza, citta[i].nome)==0)
    partenza_trovata=i;
  }
    
 printf("\nLe citta collegate solo direttamente a partire da %s sono: ", tmp_partenza);
 trovata=0;
 for(i=0; i<NC; i++){
    if(voli_(partenza_trovata,i).costo!=0)//trovo collegamenti diretti
     printf("\n%s", citta[i].nome);
     trovata=1;
 }
 if(trovata=0) printf("\nNessun collegamento a partire da questa citta");
 
 if(trovata=1){
 for(i=0; i<NC; i++)
   citta[i].visitato=0;
   
 trova_collegamenti_indiretti(partenza_trovata); //trovo i collegamenti sia diretti che indiretti
 printf("\nLe citta collegate direttamente o indirettamente a partire da %s sono: ", tmp_partenza);
 
 for(i=0; i<NC; i++)
  if(citta[i].visitato==1)
	  printf("\n%s", citta[i].nome);
 }
 
 for(i=0; i<NC; i++)
   if(voli_(i,i)!=0) ciclo=1;  // controllo sui cicli
 if(ciclo=1) printf("\nCe almeno un ciclo!");
 else printf("\nNon ci sono cicli");
 
 return 0;
}

void trova_collegamenti_indiretti(int partenza)
{
	int i;
	
	for(i=0; i<NC; i++)
	  if(voli_(partenza, i).costo!=0){
		  if(citta[i].visitato==0){
		  citta[i].visitato=1;
		  trova_collegamenti_indiretti(i);
	      }
	  }
	}
	
