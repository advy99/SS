#include <iostream>
#include "sistema_inventario.h"



int main(int argc, char ** argv) {

	if ( argc != 3 ) {
		std::cerr << "ERROR: Número erroneo de parámetros" << std::endl
					 << "\tUso: " << argv[0] << " <n_simulaciones> <mod>";
		exit(-1);
	}

	int n_veces = atoi(argv[1]);
	int mod = atoi(argv[2]);

	double nivel_inicial = 60.0;
	double tiempo_ej = 120;

	SistemaInventario sistema;

	for ( unsigned i = 0; i <= 60; i += 20 ) {
		for ( unsigned j = 40; j <= 100; j += 20) {
			if ( j > i) {
				sistema.simula(tiempo_ej, nivel_inicial, i, j, n_veces, mod);
			}
		}
	}


}
