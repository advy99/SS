#include "planta_reciclaje.h"

#include <iostream>
#include <cmath>
#include <algorithm>


PlantaReciclaje::PlantaReciclaje(const double papel_dia, const double T_ROJO,
											const double T_VERDE, const double KG_RECICLAR)
											:MAX_ROJO(T_ROJO), MAX_VERDE(T_VERDE),
											KG_NECESARIOS_RECICLAR_1KG(KG_RECICLAR) {
	dias_simulacion = 0;
	dia_actual = 0;

	contenedor_rojo = 300;
	contenedor_verde = 0;

	papel_recicla_dia = papel_dia;

}





// generar un número aleatorio uniforme en el
// intervalo [0,1)
double PlantaReciclaje::uniforme() {
	int t = random();

	double f = ((double)RAND_MAX+1.0);

	return (double)t/f;
}


void PlantaReciclaje::procesar_papel(const double kg_reciclar){

	double papel_reciclado = kg_reciclar / KG_NECESARIOS_RECICLAR_1KG;

	if ( contenedor_verde + papel_reciclado > MAX_VERDE ) {
		if ( avisos ){
			std::cerr << "AVISO: El contenedor VERDE no tiene capacidad suficiente. \n"
						 << "\t Dia: " << dia_actual << ". Capacidad contenedor verde: "
						 << MAX_VERDE << ". Intentando tamaño total de: " << contenedor_verde + papel_reciclado << std::endl;
		}

		papel_reciclado_perdido += contenedor_verde + papel_reciclado - MAX_VERDE;
	}

	// sumamos el papel reciclado, teniendo en cuenta que no nos podemos
	// pasar del máximo
	contenedor_verde = std::min(MAX_VERDE, contenedor_verde + papel_reciclado);

}



void PlantaReciclaje::almacenar_nuevo_papel_usado() {
	double papel_usado_recibido = 150;

	double num_uniforme = uniforme();

	const double INCREMENTO_PAPEL = 50.0;
	const double PROB_SIGUIENTE_NIVEL = 1.0/6.0;

	while ( num_uniforme > PROB_SIGUIENTE_NIVEL ) {
		papel_usado_recibido += INCREMENTO_PAPEL;
		num_uniforme -= PROB_SIGUIENTE_NIVEL;
	}

	if ( contenedor_rojo + papel_usado_recibido > MAX_ROJO ) {
		if ( avisos ){
			std::cerr << "AVISO: El contenedor ROJO no tiene capacidad suficiente. \n"
						 << "\t Dia: " << dia_actual << ". Capacidad contenedor rojo: "
						 << MAX_ROJO << ". Intentando tamaño total de: " << contenedor_rojo + papel_usado_recibido << std::endl;
		}

		papel_sin_reciclar_perdido += contenedor_rojo + papel_usado_recibido - MAX_ROJO;
	}

	// actualizamos el contador de papel utilizado
	contenedor_rojo = std::min(MAX_ROJO, contenedor_rojo + papel_usado_recibido);
}



void PlantaReciclaje::vender_papel_reciclado(){
	double papel_vendido = 30;

	double num_uniforme = uniforme();

	const double INCREMENTO_PAPEL = 30.0;
	const double PROB_SIGUIENTE_NIVEL = 1.0/6.0;

	while ( num_uniforme > PROB_SIGUIENTE_NIVEL ) {
		papel_vendido += INCREMENTO_PAPEL;
		num_uniforme -= PROB_SIGUIENTE_NIVEL;
	}

	if ( papel_vendido > contenedor_verde ) {
		falta_papel_reciclado_vender += papel_vendido - contenedor_verde;
		papel_vendido = contenedor_verde;
	}

	papel_total_vendido += papel_vendido;

	// actualizamos el contenedor_verde, que se queda a 0 como mínimo
	contenedor_verde -= papel_vendido;


}


void PlantaReciclaje::procesar_manana(){
	// el papel a procesar en el día es el minimo entre lo que se procesa al día
	// y lo que hay en el contenedor rojo
	// (si se procesan 300, pero el contenedor solo tiene 100, solo procesamos 100)
	double a_procesar = std::min(papel_recicla_dia, contenedor_rojo);

	// le quitamos al contenedor rojo lo que vamos a procesar
	contenedor_rojo -= a_procesar;

	procesar_papel(a_procesar);

}

void PlantaReciclaje::procesar_tarde(){

	almacenar_nuevo_papel_usado();

	vender_papel_reciclado();

}


void PlantaReciclaje::simular(const bool mensajes_aviso, const bool con_info,
										const int c_rojo, const int c_verde, const int num_dias) {
	dia_actual = 0;
	papel_total_vendido = 0.0;
	papel_sin_reciclar_perdido = 0.0;
	papel_reciclado_perdido = 0.0;
	falta_papel_reciclado_vender = 0.0;

	contenedor_rojo = c_rojo;
	contenedor_verde = c_verde;
	avisos = mensajes_aviso;

	bool salida_info = con_info;

	for (dia_actual = 0; dia_actual < num_dias; dia_actual++){
		procesar_manana();
		procesar_tarde();

		if ( salida_info ) {
			std::cout << (*this);
		}
	}

}

double PlantaReciclaje::vendido() {
	return papel_total_vendido;
}

double PlantaReciclaje::falta_reciclado() {
	return falta_papel_reciclado_vender;
}

double PlantaReciclaje::reciclado_perdido() {
	return papel_reciclado_perdido;
}

double PlantaReciclaje::usado_perdido() {
	return papel_sin_reciclar_perdido;
}



std::ostream & operator << (std::ostream & os, const PlantaReciclaje & planta) {

	os << planta.dia_actual << "\t" << planta.contenedor_rojo << "\t" << planta.contenedor_verde
		<< "\t" << planta.papel_sin_reciclar_perdido << "\t" << planta.papel_reciclado_perdido
		<< "\t" << planta.falta_papel_reciclado_vender << std::endl;

	return os;
}
