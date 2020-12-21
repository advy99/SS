#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea4/

MEJOR_A=0
MEJOR_B=0


for i in $(seq 1 1 100); do
	SALIDA_A=$(../bin/puerto 1 3 0 0.25 0 | grep -o "[0-9]\+.[0-9]\+" | head -1)
	SALIDA_B=$(../bin/puerto 1 3 1 0.25 0 | grep -o "[0-9]\+.[0-9]\+" | head -1)

	if [ $(echo "$SALIDA_A > $SALIDA_B" |bc -l) ]; then
		MEJOR_A=$(($MEJOR_A + 1))
	else
		MEJOR_B=$(($MEJOR_B + 1))
	fi

done

echo "El modelo A es preferible el ${MEJOR_A}% de veces"
echo "El modelo B es preferible el ${MEJOR_B}% de veces"


