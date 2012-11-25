#ifndef ITEM_H
#define ITEM_H
//Questo rappresenta cosa contiene l'elemento
enum ItemType {
	Intero = 0,
	Stringa = 1,
	Both = 2
}//ItemType

typedef char Stringa[51];//Na cosa per semplificare la scrittura dopo

//Questa invece è la struttura con sia l'intero che la stringa.. gangabanane
typedef struct both {
	int i;
	char s[51];
} Both;

//Ora, l'elemento è definito da un tipo e dai dati
typedef struct __item {
	ItemType type;//Tipo
	union {//Dati
		//tutti... vicini vicini xD
		int i;
		Stringa *s;
		Both *b;
	} data;
} Item;

//Genera l'elemento(vuoto)
Item createItem(ItemType);

//Riempie l'elemento
void itemCopy(Item*i, void*data);

//Elimina l'elemento
void deleteItem(Item *i);
#endif
