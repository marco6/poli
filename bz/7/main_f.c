//Puta de pariho che sbattone!
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "item.h"
#include "fifo.h"

int main(int argc, char*argv[]){
	FILE *io;//Input\output
	char filename[256];
	Item i;//La struttura 'item' da accodare
	int _int;//intero di input
	Stringa str;//Stringa di input
	Both bot;//Struttura di input
	FIFO l;//Lista
	char com = '\0',/* Può essere: 
					  * 	'n': nuova lista
					  * 	'i': inserisci elemento
					  * 	'x': estrai elemento
					  * 	'o': mostra a video gli elementi
					  * 	's': salva su file
					  * 	'l': carica da file
					  * 	'e': esce
					  */
		 type = 'm', in; //Tipo di lista
	//Metto tutto a 0
	memset(&l, 0, sizeof(FIFO));
	
	while(com != 'e'){
		if(com != '\n' && com != '\r')
			printf("\ncmd>");
		scanf("%c%*c", &com);
		switch(com) {
			case 'n':
				//Chiediamo conferma
				if(l.size){
					printf("Sovrascrivere la lista esistente?(s/n) ");
					scanf("%c%*c", &com);
					if(tolower(com) == 'n')
						break;
					putchar('\n');
				}//if
				printf("Cosa conterra' la lista?(m=mixed, i=int, c=string, s=int+string) ");
				scanf("%c%*c", &type);
				//Se non è valido, consideriamo che sia una lista mista
				if(type != 'm' && type != 'i' && type != 'c' && type != 's'){
					printf("Selezione non riconosciuta, e' stata selezionata una lista mista di default\n");
					type = 'm';
				}//if
				//E finalmente inizializziamo la lista
				l = fifo_new();
				break;
			case 'i':
				//Se la lista e' eterogenea, chiediamo di che tipo è il dato attuale
				if(type == 'm'){
					printf("Cosa vuoi inserire?(i=int, c=string, s=int+string) ");
					scanf("%c%*c", &in);//E salviamolo quì
					putchar('\n');
				}//if
				else
					in = type;//Se la lista invece è omogenea, l'input equivale al tipo
				//Ora l'input vero e proprio
				switch(in){
					case 'i':
						//Chiediamo gentilmente..
						printf("Inserisci un numero>");
						while(scanf("%d%*c", &_int) == 0)
							printf("Non valido. Riprova>");
						i = createItem(intero);
						itemFill(&i, &_int);
						break;
					case 'c':
						printf("Inserisci una stringa>");
						//Puliamo la stringa
						memset(str, 0, sizeof(Stringa));
						gets(str);
						i = createItem(stringa);
						itemFill(&i, str);
						break;
					default:
						//Qui chiediamo tutto!
						printf("Inserisci un numero>");
						//Puliamo la struttura
						memset(&bot, 0, sizeof(Both));
						
						while(scanf("%d%*c", &bot.i) == 0)
							printf("Non valido. Riprova>");
						printf("Ora inserisci la stringa>");
						gets(bot.s);
						i = createItem(both);
						itemFill(&i, &bot);
						break;
				}
				printf("Elementi totali nella lista: %d\n", fifo_enqueue(&l, i));
				break;
			case 'x':
				if(l.size == 0){
					printf("La lista e' vuota!");
					break;
				}//if
				//Estraiamo l'elemento
				i = fifo_dequeue(&l);
				//Mostriamolo
				printItem(&i, stdout, 0);
				//Ed eliminiamolo!
				deleteItem(&i);
				break;
			case 'o':
				//QUesto è facile:
				if(l.size)
					fifo_enum(&l, stdout);
				else
					printf("La lista e' vuota\n");
				break;
			case 's':
				//Dobbiamo salvare su un file
				printf("Inserisci il nome del file nel quale salvare>");
				gets(filename);
				//Apriamo il file
				io = fopen(filename, "wb");
				fifo_save(&l, io);//Salviamo
				//Chiudiamo il file
				fclose(io);
				break;
			case 'l':
				//Controlliamo che sia sicuro di voler chiudere la lista in uso
				if(l.size){
					printf("C'e' una lista attualmente in uso.\n"
						"Aprirne una nuova chiudera' quella attuale e tutti\n"
						"I dati non salvati andranno persi. Continuare?(s,n)");
					scanf("%c%*c", &com);
					if(tolower(com) == 'n')
						break;
				}//if
				//Dobbiamo salvare su un file
				printf("Inserisci il nome del file dal quale caricare>");
				gets(filename);
				//Apriamo il file
				io = fopen(filename, "rb");
				l = fifo_load(io);//Carichiamo
				//Chiudiamo il file
				fclose(io);
				break;
			case '\n':
			case '\r':
			case 'e':
				//Qui semplicemente non facciamo niente!
				break;
				
			default:
				printf("Il comando da te selezionato non e' un comando valido.");
				break;
		}
	}
	return 0;
}
