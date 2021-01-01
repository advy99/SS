#include "SIR.h"

#include <iostream>



SIR::SIR(const int argc,  char ** argv){

	if ( argc != 11) {
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

	estado.resize(NUM_EQ);

 	estado[0] = atof(argv[7]);
 	estado[1] = atof(argv[8]);
 	estado[2] = atof(argv[9]);

	std::string funcion_paso = std::string(argv[10]);

	if ( funcion_paso == "euler" ){
		puntero_funcion_paso = &SIR::one_step_euler;
	} else {
		puntero_funcion_paso = &SIR::one_step_runge_kutta;
	}

}



void SIR::integracion() {

	std::cout << (*this);

	estado = (*puntero_funcion_paso)(estado, t_actual, intervalo_calculo);

}



void SIR::simular() {
	do {
		integracion();
		t_actual += intervalo_calculo;
	} while ( t_actual < t_fin );
}


std::vector<double> SIR::one_step_runge_kutta(const std::vector<double> & estado, const double tiempo_act, const double interv_calculo){

	std::vector<double> resultado = estado;
	std::vector<double> derivadas;

	// tamaño = NUM_EQ, en este caso 3
	std::vector<std::vector<double> > matriz_k(NUM_EQ);

	double incremento;
	int tiempo = tiempo_act;

	// y cada fila tiene tamaño 4
	// haciendo la matriz 3x4
	for (unsigned i = 0; i < matriz_k.size(); i++){
		matriz_k[i].resize(NUM_EQ);
	}

	for ( int j = 0; j < 4; j++ ){
		derivadas = derivacion(resultado);

		for ( int k = 0; k < NUM_EQ; k++ ){
			matriz_k[k][j] = derivadas[j];
		}

		if ( j < 2 ){
			incremento = interv_calculo / 2.0;
		} else {
			incremento = interv_calculo;
		}

		tiempo = tiempo_act + incremento;

		for ( int i = 0; i < NUM_EQ; i++ ){
			resultado[i] = estado[i] + interv_calculo / 6 * (matriz_k[i][0] + 2 * matriz_k[i][1] + 2 * matriz_k[i][2] + matriz_k[i][3]);
		}

	}

	return resultado;
}

std::vector<double> SIR::one_step_euler(const std::vector<double> & estado, const double tiempo, const double interv_calculo){
	std::vector<double> resultado(NUM_EQ);
	std::vector<double> derivadas = derivacion(estado);

	for ( int i = 0; i < NUM_EQ; i++ ) {
		resultado[i] = estado[i] + interv_calculo * derivadas[i];
	}

	return resultado;
}

std::vector<double> SIR::derivacion(const std::vector<double> & estado){
	std::vector<double> resultado = estado;

	resultado[0] = capacidad_infeccion_enfermedad * estado[0] * estado[1] - tiempo_duracion_infeccion * estado[0];
	resultado[1] = -capacidad_infeccion_enfermedad * estado[0] * estado[1];
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
 	is >> modelo.estado[0];
 	is >> modelo.estado[1];
 	is >> modelo.estado[2];

	return is;

}


std::ostream & operator << ( std::ostream & os, const SIR & modelo ){

	os << "# Infectados \t Supceptibles \t Recuperados" << std::endl;

	for ( int i = 0; i < SIR::NUM_EQ; i++ ){
		os << modelo.estado[i] << "\t";
	}

	os << std::endl;

	return os;
}


double SIR::capacidad_infeccion_enfermedad;
double SIR::tiempo_duracion_infeccion;

