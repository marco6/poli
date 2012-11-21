#include "data.h"
#include <stdio.h>

int fleggi(Date *read, FILE *in)
{
    return fscanf(in, "%d/%d/%d", &read->gg, &read->mm, &read->aa);
}

Date fdatamin(Date read, Date min)
{
    if(read.aa<min.aa || (read.aa==min.aa&&read.mm<min.mm) || (read.aa==min.aa&&read.mm==min.mm&&read.gg<min.gg))
        return read;
    return min;
}

Date fdatamax(Date read, Date max)
{
    if(read.aa>max.aa || (read.aa==max.aa&&read.mm>max.mm) || (read.aa==max.aa&&read.mm==max.mm&&read.gg>max.gg))
       return read;
    return max;
}

Date fdifferenza(Date diff, Date max, Date min)
{
    diff.gg=max.gg-min.gg;
    diff.mm=max.mm-min.mm;
    diff.aa=max.aa-min.aa;
    if(diff.mm<0)
    {
        diff.aa--;
        diff.mm+=12;
    }
    if(diff.gg<0)
    {
        diff.mm--;
        diff.gg+=30;
    }
    return diff;
}

void fstampa(Date read)
{
    printf("%02d/%02d/%04d\n", read.gg, read.mm, read.aa);
}


