/*
 * Si scriva un programma in grado di:
 *   - leggere da tastiera un numero indefinito di stringhe, 
 *		ciascuna composta da soli caratteri alfanumerici e di 
 *		lunghezza massima pari a 30. La lettura termini quando 
 *		viene introdotta la parola "stop".
 * 	 - indicare, per ciascuna stringa acquisita, se essa è "periodica"
 *		oppure no, ovvero costituita da un’unica sotto-stringa che si 
 *		ripete. Ad esempio, sono periodiche (con periodo indicato tra 
 *		parentesi) le seguenti sotto-stringhe: "zzzzz" (1), "k21k21" (3), 
 *		"vivaviva" (4), etc. Si noti che una stringa composta da un solo 
 *		carattere, come anche una stringa in cui l’ultimo periodo non 
 *		risulti concluso, non deve essere considerata periodica.
 * 
 * 
 * Per compilare da linea di comando, si puo' usare:
 * 			gcc -o e2 e2.c -Wall -pedantic
 * -Wall e -pedantic servono a rompere le palle per scrivere c-iso90
 * Ora come ora dara' un warning per via dei commenti... Lasciatelo parlare, poi se ho voglia aggiusto u.u
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 900//Non è sufficiente?? Fa niente! xD Passiamo anche da linea di comando se se ne vuole di piu'!

int isPeriodic(char *, int);

int main(int argc, char*argv[]) {
	int l, a;//QUesto lo lascio int.. spero non si debba arrivare a stringhe così lunghe! xD
	FILE* f = fopen("test.dat", "r"), *out = fopen("outn.txt", "w");//Apro un file da cui prendere le parole per fare dei test seri!
	clock_t t1, t2;//Questo serve per calcolare il tempo
	//Init
	l = (argc > 1) ? atoi(argv[1]) : MAX;
	char *in = (char*)malloc(l+1); //Prendo un vettore riga abbastanza lungo da leggere qualcosa di grosso!
	//Guardiamo solo l'algoritmo!
	t1 = clock();
	
	//while(scanf(" %n%s%n", &a, in, &l) && strcmp("stop", in)){/* Finche' riceviamo input corretto... */
	while(fscanf(f, " %n%s%n", &a, in, &l)){
		l-=a;
		fprintf(out, "%d\n", isPeriodic(in, l));
		/*
		if((a = isPeriodic(in, l)))
			fprintf("La stringa e' periodica(%d)\n", a);
		else
			printf("La stringa non e' periodica\n");
		printf("Stringa?");//*///Questo non lo uso più perchè devo contollare dei file..
	}
	
	t2 = clock();
	//Ora stampiamo il tempo impiegato
	t2 -= t1;
	
	printf("Tempo impiegato(sec): %f\n", (float)t2/CLOCKS_PER_SEC);
	
	free(in);
	return 0;
}

int isPeriodic(char *str, int l){
	int i, j;
	if(l == 1)
		return 0;
	for(i = 1; (i+i) <= l; i++){
		if(!(l%i)){
			for(j = i; j < l; j+=i)
				if(memcmp(str, str+j, i))
					break;
			if(j==l)
				return i;
		}
	}
	return 0;
}
