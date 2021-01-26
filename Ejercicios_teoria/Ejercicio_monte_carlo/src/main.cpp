#include <iostream>
#include "planta_reciclaje.h"

int main(int argc, char ** argv) {

	if ( argc != 5 ) {
		std::cerr << "ERROR: \n"
					 << "Uso: " << argv[0] << " <num_dias> <kg_rojo> <kg_verde> <kg_reciclado_dia>"
					 << std::endl;
		exit(-1);
	}

	int num_dias = atoi(argv[1]);
	double kg_rojo = atof(argv[2]);
	double kg_verde = atof(argv[3]);
	double kg_reciclado_dia = atof(argv[4]);

	PlantaReciclaje planta(num_dias, kg_rojo, kg_verde, kg_reciclado_dia);

	planta.simular();

}
