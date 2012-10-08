/*
 * Laboratorio 1, esercizio 1
 * Un file di testo contiene una matrice quadrata di numeri reali con il seguente formato:
 * - la prima riga del file specifica la dimensione reale della matrice (si assuma che sia 
 *   comunque al più pari a 10).
 * - ciascuna delle righe successive contiene i valori corrispondenti a una riga della matrice,
 *   separati da uno o più spazi.
 * Si realizzi un programma C che:
 * - legga tale matrice dal file di ingresso, il cui nome è specificato dall’utente.
 * - generi una nuova matrice, delle stesse dimensioni di quella appena acquisita, in cui il
 *   valore di ciascun elemento è:
 *   - 0 se il corrispondente elemento della matrice di ingresso è negativo o nullo.
 *   - l’ordine di grandezza del corrispondente elemento della matrice di ingresso
 *     (definito come la più piccola potenza di 10 maggiore o uguale al valore in
 *     questione) in caso contrario.
 * - visualizzi sul video un opportuno messaggio a seconda che la matrice così generata risulti
 *   simmetrica oppure no.
 * Si risolva il problema proposto implementando un numero opportuno di funzioni (acquisizione
 * della matrice, sua elaborazione, e verifica per la generazione del messaggio da visualizzare).
 * 
 * 
 * Per compilare da linea di comando, si puo' usare:
 * 			gcc -o e1 e1.c -lm -Wall -pedantic
 * -Wall e -pedantic servono a rompere le palle per scrivere c-iso90
 */

#include <stdio.h> /* Per la lettura dei file e l'output */
#include <math.h> /* Per il logaritmo e l'arrotondamento */
#include <stdlib.h> /* Per la funzione exit */

/* Definisco il massimo numero di righe/colonne */
#define MAX 10
/* E magari anche il file da cui devo leggere */
#define INFILE "e1.dat"

/* Definisco una funzione del preprocessore per non riscrivere ogni santa volta la stessa cosa */
#define ERR(str, n) { fprintf(stderr, str); exit(n); }

/* Dichiaro le funzioni che usero' all'interno del main */

/* Prende la matrice */
void getMatrix(float mat[][MAX], unsigned int s, FILE* f);

/* Restituisce la matrice di output */
void computeMatrix(float mat1[][MAX], float mat2[][MAX], unsigned int s);

/* Stampa a video la matrice */
void printMatrix(float mat[][MAX], unsigned int s, FILE* f);

/* Controlla se e' simmetrica */
int isSymmetric(float mat[][MAX], unsigned int s);

/* Il buffer per la linea */
char line[128];/* Questa e' una variabile globale, ovvero la possono usare tutte le funzioni */

/*
 * mannaggia a loro e alle loro cazzo di funzioni! Se sparavi tutto nel 
 * main potevi evitarti un botto di roba.. Solito approccio professoresco xD
 * 
 * Amen, cazzi loro che poi devono correggere!
 * 
 * PS: usare la memoria dinamica avrebbe semplificato, ma non fa niente... 
 */

int main(){
	/* Dichiaro le variabili */
	
	/* Il puntatore al file da leggere */
	FILE* f;
	
	/* Le matrici..  Uso la massima dimensione per essere sicuro di aver spazio sufficiente! */
	float mat1[MAX][MAX],
		mat2[MAX][MAX];
	
	/* La dimensione effettiva della matrice */
	unsigned int s;
	
	/* Provo ad aprire il file... */
	if(!(f = fopen(INFILE, "r"))) 
		/* Se non riesco stamo un messaggio di errore */
		ERR("Errore nell'apertura del file.\n", 1)/* Qui non serve il punto e virgola perche' e'  
												   * un blocco.. ma se lo si mette non cambia niente */
	
	/* Ora leggo la prima linea per avere la dimensione... */
	s = atoi(fgets(line, 127, f));
	
	/* Controllo adesso che s non sia troppo grande */
	if(s > MAX) ERR ("La dimensione specificata nel file e' troppo grande.", 2)

	/* Ora leggiamo la matrice */
	getMatrix(mat1, s, f);
	
	/* Ora calcoliamo la nuova matrice */
	computeMatrix(mat1, mat2, s);
	
	/* Stampiamo il risultato */
	printMatrix(mat2, s, stdout);
	
	/* Ora controllo se e' simmetrica e stampo un messaggio  */
	printf("La matrice prodotta%s e' simmetrica.\n", (isSymmetric(mat2, s) ? "" : " non"));
	
	/* Bom */
	return 0;
}/* main */

/* Passiamo a scrivere le funzioni */
/* Questa e' la parte difficile del programma.. */
void getMatrix(float mat[][MAX], unsigned int s, FILE* f){
	int i, j = -1, 
		p;/* Questa serve per evitare di leggere le stesse cose piu' volte  */
	char *l;
	/* Finche' c'e' ancora roba da leggere... */
	while(!feof(f) && ++j < s){
		p = 0;
		l = &line[0]; /* Questo serve per fare bene i calcoli...  */
		/* Becchiamoci la linea */
		if(!fgets(line, 128, f)) /* Controllo che abbia letto qualcosa... */
			continue; /* Se non ha letto niente... Provaci ancora, sam! xD */
		for(i = 0; i < s; i++){
			if(!sscanf(l, " %f%n", &mat[j][i], &p))
				ERR ("Errore formattazione file." , 4)
			/* Non consideriamo piu' il pezzo letto */
			l += p;
		}
	}/* while */
}/* getMatrix */

/* Ora passiamo invece alle cose facili */
void computeMatrix(float mat1[][MAX], float mat2[][MAX], unsigned int s){
	int i, j;
	for(i = 0; i < s; i++)
		for(j = 0; j < s; j++)
			if(mat1[i][j] > 0)
				/* Ceil serve ad arrotondare... */
				mat2[i][j] = pow(10, ceil(
											log10(mat1[i][j])
										)
									);
			else
				mat2[i][j] = 0.0f;
}

/* Queste due non le commento perche' sono troppo facili xD */

void printMatrix(float mat[][MAX], unsigned int s, FILE* f){
	int i, j;
	for(i = 0; i < s; i++){
		for(j=0; j < s; j++)
			fprintf(f, "%f ", mat[i][j]);
		fprintf(f, "\n");
	}/* for */
	fprintf(f, "\n");
}/* printMatrix */

/* Controlla se e' simmetrica */
int isSymmetric(float mat[][MAX], unsigned int s){
	int i, j;
	for(i = 0; i < s; i++)
		for(j = i+1; j < s; j++)
			if(mat[i][j] != mat[j][i])
				return 0;
	return 1;
}
