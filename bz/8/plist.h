#ifndef PLIST_H
#define PLIST_H

#include "job.h"
typedef struct plist *Plist;

Plist plist_new();
void plist_add(Plist, Job);
Job plist_pop(Plist);
void plist_free(Plist);
int plist_empty(Plist);

#endif