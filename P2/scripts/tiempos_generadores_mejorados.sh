#!/bin/sh


mkdir -p ../datos
mkdir -p ../datos/tiempos_mejoras/
mkdir -p ../graficas/


for num_mejora in 1 2 3; do
	echo "" > ../datos/tiempos_mejoras/t_${num_mejora}.dat
	for demanda in $(seq 0 1000 1000000); do
		../bin/mejora${num_mejora}_generadores ${demanda} >> ../datos/tiempos_mejoras/t_${num_mejora}.dat
	done

done





