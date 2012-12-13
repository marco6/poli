//Provo ad implementare il metodo tuc-bz-bonny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Per comodità includo anche il nome della matrice
#define at(x, y) mat[(y)*n + (x)]

//Questa la faccio statica
const int x3[9] = { 2,7,6, 1, 8, 3, 4, 9, 5 }; //Serve da base per i quadrati dispari

//versione per i dispari
void dmagic(int, int*);
//versione per i pari
void pmagic(int, int*);

//Comodità che mi farebbe rompere i coglioni da sam... xD
void (*funcs[2]) (int, int*) = { pmagic, dmagic };

int main(int argc, char** argv){
	int n, *mat, i;
	FILE*out;
	//Mettiamo qualche caratteristica...
	if(argc < 2){
		printf("Utilizzo:\n\t <nomeProgramma> <n> [<outfile>]");
		return 0;
	}//if
	n = atoi(argv[1]);
	if(n == 2 || n < 1){
		printf("Non esistono quadrati della dimensione specificata");
		return 0;
	}//if
	//Ora, per n molto grossi, stamparlo sulla stdout sarebbe orrido
	//Quindi se specificato lo piazzo nel file
	out = argc > 2 ? fopen(argv[2], "w") : stdout;
	//Ok, ora allochiamo
	mat = malloc(sizeof(int) * n * n);
	funcs[n & 1](n, mat);
	//Ora devo stampare!
	for(i = 0; i < n*n; i++)
		fprintf(out,"%d-", mat[i]);
	
	//libero mat
	free(mat);
	//amen!
	return 0;
}//main

void dmagic(int n, int *mat){
	int x,y, *ptr, nn, diff;
	if(n == 1){
		//La matrice 1x1
		*mat = 1;
		return;
	}
	if(n == 3){
		//Devo copiare il tutto!
		memcpy(mat, x3, sizeof(x3));
		return;
	}
	
	//Inizializzo
	nn = n*n;
	
	//ok, abbiamo gestito il caso terminale...
	//ora diamoci da fare!
	
	//per prima cosa serve la matrice precedente
	dmagic(n-2, ptr = ( mat+((n-1)<<2) ) );

	//ok ora dobbiamo aggiungere a tutto il numero 2n-2
	for(x = 0, y=n*2 - 2; x < (n-2)*(n-2); x++)
		ptr[x] += y;

	//Metto il più piccolo alla prima casella
	mat[0] = 1;
	mat[n*2 - 2] = nn;
	//Calcolo la differenza
	diff = ptr[0] - 1;
	mat[n-1] = ptr[n - 3] + diff;
	mat[3*n-3] = ptr[3*n - 9] - diff;//ok! Diagonali apposto alla faccia
	//di bonato! E se poi non funge lo meno xD
	
}//dmagic

void pmagic(int n, int *mat){ }
