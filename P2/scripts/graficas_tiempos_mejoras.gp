

set xlabel "Demandas consultadas a la tabla"
set ylabel "Tiempo (s)"
set key left
set title "Mejora 1: Tablas ordenadas"

set term pngcairo dashed size 1400,1050
set output "../graficas/t_mejora1.png"

plot "../datos/tiempos_mejoras/t_1.dat" using 1:2 with lines title "Tiempo original" ls 1, \
	  "../datos/tiempos_mejoras/t_1.dat" using 1:3 with lines title "Tiempo con la mejora" ls 2


set title "Mejora 2: Busqueda binaria en las tablas"
set output "../graficas/t_mejora2.png"

plot "../datos/tiempos_mejoras/t_2.dat" using 1:2 with lines title "Tiempo original prob. a" ls 1, \
	  "../datos/tiempos_mejoras/t_2.dat" using 1:3 with lines title "Tiempo con la mejora prob. a" ls 2, \
	  "../datos/tiempos_mejoras/t_2.dat" using 1:4 with lines title "Tiempo original prob. b" ls 3, \
	  "../datos/tiempos_mejoras/t_2.dat" using 1:5 with lines title "Tiempo con la mejora prob. b" ls 4, \
	  "../datos/tiempos_mejoras/t_2.dat" using 1:6 with lines title "Tiempo original prob. c" ls 5, \
	  "../datos/tiempos_mejoras/t_2.dat" using 1:7 with lines title "Tiempo con la mejora prob. c" ls 6

set title "Mejora 3: Tiempo constante para el caso a"
set output "../graficas/t_mejora3.png"

plot "../datos/tiempos_mejoras/t_3.dat" using 1:2 with lines title "Tiempo original" ls 1, \
	  "../datos/tiempos_mejoras/t_3.dat" using 1:3 with lines title "Tiempo con la mejora" ls 2

