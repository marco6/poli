#include <containers/cvector.h>
#include <stdlib.h>
#include "job.h"
#include "plist.h"

struct plist {
	unsigned long capacity,
				itemSize,
				size;
	Job *mem; 			
};

Plist plist_new(){
	return vector_new(100, Job);
}//plist_new

void plist_add(Plist l, Job j){
	//Aggiungo un elemento
	vector_push_back(l, j);
	//E ora ordino
	qsort(& vector_at(l, 0), vector_size(l), sizeof(Job), job_cmp);
}

Job plist_pop(Plist l){
	Job r = vector_at(l, vector_size(l)-1);
	vector_pop_back(l);
	return r;
}

void plist_free(Plist p){
	int i;
	for(i =0; i < vector_size(p); i++)
		job_free(vector_at(p, i));
	vector_free(p);
}

int plist_empty(Plist p){
	return vector_empty(p);
}