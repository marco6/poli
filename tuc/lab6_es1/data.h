#include <stdio.h>

typedef struct date{
int gg, mm, aa;
}Date;

int fleggi(Date*, FILE*);
Date fdatamin(Date, Date);
Date fdatamax(Date, Date);
Date fdifferenza(Date, Date, Date);
void fstampa(Date);

