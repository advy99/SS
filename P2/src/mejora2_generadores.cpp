#include <iostream>
#include <chrono>
#include "codigo_generadores.h"



int main(int argc, char ** argv) {

	if ( argc != 2 ) {
		std::cerr << "Error - Uso: " << argv[0] << " <num_demandas> " << std::endl;
		exit(-1);
	}

	int repeticiones = atoi(argv[1]);

	double * tabla_a = construye_prop_a(100);
	double * tabla_b = construye_prop_b(100);
	double * tabla_c = construye_prop_c(100);
	int basura;

	auto start = std::chrono::steady_clock::now();

	for (int i = 0; i < repeticiones; i++){
		basura = genera_demanda(tabla_a, 100);
	}

	auto end = std::chrono::steady_clock::now();



	std::chrono::duration<double> t_original_a = end - start;


	start = std::chrono::steady_clock::now();

	for (int i = 0; i < repeticiones; i++){
		basura = genera_demanda_busqueda_binaria(tabla_a, 100);
	}

	end = std::chrono::steady_clock::now();



	std::chrono::duration<double> t_bb_a = end - start;


	start = std::chrono::steady_clock::now();

	for (int i = 0; i < repeticiones; i++){
		basura = genera_demanda(tabla_b, 100);
	}

	end = std::chrono::steady_clock::now();



	std::chrono::duration<double> t_original_b = end - start;


	start = std::chrono::steady_clock::now();

	for (int i = 0; i < repeticiones; i++){
		basura = genera_demanda_busqueda_binaria(tabla_b, 100);
	}

	end = std::chrono::steady_clock::now();



	std::chrono::duration<double> t_bb_b = end - start;



	start = std::chrono::steady_clock::now();

	for (int i = 0; i < repeticiones; i++){
		basura = genera_demanda(tabla_c, 100);
	}

	end = std::chrono::steady_clock::now();



	std::chrono::duration<double> t_original_c = end - start;


	start = std::chrono::steady_clock::now();

	for (int i = 0; i < repeticiones; i++){
		basura = genera_demanda_busqueda_binaria(tabla_c, 100);
	}

	end = std::chrono::steady_clock::now();



	std::chrono::duration<double> t_bb_c = end - start;


	std::cout << repeticiones << "\t" << t_original_a.count() << "\t" << t_bb_a.count();
	std::cout << "\t" << t_original_b.count() << "\t" << t_bb_b.count();
	std::cout << "\t" << t_original_c.count() << "\t" << t_bb_c.count() << std::endl;

	delete [] tabla_a;
	delete [] tabla_b;
	delete [] tabla_c;


	return 0;
}
