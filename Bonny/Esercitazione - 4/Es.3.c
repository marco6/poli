#include <stdio.h>
#include <stdlib.h>

#define _(a,b,C) [(b+(C*a))]

int * salva_matrice(int *a, int *b);

int main()
{
    int r1, c1, r2, c2, i, j, k;
    int *mat1, *mat2, *mat3;

    mat1 = salva_matrice(&r1, &c1);

    mat2 = salva_matrice(&r2, &c2);

    mat3 = malloc(sizeof(int)*c1*r2);
    
    for(i=0;i<r1;i++)
    {
      for(j=0;j<c2;j++)
        {
			mat3 _(i,j,c2)=0;
			for(k=0;k<c1;k++)
			  mat3 _(i,j,c2) += (mat1 _(i,k,c1))*((mat2 _(k,j,c2)));
			printf("%d ", mat3 _(i,j,c2));
		}
      printf("\n");
     }
     
    free(mat1);
    free(mat2);
    free(mat3);
    
    return 0;
}

int * salva_matrice(int *a, int *b)
{
    int i,*punt;
    FILE *file;
    char nome_file[10];

    printf("Nome file dela matrice:");
    scanf("%s",nome_file);
    file = fopen(nome_file,"r");
    if(file==NULL)printf("errore");
    fscanf(file,"%d %d", a, b);

    punt = malloc(sizeof(int)*(*a)*(*b));
    
    for(i=0; i<(*a)*(*b); i++)
		fscanf(file,"%d",&punt[i]);
		
    fclose(file);
    return punt;
}
