#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>

typedef struct graph * graph;

typedef struct edge {
	unsigned int from, to;
	int w;
} edge;

extern edge edge_new(int, int, int);

extern graph graph_init(size_t, int orientato);

extern void graph_insert(graph, edge);

extern void graph_remove(graph, edge);

extern size_t graph_vertex(graph);

extern int graph_is_connected(graph);

extern edge * graph_edges(graph);

extern void graph_free(graph);

extern void graph_dfv(graph);

/** 
  * Restituisce le lunghezze dei minimi cammini partendo da un nodo.
  * Inoltre memorizza in connected un valore booleano che indica se è connesso 
  * o no e in tree l'albero dei percorsi minimi.
  */
extern int * dijkstra(graph g, int from, int*tree, int (*add)(int, int));

extern int * bellman_ford(graph g, int from, int *tree, float (*add)(float, float));

#endif