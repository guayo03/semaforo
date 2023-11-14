#include <stdio.h>
#include <unistd.h>

#define color_rojo "\x1b[31m"
#define color_amarillo "\x1b[33m"
#define color_verde "\x1b[32m"
#define reset_color "\x1b[0m"

struct EstadoSemaforo {
	int tiempo_verde;
	int tiempo_amarillo;
	int tiempo_rojo;
};

//FunciOn para imprimir la luz activa con color
void imprimir_semaforo(int luz_verde, int luz_amarilla, int luz_roja) {
	printf("\rSemáforo: ");
	if (luz_verde) {
		printf(color_verde "Luz Verde Encendida" reset_color);
	} else {
		printf("\x1b[30mVerde\x1b[0m");
	}
	
	if (luz_amarilla) {
		printf(" | " color_amarillo "Luz Amarilla Encendida" reset_color);
	} else {
		printf(" | \x1b[30mAmarillo\x1b[0m");
	}
	
	if (luz_roja) {
		printf(" | " color_rojo "Luz Roja Encendida" reset_color);
	} else {
		printf(" | \x1b[30mRojo\x1b[0m");
	}
	fflush(stdout);
}

void borrar_linea() {
	printf("\033[K");
	fflush(stdout);
}

int main() {
	struct EstadoSemaforo semaforo = {20, 5, 15};
	
	//Bucle para el funcionamiento continuo del semáforo
	while (1) {
		//Luz Verde
		imprimir_semaforo(1, 0, 0);
		sleep(semaforo.tiempo_verde);
		borrar_linea();
		
		//Luz Amarilla
		imprimir_semaforo(0, 1, 0);
		sleep(semaforo.tiempo_amarillo);
		borrar_linea();
		
		//Luz Roja
		imprimir_semaforo(0, 0, 1);
		sleep(semaforo.tiempo_rojo);
		borrar_linea();
	}
	
	return 0;
}
