#include <iostream>
#include <list>
#include <map>
using namespace std;
/*CompConexa. Dado un grafo como map<int,list<int>> G encontrar los subconjuntos del mismo
	list<list<int>> D que est´an desconectados, es decir, los conjuntos de v´ertices de cada una de las
	componentes conexas. Por ejemplo, si G={1->{2},2->{1},3->{4},4->{3}}, entonces debe
	retornar D=({1,2},{3,4}). La signatura de la funci´on a implementar es
	void comp_conexas(map<int,list<int>> &G, list<list<int>> &D).*/

typedef map<int,list<int>> graph;

list<int> genCompConexa(graph& G,map<int,bool>&visitados, int label, list<int>&cc){
	visitados[label];
	cc.push_back(label);
	list<int>& adyacentes= G[label];
	
	
	for(auto vecino:adyacentes){
		
		if(visitados.find(vecino)==visitados.end()){
			genCompConexa(G,visitados,vecino,cc);
		}
	}
	
	
}

list<list<int>> compConexas(graph& G){
	list<list<int>> CC;
	
	map<int,bool> visitados;
	
	while(visitados.size()<G.size()){
		
		int label;
		//busco algun vertice que no haya sido visitado
		for(auto vertice:G){
			if(visitados.find(vertice.first)==visitados.end()){ //si no esta visitado asigna el nodo a la etiqueta(label)
				label=vertice.first;
				break;
			}
		}
		//generar su componente conexa
		list<int>cc;
		genCompConexa(G,visitados,label,cc);
		
		
		
		CC.push_back(cc);
	}
	
	return CC;
}

int main() {
	
	return 0;
}







