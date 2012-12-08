#ifndef CLIENT_H
#define CLIENT_H

#include "job.h"
#include "coda.h"

void nuovo_job(unsigned int *tot_jobs, Job *comps, C lista);

void end_job(Job *comps, unsigned int *tot_jobs, C lista);

#endif

