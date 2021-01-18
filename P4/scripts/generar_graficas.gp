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

set output "SIR_planoSI.png"
set title 'Ejecución del sistema con a = 0.001, b = 0.125, I0 = 1, S0 = 999 y R0 = 0'
set xlabel "Individuos Supceptibles"
set ylabel "Individuos Infectados"

plot '../datos/tarea_2_1.dat' using 3:2 w lines


set output "SIR_menor_a.png"

set title 'Ejecución del sistema con a = 0.0005, b = 0.125, I0 = 1, S0 = 999 y R0 = 0'

plot '../datos/tarea_4_1.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_4_1.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_4_1.dat' using 1:4 w lines title 'Recuperados'

set output "SIR_mayor_b.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999 y R0 = 0'

plot '../datos/tarea_4_2.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_4_2.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_4_2.dat' using 1:4 w lines title 'Recuperados'


set output "SIR_menor_a_mayor_b.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999 y R0 = 0'

plot '../datos/tarea_4_3.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_4_3.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_4_3.dat' using 1:4 w lines title 'Recuperados'

do for [r=50:900:50] {
	set output "SIR_inmunidad_".r.".png"
	s=999-r
	set title 'Ejecución del sistema con a = 0.001, b = 0.125, I0 = 1, S0 = '.s.' y R0 = '.r

	plot '../datos/tarea_5_'.s.'_'.r.'.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_5_'.s.'_'.r.'.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_5_'.s.'_'.r.'.dat' using 1:4 w lines title 'Recuperados'

	
}

set output "SIR_01_euler.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999, R0 = 0 e intervalo de cálculo = 0.1 con método de Euler'

plot '../datos/tarea_6_01_euler.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_6_01_euler.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_6_01_euler.dat' using 1:4 w lines title 'Recuperados'


set output "SIR_01_runge.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999, R0 = 0 e intervalo de cálculo = 0.1 con método de Runge-Kutta'

plot '../datos/tarea_6_01_runge.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_6_01_runge.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_6_01_runge.dat' using 1:4 w lines title 'Recuperados'




set output "SIR_005_euler.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999, R0 = 0 e intervalo de cálculo = 0.05 con método de Euler'

plot '../datos/tarea_6_005_euler.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_6_005_euler.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_6_005_euler.dat' using 1:4 w lines title 'Recuperados'


set output "SIR_005_runge.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999, R0 = 0 e intervalo de cálculo = 0.05 con método de Runge-Kutta'

plot '../datos/tarea_6_005_runge.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_6_005_runge.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_6_005_runge.dat' using 1:4 w lines title 'Recuperados'





set output "SIR_001_euler.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999, R0 = 0 e intervalo de cálculo = 0.01 con método de Euler'

plot '../datos/tarea_6_001_euler.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_6_001_euler.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_6_001_euler.dat' using 1:4 w lines title 'Recuperados'


set output "SIR_001_runge.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999, R0 = 0 e intervalo de cálculo = 0.01 con método de Runge-Kutta'

plot '../datos/tarea_6_001_runge.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_6_001_runge.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_6_001_runge.dat' using 1:4 w lines title 'Recuperados'

set output "SIR_2_euler.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999, R0 = 0 e intervalo de cálculo = 2 con método de Euler'

plot '../datos/tarea_6_2_euler.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_6_2_euler.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_6_2_euler.dat' using 1:4 w lines title 'Recuperados'


set output "SIR_2_runge.png"

set title 'Ejecución del sistema con a = 0.001, b = 0.250, I0 = 1, S0 = 999, R0 = 0 e intervalo de cálculo = 2 con método de Runge-Kutta'

plot '../datos/tarea_6_2_runge.dat' using 1:2 w lines title 'Infectados', '../datos/tarea_6_2_runge.dat' using 1:3 w lines title 'Supceptibles', '../datos/tarea_6_2_runge.dat' using 1:4 w lines title 'Recuperados'



