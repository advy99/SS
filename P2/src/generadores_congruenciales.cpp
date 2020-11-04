#include "generadores_congruenciales.h"

unsigned long int congruencia1_lineal_entera(unsigned long int & semilla) {
	semilla = (MULTIPLICADOR1 * semilla + INCREMENTO) % MODULO;

	return semilla;
}

unsigned long int congruencia2_lineal_entera(unsigned long int & semilla) {
	semilla = (MULTIPLICADOR2 * semilla + INCREMENTO) % MODULO;

	return semilla;
}

