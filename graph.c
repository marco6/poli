#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <graph.h>
#include <heap.h>
#include <math.h>

//grafo implementato con la matrice di adiacenza
struct graph {
	int **adj;//matrice di adiacenza
	size_t v;//Numero di vertici
	size_t e;//Numero di archi
	unsigned int orientato:1,
		has_gaps:1;//bitfield, sempre per bonato xD!! 
		//(cmq sta cazzata non la metterei nella relazione, anche se è standard)
	signed int connesso:2;
};

int **make_matrix(size_t r, size_t c){
	int i, **mat;
	mat = malloc(sizeof(int*)*r);
	assert(mat != NULL);
	mat[0] = malloc(sizeof(int)*r*c);//Alloco un solo blocco per comodita'
	assert(mat[0] != NULL);
	for(i = 1; i<r; i++)
		mat[i] = mat[i-1] + c;
	return mat;
}//make_matrix

edge edge_new(int from, int to, int w){
	edge r;
	r.from = from;
	r.to = to;
	r.w = w;
	return r;
}

graph graph_init(size_t s, int orientato){
	//Inizializzo il grafo
	graph r;
	assert(s != 0);//Controllo che ci sia almeno un vertice
	r = malloc(sizeof(struct graph));//Alloco memoria x il grafo
	assert(r != NULL);
	r->adj = make_matrix(s, s);//Alloco la matrice
	//e la metto a 0
	memset(r->adj, 0, sizeof(int)*s*s);
	r->orientato = orientato != 0;
	r->has_gaps = 0;//non ha archi!
	r->connesso = -1;
	r->v = r->e = 0;
	return r;
}

void graph_insert(graph g, edge e){
	assert(g != NULL);
	assert(e.from < g->v && e.to < g->v);//Controllo che siamo nei limiti
	//Ora faccio il mio dovere
	if(g->orientato)
		g->adj[e.from][e.to] = e.w;
	else
		g->adj[e.from][e.to] = 1;
	if(e.from == e.to)
		g->has_gaps = 1;
	g->e++;
}

void graph_remove(graph g, edge e){
	assert(g != NULL);
	assert(e.from < g->v && e.to < g->v);//Controllo che siamo nei limiti
	//Rimuovendo un arco, non sappiamo se il grafo resta connesso o no,
	//Quindi lo segnamo
	g->connesso = -1;
	g->adj[e.from][e.to] = 0;
	g->e--;
}

void graph_free(graph g){
	assert(g != NULL);
	//Elimino la matrice
	free(g->adj);
	free(g);
}

size_t graph_vertex(graph g){
	assert(g != NULL);
	return g->v;
}

static int heapcmp (void *a, void *b){
	if(*(int*)a == -1 || *(int*)b == -1)
		return 1;
	return *(int*)a - *(int*)b;
}

int graph_is_connected(graph g){
	//non implementato!
	//if(g->connesso == -1)//Se non lo so
		//graph_dfv(g);//Me lo ricavo
	return g->connesso;
}

edge * graph_edges(graph g){
	//alloco il necessario, per non dover allocare di nuovo.
	int i, j, es;
	edge*e;
	if(g == NULL)
		return NULL;
	e = malloc(sizeof(edge) * g->e);
	for(i = es = 0; i < g->v; i++)
		for(j = 0; j < g->v; j++)
			if(g->adj[i][j]){
				e[es] = edge_new(i, j, g->adj[i][j]);
				es++;
			}
	return e;
}

//implemento dijkstra
int * dijkstra(graph g, int from, int*tree, int (*add)(int, int)){
	int * somme, i, act;//Commistione linguistica che bonato ama! xD
	heap_t *heap;//Questa copiata di brutto da Rocco xD
	//Becco il numero di vertici
	somme = malloc(sizeof(int) * g->v);
	
	assert(somme != NULL);
	
	//E piazzo tutto a -1 che in binario è 11111111....1111 ... fino alla nausea... 1111
	memset(somme, 0xff, g->v * sizeof(int));

	//Good! Ora però la prima va a 0!
	somme[from] = 0;

	//Ci siamo quasi...
	//ora le heap!
	heap = heap_make(somme, g->v, heapcmp, sizeof(int));
	//Metto a TRUE la flag *connected
	g->connesso = 1;
	//Ultimissima cosa: inizializzo l'albero delle visite ad una foresta di alberi di un solo elemento
	for(i = 0; i < g->v; i++)
		tree[i] = i;
	//Ora il ciclo, prepariamo l'assorbente xD
	while(!heap_is_empty(heap)){
		//Estraggo il primo elemento
		from = heap_extract(heap);
		//Se la distanza per arrivare è ancora infinita (-1), significa che questa parte del
		//Grafo non è mai stata raggiunta da nessun arco e quindi è disconnessa dalla componente
		//In cui è presente il nodo di partenza, e quindi, visto che questo è il massimo possibili
		//tutti gli altri elementi nella heap avranno lo stesso valore, quindi interrompo qui
		//l'esecuzione
		if(somme[from] == -1) {
			g->connesso = 0;//Segno che il grafo non è connesso
			//interrompo il ciclo
			break;
		}
		//E itero tra tutto
		for(i = 0; i < g->v; i++){
			if(g->adj[from][i]){
				//Mi calcolo la distanza attuale + quella dell'arco tramite una funzione esterna
				act = add(somme[from], g->adj[from][i]);
				//Se la somma è a -1 (non è ancora stato aggiornato) oppure il nuovo valore
				// e' inferiore a quello vecchio, lo metto uguale e aggiorno l'albero delle visite
				if(somme[i] == -1 || somme[i] > act){
					somme[i] = act;
					tree[i] = from;
					//Ho aggiornato: devo fare un fix della heap che potrebbe essere andata a farsi fottere!
					heap_fix(heap, i);
				}//if
			}
		}//for
	}//while
	heap_free(heap);//Questa non mi cancella l'array somme, quindi sono contento xD
	//Bene! abbiamo finito! :)
	return somme;
}//Bah, anche se steve dice che non ci va molto a scriverla... io ce ne ho messo u.u

float* bellman_ford(graph g, int from, int *tree, int *negativeLoop, float (*add)(float, float)){
	float *dist, act;
	int i, j;
	edge * edges;
	*negativeLoop=1;
	//mi prendo i vertici
	dist = malloc(sizeof(float) * g->v);
	edges = graph_edges(g);//estraggo gli archi
	for(i = 0; i < g->v; i++)
		dist[i] = INFINITY; //Metto tutto a infinito... Purtroppo nello standard ansi c 90 non esiste la possibilita' di usare questa istruzione...
	dist[from]=0;
	for(i=0; i<g->v && *negativeLoop; i++)
	{
		for(j=*negativeLoop=0; j<g->e;j++)
		{
			act = add(dist[edges[j].from], edges[j].w);
			if(act<dist[edges[j].to])
			{
				tree[edges[j].to]=edges[j].from;
				dist[edges[j].to]=act;
				*negativeLoop=1;
			}
		}
	}
	
	*negativeLoop = *negativeLoop && (i==g->v);
	for(i=0; i<g->v && dist[i]!=INFINITY; i++) {}

    g->connesso= (i==g->v); 
    return dist;
}


void graph_dfv(graph g, int s, void*data, void (*visit)(int, void*)){
	
	
}
