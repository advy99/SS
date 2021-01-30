#ifndef SISTEMA_INVENTARIO
#define SISTEMA_INVENTARIO

#include <iostream>
#include <list>

#define SUCESO_DEMANDA 0
#define SUCESO_EVALUACION_INVENTARIO 1
#define SUCESO_LLEGADA_PEDIDO 2
#define SUCESO_FIN_SIMULACION 3

typedef struct {
	int suceso;
	double tiempo;
} suc;

class SistemaInventario {
	private:
		int nivel;
		int pedido;
		int t_ult_suc;

		int acum_mas;
		int acum_menos;
		int acum_pedido;

		double reloj;

		std::list<suc> l_suc;

		void demanda();
		void evaluacion();
		void llegapedido();

		double generador_exponencial(const double media);
		double uniforme();


	public:
		void simula();
};



#endif
