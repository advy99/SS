#!/bin/bash

MEDIA=0
RESTAS=()


for i in $(seq 0 1 99); do
	# parametros originales, pero no le afectan tormentas
	TMP1=$(../bin/puerto 1 3 0 0.25 0 | grep -o "[0-9]\+.[0-9]\+" | head -1)

	# parametros originales, pero es más rápido
	TMP2=$(../bin/puerto 1 3 1 0.15 0 | grep -o "[0-9]\+.[0-9]\+" | head -1)

	RESTAS+=($(echo "$TMP1 - $TMP2" | bc -l))
	MEDIA=$(echo "$MEDIA + ($TMP1 - $TMP2)" | bc -l )
done

MEDIA=$(echo "$MEDIA / 100" | bc -l )


VARIANZA=0

for i in $(seq 0 1 99); do
	VARIANZA=$(echo "(${RESTAS[$i]} + $MEDIA) * (${RESTAS[$i]} + $MEDIA)" | bc -l)
done

VARIANZA=$(echo "$VARIANZA / 100" | bc -l )

T_STUDENT=1.6604

SUP=$(echo "$MEDIA + $T_STUDENT * sqrt($VARIANZA/100)" | bc -l)
INF=$(echo "$MEDIA - $T_STUDENT * sqrt($VARIANZA/100)" | bc -l)

echo "Media: $MEDIA"
echo "Varianza: $VARIANZA"
echo "Intervalo: [$INF , $SUP]"


