#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cmath>


double generar(double media){

	double u = (double) random();

	u = (double) (u/(RAND_MAX+1.0));

	return (-media * log(1-u));
}

bool comparar_reales( const double a, const double b, const double epsilon = 0.00000005 ) {
	return fabs(a - b) < epsilon;
}

int main(int argc, char ** argv){

	//srandom(time(NULL));
	srandom(1);

	double reloj = 0.0;
	bool fallo = false;
	bool reparadorlibre = true;
	bool maquinaesperando = false;
	double numfallos = 0.0;
	double durfallos = 0.0;
	double tiempofinreparacion = 10e30;
	double comienzofallo = 0.0;
	bool hayrepuesto;
	double tfallo;
	double trepar;
	double tiempodeparar;

	if( argc != 5 ){
		std::cerr << "Numero incorrecto de argumentos" << std::endl;
		std::cerr << "bin/sistema_tiempo_variable repuesto tfallo trepar tiempodeparar" << std::endl;
		exit(-1);
	} else {

		hayrepuesto = atoi(argv[1]) != 0;

		tfallo = atoi(argv[2]);
		trepar = atoi(argv[3]);
		tiempodeparar = atoi(argv[4]);
	}

	auto tiempo_inicio = std::chrono::high_resolution_clock::now();

	double tiempofallomaquina = reloj + generar(tfallo);

	while (reloj <= tiempodeparar){

		reloj = std::min(tiempofallomaquina, tiempofinreparacion);

		if( comparar_reales(reloj, tiempofallomaquina) ) {

			if(reparadorlibre){
				reparadorlibre = false;
				tiempofinreparacion = reloj + generar(trepar);

			} else {
				maquinaesperando = true;
			}

			if(hayrepuesto){
				hayrepuesto = false;
				tiempofallomaquina = reloj + generar(tfallo);

			} else if(!fallo){
				fallo = true;
				comienzofallo = reloj;
				numfallos++;
				tiempofallomaquina = 10e30;

			}

		}


		if( comparar_reales(reloj, tiempofinreparacion) ) {

			if(maquinaesperando){
				maquinaesperando = false;
				tiempofinreparacion = reloj + generar(trepar);

			} else {
				reparadorlibre = true;
				tiempofinreparacion = 10e30;
			}


			if(!fallo){
				hayrepuesto = true;
			} else {
				tiempofallomaquina = reloj + generar(tfallo);
				durfallos += reloj - comienzofallo;
				fallo = false;
			}

		}
	}

	if(fallo){
		durfallos += reloj - comienzofallo;
	}

	auto tiempo_fin = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> t_ejecucion = std::chrono::duration_cast<std::chrono::microseconds>(tiempo_fin - tiempo_inicio);

	float durfallos_t = (trepar * tiempodeparar ) / (tfallo + trepar);
	float numfallos_t = tiempodeparar / (trepar + tfallo);

	std::cout << "Duración de los fallos: " << durfallos << std::endl;
	std::cout << "Número de fallos: " << numfallos << std::endl;
	std::cout << "Duración media de los fallos: " << durfallos/numfallos << std::endl;
	std::cout << "T. ejecucion simulación: " << t_ejecucion.count() << std::endl;
	std::cout << "D. media obtenida de forma teórica: " << durfallos_t/numfallos_t*1.0 << std::endl;

}
