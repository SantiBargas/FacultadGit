#include <iostream>
#include <list>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}
/*ListarSi. Escribir una funci´on void list_if(tree<int> &T,list<int> &L,
bool (*pred)(int x)) que retorna en L la lista de valores nodales en orden previo de un ´arbol
ordenado orientado T que satisfacen el predicado pred. Por ejemplo, si T=(1 (-2 7 (8 -7)
(3 -5 -6))), entonces despu´es de list_if(T,L,positive), debe quedar L={1,7,*/
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
///Auxiliar
 void list_if(tree<int> &T,tree<int>::iterator n,list<int> &L,bool (*pred)(int x)){
	
	if(pred(*n)){ 			///comienza a hacer la llamada recursiva
		L.push_back(*n);		 ///invocamos el predicado sobre el nodo actual
									/// y si se cumple le hacemos pushback
	}
	
	auto hijoIzq=n.lchild();
	
	while(hijoIzq!=T.end()){
		list_if(T,hijoIzq,L,pred);
		++hijoIzq;
	}
	
}


///Wrapper
void list_if(tree<int> &T,list<int> &L,bool (*pred)(int x)){
	L.clear();
	if(T.begin()!=T.end()){
		list_if(T,T.begin(),L,pred);
	}
	
	
	
}
int main() {
	string s_arbol1("(2 3 (4 -5 (6 7 -8))(9 -10) (22 -12 (13 -14 15))");
	tree<int> arbol1;
	lisp2tree(s_arbol1,arbol1);
	tree2dot(arbol1);
	
	list<int>L;
	
	list_if(arbol1,L,positive);
	cout<<"Listado de positivos: "<<endl;
	show_list(L);
	
	
	return 0;
}







