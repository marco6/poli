#!/bin/bash
#Stampa statistiche file

for dir in $(cat $1);do
    for file in $(ls dir)
    terminazione=(echo $file | cat -f 2 -d .)

    if [ $terminazione = "txt" ]
    then
	file_2=$(echo $file | cut -f 1 -d .)
	n=$(wc -m $file)
	echo "Numero di caratteri: "$n > $file_2.stat
	n=$(wc -l $file)
	echo "Numero di linee: "$n >> $file_2.stat
	n=$(wc -w $file)
	echo "Numero di parole: "$n >> $file_2.stat


	i=0
	for line in $(grep -n $file);do
	   n=(echo $line | cut -f 1 -d " ")
	   
	   while [ $i -lt $n ];do
	       graph[$1]="-"
	       let i=i+1
	   done
	done
    fi
    done