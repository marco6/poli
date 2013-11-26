#!/bin/bash
#Maiuscolare tutto

for nome in $(ls $1)
do
nome_maiuscolo=$(echo $nome | tr a-z A-Z)
mv $1/$nome $1/$nome_maiuscolo
done
exit 0

#mv ./$nome ./$nome_maiuscolo