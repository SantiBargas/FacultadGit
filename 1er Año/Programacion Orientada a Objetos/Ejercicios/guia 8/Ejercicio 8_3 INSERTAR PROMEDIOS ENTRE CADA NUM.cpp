#include <iostream>
#include <list>
#include <fstream>
using namespace std;
template <typename T>
void mostrar(string s, T v) {
	cout<<s<<"  : ";
	for(float x:v) cout<<x<<"  ";
	cout<<endl<<endl;
}

int main() {
	
	list<float> l(10);

	for(float &x:l) x=rand()%10;
	mostrar("l",l);

	for(auto it=next(l.begin());it!=l.end();advance(it,2)){
		
		float prom=(*it + *prev(it))/2;
		it=l.insert(it,prom); //si no lo asigno, me lo destruye la funcion, si lo pongo asi me va a quedar en el dato del medio que debo insertar
	}
	mostrar("l2",l);
	
	ofstream archi_out("Ejercicio 8_3 listafloat.txt");
	
	for(float x: l){
		archi_out<<x<<"  ";
	}
	
	return 0;
}

