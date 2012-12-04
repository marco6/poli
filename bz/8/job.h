#ifndef JOB_H
#define JOB_H
typedef struct job *Job;

void job_esegui(Job);

Job job_new(unsigned int, char*);

void job_free(Job);

int job_priority(Job);

char* job_name(Job);

int job_cmp(const void*, const void*);

#endif