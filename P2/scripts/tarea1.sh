#!/bin/sh

mkdir -p ../datos
mkdir -p ../datos/prob_a/
mkdir -p ../datos/prob_b/
mkdir -p ../datos/prob_c/

for distribucion in a b c; do
	for veces in 100 1000 5000 10000 100000 500000; do
		for y in 1 5 10 15; do
			../bin/quiosco 10 $y $veces $distribucion 0 > ../datos/prob_${distribucion}/datos_10_${y}_${veces}_${distribucion}_0.dat
		done
	done
done


