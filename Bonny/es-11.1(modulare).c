#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "utility.h"

char *citta;

int cmpstr(void* a, void* b){
  return strcmp((char*)a,(char*) b);
	}

int main()
{
    Graph graph;
    FILE *file;
    int citta_mem, i, j, index_arrivo, index_partenza, *index_conessioni;
    file= fopen("dati", "r");
    fscanf("%d", &NC);

    citta=malloc(sizeof(char)*NC*20);
    index_connessioni = malloc(sizeof(int)*NC);
    graph=graph_init(NC);

    for(i=0; i<NC; i++)
    {
        fscanf("%d", &n);
        for(j=0; j<n; j++) {
            fscanf("%s %s %f %f", partenza_tmp, arrivo_tmp, &costo_tmp, &durata_tmp);
            if((index_partenza=find(citta, citta_mem, 20*sizeof(char), partenza_tmp, cmpstr)) == -1)
            {
                index_partenza=[citta_mem];
                strcpy(citta[citta_mem],partenza_tmp);
                citta_mem ++;
            }
            if((index_arrivo=find(citta, citta_mem, 20*sizeof(char), arrivo_tmp, cmpstr)) == -1)
            {
                index_arrivo=[citta_mem];
                strcpy(citta[citta_mem],arrivo_tmp);
                citta_mem ++;
            }
            GRAPH_insert_E(graph, EDGE_create(index_partenza,index_arrivo,costo,durata));
        }
    }
    fclose(file);
    
    printf("Inserisci un a citta di partenza (prima lettera maiuscola): ");
    scanf("%s", tmp_partenza);

    index_partenza=find(citta,NC,sizeof(char)*20, tmp_partenza, cmpstr);

    index_connessioni=GRAPH_dir_undir_E(graph, index_artenza);

    printf("\nLe citta collegate direttamente o indirettamente a partire da %s sono: ", tmp_partenza);

    for(i=0; i<NC; i++)
        if(index_connessioni[i]==1) printf("\n%s", citta[i].nome);

    if(GRAPH_find_loop(graph)==1) printf("\nCe almeno un ciclo!");
    else printf("\nNon ci sono cicli");
	
	GRAPH_delete(graph);
	free(inde_connessioni);
	free(citta);
	
    return 0;
}
