#include "pch.h"
#include "Ajedrez.h"

int  Juego::esCorrecta(char *laJugada) {
	int posInicial, posFinal;
	if (!Movimiento::valida(laJugada))
		return FALSO;
	if (movimiento != NULL) delete movimiento;
	movimiento = new Movimiento(laJugada);
	posInicial = movimiento->damePosInicialDe();
	if (!MiTablero.hayPiezaEn(posInicial))
		return FALSO;
	if (MiTablero.quePiezaEn(posInicial)->miColor() != Turno)
		return FALSO;
	posFinal = movimiento->damePosFinalDe();
	if (MiTablero.hayPiezaEn(posFinal) AND
	(MiTablero.quePiezaEn(posFinal)->miColor() == Turno))
		return FALSO;
	Pieza *p = MiTablero.quePiezaEn(posInicial);
	return MiTablero.quePiezaEn(posInicial)->puedeRealizar(movimiento, &MiTablero);
}

void Juego::cambiaTurno() {
	if (Turno == BLANCO)
		Turno = NEGRO;
	else
		Turno = BLANCO;
}

void Juego::comienzaJuego() {
	Teclado miTeclado;
	Pantalla miPantalla;
	char laJugada[10];

	miPantalla.pon("Situacion Inicial", &MiTablero);
	miTeclado.lee(laJugada, Turno);
	while (strcmp(laJugada, "FIN")) {
		if (esCorrecta(laJugada)) {
			actualizaTablero();
			miPantalla.pon("valido", &MiTablero);
			cambiaTurno();
		} else
			miPantalla.pon("invalido", &MiTablero);
		miTeclado.lee(laJugada, Turno);
	}
}

void Juego::actualizaTablero() {

	int posInicial, posFinal;
	Pieza* captura;
	posInicial = movimiento->damePosInicialDe();
	posFinal = movimiento->damePosFinalDe();
	captura = MiTablero.quePiezaEn(posFinal);
	MiTablero.ponPieza(MiTablero.quePiezaEn(posInicial), posFinal);
	MiTablero.quitaPiezaDe(posInicial);
	if (captura) delete captura;
}

Juego::Juego() {

	MiTablero.ponPieza(new Torre(BLANCO), 1, 1);
	MiTablero.ponPieza(new Caballo(BLANCO), 2, 1);
	MiTablero.ponPieza(new Alfil(BLANCO), 3, 1);
	MiTablero.ponPieza((Alfil *)(new Dama(BLANCO)), 4, 1);
	MiTablero.ponPieza(new Rey(BLANCO), 5, 1);
	MiTablero.ponPieza(new Alfil(BLANCO), 6, 1);
	MiTablero.ponPieza(new Caballo(BLANCO), 7, 1);
	MiTablero.ponPieza(new Torre(BLANCO), 8, 1);
	for (int i = 1; i < 9; i++)
		MiTablero.ponPieza(new Peon(BLANCO), i, 2);

	MiTablero.ponPieza(new Torre(NEGRO), 1, 8);
	MiTablero.ponPieza(new Caballo(NEGRO), 2, 8);
	MiTablero.ponPieza(new Alfil(NEGRO), 3, 8);
	MiTablero.ponPieza((Alfil *)(new Dama(NEGRO)), 4, 8);
	MiTablero.ponPieza(new Rey(NEGRO), 5, 8);
	MiTablero.ponPieza(new Alfil(NEGRO), 6, 8);
	MiTablero.ponPieza(new Caballo(NEGRO), 7, 8);
	MiTablero.ponPieza(new Torre(NEGRO), 8, 8);
	for (int i = 1; i < 9; i++)
		MiTablero.ponPieza(new Peon(NEGRO), i, 7);

	Turno = BLANCO;
	movimiento = NULL;
}
Juego::~Juego() {
	if (movimiento) delete movimiento;
}
