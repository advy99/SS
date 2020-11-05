

set xlabel "Unidades pedidas (s)"
set ylabel "Ganancia esperada (g)"
set xrange [0:100]
set key left
set xtics 5
set ytics 40

distribuciones = "a b c"
veces = "100 1000 5000 10000 100000 150000"
perdida_unidad = "1 5 10 15"

do for[dist in distribuciones] {
	do for[n_veces in veces] {
		set title "Distribucion ".dist." ejecutando ".n_veces." veces"
		set term pngcairo dashed size 1400,1050
		set output "../graficas/prob_".dist."/datos_".n_veces.".png"

		stats "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_0.dat" using 1:6 name "A"

		stats "../datos/prob_".dist."/datos_10_5_".n_veces."_".dist."_0.dat" using 1:6 name "B"

		stats "../datos/prob_".dist."/datos_10_10_".n_veces."_".dist."_0.dat" using 1:6 name "C"

		stats "../datos/prob_".dist."/datos_10_15_".n_veces."_".dist."_0.dat" using 1:6 name "D"


		set print "tmp.txt"
		print A_pos_max_y , A_max_y
		print B_pos_max_y , B_max_y
		print C_pos_max_y , C_max_y
		print D_pos_max_y , D_max_y

		plot "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_0.dat" using 1:6 with lines title "Ganando 10/venta y perdiendo 1/venta" ls 1, \
			  "../datos/prob_".dist."/datos_10_5_".n_veces."_".dist."_0.dat" using 1:6 with lines title "Ganando 10/venta y perdiendo 5/venta" ls 2, \
			  "../datos/prob_".dist."/datos_10_10_".n_veces."_".dist."_0.dat" using 1:6 with lines title "Ganando 10/venta y perdiendo 10/venta" ls 3, \
			  "../datos/prob_".dist."/datos_10_15_".n_veces."_".dist."_0.dat" using 1:6 with lines title "Ganando 10/venta y perdiendo 15/venta" ls 4, \
			  "tmp.txt" using 1:2:(sprintf("(%d, %d)", $1, $2)) with labels point pt 7 offset char 0,-1 notitle

		system("rm tmp.txt")

	}
}
