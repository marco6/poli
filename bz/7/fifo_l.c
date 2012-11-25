//Implementazione con le liste
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
	rm = l->list//Ciapa lì il primo
	r = rm->value;//Adeis il suo valore
	l->list = rm->next;//Aggiorniamo la lista
	free(rm);//Ed eliminiamo il poveraccio
	l->size--;//Ricordiamo di cancellare anche dalla dimensione
	return r;//Restituiamo il valore
}//fifo_dequeue

void fifo_enum(const FIFO*, FILE*);

void fifo_save(const FIFO*, FILE*);

FIFO fifo_load(FILE*);

int fifo_size(FIFO*l){
	return l->size;//BAh
}
#endif