#ifndef SISTEMA_INVENTARIO
#define SISTEMA_INVENTARIO

#include <list>
#include <vector>

enum class Suceso {SUCESO_DEMANDA, SUCESO_EVALUACION_INVENTARIO, SUCESO_LLEGADA_PEDIDO, SUCESO_FIN_SIMULACION};

typedef struct {
	Suceso suceso;
	double tiempo;
} suc;

class SistemaInventario {
	private:
		double nivel;
		int pedido;
		int pedido_mes_anterior;
		double t_ult_suc;

		double acum_mas;
		double acum_menos;
		double acum_pedido;

		// k
		double costo_hacer_pedido;
		// i
		double costo_por_unidad;

		int s_pequena;
		int s_grande;

		double reloj;
		bool parar;

		std::list<suc> l_suc;

		// matriz para almacenar informe de cada simulación
		std::vector<double> informe;

		int modificacion;

		bool hay_pedido_en_curso;

		const double H = 1.0;
		const double PI = 5.0;

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
		double genera_informe(const int n_veces);



	public:
		double simula(const double t_final, const double nivel_inicial, const int s_p,
						const int s_g, const int n_veces, const int mod);
};



#endif
