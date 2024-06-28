#include <iostream>
#include <list>
#include <map>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/*7) Camino. Implemente la funci´on bool es_camino(map<int,list<int>> G, list<int> &L) que
	recibe una lista L y determina si es o no camino en el grafo G. El grafo se representa como un
	mapa que relaciona cada v´ertice (clave) con la lista de sus v´ertices adyacentes (valor).*/


bool es_vecino(list<int>&L, int nodo){
	list<int>::iterator it=L.begin();
	
	while(it!=L.end()){
		if(*it==nodo) return true;
		it++;
	}
	return false;
	
}

bool es_camino(map<int,list<int>> G, list<int> &L){
	list<int>::iterator itPrev= L.begin();
	list<int>::iterator it= ++L.begin();
	
	///recorre el camino
	if(L.size()<2){
		return false;
		///Si l tiene un solo nodo no es camino
	}
	while(it!=L.end()){
		///consultamos si *itPrev pertenece al grafo
		///consultamos si *it es vecino de *itPrev
		
		if(G.find(*itPrev) == G.end() || es_vecino(G[*itPrev], *it)){ //si el nodo q esta en la lista no pertenece al grafo ya se q no es camino
			///si no se cumplen ambas condiciones entonces L no es camino de G
			return false;
			
		}
		//para q sea camino tiene que pertenecer al grafo y el nodo siguiente tiene que ser un vvecino del nodo anterior
		
		itPrev++;
		it++;
		
		
	}
	
	///es camino
	return true;
}
int main() {
	
	map<int,list<int>> G={
		{2,{1,25}},
		{3,{1,6,7}},
		{4,{1,8}},
		{5,{1,9,13}},
		{6,{3}},
		{7,{3,21,25}},
		{8,{4,30}},
		{9,{5,21}},
		{13,{5,30}},
		{21,{7,9}},
		{25,{2,7}},
		{30,{8,13}}
	};
	
	list<int> L= {1,2,5,3,7};
	
	cout<<"L es camino? "<<es_camino(G,L);
	graph2dot(G);
	
	return 0;
}







