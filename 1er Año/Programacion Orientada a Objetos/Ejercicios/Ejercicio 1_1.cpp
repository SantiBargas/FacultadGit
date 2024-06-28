#include <iostream>
using namespace std;
/*Declare una variable entera estática y otra variable entera dinámica almacenando
	su dirección de memoria en un puntero. Asigne a la primera variable el valor 10 y a
	la segunda variable un valor ingresado por el usuario. Muestre luego las posiciones
	de memoria de ambas variables. Luego corra el programa varias veces y responda:
	¿las direcciones de las variables son siempre las mismas cada vez que el
	programa corre? IMPORTANTE: No olvide liberar la memoria de la segunda
	variable antes de salir.*/
int main() {
	int x=10;
	int *p = new int; ///se crea memoria para un puntero, si no lo hago new no apunta a ningun lado
	cin>>*p;
	
	cout<< &x <<endl; ///con ampersand obtengo su direccion
	cout<< p <<endl;  
	
	delete p;   ///siempre que pido un new tiene que haber un delete
	
	return 0;
}

