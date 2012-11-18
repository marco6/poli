#include <stdio.h>
#include "data.h"

#define IN "e1.in"

//Che porcata!
int main(){
	FILE *f;
	int y,m,d;
	Data min, max, i;
	f = fopen(IN, "r");
	min = max = readData(f);
	while(fscanf(f, "%d/%d/%d", &d, &m, &y)!= EOF){
		i = buildData(d, m ,y);
		min = dataMin(min, i);
		max = dataMax(max, i);
	}
	printf("Data piu' remota: ");
	printData(stdout, min);
	printf("\nData piu' recente: ");
	printData(stdout, max);
	printf("\nIntervallo di tempo: ");
	printData(stdout, dataDiff(max, min));
	return 0;
}