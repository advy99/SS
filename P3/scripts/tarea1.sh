#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea1/

TPARAR=10000


for trepar in 0.5 2 12 48 720 2880; do

	for tfallo in 1 24 1440; do
		../bin/sistema_tiempo_fijo 1 $tfallo $trepar $TPARAR > ../datos/tarea1/sistema_t_fijo_1_${tfallo}_${trepar}_${TPARAR}.dat
		../bin/sistema_tiempo_variable 1 $tfallo $trepar $TPARAR > ../datos/tarea1/sistema_t_variable_1_${tfallo}_${trepar}_${TPARAR}.dat
	done

done




