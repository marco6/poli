#include <stdlib.h>
#include <stdio.h>
#include "FIFO.h"
#include "Item.h"

static link primo, ultimo, tmp;
static int count;

void crea_lista()
{
	primo=NULL;
	count = 0;
}

int coda_vuota()
{
	return (primo==NULL);
}
	
link crea_nodo(Item thing, link next)
{
	link x = malloc(sizeof(struct Node));
	x->item=thing;
	x->next=next;
	count ++;
	return x;
}
	
void new_node(Item thing) 
{
	if(primo==NULL){
		primo=ultimo=crea_nodo(thing,primo);
		return;
	}
	ultimo->next= crea_nodo(thing,ultimo->next);
	ultimo=ultimo->next;
}

Item estrai_nodo()
{
    Item a;
	tmp=primo;
	a=primo->item;
	primo=primo->next;
	free(tmp);
	count --;
 	return a;
}

void stampa_singolo(link punt)
{
	stampa_item(punt->item);
	if(punt->next!=NULL)
		stampa_singolo(punt->next);
}
	
void stampa_tutto()
{
	stampa_singolo(primo);
}
