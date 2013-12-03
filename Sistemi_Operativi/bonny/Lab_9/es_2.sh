#!/bin/bash
#Frequenza parole
words=()
for word in $(cat $1);do
    for i in ${!words[@]}
    do
	if [ ${words[$i]} = $word ]
	then
	    let count[$i]=count[$i]+1
	    continue 2
	fi
    done

    count[${#words[@]}]=1    
    words[${#words[@]}]=$word

done
for i in ${!words[@]};do
echo ${words[$i]} ${count[$i]}
done