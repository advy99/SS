#include "generadores_congruenciales.h"
#include <set>
#include <cmath>

unsigned long int congruencia1_lineal_entera(unsigned long int & semilla) {
	semilla = (MULTIPLICADOR1 * semilla + INCREMENTO) % MODULO;

	return semilla;
}

unsigned long int congruencia2_lineal_entera(unsigned long int & semilla) {
	semilla = (MULTIPLICADOR2 * semilla + INCREMENTO) % MODULO;

	return semilla;
}


// Multiplicamos por 1.0 el modulo para que la operacion se haha como número
// real
unsigned long int congruencia1_lineal_real(unsigned long int & semilla) {

	double nuevo_valor = (MULTIPLICADOR1 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (nuevo_valor - (unsigned long int)nuevo_valor) * MODULO;


	return semilla;
}



unsigned long int congruencia2_lineal_real(unsigned long int & semilla) {

	double nuevo_valor = (MULTIPLICADOR2 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (nuevo_valor - (unsigned long int)nuevo_valor) * MODULO;


	return semilla;
}




unsigned long int congruencia1_lineal_real_corregido(unsigned long int & semilla) {

	double nuevo_valor = (MULTIPLICADOR1 * semilla + INCREMENTO) / (MODULO * 1.0);
	nuevo_valor = (nuevo_valor - (unsigned long int)nuevo_valor) * MODULO;
	semilla = (unsigned long int)(nuevo_valor + 0.5);


	return semilla;
}


unsigned long int congruencia2_lineal_real_corregido(unsigned long int & semilla) {

	double nuevo_valor = (MULTIPLICADOR2 * semilla + INCREMENTO) / (MODULO * 1.0);
	nuevo_valor = (nuevo_valor - (unsigned long int)nuevo_valor) * MODULO;
	semilla = (unsigned long int)(nuevo_valor + 0.5);


	return semilla;
}



unsigned long int congruencia1_lineal_real_fmod(unsigned long int & semilla) {
	semilla = fmod( ( MULTIPLICADOR1 * semilla + INCREMENTO ), (MODULO * 1.0 ) );

	return semilla;
}


unsigned long int congruencia2_lineal_real_fmod(unsigned long int & semilla) {
	semilla = fmod( ( MULTIPLICADOR2 * semilla + INCREMENTO ), (MODULO * 1.0 ) );

	return semilla;
}




std::pair<int, int> obtener_longitud_generador(unsigned long int (*generador)(unsigned long int &) ) {

	unsigned long int mayor_longitud = 0;

	unsigned long int i = 0;

	while (i < MODULO && mayor_longitud < MODULO) {

		unsigned long int semilla = i;
		std::unordered_set<unsigned long int> generados;
		generados.insert( semilla );

		unsigned long int nuevo_valor;
		unsigned int tam_anterior;

		bool encontrado_periodo = false;

		while ( !encontrado_periodo ) {
			nuevo_valor = generador(semilla);

			generados.insert(nuevo_valor);

			encontrado_periodo = tam_anterior == generados.size();

			tam_anterior = generados.size();

		}

		if ( mayor_longitud < generados.size() ) {
			mayor_longitud = generados.size();
		}

		i++;
	}

	return std::make_pair(mayor_longitud, i-1);

}




