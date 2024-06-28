#include <iostream>
using namespace std;


/*) Dijkstra. Programe float Dijkstra(graphW& G, int u, int v, list<int>&path) que dado el
grafo ponderado G definido como typedef map<int,map<int,float>> graphW;, implemente el
algoritmo de Dijkstra para retornar el costo del camino m´as corto entre el v´ertice de partida u y el
v´ertice de llegada v. Adem´as debe devolver en path uno de los posibles caminos. Si no hay camino
posible, retornar un n´umero muy grande (infinito).*/


typedef map<int,map<int,double>> graphW; //mapa que tiene para cada valor un adyacente con su peso
										// 1 con 2 peso 5; 1 con 5 peso 3; 2 con 3 peso 4; 2 con 1 peso 2

bool comparar(const pair<int,double>&p1,const pair<int,double>&p2){
	
	
	return isless(p1.second,p2.second);
	
	
}
float Dijkstra(graphW& G, int u, int v, list<int>&path){
	
	map<int,double> pathsTable;
	
	graphW::iterator itGW= G.begin();
	
	while(itGW!=G.end()){
		pathsTable[itG->first] = numeric_limits<double>::infinity();
	}
	
	pathsTable[u]=0;
	
	while(true){
		
		auto itPath = min_element(pathsTable.begin(),pathsTable.end(),comparar)
		
			
			
	}
	
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
	
	graph2dot(G);
	
	return 0;
}







