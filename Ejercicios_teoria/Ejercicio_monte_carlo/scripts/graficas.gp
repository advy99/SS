#!/usr/bin/env gnuplot

set xlabel "Papel reciclado al día"
set ylabel "Falta de papel reciclado"
set key right


set terminal png size 1200, 700
set output "falta_papel_cambiando_kg_procesados.png"

set title 'Falta de papel reciclado para cubrir la demanda modificando la cantidad de Kg procesados por día de papel utilizado.'

plot '../datos/falta_papel_cambiando_kg_dia.dat' using 1:2 w lines title ''

set xrange [3:1]
set xtics 0.1


set output "falta_papel_cambiando_proporcion_generacion.png"

set title 'Falta de papel reciclado para cubrir la demanda modificando la cantidad de Kg necesarios para generar 1Kg de papel reciclado.'

plot '../datos/falta_papel_mejorando_produccion.dat' using 1:2 w lines title ''
