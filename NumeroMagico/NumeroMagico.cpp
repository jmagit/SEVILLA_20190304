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
void pideNombre(Jugador *j) {
	cout << "Nombre: ";
	cin >> j->nombre;
}
void insertaRecord(Jugador* item, Jugador** tabla, int size) {
	for (int i = 0; i < size; i++) {
		if ((*(tabla + i))->record > item->record) {
			if ((tabla + i) != 0) {
				delete *(tabla + size - 1);
				for (int j = size - 1; j > i; j--)
					*(tabla + j) = *(tabla + j - 1);
			}
			*(tabla + i) = item;
			break;
		}
	}
}
void pintaRecord(Jugador** tabla, int size) {
	cout << "TABLA DE RECORDS" << endl;
	cout << "------------------" << endl;
	for (int i = 0; i < size; i++) {
		if ((tabla + i) == 0) return;
		cout << (*(tabla + i))->nombre << "\t" << (*(tabla + i))->record << endl;
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
void jugar(Jugador* tabla, int size) {
	Jugador* j = new Jugador;
	if (tabla == 0) {
		tabla = j;
	} else {
		x->siguiente = j;
	}
	pideNombre(j);
	j->record = jugar();
	insertaRecord(j, tabla, size);
}
int main() {
	Jugador* topJugadores = 0;
	//for (int i = 0; i < NUM_TOP; topJugadores[i++] = 0);
	int opc = pideOpcion();
	while (opc < 3) {
		switch (opc) {
		case 1:
			jugar(topJugadores);
		case 2:
			pintaRecord(topJugadores);
			break;
		}
		opc = pideOpcion();
	}
}