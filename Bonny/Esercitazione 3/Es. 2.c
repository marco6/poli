#include <stdio.h>
#include <stdlib.h>

#define max_r 100
#define max_c 30

int get_matrice(FILE *file, char mat[][max_c]);
void selection_sort(int, int*);
void swap(int*, int*);

int main()
{
    char matrice[max_r][max_c], *vett[max_r];   //inizializzo il vettore di puntatori
    FILE *file1, *file2;
    int i=0,j=0,tot_str;

    file1=fopen("lettura.txt","r");
    if(file1==NULL)
    {
        printf("il file non esiste o non e stato trovato");
        exit(1);
    }
    tot_str = get_matrice(file1, matrice);   //funzione che mi memorizza la matrice e mi ridà quante righe ha letto
    fclose(file1);

    for(i=0; i<tot_str; i++)
        vett[i]= &matrice[i];  //immagino che si faccia cosi per salvare i puntatori alle righe nel vettore o.o?

    selection_sort(tot_str,vett);   //ordina il il vettore a seconda di quello che ce dentro la casella 0 di ogni riga in pratica

    file2=fopen("scrittura.txt","w");

    for(i=0;i<tot_str;i++)
        fprintf("%s", vett[i]);      //qua scrivo dentro al secondo file

    fclose(file2);

    return 0;
}

int get_matrice(FILE *f, char mat[][max_c])
{
    int i=0;
while(fgets(mat[i], max_c, f)!=NULL)
        i++;
    return i;
}

void selection_sort(int N, char*V)
{
    int i,j, small;
    for(i=0; i<N-1; i++)
    {
        small = i;
        for(j=i+1; j<N; j++)
            if(*V[j]<*V[small])      //qua ho messo gli asterischi perche per fare il controllo del minore deve vedere
                small = j;           //a cosa punta l'indirizzo che ce dentro la casella e non cosa ce dentro la casella
        swap(small, i, V);           //stessa dato che e solo un indirizzo appunto (sto filosofeggiando... O.o?!?)
    }
}

void swap(int a, int b, char *V)
{
    char *tmp;
    *tmp=V[small];
    V[a]=V[b];          //lo messa in modo che scambi gli indirizzi (o puntatori che dir si voglia :P)
    V[b]=*tmp;
}
