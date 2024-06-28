#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
 /*2) insertaABB. Programe una funci´on void inserta_ABB(btree<int> &BT, int v) que inserte v
en la posici´on adecuada de BT que permita la construcci´on de un ´arbol binario de b´usqueda*/

btree<int>::iterator findABB(btree<int>&BT,int v){
	
	btree<int>::iterator it = BT.begin();
	
	while(true){
		if(it==BT.end()){
			return it;
		}
		
		if(v<*it){
			it = it.left();
		}else if(v>*it){
			it = it.right();
		}else{
			return it;
		}
	}
}

void inserta_ABB(btree<int> &BT, int v) {
	
	btree<int>::iterator pos=findABB(BT,v);
	
	if(pos==BT.end()){
		BT.insert(pos,v);
	}
}

int main() {
	
	btree<int>BT1;
	lisp2btree("(10 (5 . 7) (14 12 (18 15 .))) ",BT1);
	
	
	inserta_ABB(BT1,13);
	btree2dot(BT1);	
	return 0;
}







