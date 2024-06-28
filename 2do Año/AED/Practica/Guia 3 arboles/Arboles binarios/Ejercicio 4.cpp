#include <iostream>
#include <btree.hpp>
#include <tree.hpp>
using namespace aed;
using namespace std;
/*4) bin2ord. Escribir una funci´on void bin2ord(btree<int> &B, tree<int> &T) que dado un ´arbol
binario B de enteros positivos lo convierte a un ´arbol ordenado orientado con la siguiente
convenci´on: En caso de que uno de los nodos del AB tenga uno s´olo de los hijos reemplazamos el
valor por un valor landa (en este caso puede ser landa = -1).*/


void bin2ord(btree<int>&B, tree<int>&T,btree<int>::iterator itB,tree<int>::iterator itT){
	
	btree<int>::iterator itl = itB.left();
	btree<int>::iterator itr = itB.right();
	
	
	if(itl==B.end() and itr==B.end()){
		return;
	}
	
	tree<int>::iterator it2=itT.lchild();
	if(itl==B.end()){
		
		it2 = T.insert(it2,-1);
		++it2;
		it2 = T.insert(it2,*itr);
		bin2ord(B,T,itr,it2);
		
	}else{
		
		it2 = T.insert(it2,*itl);
		bin2ord(B,T,itl,it2); //para continuar por el lado izquierdo
		++it2; //incremento para moverme al hermano
				//si el hermano es end en el arbol T inserto un -1
		
		if(itr == B.end()){
			it2 = T.insert(it2,-1);
		}else{
			it2=T.insert(it2,*itr);
			bin2ord(B,T,itr,it2);  //volvemos a llamar la recursividad pq si estamos en el else
									//Nunca usamos recursividad por el lado derecho
		}
		
	}
	
	
	
	
}
void bin2ord(btree<int>&B, tree<int>&T){
	
	T.insert(T.begin(),*B.begin());
	bin2ord(B,T,B.begin(),T.begin());
	
}


int main() {
	
	return 0;
}







