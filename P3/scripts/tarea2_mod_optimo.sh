#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea2/

MAQUINAS=4
TREPAR=2
TFALLO=1.5
DIAS=365
PORCENTAJE=90
TREV=1
TMANTMIN=0.1
TMANTMAX=0.9

for repuestos in $(seq 1 1 10); do
	for reparadores in $(seq 1 1 10); do
		SALIDA=$(../bin/reparadores_mantenimiento $MAQUINAS $repuestos $reparadores $TREPAR $TFALLO $DIAS $TREV $TMANTMIN $TMANTMAX  | grep -o "[0-9]\+.[0-9]\+" | tail -1)

		if [ $(echo "$SALIDA < $PORCENTAJE" |bc -l) -eq 1 ]; then
			echo "Con $repuestos repuestos y $reparadores reparadores se ha conseguido que el porcentaje total de fallos esté por debajo de un $SALIDA por ciento"

		fi

	done
done

