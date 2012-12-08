#ifndef JOB_C
#define JOB_C

#include <stdio.h>
#include "job.h"

Job get_job()
{
    Job tmp;
    printf("Dammi la stringa/programma: ");
    scanf("%s", tmp.s);
    printf("Dammi la priorita: ");
    scanf("%u", &tmp.prio);
    return tmp;
}

#endif
 
