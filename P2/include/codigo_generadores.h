#ifndef CODGEN
#define CODGEN

struct tabla_demanda {
	int posicion;
	double prob_acumulada;
};

double uniforme();
double* construye_prop_a(int n);
double* construye_prop_b(int n);
double* construye_prop_c(int n);
tabla_demanda * construye_prop_c_ordenada(int n);
int genera_demanda(double* tabla, int tama);
int genera_demanda(tabla_demanda * tabla, int tama);
int genera_demanda_a_mejorado(int tama);
int genera_demanda_busqueda_binaria(double * tabla, int tama);

#endif

