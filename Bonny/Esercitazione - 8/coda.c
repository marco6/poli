#ifndef CODA_C
#define CODA_C

#include <stdlib.h>
#include <stdio.h>
#include "job.h"
#include "coda.h"

#define PARENT(i) ((int)((i-1)/2))
#define LEFT(i) ((int)((2*i)+1))
#define RIGHT(i) ((int)((2*i)+1))

typedef struct Coda{
 unsigned int count;
 Job vett[100];
}Coda;

Coda *crea_coda()
{
	Coda *a = malloc(sizeof(Coda));
	a->count=0;
    return a;
}

void swap(unsigned int j1, unsigned int j2, Coda *coda)
{
 Job tmp;

 tmp  = coda->vett[j1];
 coda->vett[j1] = coda->vett[j2];
 coda->vett[j2] = tmp;
 return;
}

void aggiungi_job(Job j, Coda *coda)
{
    unsigned int i;

    i  = coda->count;
    coda->vett[i]=j;

 while (i>0 && (coda->vett[PARENT(i)].prio) < j.prio)
    {
        coda->vett[i] = coda->vett[PARENT(i)];
        i = (i-1)/2;
    }
   coda->vett[i] = j;
   (coda->count) ++;
   printf("Lavoro inserito nella lista d'attesa.\n");

   return;
}

void heapify(unsigned int i, Coda *coda)
{
    unsigned int l, r, largest;

    l = LEFT(i);
    r = RIGHT(i);

    if (l < coda->count && coda->vett[l].prio > coda->vett[i].prio)
        largest=l;
    else
        largest = i;
    if (r < coda->count && coda->vett[r].prio>coda->vett[largest].prio)
        largest=r;
    if (largest != i)
    {
  swap(i,largest,coda);
  heapify(largest, coda);
    }
    return;
}

Job job_pop(Coda *coda){
    Job tmp;
    tmp=coda->vett[0];
    coda->vett[0]=coda->vett[(coda->count-1)];
    heapify(0,coda);
    (coda->count)--;
    printf("Elemento estratto dalla coda e spedito a un computer.\n");
    return tmp;
}

#endif
