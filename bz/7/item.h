//Queste sono le sentinelle, paladine della pace xD
#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>

typedef char Stringa[51];//Na cosa per semplificare la scrittura dopo

//Questa invece è la struttura con sia l'intero che la stringa.. gangabanane
typedef struct both {
	int i;
	char s[51];
} Both;

//Questo rappresenta cosa contiene l'elemento
typedef enum _it {
	intero = sizeof(int),
	stringa = sizeof(Stringa),
	both = sizeof(Both)
} ItemType;//ItemType

//Ora, l'elemento è definito da un tipo e dai dati
typedef struct __item {
	ItemType type;//Tipo
	union {//Dati
		//tutti... vicini vicini xD
		int *i;
		Stringa *s;
		Both *b;
		void *generic;
	} data;
} Item;

//Stampa sul file, a seconda se char == 0 in modalità leggibile, se no in modalità binaria
int printItem(const Item*, FILE*, char);

//Carica un elemento da un file in modalità binaria
Item loadItem(FILE*);

//Genera l'elemento(vuoto)
Item createItem(ItemType);

//Riempie l'elemento
void itemFill(Item*,void*);

//Elimina l'elemento
void deleteItem(Item*);
#endif
