#include <iostream>
#include <map>
#include <tree.hpp>
#include <climits>
using namespace aed;
using namespace std;
/*11) Prim. Programe int Prim(graphW& G, tree<int>&T) que dado el grafo no dirigido ponderado G
definido como typedef map<int,map<int,int>> graphW;, implemente el algoritmo de Prim para
hallar y retornar el ´arbol de expansi´on de costo m´inimo.*/

typedef map<char,map<int,int>>graphW;
const int INF = INT_MAX;
	
int Prim(graphW& G, tree<char>&T){
	
	graphW::iterator i=G.begin();
	tree<char>::iterator p = T.begin();
	map<char,tree<char>::iterator> visitados;
	
	///vertice de inicio
	p = T.insert(p,i->first);
	visitados[i->first] = p;  ///obtiene el primer char del algoritmo y guardamos el iterator de a
	
	
	int W=0;
	
	while(visitados.size()<G.size()){
		int min = INF;
		
		/// par aristas de menor peso
		char f,c;
		
		///Recorrer todos los vertices no visitados del grafo
		i = G.begin();
		for(int x=0;x<G.size()-1;x++, i++){
			
			char nodoActual = i->first; //esto me da la etiqueta del primer nodo
			
			///verifica que el vertice actual ya fue visitado
			if(visitados.find(nodoActual) != visitados.end()){
				
				map<char,int>&adyacentes = i->second;
				
				map<char,int>::iterator j = adyacentes.begin();
				
				///recorre todas las aristas adyacentes
				for(int y=0;y<adyacentes.size();y++, j++) { 
					char nodoAdyacente= j->first;
					
					
					///busca la arista adyacente de menor peso
					if(min > G[nodoActual][nodoAdyacente] && 
						visitados.find(nodoAdyacente)== visitados.end()){
						
						min = G[nodoActual][nodoAdyacente];///me quedo con el peso minimo
						f=nodoActual;
						c=nodoAdyacente;
					}
					
				}
				//G['A']['B'] -> me devuelve el peso de la arista A,B
			}
			
		}
		
		///suma del peso minimo al total acumulado
		W+=min;
		
		
		///armar el arbol
		p=T.insert(visitados[f].lchild(),c);
	   
		
		///agrega el vertice que marca la arista d peso minimo
		visitados[c]=p;
		
		
	}
	
	return W;
	
	
}
int main() {
	
	
	
	
	
	return 0;
}







