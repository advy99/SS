#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea2/

MAQUINAS=4
TREPAR=2
TFALLO=1.5
DIAS=365

for repuestos in $(seq 1 1 10); do
	for reparadores in $(seq 1 1 10); do
		../bin/reparadores $MAQUINAS $repuestos $reparadores $TREPAR $TFALLO $DIAS > ../datos/tarea2/reparadores_${MAQUINAS}_${repuestos}_${reparadores}_${TREPAR}_${TFALLO}_${DIAS}.dat
	done
done

