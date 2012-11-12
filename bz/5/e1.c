#include <stdio.h>
#include <stdlib.h>

//Certo..se li devi stampare tutti, la ricorsione funge bene..
void biNumbers(char*, char*);

int main(int c, char*a[]){
	char*bin;/* noi non siamo così cretini da usare gli interi per 
			 * rappresentare dei numeri di una sola cifra che poi 
			 * dobbiamo stampare... vero?? xD */
	int size;
	if(c < 2){
		printf("Usage: \n\t%s <bits>\n Where <bits> is the number of bits allowed.", a[0]);
		return 0;
	}//if
	size = atoi(a[1]);//buschiamo la lunghezza
	bin = (char*)malloc(size+1);//allochiamo
	bin[size] = '\0';//piazziamo no zero alla fine
	biNumbers(bin, bin+size-1);//Chiamiamo la robba ricorsiva
	free(bin);//E liberiamoci della spazzatura
	return 0;
}//main

void biNumbers(char*s, char*e){
	//ha detto in qualsiasi ordine, quindi io li stampo come mi fa comodo!
	if(s<=e){
		*e = '0';//prima lo '0'
		biNumbers(s, e-1);
		*e = '1';//poi l' '1'
		biNumbers(s, e-1);
	}//if
	else
		//Fine della ricorsione.. si stampa! :P
		printf("%s\n", s);
}//biNumbers
