#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

Item new_item(){
	Item a;
    #ifdef TINT
    printf("Dammi il numero: ");
	scanf("%d", &a);
	#else
	#ifdef TSTRING
	printf("Dammi la stringa: ");
	gets(a);
	#else
	printf("Dammi il numero: ");
	scanf("%d", &a.n);
	printf("Dammi la stringa: ");
	gets(a.s);
	#endif
	#endif
	return a;
	}

void stampa_item(Item item)
{
    #ifdef TINT
    printf("%d\n",item);
    #else
    #ifdef TSTRING
    printf("%s\n",item);
    #else
	printf("%d\n%s\n\n", item.n, item.s);
	#endif
	#endif
}



