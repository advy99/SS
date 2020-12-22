#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cmath>


// bin/sistema_tiempo_fijo hayrepuesto tfallo trepar tiempodeparar
int generar(float media){

	float u = (float) random();

	u = (float) (u/(RAND_MAX+1.0));

	float n = (-media * log(1-u));

	int ent = ceil(n);

	if (ent == 0){
		ent++;
	}

	return ent;
}


int main(int argc, char ** argv){

	//srandom(time(NULL));
	srandom(1);

	int reloj = 0;
	bool fallo = false;
	bool reparadorlibre = true;
	bool maquinaesperando = false;
	float numfallos = 0.0;
	float durfallos = 0.0;
	int tiempofinreparacion = 1000000000;
	int comienzofallo = 0;
	bool hayrepuesto;
	int tfallo;
	int trepar;
	int tiempodeparar;

	if( argc != 5 ){
		std::cerr << "Numero incorrecto de argumentos" << std::endl;
		std::cerr << "bin/sistema_tiempo_fijo repuesto tfallo trepar tiempodeparar" << std::endl;
		exit(-1);

	} else {
		hayrepuesto = atoi(argv[1]) != 0;
		tfallo = atoi(argv[2]);
		trepar = atoi(argv[3]);
		tiempodeparar = atoi(argv[4]);
	}

	auto tiempo_inicio = std::chrono::high_resolution_clock::now();

	int tiempofallomaquina = reloj + generar(tfallo);

	while (reloj <= tiempodeparar){

		if(reloj == tiempofallomaquina){

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
				tiempofallomaquina = 1000000000;
			}

		}


		if(reloj == tiempofinreparacion){

			if(maquinaesperando){
				maquinaesperando = false;
				tiempofinreparacion = reloj + generar(trepar);

			} else {
				reparadorlibre = true;
				tiempofinreparacion = 1000000000;

			}


			if(!fallo){
				hayrepuesto = true;
			} else {

				tiempofallomaquina = reloj + generar(tfallo);
				durfallos += reloj - comienzofallo;
				fallo = false;

			}

		}

		reloj++;
	}

	if(fallo){
		durfallos += reloj - comienzofallo;
	}

	auto tiempo_fin = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> t_ejecucion = std::chrono::duration_cast<std::chrono::microseconds>(tiempo_fin - tiempo_inicio);



	float durfallos_t = (trepar * tiempodeparar ) / (tfallo + trepar);
	float numfallos_t = tiempodeparar / (trepar + tfallo);

	std::cout << "D. fallos: " << durfallos << std::endl;
	std::cout << "N. Fallos: " << numfallos << std::endl;
	std::cout << "D. media fallos: " << durfallos/numfallos << std::endl;
	std::cout << "T. ejecucion simulación: " << t_ejecucion.count() << std::endl;
	std::cout << "D. media obtenida de forma teórica: " << durfallos_t/numfallos_t*1.0 << std::endl;

}
