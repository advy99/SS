#ifndef GENERADORES_CONGRUENCIALES
#define GENERADORES_CONGRUENCIALES


const unsigned long int MULTIPLICADOR1 = 2061;
const unsigned long int MULTIPLICADOR2 = 2060;

const unsigned long int INCREMENTO = 4321;
const unsigned long int MODULO = 10000;

unsigned long int congruencia1_lineal_entera(unsigned long int & semilla);
unsigned long int congruencia2_lineal_entera(unsigned long int & semilla);

#endif


