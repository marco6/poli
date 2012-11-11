/*
 *	Un file di testo contiene un numero indefinito (ma al più pari a 100) di stringhe, ciascuna di
 *	lunghezza massima pari a 30 caratteri, in ragione di una stringa per ogni riga del file.
 *	Si scriva un programma C che:
 *		• acquisisca le stringhe contenute nel file di ingresso, memorizzandole in una struttura dati
 *			opportuna (una matrice di caratteri, usando una riga della matrice per salvare una stringa).
 *		• ordini tali stringhe mediante uno degli algoritmi di ordinamento noti.
 *		• scriva le stringhe così ordinate su un secondo file di testo.
 *	Si realizzi il programma in almeno due versioni:
 *		1. eseguendo l’ordinamento direttamente sulla matrice di caratteri (ovvero, scambiando mate-
 *			rialmente le righe della matrice durante tale fase).
 *		2. utilizzando un vettore ausiliario di puntatori, opportunamente inizializzati, su cui eseguire
 *			l’algoritmo di ordinamento.
 * 
 *	Si noti che nel primo caso lo “scambio” tra due stringhe ai fini dell’ordinamento deve essere
 *	eseguito tramite delle opportune chiamate alla funzione strcpy(), mentre nel secondo occorre
 *	solo scambiare i relativi puntatori.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Boh commentare sta roba è un insulto all'intelligienza dei lettori xD
#define FILEIN "e2.dat"
#define FILEOUT "outE2.txt"
#define MAXROWS 1000
#define MAXCHARS 30

//Se questo è definito, si utilizzeranno i puntatori
//#define WITH_POINTERS

#define TOSTDOUT

//Con questo trucco, posso evitare di scrivere due funzioni di stampa/input/ordinamento
#ifdef WITH_POINTERS
typedef char *_words;
#define _set(a,b) a=b
#else
typedef char _words[MAXCHARS+1];
#define _set(a,b) strcpy(a, b)
#endif

int read(char*, _words[MAXROWS]);
void print(FILE*, _words[MAXROWS],int);

void sort(_words[MAXROWS], int);


int main(){
	char buff[MAXROWS][MAXCHARS+1];
	int size;
	FILE *f;
	
#ifdef WITH_POINTERS
	char *words[MAXROWS];
	//inizializziamo ora la lista
	for(size = 0; size < MAXROWS; size++)
		words[size] = buff[size]; 
#else
	#define words buff
#endif

#ifdef TOSTDOUT
	f = stdout;
#else
	f = fopen(FILEOUT, "w");
#endif

	size = read(FILEIN, words);
	sort(words, size);
	print(f, words,size);
	//No, adesso dico.. Sarà pure leggibile sto programma, ma fino a qui
	//non si è capito una sega su come ho implementato tutto, quindi per
	//chi legge è tempo perso xD bah... cmq se vogliono le funzioni.. ok!
	return 0;
}//main()

int read(char* file, _words buff[MAXROWS]){
	int i = 0;
	FILE*f = fopen(file, "r");
	while(fgets(buff[i++], MAXCHARS, f)!=NULL);
	fclose(f);
	return i;
}//read

void print(FILE*out, _words buff[MAXROWS], int size){
	//xD cazzata
	int i = 0;
	for(; i < size; i++)
		fprintf(out, "%s", buff[i]);
}//print

//Adesso qui implementiamo l'insertion sort
void sort(_words V[MAXROWS], int size){
	
	int i,j;
	_words key;
	for (i=1; i < size; i++){//come tuc insegna, le parentesi xD
		_set(key, V[i]);
		j=i;
		/* inserisce V[i] nella sequenza ordinata V[0...i-1] */
		while (--j>=0 && strcmp(V[j],key)>0)
			_set(V[j+1], V[j]);
		_set(V[j+1], key);
	}//for
}//sort
