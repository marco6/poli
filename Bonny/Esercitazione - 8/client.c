#ifndef CLIENT_C
#define CLIENT_C
#include <stdio.h>
#include <stdlib.h>
#include "client.h"
#include "job.h"
#include "coda.h"

#define COMPS 3

int main()
{
    Job comps[COMPS];

    unsigned int k=1, tot_jobs=0, i;
	C lista;

    printf("Scegli cosa vuoi fare:\n1)Aggiungi un nuovo lavro\n2)Dire che un lavoro e finito\n3)Stampa lavori in eseguzione\n0)Exit\n");

    lista=crea_coda();

    while(k!=0)
    {
        printf("\nInserisci un comando: ");
        scanf("%u", &k);
        switch(k)
        {
          case 1:
            nuovo_job(&tot_jobs,comps, lista);
            break;
          case 2:
            end_job(comps, &tot_jobs, lista);
            break;
            case 3:
            if(tot_jobs<=COMPS){
             for(i=0;i<tot_jobs;i++) printf("Lavoro %d: -prio %u -comando %s\n", (i+1), comps[i].prio, comps[i].s);
            }
            else
            for(i=0;i<COMPS;i++) printf("Lavoro %d: -prio %u -comando %s\n", (i+1), comps[i].prio, comps[i].s);
            break;
          case 0:
            printf("ciao");
            break;
          default:
            printf("comando non valido!");
            break;
        }
    }
    return 0;
}

void nuovo_job(unsigned int *tot_jobs, Job *comps, C lista)
{
    Job j;

    j=get_job();
    if(*tot_jobs<COMPS)
    {
        comps[*tot_jobs]=j;
        printf("Nuovo job aquisito e messo in eseguzione.\n");
    }
    else aggiungi_job(j, lista);

    (*tot_jobs) ++;

    return;
}

void end_job(Job *comps, unsigned int *tot_jobs, C lista)
{
    int i;

    for(i=0;i<COMPS-2;i++) comps[i]=comps[i+1];

    if(*tot_jobs>COMPS){
    comps[COMPS-1]= job_pop(lista);
    printf("Lavoro aquisito dalla lista di attesa e lanciato su un computer.\n");
    }
    else
    printf("Nessun lavoro trovato in lista di attesa computer libero.\n");
    tot_jobs --;

    return;
}
#endif

