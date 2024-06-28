#include <iostream>
#include <map>
#include <tree.hpp>
using namespace aed;
using namespace std;
/*8) deExpansi´on Dado un grafo G, y un ´arbol T, decimos que T expande a G si la raiz n de T es un
v´ertice de G, y los caminos de T permiten llegar desde n hasta cualquier otro nodo de G. Escribir
una funci´on bool es_arbol_de_expansion(graph G, tree<int> T) que determina si T expande
a G*/
typedef map<int,map<int,bool>> graph;

bool es_arbol_de_expansion(graph &G, tree<int> T,tree<int>::iterator p){
	if(p==T.end()) return false;
	
	bool esExpansion = true;
	tree<int>::iterator c=p.lchild();
	while(c!=T.end()){
		
		if(G[*p].find(*c)==G[*p].end() || !esExpansion){
			return false;			    ///chequear que c sea una conectividad de p
		}
		
		esExpansion= es_arbol_de_expansion(G,T,c++);
	}
	return esExpansion;
	
}
	
bool es_arbol_de_expansion(graph &G, tree<int> T){
	
	//comprobamos q no esta vacio
	if(T.begin() == T.end()) return false;
	tree<int>::iterator p=T.begin();
	if(G.find(*p)==G.end()) return false; ///comprobar que el nodo esta en el grafo
	return es_arbol_de_expansion(G,T,T.begin());
}

int main() {
	
	return 0;
}
 






