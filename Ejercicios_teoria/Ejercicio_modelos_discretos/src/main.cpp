#include <iostream>
#include "sistema_inventario.h"
#include <limits>


int main(int argc, char ** argv) {

	if ( argc != 3 ) {
		std::cerr << "ERROR: Número erroneo de parámetros\n"
					 << "\tUso: " << argv[0] << " <n_simulaciones> <mod>\n"
					 << "\t Valores de <mod>:\n"
					 << "\t\t 0 - Sistema original\n"
					 << "\t\t 1 - Política de pedidos: Pedir demanda mes anterior\n"
					 << "\t\t 2 - Política de pedidos: Pedidos dinámicos"
					 << std::endl;
		exit(-1);
	}

	int n_veces = atoi(argv[1]);
	int mod = atoi(argv[2]);


	if ( mod < 0 || mod > 2) {
		std::cerr << "Modificación incorrecta:\n"
					 << "\t Valores de <mod>:\n"
					 << "\t\t 0 - Sistema original\n"
					 << "\t\t 1 - Política de pedidos: Pedir demanda mes anterior\n"
					 << "\t\t 2 - Política de pedidos: Pedidos dinámicos"
					 << std::endl;
		exit(-2);
	}

	std::pair<double, std::pair<unsigned, unsigned> > mejor_politica;

	double costo_total = std::numeric_limits<double>::infinity();

	mejor_politica.first = costo_total;

	double nivel_inicial = 60.0;
	double tiempo_ej = 120;

	SistemaInventario sistema;

	for ( unsigned i = 0; i <= 60; i += 20 ) {
		for ( unsigned j = 40; j <= 100; j += 20) {
			if ( j > i) {
				costo_total = sistema.simula(tiempo_ej, nivel_inicial, i, j, n_veces, mod);

				if ( costo_total < mejor_politica.first) {
					mejor_politica.first = costo_total;
					mejor_politica.second.first = i;
					mejor_politica.second.second = j;
				}

			}
		}
	}

	std::cout << "La mejor politica con la modificación " << mod
				 << " es la política: (" << mejor_politica.second.first << ", "
				 << mejor_politica.second.second << ") con un costo total de "
				 << mejor_politica.first << std::endl;

}
