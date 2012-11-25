#include "item.h"

Item createItem(ItemType t){
	Item r;
	//Azzeriamo tutto
	r.type = t;//Assegnamo il tipo
	memset(&r.data, 0, sizeof(r.data));
	//Ora restituiamo gentilmente il pacco
	return r;
}//createItem

//Riempie l'elemento
void itemFill(Item*i, void*data){
	static int sizes[3] = { sizeof(int), sizeof(Stringa), sizeof(Both) };
	//Inizializziamo la memoria e copiamoci dentro il tutto
	memcpy(i->data.generic = malloc(sizes[(int)i->type]), data, sizes[(int)i->type]);//Apposto
}//itemFill

//Elimina l'elemento
void deleteItem(Item *i){
	//Dobbiamo solo eliminare la memoria presa in prestito
	free(i->data.generic);
}//deleteItem