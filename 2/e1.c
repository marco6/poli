/*
 * Laboratorio 2, esercizio 1
 *
 * Un’applicazione per la compressione di testi funziona in questo modo:
 *    - Dato un file di testo, l’applicazione individua anzitutto un’insieme di parole del testo (tipicamente lunghe e ripetute) 
 *		che verranno poi elaborate come segue:
 *    		- A ciascuna delle parole dell’insieme così costruito viene associato un intero univoco, con valore sempre compreso nell’intervallo [0 – 99]. 
 *			  L’applicazione riporta in un secondo file di testo ogni associazione intero/parola (una per riga).
 *			- Nel file di testo originale, infine, ogni parola che appartiene all’insieme viene sostituita dall’intero ad essa associato 
 * 			 (preceduto dal carattere ‘$’).
 * Si desidera un programma C che, dati due file (il file di testo trasformato e il corrispondente file delle associazioni), 
 * ricostruisca il file di testo originale. Si può assumere che ogni riga del file “compresso” sia lunga al più 80 caratteri
 * 
 * 
 * Per compilare da linea di comando, si puo' usare:
 * 			gcc -o e1 e1.c -Wall -pedantic
 * -Wall e -pedantic servono a rompere le palle per scrivere c-iso90
 */
 
#include <stdio.h>/* Per le funzioni di input/output e per i file */
#include <string.h>/* Per le funzioni per la memoria strcpy */
 
#define OUT "out.txt"
 
#define ERR(str, n) { fprintf(stderr, str); return n; }
 
 int main(int argc, char *argv[]) { /* il proffo ha detto di non fare controlli, quindi non li faccio u.u Meno fatica x me xD */
	char keys[100][61] = { { 0 } }, /* Le chiavi del dizionario. Qui ci sarebbe da usare l'allocazione dinamica, 
					ma lasciamo perdere... diciamo che le parole non saranno più lunghe di 60 caratteri */
		line[88],/* la riga da prendere dal file */
		*ptr, /* Un puntatore per far avanzare la stringa */
		*i; /* "Un puntatore per domarli. Un puntatore per trovarli. Un puntatore per ghermirli e nel buio incatenarli..." xD
					(scherzo cmq, lo uso nella funzione di sostituzione per stampare la robba xD) */
	FILE *in, *out;/* i puntatori ai file di input/output */
	int n = 0; /* Questo serve a ricevere informazioni dalla sscanf */
	if(argc < 3)
		ERR("Usage: e1.exe <dictionary> <fileToDecode> [<output>=\"out.txt\"]", 1)
	in = fopen(argv[1], "r");
	while(!feof(in)){
		fscanf(in, "%d", &n);
		fscanf(in, "%s", keys[n]);/* prendiamoci l'input! */
	}
	fclose(in);
	in = fopen(argv[2], "r");
	out = fopen(argc > 3 ? argv[3] : OUT, "w");/* Apriamo i files */
	
	/* E ora passiamo a cose serie xD */
	while(!feof(in)){
		fgets(line, 88, in);/* Ci prendiamo la linea */
		ptr = i = &line[0]; /* Poi azzeriamo il puntatore per puntare all'inizio riga */
		while((ptr = strchr(ptr, '$'))) { /* Finche' non raggiungiamo la fine... */
			/* Ora stampiamo il pezzo che ci interessa */
			fwrite ( i, ptr - i, 1, out); /* Non scomodiamo la fprintf... Per sapere come funge questa -> <http://bit.ly/oCjD2e> */
			/* Ora dobbiamo cercare quello che serve */
			if(sscanf(ptr, "$%d", &n)){/* Se subito dopo c'è un numero... */
				i = strpbrk(++ptr, " \r\n"); /* Avanziamo di quanto ci serve. Per questa funzia invece -> <http://bit.ly/d1td3e> */
				/* Ora stampiamo la stringa che ci serve dal dizionario */
				fputs(keys[n], out);/* ricordiamoci che fputs = fì, putzi! xD */
			}/* if */
			else
				i = ptr++; /* abbiamo stampato fin qui. Per continuare con le citazioni: "Fin qui arriverai, ma non oltre" xD Oggi sono ispirato [Bibbia, Giobbe 38] :P */
			/* amen! */
		}/* while */
		/* stampiamo l'ultimo pezzo */
		fputs(i, out);
	}/* while */
	return 0;
 }/* main */