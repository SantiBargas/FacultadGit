#include <iostream>
#include <map>
#include <climits>
#include <list>
using namespace std;
/*Dijkstra. Programe float Dijkstra(graphW& G, int u, int v, list<int>&path) que dado el
grafo ponderado G definido como typedef map<int,map<int,float>> graphW;, implemente el
algoritmo de Dijkstra para retornar el costo del camino m´as corto entre el v´ertice de partida u y el
v´ertice de llegada v. Adem´as debe devolver en path uno de los posibles caminos. Si no hay camino
posible, retornar un n´umero muy grande (infinito).*/


typedef map<char,map<char,int>> graphW;
const int inf = INT_MAX; ///infinito


float Dijkstra(graphW& G, char ini,char fin, list<char>&path){
	
	
	
	map<char,bool>visitados;
	map<char,pair<int,char>> acum;
	//acum['c'] -----> (3,'A');
	
	for(auto node:G){ //Para cada nodo del grafo
		acum[node.first]={inf,'-'};
	}
	acum[ini] = {0,'-'};
	
	char currentnode=ini;
	
	while(currentnode!=fin){
		visitados[currentnode];
		
		map<char,int>& adyacentes = G[currentnode];
		
		int w=acum[currentnode].first;
		///Actualizar la tabla de los vecinos
		
		for(auto vecino:adyacentes){
			char label = vecino.first;
			
			if(visitados.find(label)==visitados.end()){ //si no fue visitado actualizo su valor
				float new_w = w + vecino.second;
				
				if(new_w < acum[label].first){
					acum[label].first = new_w;
					acum[label].second = currentnode;
				}
			}
		}
		///Seleccionar el siguiente nodo a evaluar
		///Entre los no visitados buscar el de menor peso en la tabla acum
		int minw=inf;
		
		for(auto columna:acum){
			if(visitados.find(columna.first)==visitados.end()){
				if(columna.second.first < minw){
					minw=columna.second.first;
					currentnode = columna.first;
				}
			}
		}
		
		
		
	}
	///Generar la lista 'hacia atras'
	
	while(currentnode!=ini){
		
		path.push_front(currentnode);
		currentnode=acum[currentnode].second;
		
	}
	path.push_front(currentnode);
	
	int W= acum[fin].first;
	return W;
}
int main() {
	graphW G2 = {
		{'A',{
			{'B',2},
		{'C',3},
		}},
	{'B',{
		{'A',2},
	{'D',5},
		{'E',2}
	}},
		{'C',{
			{'A',3},
		{'E',5}
		}},
	{'D',{
		{'B',5},
	{'E',1},
		{'Z',2}
	}},
		{'E',{
			{'B',2},
		{'C',5},
			{'D',1},
		{'Z',4}
		}},
	{'Z',{
		{'D',2},
	{'E',4}
	}}
	}; 
	
	list<char> path;
	int W = Dijkstra(G2,'A','Z',path);
	
	cout<<" camino con peso: "<<W<<" ---> (";
	for(char x:path){
		cout<<x<<" ";
	}
	cout<<")"<<endl;
	
	return 0;
}







