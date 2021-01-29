#!/bin/bash

mkdir -p ../datos

DIAS=365
C_ROJO=300
C_VERDE=0
PAPEL_RECICLADO_DIA=300
VECES=1000000

# Ejecución por defecto, sacamos la salida a un fichero de datos
# y la salida de error nos mostrará en la terminal si hay algún punto
# donde se llenan los contenedores

../bin/main_reciclar $DIAS $C_ROJO $C_VERDE $PAPEL_RECICLADO_DIA $VECES


printf "# Papel reciclado al día \t Falta de papel reciclado (falta para vender)\n" > ../datos/falta_papel_cambiando_kg_dia.dat
for papel_dia in $(seq 300 50 900); do
	printf "$papel_dia \t" >> ../datos/falta_papel_cambiando_kg_dia.dat
	../bin/main_reciclar $DIAS $C_ROJO $C_VERDE $papel_dia $VECES | tail -1 | awk {'print $11'} >> ../datos/falta_papel_cambiando_kg_dia.dat
done


printf "# Papel usado necesario para generar 1Kg de papel reciclado \t Falta de papel reciclado (falta para vender)\n" > ../datos/falta_papel_mejorando_produccion.dat
for papel_necesario in $(seq 3 -0.1 1 | sed 's/,/./g'); do
	printf "$papel_necesario \t" >> ../datos/falta_papel_mejorando_produccion.dat
	../bin/main_reciclar $DIAS $C_ROJO $C_VERDE $PAPEL_RECICLADO_DIA $VECES $papel_necesario | tail -1 | awk {'print $11'} >> ../datos/falta_papel_mejorando_produccion.dat
done
