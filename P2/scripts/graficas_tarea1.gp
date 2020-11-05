

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

		stats "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_0.dat" using 1:6 name "A" nooutput

		stats "../datos/prob_".dist."/datos_10_5_".n_veces."_".dist."_0.dat" using 1:6 name "B" nooutput

		stats "../datos/prob_".dist."/datos_10_10_".n_veces."_".dist."_0.dat" using 1:6 name "C" nooutput

		stats "../datos/prob_".dist."/datos_10_15_".n_veces."_".dist."_0.dat" using 1:6 name "D" nooutput


		set print "tmp.txt"
		print A_pos_max_y , A_max_y
		print B_pos_max_y , B_max_y
		print C_pos_max_y , C_max_y
		print D_pos_max_y , D_max_y

		plot "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_0.dat" using 1:6 with lines title "Ganando 10 , y:1" ls 1, \
			  "../datos/prob_".dist."/datos_10_5_".n_veces."_".dist."_0.dat" using 1:6 with lines title "Ganando 10 , y:5" ls 2, \
			  "../datos/prob_".dist."/datos_10_10_".n_veces."_".dist."_0.dat" using 1:6 with lines title "Ganando 10 , y:10" ls 3, \
			  "../datos/prob_".dist."/datos_10_15_".n_veces."_".dist."_0.dat" using 1:6 with lines title "Ganando 10 , y:15" ls 4, \
			  "tmp.txt" using 1:2:(sprintf("(%d, %d)", $1, $2)) with labels point pt 7 offset char 0,-1 notitle

		system("rm tmp.txt")

	}
}



do for[dist in distribuciones] {
	do for[n_veces in veces] {

		set title "distribucion ".dist." ejecutando ".n_veces." veces con la modificacion 1"
		set term pngcairo dashed size 1400,1050
		set output "../graficas/prob_".dist."/datos_".n_veces."_1.png"

		plot "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_1_10.dat" using 1:6 with lines title "g: 10 , y:10 al devolver" ls 1, \
			  "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_1_50.dat" using 1:6 with lines title "g: 10 , y:50 al devolver" ls 2, \
			  "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_1_100.dat" using 1:6 with lines title "g: 10 , y:100 al devolver" ls 3, \
			  "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_1_500.dat" using 1:6 with lines title "g: 10 , y:500 al devolver" ls 4, \
	}
}


do for[dist in distribuciones] {
	do for[n_veces in veces] {

		set title "distribucion ".dist." ejecutando ".n_veces." veces con la modificacion 2"
		set term pngcairo dashed size 1400,1050
		set output "../graficas/prob_".dist."/datos_".n_veces."_2.png"


		plot "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_2_10.dat" using 1:6 with linespoints title "g: 10 , y:min(1, no vendidos * 10) " ls 1, \
			  "../datos/prob_".dist."/datos_10_5_".n_veces."_".dist."_2_10.dat" using 1:6 with linespoints title "g: 10 , y:min(5, no vendidos * 10) " ls 2, \
			  "../datos/prob_".dist."/datos_10_10_".n_veces."_".dist."_2_10.dat" using 1:6 with linespoints title "g: 10 , y:min(10, no vendidos * 10) " ls 3, \
			  "../datos/prob_".dist."/datos_10_15_".n_veces."_".dist."_2_10.dat" using 1:6 with linespoints title "g: 10 , y:min(15, no vendidos * 10)" ls 4, \
			  "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_2_50.dat" using 1:6 with linespoints title "g: 10 , y:min(1, no vendidos * 50)" ls 5, \
			  "../datos/prob_".dist."/datos_10_5_".n_veces."_".dist."_2_50.dat" using 1:6 with linespoints title "g: 10 , y:min(5, no vendidos * 50)" ls 6, \
			  "../datos/prob_".dist."/datos_10_10_".n_veces."_".dist."_2_50.dat" using 1:6 with linespoints title "g: 10 , y:min(10, no vendidos * 50)" ls 7, \
			  "../datos/prob_".dist."/datos_10_15_".n_veces."_".dist."_2_50.dat" using 1:6 with linespoints title "g: 10 , y:min(15, no vendidos * 50)" ls 8, \
			  "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_2_100.dat" using 1:6 with linespoints title "g: 10 , y:min(1, no vendidos * 100)" ls 9, \
			  "../datos/prob_".dist."/datos_10_5_".n_veces."_".dist."_2_100.dat" using 1:6 with linespoints title "g: 10 , y:min(5, no vendidos * 100)" ls 10, \
			  "../datos/prob_".dist."/datos_10_10_".n_veces."_".dist."_2_100.dat" using 1:6 with linespoints title "g: 10 , y:min(10, no vendidos * 100)" ls 11, \
			  "../datos/prob_".dist."/datos_10_15_".n_veces."_".dist."_2_100.dat" using 1:6 with linespoints title "g: 10 , y:min(15, no vendidos * 100)" ls 12, \
			  "../datos/prob_".dist."/datos_10_1_".n_veces."_".dist."_2_500.dat" using 1:6 with linespoints title "g: 10 , y:min(1, no vendidos * 500)" ls 13, \
			  "../datos/prob_".dist."/datos_10_5_".n_veces."_".dist."_2_500.dat" using 1:6 with lines title "g: 10 , y:min(5, no vendidos * 500)" ls 14, \
			  "../datos/prob_".dist."/datos_10_10_".n_veces."_".dist."_2_500.dat" using 1:6 with lines title "g: 10 , y:min(10, no vendidos * 500)" ls 15, \
			  "../datos/prob_".dist."/datos_10_15_".n_veces."_".dist."_2_500.dat" using 1:6 with lines title "g: 10 , y:min(15, no vendidos * 500)" ls 16, \
	}
}





