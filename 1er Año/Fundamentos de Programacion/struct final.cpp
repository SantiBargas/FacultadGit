#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Arista {
	int nodo1, nodo2;
	Arista(int n1, int n2) : nodo1(n1), nodo2(n2) {}
};

int main() {
	// Crear un mapa que asocie objetos Arista con valores int

	std::map<Arista, int> mapa;
	
	// Insertar valores en el mapa
	Arista arista1(1, 2);
	Arista arista2(2, 3);
	mapa[arista1] = 10;
	mapa[arista2] = 20;
	
	// Recuperar valores del mapa
	int valor1 = mapa[arista1];
	int valor2 = mapa[arista2];
	
	// Mostrar los valores recuperados
	cout << "Valor asociado a arista1: " << valor1 << endl;
	cout << "Valor asociado a arista2: " << valor2 << endl;
	
	return 0;
}
