#ifndef PLANTA_RECICLAJE
#define PLANTA_RECICLAJE

class PlantaReciclaje {
	private:

		double contenedor_rojo = 300;
		double contenedor_verde = 0;

		double papel_recicla_dia = 300;

		const double MAX_ROJO = 1000;
		const double MAX_VERDE = 300;

		const double KG_NECESARIOS_RECICLAR_1KG = 3;

		void procesar_manana();
		void procesar_tarde();

		void procesar_papel(const double kg_reciclar);
		void almacenar_nuevo_papel_usado();
		void vender_papel_reciclado();

		double uniforme();

	public:

		void simular();

};




#endif
