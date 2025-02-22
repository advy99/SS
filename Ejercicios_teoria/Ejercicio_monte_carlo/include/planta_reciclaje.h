#ifndef PLANTA_RECICLAJE
#define PLANTA_RECICLAJE

#include <iostream>

class PlantaReciclaje {
	private:

		int dias_simulacion;
		int dia_actual;

		double contenedor_rojo = 300.0;
		double contenedor_verde = 0.0;

		double papel_recicla_dia = 300.0;

		double papel_sin_reciclar_perdido = 0.0;
		double papel_reciclado_perdido = 0.0;
		double falta_papel_reciclado_vender = 0.0;

		double papel_total_vendido = 0;

		bool avisos = true;

		const double MAX_ROJO = 1000.0;
		const double MAX_VERDE = 300.0;

		const double KG_NECESARIOS_RECICLAR_1KG = 3.0;

		void procesar_manana();
		void procesar_tarde();

		void procesar_papel(const double kg_reciclar);
		void almacenar_nuevo_papel_usado();
		void vender_papel_reciclado();

		double uniforme();

	public:
		PlantaReciclaje(const double papel_dia, const double KG_RECICLAR = 3.0,
			 				 const double T_ROJO = 1000.0, const double T_VERDE = 300.0);
		void simular(const bool mensajes_aviso = false, const bool salida_info = false,
			 			 const int c_rojo = 300, const int c_verde = 0, const int num_dias = 365);
		double vendido();
		double falta_reciclado();
		double reciclado_perdido();
		double usado_perdido();


		friend std::ostream & operator << (std::ostream & os, const PlantaReciclaje & planta);

};




#endif
