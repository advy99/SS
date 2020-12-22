#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea2/

MAQUINAS=10
REPUESTOS=2
DIAS=365
TREPAR=1.2
TFALLO=1

for reparadores in $(seq 1 1 10); do
	../bin/reparadores $MAQUINAS $REPUESTOS $reparadores $TREPAR $TFALLO $DIAS > ../datos/tarea2/reparadores_${MAQUINAS}_${REPUESTOS}_${reparadores}_${DIAS}.dat
done

