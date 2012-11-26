//Implementazione con le liste
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fifo.h"

#ifndef VECTORIAL

FIFO fifo_new(){
	FIFO n;
	//Basta mettere tutto a 0
	memset(&n, 0, sizeof(FIFO));
	return n;
}//lifo_new

int fifo_enqueue(FIFO*l, Item i){
	//Dobbiamo aggiungere un nuovo elemento... e sarà lui il primo ad uscire!
	//Prendiamo l'attuale ultimo e accodiamoci un tizio, ma solo se c'è un ultimo
	if(l->size)
		l->last = l->last->next = (Node)malloc(sizeof(struct __node));//Aggiungiamo un posto a tavola
	//Se non ci sono ancora elementi, allora mettiamo questo come primo e ultimo
	else
		l->last = l->list = (Node)malloc(sizeof(struct __node));
	l->last->value = i;//E facciamoci sedere l'amico che ci sono le fettine panate xD
	l->last->next = NULL;
	return ++l->size;
}//fifo_enqueue

Item fifo_dequeue(FIFO*l){
	Node rm;//Qui memorizziamo il nodo da eliminare
	Item r;//Qui memorizziamo quello cio' che dobbiamo restituire
	rm = l->list;//Ciapa lì il primo
	r = rm->value;//Adeis il suo valore
	l->list = rm->next;//Aggiorniamo la lista
	free(rm);//Ed eliminiamo il poveraccio
	l->size--;//Ricordiamo di cancellare anche dalla dimensione
	return r;//Restituiamo il valore
}//fifo_dequeue

void fifo_enum(const FIFO*l, FILE*out) {
	//Dobbiamo scorrere tutta la lista e stamparla sul file
	//Partiamo dall'inizio
	Node i = l->list;
	while(i){
		//Stampiamo
		printItem( &i->value, out, 0);
		//andiamo a capo
		putc('\n', out);
		//E andiamo al prossimo
		i = i->next;
	}//while
}//fifo_enum

void fifo_save(const FIFO*l, FILE*out){
	//Uguale a prima
	Node i = l->list;
	while(i){
		//Stampiamo
		printItem( &i->value, out, 1);//Stavolta però stampiamo in formato binario
		//E andiamo al prossimo
		i = i->next;
	}//while
}//fifo_save

FIFO fifo_load(FILE*in){
	FIFO r, *er;
	Item i;
	r = fifo_new();
	er = &r;
	
	//ora carichiamo
	while(loadItem(in, &i))
		fifo_enqueue(er, i);
	return r;
}//fifo_load

void fifo_unload(FIFO*l){
	while(l->size)
		fifo_dequeue(l);//eliminiamo tutti dalla coda
}//fifo_unload

int fifo_size(FIFO*l){
	return l->size;//BAh
}//fifo_size

#endif
