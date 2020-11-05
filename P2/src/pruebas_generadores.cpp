#include <iostream>
#include <cmath>
#include "generadores_congruenciales.h"



int main () {

	unsigned long int semilla_entero = 0;
	long double semilla_real = 23;

	int longitud_generador1_enteros = obtener_longitud_generador(semilla_entero, congruencia1_lineal_entera);
	int longitud_generador2_enteros = obtener_longitud_generador(semilla_entero, congruencia2_lineal_entera);

	std::cout << "La longitud del generador 1 con enteros con semilla " << semilla_entero << " es de " << longitud_generador1_enteros << std::endl;
	std::cout << "La longitud del generador 2 con enteros con semilla " << semilla_entero << " es de " << longitud_generador2_enteros << std::endl;


	int longitud_generador1_reales_corregido = obtener_longitud_generador(semilla_real, congruencia1_lineal_real_corregido);
	int longitud_generador2_reales_corregido = obtener_longitud_generador(semilla_real, congruencia2_lineal_real_corregido);
	std::cout << "La longitud del generador 1 con reales corregido con semilla " << semilla_real << " es de " << longitud_generador1_reales_corregido << std::endl;
	std::cout << "La longitud del generador 2 con reales corregido con semilla " << semilla_real << " es de " << longitud_generador2_reales_corregido << std::endl;

	int longitud_generador1_fmod = obtener_longitud_generador(semilla_real, congruencia1_lineal_real_fmod);
	int longitud_generador2_fmod = obtener_longitud_generador(semilla_real, congruencia2_lineal_real_fmod);

	std::cout << "La longitud del generador 1 con reales fmod con semilla " << semilla_real << " es de " << longitud_generador1_fmod << std::endl;
	std::cout << "La longitud del generador 2 con reales fmod con semilla " << semilla_real << " es de " << longitud_generador2_fmod << std::endl;


	int longitud_generador1_reales = obtener_longitud_generador(semilla_real, congruencia1_lineal_real);
	int longitud_generador2_reales = obtener_longitud_generador(semilla_real, congruencia2_lineal_real);
	std::cout << "La longitud del generador 1 con reales con semilla " << semilla_real << " es de " << longitud_generador1_reales << std::endl;
	std::cout << "La longitud del generador 2 con reales con semilla " << semilla_real << " es de " << longitud_generador2_reales << std::endl;
	return 0;

}
