#include "SIR.h"

#include <iostream>



SIR::SIR(const int argc, const char ** argv){

	if ( argc != 10) {
		std::cerr << "Error: Número inesperado de argumentos." << std::endl
					 << "\t Uso: " << argv[0] << " <a> <b> <dt> <dcomunicacion> <tinic> <tfin> <I0> <S0> <R0> <f_paso>" << std::endl;
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

	std::string funcion_paso = std::string(argv[10]);

	if ( funcion_paso == "euler" ){
		puntero_funcion_paso = &SIR::one_step_euler;
	} else {
		puntero_funcion_paso = &SIR::one_step_runge_kutta;
	}

}



void SIR::integracion() {
	salida();

	estado_anterior = estado;

	one_step()
}



void SIR::simular() {
	do {
		integracion();
		t_actual += intervalo_calculo;
	} while ( t_actual < t_fin );
}


std::vector<double> SIR::one_step_runge_kutta(const std::vector<double> & estado){

	std::vector<double> resultado = estado;

	int tiempo = t_actual;
	for ( int j = 0; j < 4; j++ ){
		derivacion();

		for ( int k = 0; k < 2; k++ ){

		}

	}

	return resultado;
}

std::vector<double> SIR::derivacion(const std::vector<double> & estado){
	std::vector<double> resultado = estado;

	resultado[0] = capacidad_infeccion_enfermedad * estado[0] * estado[1] - tiempo_duracion_infeccion * estado[0];
	resultado[1] = - capacidad_infeccion_enfermedad * estado[0] * estado[1];
	resultado[2] = tiempo_duracion_infeccion * estado[0];

	return resultado;
}


std::istream & operator >> ( std::istream & is, SIR & modelo ){

	is >> modelo.capacidad_infeccion_enfermedad;
	is >> modelo.tiempo_duracion_infeccion;
	is >> modelo.intervalo_calculo;
 	is >> modelo.intervalo_comunicacion;
 	is >> modelo.t_inicio;
 	is >> modelo.t_fin;
 	is >> modelo.estado_inicial.infectados;
 	is >> modelo.estado_inicial.supceptibles;
 	is >> modelo.estado_inicial.recuperados;

	modelo.estados.clear();

	modelo.estados.push_back(modelo.estado_inicial);

	return is;

}

