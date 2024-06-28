#include <iostream>
#include <lisp.hpp>
#include <btree.hpp>
#include <graphviz.hpp>
#include <tree.hpp>
using namespace aed;
using namespace std;
/*4) bin2ord. Escribir una funci´on void bin2ord(btree<int> &B, tree<int> &T) que dado un ´arbol
binario B de enteros positivos lo convierte a un ´arbol ordenado orientado con la siguiente
convenci´on: En caso de que uno de los nodos del AB tenga uno s´olo de los hijos reemplazamos el
valor por un valor landa (en este caso puede ser landa = -1).*/

void bin2ord(btree<int> &B,btree<int>::iterator itB, tree<int> &T,tree<int>::iterator itT){
	
	if(itB==B.end()) return;
	
	itT=T.insert(itT,*itB);
	
	btree<int>::iterator itB_left=itB.left();
	btree<int>::iterator itB_right=itB.right();
	
	//ES hoja cortamos
	if(itB_left ==B.end() and itB_right == B.end()){
		return;
	}
	
	//existe hijo izquierdo y no derecho
	if(itB_left !=B.end() and itB_right == B.end()){
		//llamamos a la recursion por el izquierdo
		bin2ord(B,itB_left,T,itT.lchild());
		T.insert(itT.lchild().right(),-1); //itT.lchild().right() = itT.lchild(); itT++
	
	}else if(itB_left ==B.end() and itB_right != B.end()){//existe hijo derecho y no izq
		T.insert(itT.lchild(),-1);
		bin2ord(B,itB_right,T,itT.lchild().right()); //itT.lchild tendria valor de -1 entonces queremos insertar en el hermano derecho y por eso el right
	}else{
		bin2ord(B,itB_left,T,itT.lchild());
		bin2ord(B,itB_right,T,itT.lchild().right());
	}

}

void bin2ord(btree<int> &B, tree<int> &T){
	
	bin2ord(B,B.begin(),T,T.begin());
	
}

int main() {
	btree<int> B;
	lisp2btree("(6 (8 10 (3 8)) (4 (4 (4 2 3 ))))",B);
	btree2dot(B);
	tree<int> T;
	bin2ord(B,T);
	tree2dot(T);
	return 0;
}







