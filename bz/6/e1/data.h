#include <stdio.h>

//Dato base
typedef struct data {
	//Bisogna metterli in ordine di significato, quindi.. anno>mese>giorno
	unsigned int y:15;//15 bit per andare da 0 fino a 32767... mi dispiace per jesù, ma gli anni negativi non li conto xD
	unsigned int m:4;//month:
	unsigned int d:5;//Quì è facile.. da 1 a 31:5bit
} Data;

Data buildData(int,int,int);
Data buildData(char*,char*);

Data dataDiff(Data, Data);

char* printData(char*, char*, Data);
void printData(FILE*, char*, Data);
