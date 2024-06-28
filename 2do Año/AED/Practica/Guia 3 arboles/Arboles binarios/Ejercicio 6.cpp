#include <iostream>
#include <btree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;
/*6) compbtree. Se define una relaci´on de orden entre ´arboles binarios de enteros de la siguiente forma:
A < B si a < b, o bien (a = b y Ai < Bi), o bien (a = b y Ai = Bi y Ad < Bd), d´onde a, b son las
ra´ices y Ai
, Ad, Bi
, Bd son los sub´arboles izquierdos y derechos de A y B. Consigna: Escribir una
funci´on bool es_menor(tree<int> &A,tree<int> &B) que retorna verdadero si A < B.*/
bool es_menor(btree<int>&A,btree<int>::iterator itA,btree<int>&B,btree<int>::iterator itB){
	
	///Si los arboles estan vacios no es una relacion de orden
	///retorna falso
	
	if(itA==A.end() && itB==B.end()) return false;
	
	///Si A esta vacio y B no, se cumple q A<B
	if(itA==A.end()) return true;
	
	///Si B esta vacio y A no, no se cumple q B<A
	if(itB==B.end()) return false;

	///Si a < b retorna verdadero
	if(*itA < *itB) return true;
	///Si a > b retorna verdadero
	if(*itA > *itB) return false;

	
	
	///Si no sale por las condiciones anteriores entonces
	///a = b y hay q evaluar los hijos izquierdos
	
	///A_i < B_i
	if(es_menor(A,itA.left(),B,itB.left())) return true;
	
	///B_i no puede ser menor que A_i
	if(es_menor(B,itB.left(),A,itA.left())) return false;

	
	///resta evaluar los hijos derechos
	/// (a=b y A_i = B_i y A_d < B_d)
	return es_menor(A,itA.right(),B,itB.right());
}

bool es_menor(btree<int>&A,btree<int>&B){
	
	return es_menor(A,A.begin(),B,B.begin());
	
}

int main() {
	
	btree<int>BT1,BT2;
	lisp2btree("(4 (9 4 6 ) ( 8 2 3) )",BT1);
	lisp2btree("(4 (9 4 6 ) ( 9 4 5) )",BT2);

	btree2dot(BT1,"A");
	btree2dot(BT2,"B");
	
	
	if(es_menor(BT1,BT2)){
		cout<<"Se cumple la relacion de orden";
	}else{
		cout<<"No se cumple la relacion de orden";
	}
	return 0;
}







