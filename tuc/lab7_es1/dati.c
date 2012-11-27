#include <stdlib.h>
#include <stdio.h>
#include "dati.h"

Item getnum()
{
    printf("\ninserire dati:\n");
    Item tipo;
#ifdef TINT
    scanf("%d", &tipo);
#else
#ifdef TSTRING
#define SIZE 50
    scanf("%s", tipo);
#else
    scanf("%d", &tipo.n);
    scanf("%s", tipo.str);
#endif
#endif
    return tipo;
}

void print_item(Item tipo)
{
    printf("\ni dati sono:\n");
#ifdef TINT
    printf("%d1", tipo);
#else
#ifdef TSTRING
#define SIZE 50
    printf("%s", tipo);
#else
    printf("%d", tipo.n);
    printf("%s", tipo.str);
#endif
#endif
}
