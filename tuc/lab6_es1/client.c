#include <stdio.h>
#include <string.h>
#include "data.h"

int main()
{
    Date read, min, max, diff;

    FILE *in;
    in=fopen("date.txt", "r");

    memset(&max,0,sizeof(max));
    memset(&diff,0,sizeof(diff));

    while(fleggi(&read, in)!=EOF)
    {
        min=fdatamin(read, min);
        max=fdatamax(read, max);
    }//while
    fclose(in);
    diff=fdifferenza(diff, max, min);

    printf("data minore=");
    fstampa(min);
    printf("\ndata maggiore=");
    fstampa(max);
    printf("\ndifferenza=");
    fstampa(diff);

    return 0;
}//main
