#!/bin/bash

if [ $# -lt 1 ]
then
    folders=( "." )
else
    folders=( "$@" )
fi

for fold in $folders
do
    #cambio directory di lavoro!
    pushd $fold > /dev/null
    #ora becco tutti gli svg
    for file in $(ls *.svg)
    do
	echo -n "Converto $file..."
	convert -density 144 $file -gravity Center -crop 90%x73%+0+0 -trim $(echo $file | cut -f 1 -d .).png
	echo " Fatto!"
    done
    
    #torno dov'ero!
    popd > /dev/null
done
