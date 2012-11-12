#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void insertion_sort(int, int*);
void selection_sort(int, int*);
void bubble_sort(int, int*);
void swap(int*, int*);


int main()
{
    int M, N, i, j, k, *vett;
    float t0, t1;

    while(1)
    {
        printf("inserire M ed N\n");
        scanf("%d" "%d", &M,&N);
        printf("Inserire quale funzione si vuole usare:\n1)Insertion sort\n2)Selection sort\n3)Bubble sort\n0)Esci.");
        scanf("%d", &k);
        t0 = ((float)clock())/CLOCKS_PER_SEC;
        vett=malloc(N*sizeof(int));
        for(i=0; i<M; i++)
        {
            for(j=0; j<N; j++)
                vett[j]=rand();
            switch(k)
            {
            case 1:
                insertion_sort(N, vett);
                break;
            case 2:
                selection_sort(N, vett);
                break;
            case 3:
                bubble_sort(N, vett);
                break;
            case 0:
                exit(1);
                break;
            default:
                break;
            } //switch
        } //for
        t1 = ((float)clock())/CLOCKS_PER_SEC;
        printf("Tempo in secondi per %d ripetizioni: %f\n",M,t1-t0);
        free(vett);
    }
    return 0;
} //main

void insertion_sort(int N, int*V)
{
    int i,j,key;
    for(i=1; i<N-1; i++)
    {
        key = V[i];
        j = i-1;
        while (j>=0&&V[j]>key)
        {
            V[j+1] = V[j];
            j = j-1;
        }
        V[j+1] = key;
    }
}

void selection_sort(int N, int*V)
{
    int i,j, small;
    for(i=0; i<N-1; i++)
    {
        small = i;
        for(j=i+1; j<N; j++)
            if(V[j]<V[small])
                small = j;
        swap(V+small, V+i);
    }
}

void bubble_sort(int N, int*V)
{
    int i,j;
    for(i=N-1; i>1; i--)
        for(j=0; j<i-1; j++)
            if(V[j]>V[j+1])
                swap(V+j, V+j+1);
}

void swap(int*a, int*b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
