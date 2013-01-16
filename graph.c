#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <graph.h>
#include <heap.h>

//grafo implementato con la matrice di adiacenza
struct graph {
	int **adj;//matrice di adiacenza
	size_t v;//Numero di vertici
	size_t e;//Numero di archi
	unsigned int orientato:1,
		has_gaps;//bitfield, sempre per bonato xD!! 
		//(cmq sta cazzata non la metterei nella relazione, anche se � standard)
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
}

void graph_remove(graph g, edge e){
	assert(g != NULL);
	assert(e.from < g->v && e.to < g->v);//Controllo che siamo nei limiti
	//Rimuovendo un arco, non sappiamo se il grafo resta connesso o no,
	//Quindi lo segnamo
	g->connesso = -1;
	g->adj[e.from][e.to] = 0;
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
	if(*(int*)a == -1)
		return 1;
	return *(int*)a - *(int*)b;
}

int graph_is_connected(graph g){
	if(g->connesso == -1)//Se non lo so
		graph_dfv(g);//Me lo ricavo
	return g->connesso;
}

edge * graph_adjacency(graph g, int from, size_t *out){
	//alloco il necessario, per non dover allocare di nuovo.
	int i;
	edge*e;
	if(g == NULL || out == NULL)
		return NULL;
	*out = 0;
	e = malloc(sizeof(edge) * sizeof(g->v));
	for(i = 0; i < g->v; i++)
		if(g->adj[from][i]){
			e[*out] = edge_new(from, i, g->adj[from][i]);
			*out += 1;
		}
	return e;
}

//implemento dijkstra
int * dijkstra(graph g, int from, int*tree, int (*add)(int, int)){
	edge *adj;
	size_t adj_size, vertex;
	int * somme, i, act;//Commistione linguistica che bonato ama! xD
	heap_t *heap;//Questa copiata di brutto da Rocco xD
	//Becco il numero di vertici
	vertex = graph_vertex(g);
	//Ok ora alloco lo spazio per le somme
	somme = malloc(sizeof(int) * vertex);
	
	assert(somme != NULL);
	
	//E piazzo tutto a -1 che in binario � 11111111....1111 ... fino alla nausea... 1111
	memset(somme, 0xff, vertex * sizeof(int));
	//Good! Ora per� la prima va a 0!
	somme[from] = 0;
	//Ci siamo quasi...
	//ora le heap!
	heap = heap_make(somme, vertex, heapcmp, sizeof(int));
	//Metto a TRUE la flag *connected
	g->connesso = 1;
	//Ultimissima cosa: inizializzo l'albero delle visite ad una foresta di alberi di un solo elemento
	for(i = 0; i < vertex; i++)
		tree[i] = i;
	//Ora il ciclo, prepariamo l'assorbente xD
	while(!heap_is_empty(heap)){
		//Estraggo il primo elemento
		from = heap_extract(heap);
		//Se la distanza per arrivare � ancora infinita (-1), significa che questa parte del
		//Grafo non � mai stata raggiunta da nessun arco e quindi � disconnessa dalla componente
		//In cui � presente il nodo di partenza, e quindi, visto che questo � il massimo possibili
		//tutti gli altri elementi nella heap avranno lo stesso valore, quindi interrompo qui
		//l'esecuzione
		if(somme[from] == -1) {
			g->connesso = 0;//Segno che il grafo non � connesso
			//interrompo il ciclo
			break;
		}
		//Adesso mi ricavo la lista di adiacenza sottoforma di vettore
		adj = graph_adjacency(g, from, &adj_size);
		//E itero tra tutto
		for(i = 0; i < adj_size; i++){
			//Mi calcolo la distanza attuale + quella dell'arco tramite una funzione esterna
			act = add(somme[from], adj[i].w);
			//Se la somma � a -1 (non � ancora stato aggiornato) oppure il nuovo valore
			// e' inferiore a quello vecchio, lo metto uguale e aggiorno l'albero delle visite
			if(somme[adj[i].to] == -1 || somme[adj[i].to] > act){
				somme[adj[i].to] = act;
				tree[adj[i].to] = from;
				//Ho aggiornato: devo fare un fix della heap che potrebbe essere andata a farsi fottere!
				heap_fix(heap, adj[i].to);
			}//if
		}//for
		//Ora elimino la copia della lista di adiacenza che avevo ottenuto dal grafo
		free(adj);
	}//while
	heap_free(heap);//Questa non mi cancella l'array somme, quindi sono contento xD
	//Bene! abbiamo finito! :)
	return somme;
}//Bah, anche se steve dice che non ci va molto a scriverla... io ce ne ho messo u.u

