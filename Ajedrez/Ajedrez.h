#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

// Definicion de nombres para clarificar la lectura del codigo

# define BLANCO 0
# define NEGRO  1

# define FALSO  0
# define CIERTO 1

# define AND    &&
# define OR     ||

class Tablero;
class Pieza;

class Posicion {
private:
	int fila;
	int columna;
public:
	Posicion(int fila, int columna);
	Posicion(char fila, char columna);
	int dameFila();
	int dameColumna();
};

class Movimiento {
private:
	Posicion *pInicial, *pFinal;
	int  deltaEntre(int valorInicial, int valorFinal);
public:
	Movimiento(char *unMovimiento);
	~Movimiento();
	int damePosFinalDe();
	int damePosInicialDe();
	int filaInicial();
	int deltaFila();
	int deltaColumna();
	int saltoVertical();
	int saltoHorizontal();
	bool esVertical();
	bool esHorizontal();
	bool esDiagonal();
	static int valida(char *laJugada);
};

class Tablero {
private:
	Pieza *miTablero[64];
public:
	Tablero();
	~Tablero();
	int hayPiezaEn(int posicion);
	int interpreta(int colummna, int fila);
	void ponPieza(Pieza *pieza, int posicion);
	void ponPieza(Pieza *pieza, int colummna, int fila);
	void ponPieza(void *pieza, int colummna, int fila);
	Pieza *quePiezaEn(int posicion);
	void quitaPiezaDe(int posicion);
	int  hayPiezaEntre(Movimiento* unMovimiento);
	void pintate();
	void pintate_ASCCI();
};

class Pieza {
private:
	int color;
	char nombre[20];
protected:
	void ponNombre(char const* miNombre);
public:
	Pieza(int unColor, char const* miNombre);
	void deColor(int unColor);
	int  miColor();
	char *dameNombre();
	virtual int puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero) = 0;
};

class Alfil : public Pieza {
public:
	Alfil(int unColor);
	int puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero);
};

class Torre : public Pieza {
public:
	Torre(int unColor);
	int puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero);
};

class Caballo : public Pieza {
public:
	Caballo(int unColor);
	int puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero);
};

class Dama : public Alfil, private Torre {
public:
	Dama(int unColor);
	int puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero);
};

class Rey : public Pieza {
public:
	Rey(int unColor);
	int puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero);
};

class Peon : public Pieza {
private:
	bool avanza(Movimiento* unMovimiento);
public:
	Peon(int unColor);
	int puedeRealizar(Movimiento* unMovimiento, Tablero* miTablero);
	int enPosDePartida(int posicion);
};

class Teclado {
public:
	void lee(char *laJugada, int color);
};

class Pantalla {
public:
	void pon(char const* mensaje, Tablero* miTablero);
};

class Juego {
private:
	Tablero MiTablero;
	Movimiento* movimiento;
	int Turno;
public:
	Juego(); // hace el init
	~Juego(); // hace el init
	void actualizaTablero();
	void cambiaTurno();
	void comienzaJuego();
	int  esCorrecta(char *laJugada);
};



