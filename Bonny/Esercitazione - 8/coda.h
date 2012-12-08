#ifndef CODA_H
#define CODA_H


typedef struct Coda *C;

C crea_coda();

void aggiungi_job(Job j, C coda);

Job job_pop(C coda);

#endif
