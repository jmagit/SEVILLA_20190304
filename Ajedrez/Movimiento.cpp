#include "pch.h"
#include "Ajedrez.h"

Posicion::Posicion(int fila, int columna) {
	this->fila = fila;
	this->columna = columna;
}
Posicion::Posicion(char fila, char columna) {
	this->fila = fila - '0';
	this->columna = columna - 'a' + 1;
}
int Posicion::dameFila() {
	return fila;
}
int Posicion::dameColumna() {
	return columna;
}

Movimiento::Movimiento(char *laJugada) {
	if (!valida(laJugada))
		throw "Error";
	pInicial = new Posicion(*(laJugada + 1), *laJugada);
	pFinal = new Posicion(*(laJugada + 3), *(laJugada + 2));
}

Movimiento::~Movimiento() {
	delete pInicial;
	delete pFinal;
}

int Movimiento::damePosFinalDe() {
	return (pFinal->dameFila() - 1) * 8 + pFinal->dameColumna() - 1;
}

int Movimiento::damePosInicialDe() {
	return (pInicial->dameFila() - 1) * 8 + pInicial->dameColumna() - 1;
}

int Movimiento::valida(char *laJugada) {
	return  // Regla 1: Notacion Internacional.
		('a' <= *laJugada) AND (*laJugada <= 'h') AND
		('1' <= *(laJugada + 1)) AND (*(laJugada + 1) <= '8') AND
		('a' <= *(laJugada + 2)) AND (*(laJugada + 2) <= 'h') AND
		('1' <= *(laJugada + 3)) AND (*(laJugada + 3) <= '8') AND
		// Regla 2: Posicion inicil distinta de la final.
		(*laJugada != *(laJugada + 2) OR
			*(laJugada + 1) != *(laJugada + 3));
}

int Movimiento::deltaEntre(int valorInicial, int valorFinal) {
	return	(valorInicial == valorFinal) ? 0 :
		(valorInicial > valorFinal) ? -1 : 1;
}

int Movimiento::deltaFila() {
	return deltaEntre(pInicial->dameFila(), pFinal->dameFila());
}

int Movimiento::deltaColumna() {
	return deltaEntre(pInicial->dameColumna(), pFinal->dameColumna());
}

int Movimiento::saltoVertical() {
	return abs(pFinal->dameFila() - pInicial->dameFila());
}

int Movimiento::saltoHorizontal() {
	return abs(pFinal->dameColumna() - pInicial->dameColumna());
}

bool Movimiento::esVertical() {
	return pInicial->dameColumna() == pFinal->dameColumna();
}

bool Movimiento::esHorizontal() {
	return pInicial->dameFila() == pFinal->dameFila();
}

bool Movimiento::esDiagonal() {
	return saltoHorizontal() == saltoVertical();
}

int Movimiento::filaInicial() {
	return pInicial->dameFila();
}
