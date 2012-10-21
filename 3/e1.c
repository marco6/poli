/*
 * Esercitazione 3, esercizio 1
 *
 * Si realizzi un programma che:
 * 	- legga due numeri interi positivi M ed N.
 * 	- generi casualmente N numeri interi, memorizzandoli in un vettore allocato dinamicamente.
 * 	- ordini tale vettore in maniera crescente, utilizzando uno dei seguenti algoritmi:
 * 		- insertion sort
 * 		- selection sort
 * 		- bubble sort
 * 	- ripeta la generazione casuale e l’ordinamento per M volte.
 * Si confrontino le prestazioni dei tre algoritmi per i valori di M=10, 100, 1000 e di 
 * N=1000, 5000, 10000, misurandone i tempi di esecuzione.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct __info { 
	int M, N;
	char timing, algorithm;
} Info;

/* Io sono convinto che il programma diventi meno leggibile se spezzo tutto 
 * in funzioni... Comunque visto che vogliono così.. amen! */
Info getArgs(int argc, char*argv[]);
void bubbleSort(int, int*);/* Le bolle più grandi vengono a galla */
void selectionSort(int, int*);
void insertionSort(int, int*);
void swap(int*, int*);

int main(int argc, char*argv[]){
	Info spec;
	clock_t t;/* Questo per calcolare il tempo */
	int *vect, i; /* Qui il vettore di interi */
	void (*sortFunc[])(int, int*) = { 
			bubbleSort, selectionSort, insertionSort 
		}; /* E.. sì questa è una bastardata xD
			* Sono puntatori a funzioni(ebbene: esistono!!) xD*/
	if(argc < 3)
		return -1;
	spec = getArgs(argc, argv); /* Becchiamoci cosa vogliono da noi! */
	
	if(spec.timing)/* Se proprio dobbiamo, guardiamo l'orologgio */
		t = clock();
	srand((int)time(NULL));
	/* Inizializziamo il vettore! */
	vect = malloc(spec.N * sizeof(int));
	for(; spec.M > 0; spec.M--){ /* Ripetiamo millanta(M) volte */
		for(i=0; i < spec.N; i++)
			vect[i] = rand();/* inizializziamo */
		/* e ora ordiniamo! */
		sortFunc[(int)spec.algorithm](spec.N, vect);
	}/* for */

	if(spec.timing){
		t = clock() - t;
		printf("Tempo impiegato: %f sec\n", (float)(t)/CLOCKS_PER_SEC);/* Comunque: col cazzo che faccio davvero i test di performance! xD */
	}/* if */

	return 0;
}/* main */

Info getArgs(int argc, char*argv[]){/* Restituisce le informazioni passate da linea di comando */
	Info ret;
	memset(&ret, 0, sizeof(Info));/* Azzeriamo tutti i valori! */
	for(argc--; argc > 2; argc--){
		/* Se è non è una flag, ignoriamola */
		if(argv[argc][0] == '-' && argv[argc][2] == '\0')
			switch(argv[argc][1]){
				case 't':/* timing */
				case 'T':
					ret.timing = 1;
					break;
				case 'b':/* bubble, che poi sarebbe anche il default */
				case 'B':
					ret.algorithm = 0;
					break;
				case 's':/* Selection */
				case 'S':
					ret.algorithm = 1;
					break;
				case 'i':/* Insertion */
				case 'I':
					ret.algorithm = 2;
					break;
			}
	}
	ret.M = atoi(argv[1]);
	ret.N = atoi(argv[2]);
	return ret;
}/* getArgs */

void bubbleSort(int i, int* v){ /* Che poi su wikipedia ti spiega magari anche il perchè si fa così.. */
	int j;/* Bah.. il senso di darci già il codice pronto e farcelo tradurre... MISTERO! xD */
	for (i--; i > 0; i--){
		for( j = 0; j < i; j++)
			if(v[j] > v[j+1]){
				swap(v+j, v+1+j);
			}
	}
}
void selectionSort(int N, int* v){/* Non commento, tanto non sappiamo cosa stiamo facendo.. D: */
	int key, j, i;
	for(i=1; i < N; i++){
		key = v[i];
		for(j = i-1; j >-1 && v[j]>key; j--){
			v[j+1] = v[j];
		}
		v[j+1] = key; 
	}
}
void insertionSort(int N, int*v) {
	int i, small, j;
	for(i = 0; i < N-1; i++){
		small = i;
		for(j=i+1; j<N; j++){
			if(v[j]<v[small])
				small = j;
		}
		swap(v+small, v+i);
	}
}

void swap(int* a, int*b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}