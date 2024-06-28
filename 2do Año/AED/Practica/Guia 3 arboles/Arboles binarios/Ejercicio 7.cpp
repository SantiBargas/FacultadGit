#include <iostream>
#include <lisp.hpp>
#include <btree.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

/*) contenido. Escribir una funci´on predicado bool contenido(btree<int> &A, btree<int> &B)
que retorna verdadero si la estructura del ´arbol binario A esta contenido dentro de la de B y las
etiquetas correspondientes de A son menores que las de B.*/
bool contenido(btree<int> &A,btree<int>::iterator itA, btree<int> &B,btree<int>::iterator itB){
	
	///retorna verdadero si la estructura del arbol binario A esta
	///contenido dentro de la de B y las etiquetas correspondientes de A son
	///menores que las de B
	
	
	///itA no tiene ningun valor, no importa lo que itB tenga
	if(itA==A.end()) return true;
	
	///itA tiene un valor pero itB no
	if(itB==B.end()) return false;
	
	///itB no tiene que ser mayor a itA
	if(*itB < *itA) return false;
	
	///se evalua la estructura de cada hijo de forma recursiva
	
	if(!contenido(A,itA.left(),B,itB.left())) return false;
	if(!contenido(A,itA.right(),B,itB.right())) return false;
	
	return true; 
	
	
}
bool contenido(btree<int> &A, btree<int> &B){

	return contenido(A,A.begin(),B,B.begin());
	
}
	

int main() {
	
	btree<int>BT1,BT2;
	lisp2btree("(4 (9 4 6 ) ( 8 2 3) )",BT1);
	lisp2btree("(4 (9 4 6 ) ( 9 4 5) )",BT2);
	
	btree2dot(BT1,"A");
	btree2dot(BT2,"B");
	
	
	if(contenido(BT1,BT2)){
		cout<<"Esta contenido";
	}else{
		cout<<"No esta contenido";
	}
	return 0;
}







