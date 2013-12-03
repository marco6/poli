#!/bin/bash
#Stampa su file di fibonacci

for n in $(less $1);do
    i=2
    var1=1
    var2=1 
    file_2=$(echo $1 | cut -f 1 -d .)
    echo $var1 > $file_2$n$2
    echo $var2 >> $file_2$n$2

    while [ $i -lt $n ]; do
	let var3=var1+var2
	echo $var3
	var1=$var2
	var2=$var3
	let i=i+1
    done >> $file_2$n$2
done