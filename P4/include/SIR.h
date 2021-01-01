#ifndef SIR_H
#define SIR_H

#include <iostream>
#include <vector>

struct estado{
	unsigned long int infectados;
	unsigned long int supceptibles;
	unsigned long int recuperados;
};

class SIR {
	private:

		// a en el guion
		double capacidad_infeccion_enfermedad;

		// b en el guion
		double tiempo_duracion_infeccion;

		// intervalo calculo: dt en el guion
		double intervalo_calculo;

		double intervalo_comunicacion;
		double t_inicio;
		double t_fin;

		estado estado_inicial;

		std::vector<estado> estados;

		double t_actual;


	public:
		SIR();
		SIR(const int argc, const char ** argv);

		void integracion();
		void one_step_runge_kutta();
		void one_step_euler();
		void derivacion();

		friend std::istream & operator >> (std::istream & is, SIR & modelo);
		friend std::ostream & operator << (std::ostream & os, const SIR & modelo);


};


#endif
