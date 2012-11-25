//Malfoy: Fifa potter eh???
//Harry: No! FIFO! xD
//Ok scusate... non lo faccio apposta xD
#ifndef FIFO_H
#define FIFO_H

#include "item.h"
#include <stdio.h>

//A seconda di come compiliamo, avremmo o una lista normale o un vettore
#ifdef VECTORIAL
	typedef Item Node[100]; //Massimo 100 
#else
	typedef struct __node {
		Item value;
		struct __node *next;
	} * Node;
#endif

typedef struct _fifoPotter {
	//Qui memoriziamo quanta robba c'è
	int size;
	//Qui invece a seconda dell'implementazione, facciamo o un vettore o il primo elemento della lista
	Node list;
#ifndef VECTORIAL
	//Se non facciamo niente di vettoriale, allora per velocizzare ci memorizziamo anche l'ultimo elemento
	Node last;
#else
	int ref;
#endif
} FIFO;

//Ora le funzioni:

// - creazione di una nuova struttura (vuota).
FIFO lifo_new();//Restituisce una lista vuota

// - inserimento di un nuovo elemento della struttura.
int fifo_enqueue(FIFO*, Item);//Restituisce la dimensione della nuova lista

// - estrazione di un elemento dalla struttura.
Item fifo_dequeue(FIFO*);

// - visualizzazione (a video) di tutti gli elementi nella base dati (opzionale).
void fifo_enum(const FIFO*, FILE*);

// - salvataggio della base dati su file (opzionale).
void fifo_save(const FIFO*, FILE*);

// - caricamento di una nuova base dati da file (opzionale).
FIFO fifo_load(FILE*);


int fifo_size(FIFO*);
#endif