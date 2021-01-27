#include "sistema_inventario.h"


void SistemaInventario::demanda() {
	if ( nivel > 0 ) {
		acum_mas += ( reloj - t_ult_suc ) * nivel;
	} else {
		acum_menos += ( reloj - t_ult_suc ) * ( -nivel );
	}

	t_ult_suc = reloj;

	tam = genera_tamano();

	nivel -= tam;

	insertar_lsuc(suc_demanda, reloj + gendem(0.1) );

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
