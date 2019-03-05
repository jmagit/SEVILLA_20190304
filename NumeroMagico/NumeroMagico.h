#define NUM_MAX 100
#define MAX_INT 10
#define NUM_TOP 10


struct Jugador {
	char nombre[50];
	int record = 99;
	Jugador* siguiente = 0;
};

struct Nodo {
	void* contenido;
	Nodo* siguiente = 0;
};
