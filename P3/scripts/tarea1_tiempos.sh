#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea1/

printf "# N. Dias \t T. Fijo \t T. Variable\n" > ../datos/tarea1/tiempos_fijo.dat
printf "# N. Dias \t T. Fijo \t T. Variable\n" > ../datos/tarea1/tiempos_variable.dat

for dias in $(seq 100 10000 10000000); do
	printf "$dias \t" >> ../datos/tarea1/tiempos_fijo.dat
	printf "$dias \t" >> ../datos/tarea1/tiempos_variable.dat
	../bin/sistema_tiempo_fijo 1 2 2 ${dias} | tail -1 | awk '{print $4 }' >> ../datos/tarea1/tiempos_fijo.dat
	../bin/sistema_tiempo_variable 1 2 2 ${dias} | tail -1 | awk '{print $4}' >> ../datos/tarea1/tiempos_variable.dat
done








