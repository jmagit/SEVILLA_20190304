#include "pch.h"
#include "Ajedrez.h"

void clrscr() { system("CLS"); }

Tablero::Tablero() {
	for (int i = 0; i < 64; i++)
		miTablero[i] = (Pieza *)0;
}
Tablero::~Tablero() {
	for (int i = 0; i < 64; i++)
		if(miTablero[i]) delete miTablero[i];
}

void Tablero::pintate() {
	int i, j, k;
	clrscr();
	printf("      +");
	for (k = 0; k < 8; k++)
		printf("--------+");
	printf("\b+");
	for (i = 7; i >= 0; i--) {
		printf("\n%4d  |", i + 1);
		for (j = 0; j < 8; j++) {
			if (miTablero[i * 8 + j] == (Pieza *)0)
				printf("%s|", !((i + j) % 2) ? "XXXXXXXX" : "        ");
			else
				if (quePiezaEn(i * 8 + j)->miColor())
					printf(" \x1b[7m%-7s\x1b[0m|",
						quePiezaEn(i * 8 + j)->dameNombre());
				else
					printf(" %-7s|",
						quePiezaEn(i * 8 + j)->dameNombre());
		}
		printf("\n      +");
		for (k = 0; k < 8; k++)
			printf("--------+");
		printf("\b+");
	}
	printf("\r      +");
	for (k = 0; k < 8; k++)
		printf("--------+");
	printf("\b+\n");
	printf("       ");
	for (k = 0; k < 8; k++)
		printf("    %c    ", 'a' + k);
}

void Tablero::pintate_ASCCI() {
	int i, j, k;
	clrscr();
	printf("      ┌");
	for (k = 0; k < 8; k++)
		printf("────────┬");
	printf("\b┐");
	for (i = 7; i >= 0; i--) {
		printf("\n%4d  │", i + 1);
		for (j = 0; j < 8; j++) {
			if (miTablero[i * 8 + j] == (Pieza *)0)
				printf("%s│", !((i + j) % 2) ? "░░░░░░░░" : "      ");
			else
				if (quePiezaEn(i * 8 + j)->miColor())
					printf(" \x1b[7m%-7s\x1b[0m│",
						quePiezaEn(i * 8 + j)->dameNombre());
				else
					printf(" %-7s│",
						quePiezaEn(i * 8 + j)->dameNombre());
		}
		printf("\n      ├");
		for (k = 0; k < 8; k++)
			printf("────────┼");
		printf("\b┤");
	}
	printf("\r      └");
	for (k = 0; k < 8; k++)
		printf("────────┴");
	printf("\b┘\n");
	printf("       ");
	for (k = 0; k < 8; k++)
		printf("    %c    ", 'a' + k);
}

int Tablero::hayPiezaEn(int posicion) {
	return miTablero[posicion] != (Pieza *)0;
}

int Tablero::interpreta(int colummna, int fila) {
	return (fila - 1) * 8 + colummna - 1;
}

void Tablero::ponPieza(Pieza *pieza, int posicion) {
	miTablero[posicion] = pieza;
}
void Tablero::ponPieza(Pieza *pieza, int colummna, int fila) {
	miTablero[interpreta(colummna, fila)] = pieza;
}

void Tablero::ponPieza(void *pieza, int colummna, int fila) {
	miTablero[interpreta(colummna, fila)] = (Pieza *)pieza;
}

Pieza *Tablero::quePiezaEn(int posicion) {
	return (Pieza *)miTablero[posicion];
}

void Tablero::quitaPiezaDe(int posicion) {
	miTablero[posicion] = (Pieza *)0;
}

int Tablero::hayPiezaEntre(Movimiento* unMovimiento) {
	int deltaF, deltaC, posAux;
	// Establecer los pasos de avance de filas y columnas
	deltaF = unMovimiento->deltaFila();
	deltaC = unMovimiento->deltaColumna();
	// La primera posicion a analizar es la siguiente a posInicial
	posAux = unMovimiento->damePosInicialDe();
	do {
		posAux = posAux + deltaF * 8 + deltaC;
		if (hayPiezaEn(posAux))
			break;//return CIERTO;
	} while (unMovimiento->damePosFinalDe() != posAux);
	return unMovimiento->damePosFinalDe() != posAux; //FALSO;
}
