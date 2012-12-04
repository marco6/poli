#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "job.h"

#define JSIZE 30

struct job {
	unsigned int priorita;
	char nome[JSIZE + 1];
};

void job_esegui(Job w){
	//Qui libero la memoria
	job_free(w);
}//job_esegui

Job job_new(unsigned int p, char* name){
	Job j = (Job)malloc(sizeof(struct job));
	j->priorita = p;
	strncpy(j->nome, name, JSIZE);
	return j;
}//job_new

void job_free(Job j){
	free(j);
}

int job_priority(Job j){
	return j->priorita;
}//job_priority

char* job_name(Job j){
	return j->nome;
}//job_name

int job_cmp(const void* a, const void*b){
	return job_priority(*(Job*)a) - job_priority(*(Job*)b);
}