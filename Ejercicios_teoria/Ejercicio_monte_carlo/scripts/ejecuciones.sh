#!/bin/bash

mkdir -p ../datos

DIAS=365
C_ROJO=300
C_VERDE=0
KG_PARA_RECICLAR_1=3

# Ejecución por defecto, sacamos la salida a un fichero de datos
# y la salida de error nos mostrará en la terminal si hay algún punto
# donde se llenan los contenedores
printf "# Dia actual \t Contenedor rojo \t Contenedor Verde \t Papel usado perdido (sin espacio en rojo) \t Papel reciclado perdido (sin espacio en verde) \t Falta papel vender (sin papel reciclado)\n" > ../datos/ejecucion_defecto.dat

../bin/main_reciclar $DIAS $C_ROJO $C_VERDE $KG_PARA_RECICLAR_1 >> ../datos/ejecucion_defecto.dat
