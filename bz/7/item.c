#include <string.h>
#include <stdlib.h>
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
	//Inizializziamo la memoria e copiamoci dentro il tutto
	memcpy(i->data.generic = malloc((int)i->type), data, (int)i->type);//Apposto
}//itemFill

//Elimina l'elemento
void deleteItem(Item *i){
	//Dobbiamo solo eliminare la memoria presa in prestito
	free(i->data.generic);
}//deleteItem

int printItem(const Item *i, FILE* out, char binary){
	if(binary)//Se dobbiamo salvarlo, salviamo il tipo di file 
			  //e il contenuto in modalità binaria
		return fwrite(&i->type, sizeof(ItemType), 1,out) &&
			fwrite(i->data.generic, (int)i->type, 1, out);

	switch(i->type){
		case intero:
			return fprintf(out, "int(%d)", *i->data.i);//Stampiamo l'intero
		case stringa:
			return fprintf(out, "string(\n%s\n)", (char*)i->data.s);//La stringa
		case both:
			//O entrambi
			return fprintf(out, "struct {\n\tint(%d)\n\tstring(\n\t\t%s\n\t)\n}", *i->data.i, (char*)i->data.s);
		default:
			return 0;
	}//Switch
}//printItem

Item loadItem(FILE* in){
	Item r;
	//Leggiamo il tipo
	fread(&r.type, sizeof(ItemType), 1, in);
	//E usiamolo come lunghezza
	fread(r.data.generic = malloc(r.type), r.type, 1, in);
	return r;//Restituiamo il risultato
}//loadItem
