#include <iostream>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/*5) ContarSi. Escribir una funci´on int count_if(tree<int> &T,bool (*pred)(int x)) que retorna
el n´umero de nodos del ´arbol T que satisfacen el predicado pred. Por ejemplo, si
T=(1 2 (3 5 7 6) 4), entonces count_if(T,odd) debe retornar 4. Escribir el predicado
bool odd(int x) que determina si un entero es impar*/

/// Funciones predicado
bool odd(int x) {
	return x % 2;
}

bool positive(int x) {
	return x > 0;
}

bool negative(int x) {
	return x < 0;
}

	
///auxiliar
int count_if(tree<int> &T,tree<int>::iterator n,bool (*pred)(int x)){
	if(n==T.end()) return 0;
	
	int count = pred(*n); ///verificar que el valor del nodo cumpla con la condicion
	
	tree<int>::iterator hijoIzq =n.lchild();
	while(hijoIzq!=T.end()){
		count += count_if(T,hijoIzq,pred);
		++hijoIzq;
	}
	return count;
}


///Wrapper
int count_if(tree<int>&T, bool(*pred)(int x)){
	
	return count_if(T,T.begin(),pred);
}
int main() {
	string s_arbol1("(2 3 (4 5 (6 7 8))(9 10) (22 12 (13 14 15))");
	tree<int> arbol1;
	lisp2tree(s_arbol1,arbol1);
	tree2dot(arbol1);
	
	int count = count_if(arbol1,odd);
	cout<<"Cantidad de nodos impares: "<<count;
	return 0;
}







