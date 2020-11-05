#!/bin/sh

mkdir -p ../datos
mkdir -p ../datos/prob_a/
mkdir -p ../datos/prob_b/
mkdir -p ../datos/prob_c/
mkdir -p ../graficos/

for distribucion in a b c; do
	for veces in 100 1000 5000 10000 100000 150000; do
		for y in 1 5 10 15; do
			../bin/quiosco 10 $y $veces $distribucion 0 > ../datos/prob_${distribucion}/datos_10_${y}_${veces}_${distribucion}_0.dat
		done
	done
done

for modificacion in 1 2; do
	for z in 1 5 10 15 20 25 30; do

		for veces in 100 1000 5000 10000 100000 150000; do
			for y in 1 5 10 15; do
				../bin/quiosco 10 $y $veces $distribucion $modificacion $z > ../datos/prob_${distribucion}/datos_10_${y}_${veces}_${distribucion}_${modificacion}_${z}.dat
			done
		done


	done

done

