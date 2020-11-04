#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include "codigo_generadores.h"
#include <iostream>

//Genera un número uniformemente distribuido en el
//intervalo [0,1) a partir de uno de los generadores
//disponibles en C. Lo utiliza el generador de demanda
double uniforme() {
	int t = random();
	double f = ((double)RAND_MAX+1.0);
	return (double)t/f;
}



//Construye la tabla de búsqueda de
//tamaño n para la distribución de
//la demanda del apartado (a).
double * construye_prop_a(int n) {
	int i;
	double * temp = new double[n];

	if ( temp == nullptr ) {
		std::cerr << "Error reservando memoria para generador uniforme" << std::endl;

		exit(1);
	}

	temp[0] = 1.0/n;

	for (i=1;i<n;i++)
		temp[i] = temp[i-1]+1.0/n;

	return temp;
}


//Construye la tabla de búsqueda de
//tamaño n para la distribución de
//la demanda del apartado (b).

double * construye_prop_b(int n) {
	int i, max;
	double * temp = new double[n];

	if ( temp == nullptr ) {
		std::cerr << "Error reservando memoria para generador uniforme" << std::endl;

		exit(1);
	}

	max = (n/2)*(n+1);
	temp[0] = n*1.0/max;

	for (i=1;i<n;i++)
		temp[i] = temp[i-1]+(double)(n-i)/max;

	return temp;
}



//Construye la tabla de búsqueda de
//tamaño n para la distribución de
//la demanda del apartado (c).
double * construye_prop_c(int n) {
	int i, max;
	double * temp = new double[n];

	if ( temp == nullptr ) {
		std::cerr << "Error reservando memoria para generador uniforme" << std::endl;

		exit(1);
	}

	max = n*n/4;
	temp[0] = 0.0;

	for ( i =1; i < (n/2); i++)
		temp[i] = temp[i-1] + (double)i/max;

	for (i = (n/2); i < n; i++)
		temp[i] = temp[i-1] + (double)(n-i)/max;

	return temp;
}



tabla_demanda * construye_prop_c_ordenada ( int n ) {
	int i, max;
	tabla_demanda * temp = new tabla_demanda[n];

	if ( temp == nullptr ) {
		std::cerr << "Error reservando memoria para generador uniforme" << std::endl;

		exit(1);
	}

	max = n*n/4;

	int valor_medio = n / 2;

	int iterador = 0;
	temp[iterador].posicion = valor_medio;
	temp[iterador].prob_acumulada = (double)valor_medio / max;
	iterador++;


	for ( i = valor_medio - 1; i > 0; i-- ) {
		double probabilidad = (double)i / max;

		temp[iterador].posicion = i;
		temp[iterador].prob_acumulada = temp[iterador - 1].prob_acumulada + probabilidad;
		iterador++;


		temp[iterador].posicion = valor_medio + (valor_medio - i);
		temp[iterador].prob_acumulada = temp[iterador - 1].prob_acumulada + probabilidad;
		iterador++;

	}

	if ( n % 2 == 0 ) {
		double probabilidad = (double)0.0 / max;
		temp[iterador].posicion = 0;
		temp[iterador].prob_acumulada = temp[iterador - 1].prob_acumulada + probabilidad;
	}


	return temp;

}



// Genera un valor de la
// distribución de la demanda codificada en tabla, por el
// método de tablas de búsqueda.
// tama es el tamaño de la tabla, 100 en nuestro caso particular
int genera_demanda(double * tabla, int tama) {
	int i;
	double u = uniforme();
	i = 0;

	while((i<tama) && (u>=tabla[i]))
		i++;

	return i;
}

int genera_demanda_a_mejorado(int tama) {
	double u = uniforme();
	return u * tama;
}

int genera_demanda(tabla_demanda * tabla, int tama) {
	int i;
	double u = uniforme();
	i = 0;

	while((i<tama) && (u>=tabla[i].prob_acumulada))
		i++;

	return tabla[i].posicion;
}


// Genera un valor de la
// distribución de la demanda codificada en tabla, por el
// método de tablas de búsqueda.
// tama es el tamaño de la tabla, 100 en nuestro caso particular
int genera_demanda_busqueda_binaria(double * tabla, int tama) {
	int i;
	double u = uniforme();
	int limite_superior = tama;
	int limite_inferior = 0;

	bool encontrado = false;


	while ( !encontrado ) {
		i = (limite_superior + limite_inferior) / 2;

		if ( u < tabla[i] ) {
			if ( i == 1 ) {
				encontrado = true;
			} else if (tabla[ i - 1 ] <= u) {
				encontrado = true;
			} else {
				limite_superior = i - 1;
			}
		} else {
			limite_inferior = i + 1;
		}


	}

	return i;
}

