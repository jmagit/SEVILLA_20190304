// Demo1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include "Cadenas.h"
#include "demo.h"

using namespace std;
Punto::Punto() {
	x = 0;
	y = 0;
}
Punto::Punto(int x, int y) {
	this->x = x;
	ponY(y);
}
Punto::~Punto() {
	cout << "Me destruyo" << endl;
}

int Punto::dameX() {
	return x;
};
int Punto::dameY() {
	return y;
};
void Punto::ponX(int valor) {
	x = valor;
}
void Punto::ponY(int valor){
	y = valor;
}

void Punto::desplaza(int delta) {
	ponX(dameX() + delta);
	ponY(dameY() + delta);
}
Punto Punto::operator+(Punto a) {
	return Punto(x + a.x, y + y);
}

Punto3D::Punto3D() : Punto(0 ,0) {
	ponZ(0);
}
Punto3D::Punto3D(int x, int y, int z) : Punto(x, y) {
	ponZ(z);
}
Punto3D::~Punto3D() {
	cout << "Punto3D: Me destruyo" << endl;
}
int Punto3D::dameZ() {
	return z;
};
void Punto3D::ponZ(int valor) {
	z = valor;
}
void Punto3D::desplaza(int delta) {
	ponZ(dameZ() + delta);
	Punto::desplaza(delta);
}

void demoPunto() {
	Punto p = Punto(6,9);
	Punto p2 = Punto(10,10);
	printf("Punto: x=%d y=%d\n", p.dameX(), p.dameY());
	p.desplaza(10);
	printf("Punto: x=%d y=%d\n", p.dameX(), p.dameY());
	Punto p3 = p + p2;
	printf("Punto: x=%d y=%d\n", p3.dameX(), p3.dameY());
	Punto3D p3d = Punto3D(1, 2, 3);
	printf("Punto: x=%d y=%d z=%d\n", p3d.dameX(), p3d.dameY(), p3d.dameZ());
	p3d.desplaza(3);
	printf("Punto: x=%d y=%d z=%d\n", p3d.dameX(), p3d.dameY(), p3d.dameZ());
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

void demoBiblio() {
	cout << cadLong((char *)"Hola mundo");
}
int main() {
	demoPunto();
	char kk[10];
	cout << "pulsa";
	cin >> kk;
	// demoUnion();
	// demoPuntero();
	//demoBiblio();
}
