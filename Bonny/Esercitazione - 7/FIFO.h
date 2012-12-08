#ifndef CODA_H
#define CODA_H

#include <stdlib.h>
#include "Item.h"

typedef struct Node *link;

typedef struct Node {
	 Item item;
	 link next;
	} Node;

void crea_lista();

int coda_vuota();

void new_node(Item thing);

Item estrai_nodo();

void stampa_tutto();

#endif
