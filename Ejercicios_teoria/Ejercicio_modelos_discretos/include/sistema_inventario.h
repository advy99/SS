#ifndef SISTEMA_INVENTARIO
#define SISTEMA_INVENTARIO

#include <iostream>
#include <list>

typedef struct {
	int tipo;
	float tiempo;
} registro;

typedef struct {
	int suceso;
	float tiempo;
	registro reg_cola;
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


	public:
		void simula();
};



#endif
