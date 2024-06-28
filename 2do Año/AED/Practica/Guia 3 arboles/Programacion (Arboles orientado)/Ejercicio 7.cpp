#include <iostream>
#include <tree.hpp>
#include <list>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/*7) list2tree Escribir una funci´on void list2tree(tree<int> &T,list<int> &L) que dada una
lista L con el orden previo de T y el tama˜no de sus sub´arboles reconstruye T. La forma de
almacenar el ´arbol en T es la siguiente: se almacena en orden previo 2 valores enteros por cada
nodo, a saber el contenido del nodo y el n´umero de hijos. Por ejemplo para el ´arbol
(6 4 8 (5 4 4) 7 9) tenemos L=(6 5 4 0 8 0 5 2 4 0 4 0 7 0 9 0). Escribir tambi´en la
funci´on inversa void tree2list(tree<int> &T,list<int> &L).*/

///Auxiliar
tree<int>::iterator list2tree(tree<int> &T,tree<int>::iterator n,list<int> &L, list<int>::iterator &p){
	/// agrega el valor del nodo
	n = T.insert(n, *p);
	
	/// avanza el iterator para obtener la 
	/// cantidad de hijos a procesar
	++p;
	
	/// obtiene la cantidad de hijos del nodo
	int cantHijos = *p;
	++p;
	
	/// reconstruccion de los hijos
	tree<int>::iterator hijoIzq = n.lchild();
	for(int i = 0; i < cantHijos; i++) {
		hijoIzq = list2tree(T, hijoIzq, L, p);
		hijoIzq++;
	}
	
	return n;
}
	
	
/// Wrapper
void list2tree(tree<int>& T, list<int>& L) {
	list<int>::iterator p = L.begin();
	list2tree(T, T.begin(), L, p);
}

int main() {
	tree<int>T;
	list<int>L={6, 5, 4, 0, 8, 0, 5, 2, 4, 0, 4, 0, 7, 0, 9, 0};
	
	list2tree(T,L);
	tree2dot(T);
	return 0;
}







