#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Ingredienti{
	  char nome[21];
	  int quantita;
  }Ingredienti;
  
typedef struct Ricette{
	char nome[21];
	int prezzo;
	int *ingredienti;
}Ricette;

Ricette *ricette;
Ingredienti *ingredienti;
int ni, nr, MAX = 0, *ordine_ideale, *ordine_prov;

void ricors(int);

int main()
{
	int i, q_tmp, num, j, k;
	FILE *fi, *fr;
	char tmp[21];
	
	fi=fopen("Ingredienti","r");
	fr=fopen("Ricette", "r");
	
	fscanf(fi,"%d", &ni);
	fscanf(fr,"%d", &nr);
	
	ingredienti=malloc(sizeof(Ingredienti)*ni);
	ricette=malloc(sizeof(Ricette)*nr);
	ordine_ideale=malloc(sizeof(int)*nr);
	ordine_prov=malloc(sizeof(int)*nr);
	
	for(i=0;i<ni;i++)
		fscanf(fi,"%s %d", ingredienti[i].nome, &ingredienti[i].quantita);
	
	for(i=0;i<nr; i++){
		ricette[i].ingredienti=calloc(ni, sizeof(int));
	   
		fscanf(fr,"%s %d %d", ricette[i].nome, &ricette[i].prezzo, &num);
		for(j=0;j<num;j++){
			fscanf(fr, "%s %d", tmp, &q_tmp);
			k = 0;
			while(k < ni && strcmp(tmp, ingredienti[k].nome))
				k++;
			ricette[i].ingredienti[k]= q_tmp;
		}
	}
	
	ricors(0);
	
    printf("L'ordine ideale e':\n");	

	for(i=0;i<nr;i++)
	  if(ordine_ideale[i])
		printf("%d %s valore %d\n", ordine_ideale[i], ricette[i].nome, ordine_ideale[i]*ricette[i].prezzo);
	
	printf("Il guadagno massimo e' %d\n", MAX);
	
	for(i=0; i<nr; i++)
	  free(ricette[i].ingredienti);
	  
	free(ricette);
	free(ingredienti);
	
	return 0;
}

void ricors(int max){
	int i,j, possibile;
	
		for(i=0; i<nr; i++){
			possibile=1;
			for(j=0;j<ni && possibile; j++){
				if(ricette[i].ingredienti[j]!=0 && ingredienti[j].quantita < ricette[i].ingredienti[j])
						possibile=0;
			}
			if(possibile==1){
				for(j=0; j<ni; j++)
					ingredienti[j].quantita -= ricette[i].ingredienti[j];
				ordine_prov[i]++;
				max+=ricette[i].prezzo;
			
				if(max > MAX){
					MAX=max;
					memcpy(ordine_ideale,ordine_prov,sizeof(int)*nr);
				}
				ricors(max);
		   
				for(j=0; j<ni; j++)
					ingredienti[j].quantita+=ricette[i].ingredienti[j];
				 
				max-=ricette[i].prezzo;
				ordine_prov[i]--;
			}
		}
}
