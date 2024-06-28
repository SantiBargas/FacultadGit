#define USECHRONO
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

using namespace aed;
using namespace std;

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
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

/*[Ej. 2] [es-circuito] Dado un grafo G representado por un map de nodos a lista de vecinos
(map<int,list<int>>), y una lista de nodos list<int> L , escriba una función
bool esCircuito(map<int,list<int>>&G,list<int>&L) que determine si la secuencia de nodos L es
un camino dentro del grafo G.
Ejemplos:
G=(1->{2,4},2->{1,3},3->{2,4},4->{1,3}), L={1,2,3,4} -> true.
G=(1->{2},2->{1,3},3->{2,4},4->{3}), L={1,2,3,4} -> false.*/
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
// Retorna `true' si x esta en `L'
bool contiene(list<int>&L,int x){
  for(auto y : L)
    if(y == x) return true;
  return false;
}
  
bool es_circuito(map<int,list<int>>&G,list<int>&L){
  
  ///recorre los elementos de L
  list<int>::iterator it= L.begin();
  while(it!=L.end()){
    // En cada iteracion it y ++it son dos vertices
    // consecutivos en L
    map<int,list<int>>::iterator itg= G.find(*it);
    ++it;
    //es el siguiente (o begin() si llegamos al final
    auto z=(it==L.end() ? *L.begin():*it);
    if(!contiene(itg->second,z)) return false;
  }
  return true;
}
/*Ej. 3] [map-graph] Dado un grafo
  typedef map<int,vector<int>> graph_t;
  graph_t Gin;
  y una permutación map<int,int> P, encontrar el grafo Gout que resulta de permutar los vértices de Gin
  por la pertmutación P, es decir si la arista (j,k) está en Gin, entonces la arista (P[j],P[k]) debe estar
  en Gout.
  Consigna: Escribir una función
  void map_graph(graph_t &Gin,map<int,int> &P,graph_t &Gout);
  Ejemplos:
  Gin= (0->{1}, 1->{0,2,3},2->{1,4},3->{1,4},4->{2,3}),
  P=(0->1,1->2,2->3,3->4,4->0)
  Debe quedar:
  Gout= (0->{3,4},1->{2},2->{1,3,4},3->{2,0},4->{2,0}),
  Gin= (0->{1}, 1->{0,2,3},2->{1,4},3->{1,4},4->{2,3}),
  P=(0->1,1->0,2->2,3->4,4->3)
  Debe quedar:
  Gout= (0->{1,2,4},1->{0},2->{0,3},3->{2,4},4->{0,3}),
  Nota: En Gout los vecinos del grafo deben quedar ordenados de menor a mayor.
  Ayuda: Con un doble lazo recorrer las aristas de Gin. Para cada arista (i,j) en Gin agregar la arista
  (P[i],P[j]) en Gout.*/
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>  
void map_graph(map<int,vector<int> > &Gin,map<int,int> &P,
               map<int,vector<int> > &Gout) {
  
  for (auto it=Gin.begin();it!=Gin.end();it++){
    
    int j= it->first;
    
    for(auto it2= it->second.begin(); it2 != it->second.end(); it2++){
      
      int k = *it2;
      int Pj = P[j];
      int Pk = P[k];
      Gout[Pj].push_back(Pk);
      
    }
  }
  for (auto it=Gout.begin();it!=Gout.end();it++){
    
    sort(it->second.begin(),it->second.end());
    
  }
  
}
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  do {
    ev.eval<1>(prom_nivel,vrbs);
    h3 = ev.evalr<1>(prom_nivel,seed,vrbs);
    
    ev.eval<2>(es_circuito,vrbs);
    h1 = ev.evalr<2>(es_circuito,seed,vrbs);
    
    ev.eval<3>(map_graph,vrbs);
    h2 = ev.evalr<3>(map_graph,seed,vrbs);

    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);

  return 0;
}
