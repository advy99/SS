#!/bin/sh


mkdir -p ../datos
mkdir -p ../datos/tiempos_mejoras/
mkdir -p ../datos/tiempos_mejoras/mejora1/
mkdir -p ../datos/tiempos_mejoras/mejora2/
mkdir -p ../datos/tiempos_mejoras/mejora3/
mkdir -p ../graficas/


for num_mejora in 1 2 3; do
	for demanda in 100 500 1000 5000 10000 50000 100000 250000 500000 1000000; do
		../bin/mejora${num_mejora}_generadores ${demanda} >> ../datos/tiempos_mejoras/mejora${num_mejora}/t_${num_mejora}_${demanda}.dat
	done

done





