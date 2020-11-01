#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include "codigo_generadores.h"
#include <iostream>

//Genera un n�mero uniformemente distribuido en el
//intervalo [0,1) a partir de uno de los generadores
//disponibles en C. Lo utiliza el generador de demanda
double uniforme() {
	int t = random();
	double f = ((double)RAND_MAX+1.0);
	return (double)t/f;
}



//Construye la tabla de b�squeda de
//tama�o n para la distribuci�n de
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


//Construye la tabla de b�squeda de
//tama�o n para la distribuci�n de
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



//Construye la tabla de b�squeda de
//tama�o n para la distribuci�n de
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




// Genera un valor de la
// distribuci�n de la demanda codificada en tabla, por el
// m�todo de tablas de b�squeda.
// tama es el tama�o de la tabla, 100 en nuestro caso particular
int genera_demanda(double * tabla, int tama) {
	int i;
	double u = uniforme();
	i = 0;

	while((i<tama) && (u>=tabla[i]))
		i++;

	return i;
}
