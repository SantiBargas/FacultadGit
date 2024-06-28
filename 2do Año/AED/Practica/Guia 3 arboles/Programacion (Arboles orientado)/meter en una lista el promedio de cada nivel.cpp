#include <iostream>
#include <list>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/*[Ej. 1] [prom-nivel]
Dado un árbol tree<int> T, generar mediante la función
void prom_nivel(tree<int> &T, list<float> &P); una lista de reales P, donde el primer elemento
de la lista sea el promedio de los nodos del árbol de nivel 0, el segundo sea el promedio de los de nivel 1,
el tercero el promedio de los de nivel 2, y así sucesivamente. Es decir, que si el árbol tiene profundidad N,
la lista tendrá N+1 elementos de tipo float.
Ejemplos:
T= (5 (10 8 9) (7 3)) -> P=(5, 8.5, 6.66666666)
T= (23 78 52 (69 50) 28 (79 13)) -> P=(23, 61.2000007629395, 31.5)
Nota: recuerde que en C++ la división entre enteros siempre arroja un resultado entero (por ejemplo, 7/3
da 2). Para lograr un resultado real puede castear uno o ambos operandos a float: float(7)/3 da 2.33333.
Ayuda: utilizar una o dos estructuras auxiliares donde guardar las sumatorias y los conteos de nodos por
nivel (por ejemplo dos mapas, uno de nivel a sumatoria, otro de nivel a cantidad de nodos)*/
void show_list(list<float>& L) {
	cout<<"(";
	for(list<float>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

void prom_nivel(tree<int> &T, tree<int>::iterator it, 
				int level, map<int,int> &N, map<int,int> &S) {
	
	if (it==T.end()) return;
	S[level]+=*it; 
	N[level]++; 
	level++;
	for(auto it2=it.lchild();it2!=T.end();++it2)
		prom_nivel(T,it2,level,N,S);
}

void prom_nivel(tree<int> &T, list<float> &P) {
	if (T.begin()==T.end()) return;
	// Llama a la funcion auxiliar y calcula las sumas y
	// numero de nodos
	map<int,int> N;
	map<int,int> S;
	prom_nivel(T,T.begin(),0,N,S);
	// Va calculando el promedio
	for(auto p:N) {
		P.push_back(float(S[p.first])/p.second);
	}
}
int main() {
	tree<int> T;
	lisp2tree("(0 3 (8 3) (9 4) (2 (2 3 1)) (4 (8 7) 7))",T);
	//tree2dot(T);
	list<float>lista;
	prom_nivel(T,lista);
	show_list(lista);
	
	
	return 0;
}







