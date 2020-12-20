#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea2/

MAQUINAS=10
REPUESTOS=2
DIAS=365

for reparadores in $(seq 1 1 10); do
	for trepar in 1 2 4 6; do
		for tfallo in 1 2 4 6; do
			../bin/reparadores $MAQUINAS $REPUESTOS $reparadores $trepar $tfallo $DIAS > ../datos/tarea2/reparadores_${MAQUINAS}_${REPUESTOS}_${reparadores}_${trepar}_${tfallo}_${DIAS}.dat
		done
	done
done

