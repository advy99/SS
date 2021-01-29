#include <iostream>
#include "planta_reciclaje.h"

int main(int argc, char ** argv) {

	if ( argc != 6 ) {
		std::cerr << "ERROR: \n"
					 << "Uso: " << argv[0] << " <num_dias> <kg_rojo> <kg_verde> <kg_reciclado_dia> <n_veces>"
					 << std::endl;
		exit(-1);
	}

	int num_dias = atoi(argv[1]);
	double kg_rojo = atof(argv[2]);
	double kg_verde = atof(argv[3]);
	double kg_reciclado_dia = atof(argv[4]);

	int n_veces = atoi(argv[5]);

	PlantaReciclaje planta( kg_reciclado_dia);

	double media_papel_vendido = 0.0;
	double media_papel_reciclado_perdido = 0.0;
	double media_papel_usado_perdido = 0.0;
	double media_falta_papel_reciclado = 0.0;

	// ponemos la semilla del generador a un número aleatorio
	srand(time(NULL));

	for ( int i = 0; i < n_veces; i++ ) {
		// al simular le pasamos la cantidad inicial de cada contenedor
		planta.simular(false, false, kg_rojo, kg_verde, num_dias);

		media_papel_vendido += planta.vendido();
		media_papel_reciclado_perdido += planta.reciclado_perdido();
		media_papel_usado_perdido += planta.usado_perdido();
		media_falta_papel_reciclado += planta.falta_reciclado();
	}

	media_papel_vendido /= n_veces;
	media_papel_reciclado_perdido /= n_veces;
	media_papel_usado_perdido /= n_veces;
	media_falta_papel_reciclado /= n_veces;


	std::cout << "Media de papel vendido: " << media_papel_vendido << std::endl
				 << "Media de papel reciclado perdido (falta espacio en verde): " << media_papel_reciclado_perdido << std::endl
				 << "Media falta de papel usado perdido (falta espacio en rojo): " << media_papel_usado_perdido << std::endl
				 << "Media falta de papel reciclado (falta papel reciclado para vender): " << media_falta_papel_reciclado << std::endl;


}
