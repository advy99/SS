#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea1/

printf "# N. Dias \t T. Fijo \t T. Variable\n" > ../datos/tarea1/tiempos.dat

for dias in $(seq 100 10000 10000000); do
	printf "$dias \t" >> ../datos/tarea1/tiempos.dat
	../bin/sistema_tiempo_fijo 1 2 2 ${dias} | tail -1 | awk '{printf $4 "\t" }' >> ../datos/tarea1/tiempos.dat
	../bin/sistema_tiempo_variable 1 2 2 ${dias} | tail -1 | awk '{print $4}' >> ../datos/tarea1/tiempos.dat
done








