#include <stdlib.h>
#include <stdio.h>
#include "Item.h"
#include "FIFO.h"

int main()
{
	Item tmp;
	int i, k;

	printf("Cosa vuoi fare?\n1)Crezione di una uova struttura\n2)Inserzione nuovo elemento");
		printf("\n3)Estrai un elemento\n4)Sapere se la coda e vuota\n");
		printf("5)Stampa tutto\n6)Exit\n");

	while(1)
	{
		printf("Inserisci istruzione: ");
		scanf("%d", &k);
		switch(k)
		{
		  case 1:
		   crea_lista();
		   break;
		  case 2:
			tmp = new_item();
			new_node(tmp);
			break;
		  case 3:
			tmp=estrai_nodo();
			stampa_item(tmp);
			break;
		  case 4:
		   i=coda_vuota();
		   if(i==1)
		    printf("La coda e vuota\n");
		   else
		   printf("La coda non e vuota\n");
	      break;
	      case 5:
	       stampa_tutto();
	       break;
		  case 6:
		     exit (1);
		     break;
		  default:
		   printf("Scelta non valida");
		   break;
		}
	  }
	return 0;
	}
