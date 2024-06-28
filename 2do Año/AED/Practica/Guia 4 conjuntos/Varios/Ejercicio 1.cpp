#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/*1) listarABB. Programe una funci´on void listar_ABB(btree<int> &BT) que muestre en orden
ascendente los elementos del conjunto implementado como ABB*/


void listar_ABB(btree<int> &BT,btree<int>::iterator p){

	if(p==BT.end()) return;
	
	listar_ABB(BT,p.left()); //Menores
	cout<<*p<<" ";
	listar_ABB(BT,p.right()); //Mayores
}	

void listar_ABB(btree<int> &BT){
	
	return listar_ABB(BT,BT.begin());
	
}

int main() {
	
	btree<int>BT1;
	lisp2btree("(10 (5 . 7) (14 12 (18 15 .))) ",BT1);

	
	listar_ABB(BT1);
	btree2dot(BT1);	
	return 0;
}







