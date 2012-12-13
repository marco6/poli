#ifndef DATI_H
#define DATI_H

#ifdef TINT
typedef int Item;
#else
#define SIZE 50
#ifdef TSTRING
typedef char Item[SIZE+1];
#else
typedef struct st
{
    int n;
    char str[SIZE+1];
} Item;
#endif
#endif

Item getnum();
void print_item();

#endif
