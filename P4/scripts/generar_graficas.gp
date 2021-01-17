#!/usr/bin/env gnuplot


set xlabel "Tiempo"
set ylabel "Individuos"
set key right

set terminal png size 1200, 700
set output "SIR_prueba_basica.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.125, I0 = 1, S0 = 999 y R0 = 0'

plot '../datos/tarea_2_1.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_2_1.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_2_1.dat' using 1:4 w lines title 'Recuperados'

set output "SIR_s0_menor.png"
set title 'Ejecución del sistema con a = 0.001, b = 1.1, I0 = 1, S0 = 999 y R0 = 0'


plot '../datos/tarea_2_2_menor.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_2_2_menor.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_2_2_menor.dat' using 1:4 w lines title 'Recuperados'

set output "SIR_s0_mayor.png"
set title 'Ejecución del sistema con a = 0.001, b = 0.5, I0 = 1, S0 = 999 y R0 = 0'

plot '../datos/tarea_2_2_mayor.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_2_2_mayor.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_2_2_mayor.dat' using 1:4 w lines title 'Recuperados'

set output "SIR_s0_igual.png"
set title 'Ejecución del sistema con a = 0.001, b = 0.999, I0 = 1, S0 = 999 y R0 = 0'

plot '../datos/tarea_2_2_igual.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_2_2_igual.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_2_2_igual.dat' using 1:4 w lines title 'Recuperados'

