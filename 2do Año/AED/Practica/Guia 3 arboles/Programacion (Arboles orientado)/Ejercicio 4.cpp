#include <iostream>
#include <lisp.hpp>
#include <tree.hpp>
#include <map>
#include <list>
using namespace aed;
using namespace std;

/*4) levelList El listado en ´orden de nivel de los nodos de un ´arbol lista primero la ra´iz, luego todos los
nodos de profundidad 1, despu´es todos los de profundidad 2, y as´i sucesivamente. Los nodos que
est´en en la misma profundidad se listan en ´orden de izquierda a derecha. Escribir una funci´on
void orden_de_nivel (tree <int> &T) para listar los nodos de un ´arbol en orden de nivel.*/

list<int> orden_de_nivel (tree<int>&T){
	
	list<int>L;
	map<int,list<int>>M;
	int nivel=0;
	
	orden_de_nivel(T,M,T.begin(),nivel);
	
	for(itm=M.begin();itm!=M.end(); itm++){
		L.insert(L.end(),itm->second.begin(),itm->second.end());
	}
	
	return L;
}

void orden_nivel(tree<int>&T,map<int,list<int>>&M,iterator it,nivel){
	
	map<int,list<int>>::iterator it1;
	it1=M.find(nivel);
	if(it1!=M.end()) {
		it1->second.push_back(*it);
	}else{
		M.insert({nivel, {*it}})
	}
	tree<int>::iterator itt=it.lchild();
	
	while(itt!=T.end()){
		orden_de_nivel(T,M,itt,nivel+1)
		++itt;
	}
	
}
int main() {
	tree<int> T;	lisp2tree("(1 2 3 (4 (5 7 8 (9 10)) 6))",T);
	
	return 0;
}







