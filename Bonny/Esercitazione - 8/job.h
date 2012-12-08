#ifndef JOB_H
#define JOB_H

typedef struct Job{
    unsigned int prio;
    char s[32];
}Job;

Job get_job();

#endif
