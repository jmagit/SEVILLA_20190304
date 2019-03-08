#include "pch.h"
#include "Ajedrez.h"


void Teclado::lee(char *laJugada, int color) {
	printf("\nJuegan las %s. Dame la jugada: ", color ? "negras" : "blancas");
	cin >> laJugada;
}

void Pantalla::pon(char const* mensaje, Tablero* miTablero) {
	miTablero->pintate();
	printf("\n\nMovimiento %s", mensaje);
}

