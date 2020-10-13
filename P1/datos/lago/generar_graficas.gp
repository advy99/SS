
do for [i in "100 500 1000 1500 3000 6000 10000 20000"] {
	do for [j in "10 50 100 500 1000 1500"]{
		set key out
		set lmargin at screen 0.25
		set rmargin at screen 0.75

		set terminal pngcairo size 800,400
		set output "../../memoria/images/lago_10950_".i."_".j.".png"
		set title "Simulación del lago con ".i." peces pequeños y ".j." peces grandes durante 30 años."
		set xlabel "Tiempo en días"

		set multiplot
			set key left
			set ytics nomirror
			set ylabel "N. peces pequeños"
			set y2label ""
			plot "lago_10950_".i."_".j.".dat" using 1:2 with lines lt 1 title "Pequeños"

			unset ytics
			set y2tics
			set key right
			set y2label "N. peces grandes"
			set ylabel ""
			plot "lago_10950_".i."_".j.".dat" using 1:3 with lines axis x1y2 lt 2 title "Grandes"

		unset multiplot


	}

}
