#include "data.h"

Data buildData(int day, int month, int year){
	return year * 360 + month * 30 + day - 31;
}

Data readData(FILE*f){
	int d,m,y;
	fscanf(f, "%d/%d/%d", &d, &m, &y);
	return buildData(d,m,y);
}//Che orrore..

Data dataDiff(Data a, Data b){
	return (a>b)? (a-b) : (b-a);
}//dataDiff

void printData(FILE*f, Data d){
	fprintf(f,"%d/%d/%d", d % 30 + 1, (d % 360)/30 + 1, d/360);
}