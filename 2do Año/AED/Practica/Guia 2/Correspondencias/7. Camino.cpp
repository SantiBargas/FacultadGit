#include <iostream>
#include <map>
#include <graphviz.hpp>
#include <list>
using namespace std;

/*
Camino. Implemente la funcion bool es_camino(map<int,list<int>> G, list<int> &L) que
recibe una lista L y determina si es o no camino en el grafo G. El grafo se representa como un
mapa que relaciona cada v´ertice (clave) con la lista de sus v´ertices adyacentes (valor)
*/

typedef map<int, list<int>> Graph;



bool es_camino(map<int,list<int>> G, list<int> &L){
	if(L.empty()) return false;
	
	auto itL1 = L.begin();
	auto itL2 = itL1; 
	itL2++;
	
	if(L.size() == 1){
		auto it = G.find(*itL1);
		if(it == G.end()) return false;
	}
	
	
	while(itL2 != L.end()){
		
		auto it = G.find(*itL1);
		if(it == G.end()) return false;
		
		auto itTemp = it->second.begin();
		
		while(itTemp != it->second.end()){
			
			if(*itTemp == *itL2) break;
			itTemp++;
		}
		
		if(itTemp == it->second.end()) return false;
		
		
		itL1++;
		itL2++;
	}
	
	return true;
	
}

int main() {
	
	Graph Gl = {{1,{2,3,4,5}},
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
	{30,{8,13}}};
	list<int> L ={1,2 , 5, 7, 21};
	
	cout << es_camino(Gl, L) << endl;
		
	aed::graph2dot(Gl, "Grafo");	
	return 0;
}







