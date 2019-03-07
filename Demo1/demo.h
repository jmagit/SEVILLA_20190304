#pragma once
class Punto {
private:
	int x, y;
protected:
	void ponX(int valor);
	void ponY(int valor);
public:
	Punto();
	Punto(int x, int y);
	~Punto();
	int dameX();
	int dameY();
	virtual void desplaza(int delta);
	Punto operator+(Punto a);
};
class Punto3D: public Punto {
private:
	int z;
protected:
	void ponZ(int valor);
public:
	Punto3D();
	Punto3D(int x, int y, int z);
	~Punto3D();
	int dameZ();
};
