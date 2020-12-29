#include <iostream>



void integracion() {
	do {
		salida();
		oldestado=estado;
		one_step(oldestado,estado,t,dt); //sustituir por one-step-runge-kutta o por one-step-euler
		t+=dt;
	} while (t<tfin);
}


void one_step_runge_kutta(inp,out,tt,hh) {
	for (i=0; i<numeq; i++)
		out[i]=inp[i];

	time=tt;

	for (j=0; j<4; j++) {
		derivacion(out,f,time);
		for (i=0; i<numeq; i++)
			k[i,j]=f[i];

		if (j<2)
			incr=hh/2;
		else
			incr=hh;

		time=tt+incr;

		for (i=0; i<numeq; i++)
			out[i] = inp[i] + k[i,j] * incr;
	}

	for (i=0; i<numeq; i++)
		out[i]=inp[i]+hh/6*(k[i,0]+2*k[i,1]+2*k[i,2]+k[i,3]);

}


void one_step_euler(inp,out,tt,hh) {
	derivacion(inp,f,tt);
	for (i=0; i<numeq; i++)
		out[i]=inp[i]+hh*f[i];
}


// específico para el modelo considerado
void derivacion(est,f,tt) {
	f[0]=a*est[0]*est[1]-b*est[0];
	f[1]=-a*est[0]*est[1];
	f[2]=b*est[0];
}


int main (int argc, char ** argv) {

	fijar_parametros();
	t=tinic;
	integracion();

}


