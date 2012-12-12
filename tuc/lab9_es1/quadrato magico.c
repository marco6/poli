#include <stdio.h>
#include <stdlib.h>


int genera_mat(int**,int*,int,int,int,int);

int controlla_mat(int**,int);


int main()
{
    int i, j, N, **mat, *vet;

    printf("inserire dimensione quadrato\n");
    scanf("%d", &N);

    vet=(int*)malloc((N*N+1)*sizeof(int));
    mat=(int**)malloc(N*sizeof(int*));

    for (i=0; i<N; i++)
        mat[i]=(int*)malloc(N*sizeof(int));

    for(i=0; i<N*N; i++)
        vet[i]=i+1;

    if(genera_mat(mat, vet, N, 0, 0, 0))
    {
        printf("\n");
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
                printf("%d\t", mat[i][j]);
            printf("\n");
        }
    }

    else
        printf("quadrati non trovati!\n");

    for (i=0; i<N; i++)
        free(mat[i]);
    free(vet);
    return 0;
}



int genera_mat(int **m, int *v, int N, int cont, int i, int j)
{
    int k;

    if(cont==N*N)
    {
        if(controlla_mat(m, N))
            return 1;
    }

    if(j==N)
    {
        i++;
        j=0;
    }

    for(k=0; k<N*N; k++)
    {
        if(v[k]!=k+1)
            continue;
        m[i][j]=v[k];
        v[k]=0;
        if(genera_mat(m, v, N, cont+1, i, j+1))
            return 1;
        else
            v[k]=k+1;
    }
    return 0;
}



int controlla_mat(int **m, int N)
{
    int i, j, somma, s_righe, s_colonne, s_diag=0, s_antidiag=0;

    somma=N*(N*N+1)/2;

    for(i=0; i<N; i++)
    {
        s_righe=0;
        s_colonne=0;
        s_diag+=m[i][i];
        for(j=0; j<N; j++)
        {
            s_righe+=m[i][j];
            s_colonne+=m[j][i];

            if(j+i==N-1)
                s_antidiag+=m[i][j];
        }
        if(somma!=s_righe || somma!=s_colonne)
            return 0;
    }

    if(somma!=s_diag || somma!=s_antidiag)
        return 0;
    else
        return 1;
}


