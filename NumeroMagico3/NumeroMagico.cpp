#include "pch.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

#include "NumeroMagico.h"

using namespace std;

int pideOpcion() {
	char cad[50];
	while (true) {
		cout << "Juego" << endl;
		cout << "------------------" << endl;
		cout << "1. Jugar" << endl;
		cout << "2. Records" << endl;
		cout << "3. Salir" << endl;
		cout << "Opcion: ";
		cin >> cad;
		if ('1' <= *cad && *cad <= '3')
			return *cad - '0';
	}
}
void pideDatos(Jugador *j) {
	cout << "Nombre: ";
	cin >> j->nombre;
}
Jugador* buscar(Jugador* tabla) {
	return tabla == 0 || tabla->siguiente == 0 ? tabla : buscar(tabla->siguiente);
}
void insertaRecord(Jugador* item, Jugador** lista) {
	if (*lista == 0) {
		*lista = item;
		return;
	}
	if ((*lista)->record > item->record) {
		item->siguiente = *lista;
		*lista = item;
	} else if ((*lista)->siguiente == 0) {
		(*lista)->siguiente = item;
	} else {
		insertaRecord(item, &((*lista)->siguiente));
	}
}
void pintaRecord(Jugador* lista) {
	cout << "TABLA DE RECORDS" << endl;
	cout << "------------------" << endl;
	Jugador* actual = lista;
	while(actual) {
		cout << actual->nombre << "\t" << actual->record << endl;
		actual = actual->siguiente;
	}
}
int jugar() {
	srand((unsigned int)time(0));
	int objetivo = rand() % NUM_MAX + 1;
#if _DEBUG
	cout << "Numero buscado: " << objetivo << endl;
#endif
	int i = 1;
	for (; i <= MAX_INT; i++) {
		int num;
		char cad[10];
		cout << "Dime tu numero (" << i << " de " << MAX_INT << "): ";
		cin >> cad;
		if (!strcmp(cad, "FIN")) {
			i = MAX_INT;
			continue;
		}
		if (!(num = atoi(cad))) {
			cout << "No es un numero valido" << endl;
			i--;
			continue;
		}
		if (num == objetivo) {
			cout << "Acertastes" << endl;
			break;
		} else if (num < objetivo) {
			cout << "Te has quedado corto" << endl;
		} else {
			cout << "Te has pasado" << endl;

		}
	}
	return i;
}
void jugar(Jugador** lista) {
	Jugador* j = new Jugador;
	pideDatos(j);
#if _DEBUG
	j->record = rand() % 10 + 1;
#else
	j->record = jugar();
#endif
	cout << "Intentos: " << j->record << endl;
	insertaRecord(j, lista);
}
int main() {
	Jugador* topJugadores = 0;
	int opc = pideOpcion();
	while (opc < 3) {
		switch (opc) {
		case 1:
			jugar(&topJugadores);
		case 2:
			pintaRecord(topJugadores);
			break;
		}
		opc = pideOpcion();
	}
}