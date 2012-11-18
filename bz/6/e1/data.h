#include <stdio.h>

//Dato base
//Numero di giorni passati dall'anno 1/1/0.. mi dispiace per gesù, ma degli anni a.c. non me ne frega cazzi :P
//                                     ||
//                                     \/
//                          A natale tutti sono più buoni *.*
typedef unsigned long Data;

Data buildData(int,int,int);
Data readData(FILE*);

Data dataDiff(Data, Data);

void printData(FILE*, Data);

#define dataMax(a,b) (a)>(b) ? (a) : (b)
#define dataMin(a,b) (a)<(b) ? (a) : (b)