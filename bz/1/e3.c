/*
 * Laboratorio 1, esercizio 3
 * Un file di testo contiene una matrice di interi con il seguente formato:
 *    - la prima riga del file specifica le dimensioni reali della matrice (numero di righe nr e numero di colonne nc). Si assuma che entrambi i valori siano comunque al più pari a 20.
 *    - ciascuna delle nr righe successive contiene gli nc valori corrispondenti a una riga della matrice, separati da uno o più spazi.
 * Si scriva un programma C che:
 *    - legga tale matrice dal file di ingresso.
 *    - generi una nuova matrice, in cui il valore di ciascun elemento è dato dalla media aritmetica delle (al più) 8 caselle adiacenti all’elemento corrispondente della matrice di ingresso.
 *    - scriva la matrice così ottenuta su un file di uscita, con lo stesso formato del file di ingresso.
 * Il nome dei due file sia passato al programma sulla riga di comando.
 *
 * Per compilare:
 * 			gcc -o e3 e3.c -Wall -pedantic
 *
 *
 * Visto che i prof hanno detto che dei controlli ce ne frega cazzi... Non controlliamo più! xD
 */
#include <stdio.h>

#define MAX 20

int main(int argc, char*argv[]){
	FILE* in, *out;
	int m1[MAX+2][MAX+2] = {{0}}; /* Qui usiamo un trucchetto: scriviamo la matrice in una "cornice di zeri" 
									 in modo da non preoccuparci di controllare se siamo al bordo o no */
	int i, j, /* indici per i for */
		sx, sy; /* dimensioni effettive della matrice */
	float m2[MAX][MAX]; /* Matrice risultante */
	const float num[3] = { 8.0, 5.0, 3.0 }; /* Questa serve per sapere come dividere il numero: 8 se è al centro, 5 se è al bordo, 3 se è all'angolo */
	in = fopen(argv[1], "r");
	fscanf(in, "%d %d", &sy, &sx);
	for(j = 1; j <= sy; j++)
		for(i = 1; i <= sx; i++)
			fscanf(in, "%d", &m1[j][i]);/* becchiamoci la matrice ricordando magari che si parte da (1,1) */
	fclose(in);

	out = fopen(argv[2], "w");
	
	for(j = 0; j < sy; j++){
		for(i = 0; i < sx; i++){
			m2[j][i] = (m1[j][i+1] + /* Sommiamo tutta la cornice, uno alla volta */
						m1[j][i+2] +
						m1[j+1][i+2] +
						m1[j+2][i+2] +
						m1[j+2][i+1] +
						m1[j+2][i] +
						m1[j+1][i] +
						m1[j][i]) / num[ !(i%(sx-1)) + !(j%(sy-1)) ];/* E qui arriva la parte brutta xD E' 
													* un po' contorta la cosa, ma funziona ed è veloce..  
													* Se si è ai lati, allora l'indice (sia x che y) equivale
													* o a 0 o a (dimensione-1). Con il comanfo "%", entrambi 
													* questi valori restituiscono 0. Ma 0 è anche una variabile
													* booleana che significa "false" e che se io nego (!) mi 
													* restituisce 1. Quindi sia il primo termine da 1 quando è
													* ai lati che il secondo. Essere agli angoli quindi significa
													* essere a due lati. Se do un indice a tutto questo, ottengo
													* 	0: Al centro
													*	1: A uno dei due lati
													* 	1+1: Ad un angolo 
													*
													* Mi basta quindi usare questi indici in un vettore fatto bene
													* per ottenere il numero per cui devo dividere ;) 
													* PS: In barba a BBBBBonato che si spara 20 if xD */
			fprintf(out, "%f ", m2[j][i]);
		}/* for */
		fprintf(out, "\n");
	}/* for */
	return 0;
}/* main */