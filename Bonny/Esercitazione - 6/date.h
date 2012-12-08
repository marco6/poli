#include <stdio.h>

typedef struct{
	int giorno;
	int mese;
	int anno;
}Data;

Data prendi_data(FILE *);

int confronta_data(Data, Data);

Data diff_date(Data, Data);

void stampa_data(Data);
