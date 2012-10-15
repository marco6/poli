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
 */

#include <stdio.h>
#include <string.h>

const char isPrime(const int);
const char allTheSame(char *, int);
const int isPeriodic(char *, int);
const int isPeriodic(char *, int, int);

const int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 }; /* Questi bastano per stringhe lunghe piu' di 400 :P noi abbiamo 30 e avremmo potuto fermarci a 7 xD */

int main() {
	char in[31];
	int l;
	
	return 0;
	while(scanf("%s%n", in, &l) && !strcmp("stop", in)){/* Finche' riceviamo input corretto... */
		if(isPrime(l)){
			//TODO
		}//if
		else//TODO: stampare anche il numero
			printf("La stringa%s e' periodica.\n", ( isPeriodic(in, l) ? "" : " non" ));
		else if(l == 1)
			printf("La stringa non e' periodica.\n");
	}
}

const int isPeriodic(char *str, int l){
	int *p;
	if(l == 1)
		return 0;
	else if(isPrime(l)) //Se la lunghezza è un numero primo, non c'è modo che sia periodica tranne se è tutta uguale!
		return allTheSame(str, l);
	else
		for(p = &primes[0]; (*p)*(*p) < l; p++)
			if(isPeriodic(str, 
}

const int isPeriodic(char *str, int l, int period) {
	int i, j;//TODO
	if(l % period)
		return 0;
	for(i = 0; i < period; i++)
		for(j = i; j < l; j+=period)
			if(str[j] != str[i])
				break;
	return 1;
}

const char allTheSame(char* a, int l){
	char p = *a++;
	for(; *a; a++)
		if(*a != p)
			return 0;
	return 1;
}

const char isPrime(const int n){
	const int *p;
	for(p = &primes[0]; (*p)*(*p) < n; p++)
		if(!(n % (*p)))
			return 0;
	return 1;
}