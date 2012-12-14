//Provo ad implementare il metodo tuc-bz-bonny
#include <stdio.h>
#include <stdlib.h>

//Per comodità includo anche il nome della matrice
#define at(x, y) mat[(y)*n + (x)]

//Questa la faccio statica
const int x3[3][3] = { 
			{2,7,6},
			{9,5,1},
			{4,3,8}
		};//Serve da base per i quadrati dispari

//versione per i dispari
void dmagic(int, int*);
//versione per i pari
void pmagic(int, int*);

//Comodità che mi farebbe rompere i coglioni da sam... xD
void (*funcs[2]) (int, int*) = { pmagic, dmagic };

int main(int argc, char** argv){
	int n, *mat, i, j;
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
	//==================da rivedere!=======================
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			fprintf(out, "%d\t", mat at(j, i));
		fprintf(out, "\n");
	}//for
	//libero mat
	free(mat);
	//amen!
	return 0;
}//main

void dmagic(int n, int *mat){
	int x,y, *ptr;
	if(n == 1){
		//La matrice 1x1
		*mat = 1;
	}
	if(n == 3)
		//Devo copiare il tutto!
		memcpy(mat, x3, sizeof(x3));
	//ok, abbiamo gestito il caso terminale...
	//ora diamoci da fare!
	
	//per prima cosa serve la matrice precedente
	dmagic(n-2, mat + ((n-1) << 2));

	//ok ora dobbiamo aggiungere a tutto il
}//dmagic
