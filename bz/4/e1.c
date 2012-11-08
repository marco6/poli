/*
 *	Esercitazione 4 es 1
 *
 *	Si scriva un programma in grado di contare le occorrenze di ogni parola, 
 *	appartenente a un insie-me specificato, all’interno di un generico testo.
 *	Più in dettaglio, l’elenco delle parole da ricercare è memorizzato in un 
 *	file di testo, in ragione di una parola per riga del file. La lunghezza 
 *	delle singole parole è limitata a 20 caratteri, e inoltre il numero totale 
 *	di tali parole è indicato sulla prima riga del file stesso.
 *	Le parole così specificate devono essere ricercate in un testo memorizzato 
 *	in un secondo file. Il numero di righe di questo file è indefinito, ma si 
 *	può assumere che la lunghezza di ogni riga sia al più pari a 100 caratteri.
 *	Come output, il programma deve riportare su video l’elenco delle parole 
 *	contenute nel primo file, ciascuna seguita dal numero di occorrenze con cui 
 *	compare nel testo contenuto nel secondo file. Si noti che i due file devono 
 *	essere letti una volta sola.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DICTIONARY "e1.diz"
#define DATI "e1.dat"
#define WLEN 40

typedef struct _wc { //Ok, fa schifo sto nome, ma non mi veniva in mente altro, quindi... se avete da ridire, andate a cagare xD (nel _wc)
	char word[WLEN+1];
	unsigned int count;//Solo positivi
} wordCount;

wordCount *search(wordCount*,wordCount*, char*);

int main(){
	FILE *in;
	int dicS;//Dimensione del dizionario
	wordCount *list, *i;//Questo invece è poi da usare come lista, poi se ho voglia lo faccio + veloce.. ora no! xD
	char buff[WLEN+1];
	in = fopen(DICTIONARY, "r");
	
	fscanf(in, "%d", &dicS);//Becchiamoci la dimensione
	
	//E ora allochiamo memoria a sufficienza
	i = list = malloc(sizeof(wordCount)*dicS);
	
	//Ok, carichiamo tutto
	while(i - list < dicS){
		fscanf(in, "%s", i->word);
		i->count = 0;
		i++;
	}//while
	
	fclose(in);
	printf("ok %d", dicS);
	in = fopen(DATI, "r");
	i = list+dicS;
	//Qui sarebbe meglio usare la ricerca binaria, ma servirebbe prima ordinare la lista...
	while(fscanf(in, "%s", buff) != EOF){
		(search(list, i, buff))->count++;//Cerchiamo e incrementiamo
	}//while
	
	for(; list != i; list++)
		printf("%.*s - %d occorrenza/e\n", WLEN, list->word, list->count);//Stampiamo!
	return 0;
}//main

wordCount *search(wordCount* hstart, wordCount *hend, char* needle){
	static wordCount _null;
	while(hstart <= hend && strcmp(hstart->word, needle)) hstart++;
	return ((hstart > hend) ? &_null : hstart);
}