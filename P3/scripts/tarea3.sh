#!/bin/bash

mkdir -p ../datos
mkdir -p ../datos/tarea3/

# parametros originales, pero variamos numero de puntos de atraque
for n_atraques in 3 4 5; do
	../bin/puertos 1 $n_atraques 1 0.25 0 > ../datos/tarea3/puertos_n_atraques_${n_atraques}.dat
done

# parametros originales, pero no le afectan tormentas
../bin/puertos 1 3 0 0.25 0 > ../datos/tarea3/puertos_no_tormentas.dat

# parametros originales, pero es más rápido
../bin/puertos 1 3 1 0.15 0 > ../datos/tarea3/puertos_rapido.dat


# parametros originales, pero variamos numero de puntos de atraque
for n_atraques in 3 4 5; do
	../bin/puertos 1 $n_atraques 1 0.25 1 > ../datos/tarea3/puertos_n_atraques_${n_atraques}_carga.dat
done

# parametros originales, pero no le afectan tormentas
../bin/puertos 1 3 0 0.25 1 > ../datos/tarea3/puertos_no_tormentas_carga.dat

# parametros originales, pero es más rápido
../bin/puertos 1 3 1 0.15 1 > ../datos/tarea3/puertos_rapido_carga.dat


