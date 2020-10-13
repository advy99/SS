set key off
set lmargin at screen 0.25
set rmargin at screen 0.75

set terminal pngcairo size 800,400

set output "../../memoria/images/lago_10950_1500_10_peces.png"

set title "Simulación del lago con 1500 peces pequeños y 10 peces grandes durante 30 años."
set xlabel "N. peces pequeños"
set ylabel "N. peces grandes"

plot "lago_10950_1500_10.dat" using 2:3 with lines lt 2


