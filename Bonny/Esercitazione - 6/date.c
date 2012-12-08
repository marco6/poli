#include <stdio.h>
#include "date.h"

Data prendi_data(FILE *f)
{   Data tmp;
	fscanf(f,"%d/%d/%d", &tmp.giorno, &tmp.mese, &tmp.anno);
	return tmp;
	}

int confronta_data(Data a, Data b)
{
	if(a.anno==b.anno && a.mese==b.mese && a.giorno==a.giorno) return 0;
	else
	if(a.anno>b.anno) return 1;
	else
	if(a.anno<b.anno) return 0;
	else
	if(a.mese>b.mese) return 1;
	else
	if(a.mese<b.mese) return 0;
	else
	if(a.giorno>b.giorno) return 1;

    return 0;
	}

void stampa_data(Data a)
{
	printf("%02d/%02d/%04d\n", a.giorno, a.mese, a.anno);
	return;
	}

Data diff_date(Data a, Data b)
{
	Data diff;

	diff.anno= a.anno - b.anno;

	if(a.mese>=b.mese) diff.mese= a.mese - b.mese;
	else{
	diff.mese= a.mese - b.mese + 12;
	diff.anno --;}

	if(a.giorno>=b.giorno) diff.giorno= a.giorno - b.giorno;
	else{
	diff.giorno= a.giorno - b.giorno + 30;
	diff.mese --;}

	return diff;
}
