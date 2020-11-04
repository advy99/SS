#include <iostream>
#include <chrono>
#include "codigo_generadores.h"



int main(int argc, char ** argv) {

	if ( argc != 2 ) {
		std::cerr << "Error - Uso: " << argv[0] << " <num_demandas> " << std::endl;
		exit(-1);
	}

	int repeticiones = atoi(argv[1]);

	double * tabla = construye_prop_a(100);
	int basura;

	auto start = std::chrono::steady_clock::now();

	for (int i = 0; i < repeticiones; i++){
		basura = genera_demanda(tabla, 100);
	}

	auto end = std::chrono::steady_clock::now();



	std::chrono::duration<double> t_original = end - start;


	start = std::chrono::steady_clock::now();

	for (int i = 0; i < repeticiones; i++){
		basura = genera_demanda_a_mejorado(100);
	}

	end = std::chrono::steady_clock::now();



	std::chrono::duration<double> t_modificado = end - start;

	std::cout << repeticiones << "\t" << t_original.count() << "\t" << t_modificado.count() << std::endl;

	delete [] tabla;


	return 0;
}
