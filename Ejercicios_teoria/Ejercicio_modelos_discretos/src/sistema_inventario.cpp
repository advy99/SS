#include "sistema_inventario.h"
#include <cmath>

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
		acum_pedido += k + i * pedido;
		insertar_lsuc ( suc_llega_pedido, reloj + gen_pedido(0.5, 1));
	}

	insertar_lsuc( suc_evaluacion, reloj + 1);
}

void SistemaInventario::llegapedido() {
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
