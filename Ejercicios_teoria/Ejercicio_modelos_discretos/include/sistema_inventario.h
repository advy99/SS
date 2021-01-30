#ifndef SISTEMA_INVENTARIO
#define SISTEMA_INVENTARIO

#include <iostream>
#include <list>

enum class Suceso {SUCESO_DEMANDA, SUCESO_EVALUACION_INVENTARIO, SUCESO_LLEGADA_PEDIDO, SUCESO_FIN_SIMULACION};

typedef struct {
	Suceso suceso;
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

		// k
		int costo_hacer_pedido;
		// i
		int costo_por_unidad;

		int s_pequena;
		int s_grande;

		double reloj;
		bool parar;

		std::list<suc> l_suc;

		void demanda();
		void evaluacion();
		void llega_pedido();

		double generador_exponencial(const double media);
		double uniforme();
		// uniforme entre un rango
		double uniforme(const double superior, const double inferior);


		void insertar_lsuc(const Suceso suce, const double tiempo);

		double genera_demanda(const double media);
		int genera_tamano();

		double genera_pedido(const double inf, const double sup);
		void suceso(const suc nodo);
		void fin_simulacion();


	public:
		void simula(const double t_final, const int nivel_inicial, const int s_p, const int s_g);
};



#endif
