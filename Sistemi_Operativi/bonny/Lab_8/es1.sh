#!/bin/bash
#Stampa delle funzioni

#echo Dammi il nome della directory su cui cercare: 
#read dir
#echo La funzione: 
#read funz
#echo Il nome del file su cui stampare:
#read file

#find $1 -type f -name "*.c" -exec grep -i -n $2 '{}' ';' | sort > $3

echo $1
echo $2
echo $3

for var in $(find $1 -type f -name "*.c")
do
    grep -i -n $2 $var >> $3
done
exit 0
