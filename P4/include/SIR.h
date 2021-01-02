#ifndef SIR_H
#define SIR_H

#include <iostream>
#include <vector>

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

		double t_actual;

		std::vector<double> estado;
		std::string funcion_paso;


		void integracion();
		std::vector<double> one_step_runge_kutta(const std::vector<double> & estado, const double interv_calculo);
		std::vector<double> one_step_euler(const std::vector<double> & estado, const double interv_calculo);
		std::vector<double> derivacion(const std::vector<double> & estado);
		void salida();


	public:
		SIR();
		SIR(const int argc,  char ** argv);

		void simular();

		static const int NUM_EQ = 3;

		friend std::istream & operator >> (std::istream & is, SIR & modelo);
		friend std::ostream & operator << (std::ostream & os, const SIR & modelo);


};


#endif
