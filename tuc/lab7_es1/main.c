#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coda.h"
#include "dati.h"

int main()
{
    int N=100, opzione;
    Item num;

    while(opzione!=0)
    {
        printf("\ninserire operazione:\n  1-new\n  2-insert\n  3-extract\n  0-fine\n");
        scanf("%d", &opzione);

        switch(opzione)
        {
        case 1:
            new_(N);
            break;
        case 2:
            num=getnum();
            insert(num);
            break;
        case 3:
            num=extract();
            print_item(num);
            break;
        }
    }//while
    return 0;
}



