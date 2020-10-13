set terminal pngcairo size 1920,1080
set output "../../memoria/images/pesca/total.png"

set key out
set xlabel "Tiempo en días"
set ylabel "N. peces pescados"

plot 'lago_10950_1500_10_90_0.10.dat' using 1:4 with lines title 'Pescando el 0.10 porciendo cada 90 dias', \
'lago_10950_1500_10_180_0.10.dat' using 1:4 with lines title 'Pescando el 0.10 porciendo cada 180 dias', \
'lago_10950_1500_10_365_0.10.dat' using 1:4 with lines title 'Pescando el 0.10 porciendo cada 365 dias', \
'lago_10950_1500_10_750_0.10.dat' using 1:4 with lines title 'Pescando el 0.10 porciendo cada 750 dias', \
'lago_10950_1500_10_1400_0.10.dat' using 1:4 with lines title 'Pescando el 0.10 porciendo cada 1400 dias', \
'lago_10950_1500_10_2000_0.10.dat' using 1:4 with lines title 'Pescando el 0.10 porciendo cada 2000 dias', \
'lago_10950_1500_10_5000_0.10.dat' using 1:4 with lines title 'Pescando el 0.10 porciendo cada 5000 dias', \
'lago_10950_1500_10_90_0.30.dat' using 1:4 with lines title 'Pescando el 0.30 porciendo cada 90 dias', \
'lago_10950_1500_10_180_0.30.dat' using 1:4 with lines title 'Pescando el 0.30 porciendo cada 180 dias', \
'lago_10950_1500_10_365_0.30.dat' using 1:4 with lines title 'Pescando el 0.30 porciendo cada 365 dias', \
'lago_10950_1500_10_750_0.30.dat' using 1:4 with lines title 'Pescando el 0.30 porciendo cada 750 dias', \
'lago_10950_1500_10_1400_0.30.dat' using 1:4 with lines title 'Pescando el 0.30 porciendo cada 1400 dias', \
'lago_10950_1500_10_2000_0.30.dat' using 1:4 with lines title 'Pescando el 0.30 porciendo cada 2000 dias', \
'lago_10950_1500_10_5000_0.30.dat' using 1:4 with lines title 'Pescando el 0.30 porciendo cada 5000 dias', \
'lago_10950_1500_10_90_0.50.dat' using 1:4 with lines title 'Pescando el 0.50 porciendo cada 90 dias', \
'lago_10950_1500_10_180_0.50.dat' using 1:4 with lines title 'Pescando el 0.50 porciendo cada 180 dias', \
'lago_10950_1500_10_365_0.50.dat' using 1:4 with lines title 'Pescando el 0.50 porciendo cada 365 dias', \
'lago_10950_1500_10_750_0.50.dat' using 1:4 with lines title 'Pescando el 0.50 porciendo cada 750 dias', \
'lago_10950_1500_10_1400_0.50.dat' using 1:4 with lines title 'Pescando el 0.50 porciendo cada 1400 dias', \
'lago_10950_1500_10_2000_0.50.dat' using 1:4 with lines title 'Pescando el 0.50 porciendo cada 2000 dias', \
'lago_10950_1500_10_5000_0.50.dat' using 1:4 with lines title 'Pescando el 0.50 porciendo cada 5000 dias', \
'lago_10950_1500_10_90_0.70.dat' using 1:4 with lines title 'Pescando el 0.70 porciendo cada 90 dias', \
'lago_10950_1500_10_180_0.70.dat' using 1:4 with lines title 'Pescando el 0.70 porciendo cada 180 dias', \
'lago_10950_1500_10_365_0.70.dat' using 1:4 with lines title 'Pescando el 0.70 porciendo cada 365 dias', \
'lago_10950_1500_10_750_0.70.dat' using 1:4 with lines title 'Pescando el 0.70 porciendo cada 750 dias', \
'lago_10950_1500_10_1400_0.70.dat' using 1:4 with lines title 'Pescando el 0.70 porciendo cada 1400 dias', \
'lago_10950_1500_10_2000_0.70.dat' using 1:4 with lines title 'Pescando el 0.70 porciendo cada 2000 dias', \
'lago_10950_1500_10_5000_0.70.dat' using 1:4 with lines title 'Pescando el 0.70 porciendo cada 5000 dias', \
'lago_10950_1500_10_90_0.90.dat' using 1:4 with lines title 'Pescando el 0.90 porciendo cada 90 dias', \
'lago_10950_1500_10_180_0.90.dat' using 1:4 with lines title 'Pescando el 0.90 porciendo cada 180 dias', \
'lago_10950_1500_10_365_0.90.dat' using 1:4 with lines title 'Pescando el 0.90 porciendo cada 365 dias', \
'lago_10950_1500_10_750_0.90.dat' using 1:4 with lines title 'Pescando el 0.90 porciendo cada 750 dias', \
'lago_10950_1500_10_1400_0.90.dat' using 1:4 with lines title 'Pescando el 0.90 porciendo cada 1400 dias', \
'lago_10950_1500_10_2000_0.90.dat' using 1:4 with lines title 'Pescando el 0.90 porciendo cada 2000 dias', \
'lago_10950_1500_10_5000_0.90.dat' using 1:4 with lines title 'Pescando el 0.90 porciendo cada 5000 dias'
