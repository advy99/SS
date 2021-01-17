#!/bin/bash


mkdir -p ../datos


# ejecucion inicial básica
../bin/practica4 0.001 0.125 0.1 0.1 1 100 1 999 0 runge > ../datos/tarea_2_1.dat


# b / a es 125

# S0 menor a b/a
../bin/practica4 0.001 1.1 0.1 0.1 1 100 1 999 0 runge > ../datos/tarea_2_2_menor.dat

# S0 mayor a b/a
../bin/practica4 0.001 0.5 0.1 0.1 1 100 1 999 0 runge > ../datos/tarea_2_2_mayor.dat



# apartado 4: distintos parámetros

# a vale la mitad
../bin/practica4 0.0005 0.125 0.1 0.1 1 100 1 999 0 runge > ../datos/tarea_4_1.dat

# b vale el doble
../bin/practica4 0.001 0.250 0.1 0.1 1 100 1 999 0 runge > ../datos/tarea_4_2.dat

# a vale la mitad y b el doble
../bin/practica4 0.0005 0.250 0.1 0.1 1 100 1 999 0 runge > ../datos/tarea_4_3.dat



# apartado 5

diferencia=50

for r in $(seq 50 $diferencia 900); do
	s0=$((999 - $r))
	../bin/practica4 0.001 0.125 0.1 0.1 1 100 1 $s0 $r runge > ../datos/tarea_5_${s0}_${r}.dat
done


# apartado 6

../bin/practica4 0.001 0.250 0.1 0.1 1 100 1 999 0 runge > ../datos/tarea_6_01_runge.dat
../bin/practica4 0.001 0.250 0.1 0.1 1 100 1 999 0 euler > ../datos/tarea_6_01_euler.dat

../bin/practica4 0.001 0.250 0.05 0.1 1 100 1 999 0 runge > ../datos/tarea_6_005_runge.dat
../bin/practica4 0.001 0.250 0.05 0.1 1 100 1 999 0 euler > ../datos/tarea_6_005_euler.dat

../bin/practica4 0.001 0.250 0.01 0.1 1 100 1 999 0 runge > ../datos/tarea_6_001_runge.dat
../bin/practica4 0.001 0.250 0.01 0.1 1 100 1 999 0 euler > ../datos/tarea_6_001_euler.dat

