#include "pch.h"
#include "Ajedrez.h"


Pieza::Pieza(int unColor = NEGRO, char const* miNombre = "          ") {
	deColor(unColor);
	ponNombre(miNombre);
}

void Pieza::deColor(int unColor) {
	color = unColor;
}

int  Pieza::miColor() {
	return color;
}

void Pieza::ponNombre(char const* miNombre) {
	strcpy_s(nombre, miNombre);
}

char* Pieza::dameNombre() {
	return nombre;
}

//--------------------------------------------------------------//

Rey::Rey(int unColor) : Pieza(unColor, "Rey") {}

int Rey::puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero) {
	return (unMovimiento->saltoVertical() < 2) AND
	(unMovimiento->saltoHorizontal() < 2);
}

//--------------------------------------------------------------//

Alfil::Alfil(int unColor) : Pieza(unColor, "Alfil") { }

int Alfil::puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero) {
	return unMovimiento->esDiagonal()
		AND !miTablero->hayPiezaEntre(unMovimiento);
}


//--------------------------------------------------------------//

Torre::Torre(int unColor) : Pieza(unColor, "Torre") {}

int Torre::puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero) {
	return (unMovimiento->esVertical() OR unMovimiento->esHorizontal() == 0) AND
		!miTablero->hayPiezaEntre(unMovimiento);
}


//--------------------------------------------------------------//

Peon::Peon(int unColor) : Pieza(unColor, "Peon") {}

bool Peon::avanza(Movimiento* unMovimiento) {
	return unMovimiento->deltaFila() == (miColor() == BLANCO ? 1 : -1)
		&& (unMovimiento->esDiagonal() || unMovimiento->esVertical())
		&& !unMovimiento->esHorizontal();
}

int Peon::enPosDePartida(int posicion) {
	if (miColor() == BLANCO)
		return posicion == 2;
	else
		return posicion == 7;
}

int Peon::puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero) {
	int difF, difC, color;
	color = miColor();
	if (!avanza(unMovimiento))
		return FALSO;
	difF = unMovimiento->saltoVertical();
	difC = unMovimiento->saltoHorizontal();
	if (difF == 1 AND difC == 1)
		return miTablero->hayPiezaEn(unMovimiento->damePosFinalDe());
	if (difF == 1 AND difC == 0)
		return !miTablero->hayPiezaEn(unMovimiento->damePosFinalDe());
	if (difF == 2 AND difC == 0)
		return !(miTablero->hayPiezaEn(unMovimiento->damePosFinalDe())
			OR miTablero->hayPiezaEntre(unMovimiento) OR
			!enPosDePartida(unMovimiento->filaInicial()));
	return FALSO;
}


//--------------------------------------------------------------//

Dama::Dama(int unColor) : Alfil(unColor), Torre(unColor) {
	Alfil::ponNombre("Dama");
}

int Dama::puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero) {
	return (Alfil::puedeRealizar(unMovimiento, miTablero)) OR
	(Torre::puedeRealizar(unMovimiento, miTablero));
}

//--------------------------------------------------------------//

Caballo::Caballo(int unColor) : Pieza(unColor, "Caballo") {}

int Caballo::puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero) {
	int difF, difC;
	difF = unMovimiento->saltoVertical();
	difC = unMovimiento->saltoHorizontal();
	return (difF == 2 AND difC == 1) OR(difF == 1 AND difC == 2);
}
