#include <stdio.h>
#include <stdlib.h>

typedef struct __item {
	char s[6];
	int i;
	struct __item *next;
} Item;

void itera(Item*, Item*);

int main(int argc, char*argv[]){
	FILE *f;
	Item *i, *start;//primo elemento
	
	f = fopen(argv[1], "r");//Apro il file
	i = start = (Item*)malloc(sizeof(Item)); //Alloco il primo
	fgets(i->s, 5, f);//E lo riempio
	while(!feof(f)){//Se c'è roba.. Anche se feof potrebbe dare errore, fidiamoci :P
		i = i->next = (Item*)malloc(sizeof(Item));
		fgets(i->s, 5, f);
	}//While
	i->next = NULL;//Ok c'abbiamo la lista...
	
	itera(start,start);
	return 0;
}

void itera(Item*start, Item *i){
	if(i==NULL || !i->s[0]){
		putchar('-');
		//Ok, ora si stampa!
		i = start;
		while(i){
			putchar(i->s[i->i]);
			i = i->next;
		}
		putchar('\n');
		return;
	}
	//E mo so cazzi amari... sugarfree dicks xD
	for(i->i=0;i->s[i->i]!='\0'; i->i++){
		itera(start, i->next);//dai nemmeno tanto..
	}
}
