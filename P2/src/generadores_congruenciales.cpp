#include "generadores_congruenciales.h"
#include <cmath>

unsigned long int congruencia1_lineal_entera(unsigned long int & semilla) {
	semilla = (MULTIPLICADOR1 * semilla + INCREMENTO) % MODULO;

	return semilla;
}

unsigned long int congruencia2_lineal_entera(unsigned long int & semilla) {
	semilla = (MULTIPLICADOR2 * semilla + INCREMENTO) % MODULO;

	return semilla;
}

long double congruencia1_lineal_real(long double & semilla) {

	semilla = (MULTIPLICADOR1 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (semilla - (unsigned long int)semilla) * MODULO;


	return semilla;
}



long double congruencia2_lineal_real(long double & semilla) {

	semilla = (MULTIPLICADOR2 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (semilla - (unsigned long int)semilla) * MODULO;


	return semilla;
}




long double congruencia1_lineal_real_corregido(long double & semilla) {

	semilla = (MULTIPLICADOR1 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (semilla - (unsigned long int)semilla) * MODULO;
	semilla = (unsigned long int)(semilla + 0.5);


	return semilla;
}


long double congruencia2_lineal_real_corregido(long double & semilla) {

	semilla = (MULTIPLICADOR2 * semilla + INCREMENTO) / (MODULO * 1.0);
	semilla = (semilla - (unsigned long int)semilla) * MODULO;
	semilla = (unsigned long int)(semilla + 0.5);


	return semilla;
}



long double congruencia1_lineal_real_fmod(long double & semilla) {
	semilla = fmod( ( MULTIPLICADOR1 * semilla + INCREMENTO ), MODULO );

	return semilla;
}


long double congruencia2_lineal_real_fmod(long double & semilla) {
	semilla = fmod( ( MULTIPLICADOR2 * semilla + INCREMENTO ), MODULO );

	return semilla;
}




