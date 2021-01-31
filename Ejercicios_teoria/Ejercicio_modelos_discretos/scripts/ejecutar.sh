#!/bin/bash

NUM_VECES=10000


for mod in $(seq 0 2); do
	../bin/main_inventario $NUM_VECES $mod
done
