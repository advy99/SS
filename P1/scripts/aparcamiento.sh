#!/bin/sh

num_veces=100000
objetivo=100
vision=2
prob_ocupado=0.9

if [ ! -e ../bin/aparcamiento ]; then
	printf "Compilando binario\n"
	cd .. && make bin/aparcamiento
	cd scripts
fi

output=$(../bin/aparcamiento $num_veces $objetivo $vision $prob_ocupado | grep -e inicial:\ \(\[0-9\]\*\) -e media\ \[0-9\.\]\* -e desv.tipica\ \[0-9\.\]\* -o)

printf "# Pos. I.\tMedia\tDesv. tipica\n"


for i in {0..100}; do

	unica_linea=$(echo $output | grep -e inicial:\ \($i\)\ media\ \[0-9\.\]\*\ desv.tipica\ \[0-9\.\]\* -o)

	printf "$i\t"
	awk '{print $4,"\t",$6}' <<< $unica_linea

done
