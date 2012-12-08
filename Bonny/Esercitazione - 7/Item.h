#ifndef DATI_H
#define DATI_H

#ifdef TINT
typedef int Item;
#else
#define SIZE 50
#ifdef TSTRING
typedef char Item[SIZE+1];
#else
typedef struct {
	 int n;
	 char s[SIZE+1];
	}Item;
#endif
#endif

Item new_item();

void stampa_item(Item item);

#endif
