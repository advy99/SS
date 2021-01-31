#include <iostream>
#include "sistema_inventario.h"



int main(int argc, char ** argv) {

	if ( argc != 5 ) {
		std::cerr << "ERROR: Número erroneo de parámetros" << std::endl
					 << "\tUso: " << argv[0] << " <s> <S> <n_simulaciones> <mod>";
	}



	int nivel_inicial = 60;
	double tiempo_ej = 120;

	SistemaInventario sistema;

	for ( unsigned i = 0; i <= 60; i += 20 ) {
		for ( unsigned j = 40; j <= 100; j += 20) {
			sistema.simula(tiempo_ej, nivel_inicial, i, j, 10000, 0);
		}
	}


}
