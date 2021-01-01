#include "SIR.h"

#include <iostream>



SIR::SIR(const int argc, const char ** argv){

	if ( argc != 10) {
		std::cerr << "Error: Número inesperado de argumentos." << std::endl
					 << "\t Uso: " << argv[0] << " <a> <b> <dt> <dcomunicacion> <tinic> <tfin> <I0> <S0> <R0>" << std::endl;
		exit(-1);
	}

	capacidad_infeccion_enfermedad = atof(argv[1]);
	tiempo_duracion_infeccion = atof(argv[2]);
	intervalo_calculo = atof(argv[3]);
 	intervalo_comunicacion = atof(argv[4]);
 	t_inicio = atof(argv[5]);
 	t_fin = atof(argv[6]);
 	estado_inicial.infectados = atoi(argv[7]);
 	estado_inicial.supceptibles = atoi(argv[8]);
 	estado_inicial.recuperados = atoi(argv[9]);

	estados.push_back(estado_inicial);

}

