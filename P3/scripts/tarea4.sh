#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea4/


for n_simul in 1 5 10 25 50; do

	MEJOR_A=0
	MEJOR_B=0

	for i in $(seq 1 1 100); do
		SALIDA_A=$(../bin/puerto $n_simul 3 1 0.25 0 | grep -o "[0-9]\+.[0-9]\+" | head -1)
		SALIDA_B=$(../bin/puerto $n_simul 3 0 0.25 0 | grep -o "[0-9]\+.[0-9]\+" | head -1)

		if [ $(echo "$SALIDA_A < $SALIDA_B" |bc -l) -eq 1 ]; then
			MEJOR_A=$(($MEJOR_A + 1))
		else
			MEJOR_B=$(($MEJOR_B + 1))
		fi

	done

	echo "Con $n_simul simulaciones el modelo A (original) es preferible el ${MEJOR_A}% de veces"
	echo "Con $n_simul simulaciones el modelo B (no le afectan las tormentas) es preferible el ${MEJOR_B}% de veces"

done


# comparamos el A con el C
for n_simul in 1 5 10 25 50; do

	MEJOR_A=0
	MEJOR_C=0

	for i in $(seq 1 1 100); do
		SALIDA_A=$(../bin/puerto $n_simul 3 1 0.25 0 | grep -o "[0-9]\+.[0-9]\+" | head -1)
		SALIDA_C=$(../bin/puerto $n_simul 3 1 0.15 0 | grep -o "[0-9]\+.[0-9]\+" | head -1)

		if [ $(echo "$SALIDA_A < $SALIDA_C" |bc -l) -eq 1 ]; then
			MEJOR_A=$(($MEJOR_A + 1))
		else
			MEJOR_C=$(($MEJOR_C + 1))
		fi

	done

	echo "Con $n_simul simulaciones el modelo A (original) es preferible el ${MEJOR_A}% de veces"
	echo "Con $n_simul simulaciones el modelo C (remolcador más rápido) es preferible el ${MEJOR_C}% de veces"

done
