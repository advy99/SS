#include "sistema_inventario.h"
#include <cmath>
#include <iostream>


bool compare(const suc & s1, const suc & s2) {
	return s1.tiempo < s2.tiempo;
}


void SistemaInventario::insertar_lsuc(const Suceso suceso, const double tiempo) {
	suc nuevo_suceso;
	nuevo_suceso.suceso = suceso;
	nuevo_suceso.tiempo = tiempo;

	l_suc.push_back(nuevo_suceso);

	l_suc.sort(compare);

}

void SistemaInventario::demanda() {
	if ( nivel > 0 ) {
		acum_mas += ( reloj - t_ult_suc ) * nivel;
	} else {
		acum_menos += ( reloj - t_ult_suc ) * ( -nivel );
	}

	t_ult_suc = reloj;

	int tam = genera_tamano();

	nivel -= tam;

	insertar_lsuc(Suceso::SUCESO_DEMANDA, reloj + genera_demanda(0.1) );

}

void SistemaInventario::evaluacion() {
	if ( nivel < s_pequena && pedido == 0 ) {
		pedido = s_grande - nivel;
		acum_pedido += costo_hacer_pedido + costo_por_unidad * pedido;
		insertar_lsuc ( Suceso::SUCESO_LLEGADA_PEDIDO, reloj + genera_pedido(0.5, 1));
	}

	insertar_lsuc( Suceso::SUCESO_EVALUACION_INVENTARIO, reloj + 1);
}

void SistemaInventario::llega_pedido() {
	if ( nivel > 0 ) {
		acum_mas += (reloj - t_ult_suc) * nivel;
	} else {
		acum_menos += (reloj - t_ult_suc) * (-nivel);
	}

	t_ult_suc = reloj;
	nivel += pedido;
	pedido = 0;

}


double SistemaInventario::generador_exponencial(const double media) {
	double u;
	u = (double) random();
	u = u/(double)(RAND_MAX+1.0);

	return(-media*log(1-u));
}

double SistemaInventario::uniforme() {
	int t = random();

	double f = ((double)RAND_MAX+1.0);

	return (double)t/f;
}

double SistemaInventario::uniforme(const double superior, const double inferior) {
	return (inferior + (superior-inferior) * uniforme());
}

double SistemaInventario::genera_demanda(const double media) {
	return generador_exponencial(media);
}


int SistemaInventario::genera_tamano(){
	double num_aleatorio = uniforme();

	int resultado = 1;

	if ( num_aleatorio < 1.0/6.0) {
		resultado = 1;
	} else if (num_aleatorio < 3.0/6.0 ) {
		// 1/6 + 1/3 = 3/6
		resultado = 2;
	} else if ( num_aleatorio < 5.0/6.0) {
		// 3/6 + 1/3 = 5/6
		resultado = 3;
	} else {
		resultado = 4;
	}

	return resultado;

}

double SistemaInventario::genera_pedido(const double inferior, const double superior) {
	return uniforme(inferior, superior);
}

void SistemaInventario::suceso(const suc nodo) {
	if ( nodo.suceso == Suceso::SUCESO_DEMANDA) {
		demanda();
	} else if ( nodo.suceso == Suceso::SUCESO_EVALUACION_INVENTARIO) {
		evaluacion();
	} else if ( nodo.suceso == Suceso::SUCESO_LLEGADA_PEDIDO ) {
		llega_pedido();
	} else if ( nodo.suceso == Suceso::SUCESO_FIN_SIMULACION ) {
		fin_simulacion();
	}
}


void SistemaInventario::fin_simulacion() {
	parar = true;

	// multiplicamos por H y por PI acum_mas y acum_menos
	acum_mas *= H;
	acum_menos *= PI;

	std::vector<double> informe_ejecucion = { (acum_pedido + acum_mas + acum_menos) / reloj, acum_pedido / reloj, acum_mas / reloj, acum_menos / reloj};

	// si el informe esta vacio, es la primera ejecucion
	if ( informe.size() == 0) {
		informe = informe_ejecucion;
	} else {
		for ( unsigned i = 0; i < informe.size(); i++ ) {
			informe[i] += informe_ejecucion[i];
		}
	}

}


void SistemaInventario::genera_informe(const int num_simul) {

	std::vector<double> informe_media = informe;

	for (unsigned i = 0; i < informe_media.size(); i++) {
		informe_media[i] /= (double)num_simul;
	}

	std::cout << "Modificacion " << "\t"
			 	 << "Política" << "\t"
				 << "Costo total" << "\t"
				 << "Costo de pedido" << "\t"
				 << "Costo de mantenimiento" << "\t"
				 << "Costo de déficit" << std::endl;

	std::cout << modificacion << "\t"
				 << "(" << s_pequena << ", " << s_grande << ") \t";

	for (unsigned i = 0; i < informe_media.size(); i++) {
		informe_media[i] /= (double)num_simul;

		std::cout << informe_media[i] << "\t";
	}

	std::cout << std::endl;

}


void SistemaInventario::simula(const double t_final, const int nivel_inicial,
	 									 const int s_p, const int s_g, const int n_veces,
									 	 const int mod) {

	acum_mas = 0;
	acum_menos = 0;
	acum_pedido = 0;

	s_pequena = s_p;
	s_grande = s_g;

	informe.clear();

	modificacion = mod;

	for ( int i = 0; i < n_veces; i++ ) {
		nivel = nivel_inicial;
		pedido = 0;

		reloj = 0.0;
		t_ult_suc = reloj;

		// vaciamos la lista de sucesos
		while ( !l_suc.empty() ) {
			l_suc.pop_front();
		}

		insertar_lsuc(Suceso::SUCESO_FIN_SIMULACION, reloj + t_final);
		insertar_lsuc(Suceso::SUCESO_EVALUACION_INVENTARIO, reloj + 1);
		insertar_lsuc(Suceso::SUCESO_DEMANDA, reloj + genera_demanda(0.1));

		parar = false;

		// simulamos
		while ( !parar ){
			suc nodo = l_suc.front();
			l_suc.pop_front();

			reloj = nodo.tiempo;

			suceso(nodo);
		}
	}

	genera_informe(n_veces);

}
