#include <iostream>
#include <cmath>
#include "generadores_congruenciales.h"



int main () {

	std::pair<int, int> longitud_generador1_enteros = obtener_longitud_generador(congruencia1_lineal_entera);
	std::pair<int, int> longitud_generador2_enteros = obtener_longitud_generador(congruencia2_lineal_entera);


	std::cout << "Con el generador congruencial de enteros con multiplicador 2061 se ha encontrado la máxima secuencia con la semilla " << longitud_generador1_enteros.second << " y tiene una longitud de " << longitud_generador1_enteros.first << " numeros " << std::endl;

	std::cout << "Con el generador congruencial de enteros con multiplicador 2060 se ha encontrado la máxima secuencia con la semilla " << longitud_generador2_enteros.second << " y tiene una longitud de " << longitud_generador2_enteros.first << " numeros " << std::endl;



	std::pair<int, int> longitud_generador1_reales = obtener_longitud_generador(congruencia1_lineal_real);
	std::pair<int, int> longitud_generador2_reales = obtener_longitud_generador(congruencia2_lineal_real);


	std::cout << "Con el generador congruencial de reales con multiplicador 2061 se ha encontrado la máxima secuencia con la semilla " << longitud_generador1_reales.second << " y tiene una longitud de " << longitud_generador1_reales.first << " numeros " << std::endl;

	std::cout << "Con el generador congruencial de reales con multiplicador 2060 se ha encontrado la máxima secuencia con la semilla " << longitud_generador2_reales.second << " y tiene una longitud de " << longitud_generador2_reales.first << " numeros " << std::endl;

	std::pair<int, int> longitud_generador1_reales_corregido = obtener_longitud_generador(congruencia1_lineal_real_corregido);
	std::pair<int, int> longitud_generador2_reales_corregido = obtener_longitud_generador(congruencia2_lineal_real_corregido);


	std::cout << "Con el generador congruencial de reales corregido con multiplicador 2061 se ha encontrado la máxima secuencia con la semilla " << longitud_generador1_reales_corregido.second << " y tiene una longitud de " << longitud_generador1_reales_corregido.first << " numeros " << std::endl;

	std::cout << "Con el generador congruencial de reales corregido con multiplicador 2060 se ha encontrado la máxima secuencia con la semilla " << longitud_generador2_reales_corregido.second << " y tiene una longitud de " << longitud_generador2_reales_corregido.first << " numeros " << std::endl;

	std::pair<int, int> longitud_generador1_fmod = obtener_longitud_generador(congruencia1_lineal_real_fmod);
	std::pair<int, int> longitud_generador2_fmod = obtener_longitud_generador(congruencia2_lineal_real_fmod);

	std::cout << "Con el generador congruencial de reales fmod con multiplicador 2061 se ha encontrado la máxima secuencia con la semilla " << longitud_generador1_fmod.second << " y tiene una longitud de " << longitud_generador1_fmod.first << " numeros " << std::endl;


	std::cout << "Con el generador congruencial de reales fmod con multiplicador 2060 se ha encontrado la máxima secuencia con la semilla " << longitud_generador2_fmod.second << " y tiene una longitud de " << longitud_generador2_fmod.first << " numeros " << std::endl;

	return 0;

}
