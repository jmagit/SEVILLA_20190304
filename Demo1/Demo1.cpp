// Demo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>

struct Punto {
	int x = 0, y = 0;
};

void demoPunto() {
	Punto p;
	p.x = 1;
	p.y = 2;
	printf("Punto: x=%d y=%d\n", p.x, p.y);
}

struct Trama {
	unsigned char origen : 3;
	unsigned char tipo : 2;
	unsigned char hayError : 1;
	unsigned char causa : 2;
};

union DecodeTrama {
	unsigned char codigo;
	Trama trama;
};

void demoUnion() {
	DecodeTrama value;
	value.codigo = 0xF8;

	printf("origen: %d tipo:%d hayError:%d causa:%d\n",
		value.trama.origen, value.trama.tipo, value.trama.hayError,
		value.trama.causa);
	value.trama.hayError = 0;
	printf("origen: %d tipo:%d hayError:%d causa:%d",
		value.trama.origen, value.trama.tipo, value.trama.hayError,
		value.trama.causa);
}

void demoPuntero() {
	int t[] = { 0, 1, 2, 3, 4 };
	int *pp = t;
	std::cout << "Int: " << sizeof(int) << " Array: " << sizeof(t)
		<< " Puntero: " << sizeof(pp) << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << t[i] << " ";
	std::cout << std::endl;
	for (int *p = t; p <= t + 4; std::cout << *p++ << " ");
	std::cout << std::endl;
}

int main() {
	// demoUnion();
	demoPuntero();
}
