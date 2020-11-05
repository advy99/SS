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

unsigned long int congruencia1_lineal_real(unsigned long int & semilla) {

	semilla = (MULTIPLICADOR1 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (semilla - (unsigned long int)semilla) * MODULO;


	return semilla;
}



unsigned long int congruencia2_lineal_real(unsigned long int & semilla) {

	semilla = (MULTIPLICADOR2 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (semilla - (unsigned long int)semilla) * MODULO;


	return semilla;
}




unsigned long int congruencia1_lineal_real_corregido(unsigned long int & semilla) {

	semilla = (MULTIPLICADOR1 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (semilla - (unsigned long int)semilla) * MODULO;
	semilla = (unsigned long int)(semilla + 0.5);


	return semilla;
}


unsigned long int congruencia2_lineal_real_corregido(unsigned long int & semilla) {

	semilla = (MULTIPLICADOR2 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (semilla - (unsigned long int)semilla) * MODULO;
	semilla = (unsigned long int)(semilla + 0.5);


	return semilla;
}



unsigned long int congruencia1_lineal_real_fmod(unsigned long int & semilla) {
	semilla = fmod( ( MULTIPLICADOR1 * semilla + INCREMENTO ), MODULO );

	return semilla;
}


unsigned long int congruencia2_lineal_real_fmod(unsigned long int & semilla) {
	semilla = fmod( ( MULTIPLICADOR2 * semilla + INCREMENTO ), MODULO );

	return semilla;
}




int obtener_longitud_generador(unsigned long int semilla, unsigned long int (*generador)(unsigned long int &) ) {

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


	return generados.size();

}




