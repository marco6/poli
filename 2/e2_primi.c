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
 * E visto che il ragazzo mi ha stuzzicato... Adesso facciamo un qualcosa di massiccio.
 * Potrei ancora ottimizzare, memorizzando anche i primi che trovo man mano, ma già così 
 * questo è molto più veloce di quello normale: ecco le statistiche!
 * 
 * Compilando SENZA chiedere al compilatore di ottimizzare con il comando:
 * 		gcc -o e2 file.c -O2
 * Ottengo in media (su dieci esecuzioni)
 * 		- Per il mio codice con i numeri primi: 1,9231 secondi 
 *		(con TUTTI i risultati al di sotto di 2 secondi su un file di ~87 MB 
 *		contenente 3000 stringhe di lunghezza variabile tra 1 e 6000 caratteri 
 *		Che ho generato con il file tst.c)
 * 		- Per il suo codice SENZA numeri primi: 2,3023 secondi
 * 		(con TUTTI i risultati al di sopra dei 2,2 secondi)
 * Ovvero, il mio algoritmo spende circa il 16.4% di tempo in meno rispetto al suo. 
 * Stesso test, ma ottimizzando al massimo con gcc con il comando
 * 		gcc -o e2 file.c -O3 -march=native
 * In media:
 * 		- Per il mio codice: 1,633 secondi
 *		- Per il suo codice: 2,0418 secondi
 * Anche ottimizzando, il suo codice è più lento del mio NON ottimizzato xD (Con tutti i risultati > 2 secondi)
 * E anzi ottimizzando la differenza tra il mio e il suo aumenta: ~20% più veloce xD
 *
 *
 * Adesso però voglio anche far notare che il mio codice è più complesso, più lungo e soprattutto occupa più memoria:
 * 		-lui occupa: N caratteri
 * 		-io occupo: N + sqrt(N) caratteri
 * 
 * E poi cmq x il mio codice mi sono fatto un sbattone assurdo per un esercizio del cazzo che non mi da nemmeno punti xD
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 900//Non è sufficiente?? Fa niente! xD Passiamo anche da linea di comando se se ne vuole di piu'!

char isPrime(const int, int *);
char isNotPrime(int);
char allTheSame(char *, int);
int isPeriodic(char *, int);

int *primes;//Massimo indice dei primi caricati

int main(int argc, char*argv[]) {
	int l, a;//QUesto lo lascio int.. spero non si debba arrivare a stringhe così lunghe! xD
	FILE* f = fopen("test.dat", "r"), *out = fopen("out.txt", "w");//Apro un file da cui prendere le parole per fare dei test seri!
	clock_t t1, t2;//Questo serve per calcolare il tempo
	//Init
	l = (argc > 1) ? atoi(argv[1]) : MAX;
	char *in = (char*)malloc(l+1); //Prendo un vettore riga abbastanza lungo da leggere qualcosa di grosso!
	l = (int)sqrt((float)l);
	primes = (int*)malloc(l +1);//E ora prendo lo spazio per i primi. Ovviamente questo algoritmo sacrifica memoria in favore del tempo di esecuzione
	memset(primes+2, 0, l);
	primes[0] = 2;//i primi due li carico io
	primes[1] = 3;
	
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
		printf("Stringa?");*/
	}
	
	t2 = clock();
	//Ora stampiamo il tempo impiegato
	t2 -= t1;
	printf("Tempo impiegato(sec): %f\n", (float)t2/CLOCKS_PER_SEC);
	
	free(primes);
	free(in);
	return 0;
}

int isPeriodic(char *str, int l){
	int i, j, s;
	if(l == 1)
		return 0;
	else if(isPrime(l, &i)) //Se la lunghezza è un numero primo, non c'è modo che sia periodica tranne se è tutta uguale!
		return allTheSame(str, l);
	else if(allTheSame(str, l))
		return 1;
	else {
		s = (i&1) ? 2 : 1;
		for(; (i+i) <= l; i+= s) {
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
}

char allTheSame(char* a, int l){
	return !memcmp(a, a+1, l-1);
}

int nextPrime(){
	static int p = 3;
	while(isNotPrime(p+=2));
	return p;
}

char isNotPrime(int n){
	int *p;
	for(p = primes+1; (*p) * (*p) <= n; p++)
		if(!(n % (*p)))
			return 1;
	return 0;
}

char isPrime(const int n, int*i){
	//Adesso modifico un po' sta funzione per caricare "live" i primi. Cosi' non si potra' dire che sto usando roba statica o che devo ogni volta ricompilare
	int *p = primes;
	for(; (*p) * (*p) <= n;p++){
		if(!(*p))
			*p = nextPrime();
		if(!(n % (*p))){
			*i = *p;
			return 0;
		}
	}
	return 1;
}