
do for [i in "0.10 0.30 0.50 0.70 0.90"] {
	do for [j in "90 180 365 750 1400 2000 5000"]{
		set key out
		set lmargin at screen 0.25
		set rmargin at screen 0.75

		set terminal pngcairo size 800,400
		set output "../../memoria/images/pesca/lago_10950_1500_10_".i."_".j.".png"
		set title "Simulación del lago con 1500 peces pequeños y 10 peces grandes durante 30 años."
		set xlabel "Tiempo en días"

		set multiplot
			set key left
			set ytics nomirror
			set ylabel "N. peces pequeños"
			set y2label ""
			plot "lago_10950_1500_10_".j."_".i.".dat" using 1:2 with lines lt 1 title "Pequeños"

			unset ytics
			set y2tics
			set key right
			set y2label "N. peces grandes"
			set ylabel ""
			plot "lago_10950_1500_10_".j."_".i.".dat" using 1:3 with lines axis x1y2 lt 2 title "Grandes"

		unset multiplot


	}

}
