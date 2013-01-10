#ifndef GRAPH_H
#def GRAPH_H
#include <stdlib.h>
#include <stdio.h>

typedef GRAPH* Graph; 

typedef struct{
 int a,
     b;
 float costo,
       durata;
}Edge;

Graph GRAPH_init(int);
void GRAPH_insert_E(Graph, Edge);
int* GRAPH_dir_undir_E(Graph, int);
Edge EDGE_create(int, int, float, float);
int GRAPH_find_loop(Graph);
void GRAPH_delete(Graph);

#endif 
