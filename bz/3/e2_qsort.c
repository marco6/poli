/*
 *	La differenza tra questo e quello di prima è la voglia xD
 *	Usando furbamente il define questo programma diventa veramente facile xD
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Boh commentare sta roba è un insulto all'intelligienza dei lettori xD
#define FILEIN "e2.dat"
#define FILEOUT "outE2.txt"
#define MAXROWS 100
#define MAXCHARS 30

//Se questo è definito, si utilizzeranno i puntatori
#define WITH_POINTERS

#define TOSTDOUT

//Definisco un tipo che varia a seconda se usiamo o no i puntatori
#ifdef WITH_POINTERS
typedef char *_words[MAXROWS];

//Piccolo trucchetto xD
int _strcmp(const char** a, const char**b) { return strcmp(*a, *b); }
#define strcmp _strcmp 

#else
typedef char _words[MAXROWS][MAXCHARS+1];
#endif
//Usando in modo strano il define, NON ho scritto nessuna funzione di ordinamento...

int read(char*, _words);
void print(FILE*, _words,int);

//Se vogliamo usare qsort, dobbiamo fare un redirect ad essa
//E lo facciamo con define ;)
//QUello che in pratica faccio è chiamare qsort, dirgli che i dati da 
//confrontare sono MAXCHARS+1 (il \0 maledetto) e che la funzione 
//di confronto è strcmp.. il resto fa lui!
#define sort(arr,size) qsort(arr, size, sizeof(arr[0]), (int(*)(const void*,const void*))strcmp) //lool cmq questa è brutta ahah
//E fin qui, io non ho ancora scritto na linea di codice xD

int main(){
	int size;
	FILE *f;
	char buff[MAXROWS][MAXCHARS+1];
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

int read(char* file, _words buff){
	int i = 0;
	FILE*f = fopen(file, "r");
	while(fgets(buff[i++], MAXCHARS, f)!=NULL);
	fclose(f);
	return i;
}//read

void print(FILE*out, _words buff, int size){
	//xD cazzata
	int i = 0;
	for(; i < size; i++)
		fprintf(out, "%s", buff[i]);
}//print

