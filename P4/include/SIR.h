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


		void integracion();
		std::vector<double> one_step_runge_kutta(const std::vector<double> & estado);
		std::vector<double> one_step_euler(const std::vector<double> & estado);
		std::vector<double> derivacion(const std::vector<double> & estado);
		void salida();

		std::vector<double> (SIR::*puntero_funcion_paso)(const std::vector<double> &) = &SIR::one_step_euler;


	public:
		SIR();
		SIR(const int argc, const char ** argv);

		void simular();

		static const int NUM_EQ = 3;

		friend std::istream & operator >> (std::istream & is, SIR & modelo);
		friend std::ostream & operator << (std::ostream & os, const SIR & modelo);


};


#endif
