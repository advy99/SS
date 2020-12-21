#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea1/

TPARAR=10000

for repuesto in 0 1; do

	for trepar in 0.5 2; do

		for tfallo in 1; do
			../bin/sistema_tiempo_fijo $repuesto $tfallo $trepar $TPARAR > ../datos/tarea1/sistema_t_fijo_${repuesto}_${tfallo}_${trepar}_${TPARAR}.dat
			../bin/sistema_tiempo_variable $repuesto $tfallo $trepar $TPARAR > ../datos/tarea1/sistema_t_fijo_${repuesto}_${tfallo}_${trepar}_${TPARAR}.dat
		done

	done

done




