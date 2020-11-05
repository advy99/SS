#ifndef GENERADORES_CONGRUENCIALES
#define GENERADORES_CONGRUENCIALES

#include <unordered_set>

const unsigned long int MULTIPLICADOR1 = 2061;
const unsigned long int MULTIPLICADOR2 = 2060;

const unsigned long int INCREMENTO = 4321;
const unsigned long int MODULO = 10000;

unsigned long int congruencia1_lineal_entera(unsigned long int & semilla);
unsigned long int congruencia2_lineal_entera(unsigned long int & semilla);

unsigned long int congruencia1_lineal_real(unsigned long int & semilla);
unsigned long int congruencia2_lineal_real(unsigned long int & semilla);

unsigned long int congruencia1_lineal_real_corregido(unsigned long int & semilla);
unsigned long int congruencia2_lineal_real_corregido(unsigned long int & semilla);

unsigned long int congruencia1_lineal_real_fmod(unsigned long int & semilla);
unsigned long int congruencia2_lineal_real_fmod(unsigned long int & semilla);

std::pair<int, int> obtener_longitud_generador(unsigned long int (*generador)(unsigned long int &) );


#endif


