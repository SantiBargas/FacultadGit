#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

using namespace aed;
using namespace std;

int spaceship(btree<int> &T1,btree<int>::iterator it1,btree<int> &T2,btree<int>::iterator it2) {
  
  if(it1==T1.end() && it2==T2.end()) return 0;
  if(it1==T1.end() && it2!=T2.end())return -1;
  if(it1!=T1.end() && it2==T2.end())return 1;
  
  int rv=*it1-*it2;
  if(rv!=0) return rv;
  
 rv = spaceship(T1,it1.left(),T2,it2.left()); if (rv!=0) return rv;
  rv = spaceship(T1,it1.right(),T2,it2.right()); if (rv!=0) return rv;
  return 0;
}

int spaceship(btree<int> &T1,btree<int> &T2) {
  
 int a = spaceship(T1,T1.begin(),T2,T2.begin());
  
 if(a>0)return 1;
 if(a<0) return -1;
 return 0;

  return 0;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
// FunciÃ³n auxiliar provista por la cÃ¡tedra
list<pair<btree<char>,float>>::iterator getMin(list<pair<btree<char>,float>> & bosque){
  auto it = bosque.begin();
  list<pair<btree<char>,float>>::iterator itMini = it;
  it++;
  while(it!=bosque.end()){
    if(it->second<itMini->second){
      itMini = it;
    }
    it++;
  }
  return itMini;    
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
btree<char> makeHuffmanTree(list<pair<btree<char>,float>> & bosque){
  // COMPLETAR AQUI...
  return btree<char>();
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  /*[min-cost-sets] (Conjuntos)
  Dado un conjunto universal U de n elementos y una lista de subconjuntos de U denominada
  S = (S1, S2,...,Sm) en donde cada subconjunto Si tiene un costo asociado, se pide implementar una
  función int minCostSets(set<int>& U, vector<set<int>>& S, map<set<int>, int>& costos);
  que retorna el costo de la sublista de S de costo mínimo y que cubra todos los elementos de U. Si no se
  puede cubrir el conjunto U se debe retornar INT_MAX.
  Ejemplo 1: Retorna costo mínimo 13 correspondiente a la sublista (S2, S3).
  U = {1,2,3,4,5}
  S = {S1,S2,S3}
  S1 = {4,1,3}, Cost(S1) = 5
  S2 = {2,5}, Cost(S2) = 10
  S3 = {1,4,3,2}, Cost(S3) = 3
  Ejemplo 2: Retorna costo mínimo INT_MAX ya que no se puede cubrir U.
  U = {1,6}
  S = {S1,S2}
  S1 = {1}, Cost(S1) = 2
  S2 = {}, Cost(S2) = 4
  Ayuda:
  Escribir una función auxiliar recursiva int minCostSets(set<int>& U, vector<set<int>> S,
  map<set<int>, int>& costos, list<set<int>>& L, int pos); donde L es la lista de conjuntos
  que participan de la solución actual.
  Utilizar el índice pos para procesar el vector de conjuntos S y poder desplazarse sobre él en cada
  llamada a la recursión.
  Cuando se inserta un conjunto en la lista de conjuntos L, quitar todos sus elementos del conjunto U
  para reducir el problema y llegar a una solución. Recordar que se busca el listado de subconjuntos
  tal que su costo sea mínimo y que su unión sea igual al conjunto U.
  Por ejemplo, dado el conjunto U = {1, 2, 3, 4, 5}, si se insertó el conjunto Si = {1, 2, 3} en
  L entonces, al quitar los elementos de Si, el conjunto queda como U = {4, 5}.*/
int minCostSets(set<int>& U, vector<set<int>> S,
      map<set<int>, int>& costos, list<set<int>>& L, int pos){

  if(U.size()==0){ //cuando U esta vacio sumamos todos los elementos de L
    int costo=0;
    auto itl=L.begin();
    while(itl!=L.end()){
    
      costo = costo + costos[*itl]; ///es sumarle el second
      itl++;      
    }
    return costo;
  }
  
  if(pos < 0 ){
    
    return INT_MAX;
    
  }
  
  
  set<int>U2(U);
  list<set<int>>L2(L);
  
  L.push_back(S[pos]);
  
  for(int e:S[pos]){
    U.erase(e);
  }
  
  
  int c1= minCostSets(U,S,costos,L,pos-1);
  int c2= minCostSets(U2,S,costos,L2,pos-1);
  
  if(c1<c2) return c1;
  else{
    L = L2;
    return c2;
  }

}
  
  
  
int minCostSets(set<int>& U, vector<set<int>>& S,map<set<int>, int>& costos) {
  list<set<int>>L;
  int pos = S.size()-1;
 return minCostSets(U,S,costos,L,pos);
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {

  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  // Para el examen final
  cout << "seed: 123" << endl;
  do {
    ev.eval<1>(spaceship,vrbs);
	  h1 = ev.evalr<1>(spaceship,seed,vrbs);
    
	  ev.eval<2>(makeHuffmanTree,vrbs);
	  h2 = ev.evalr<2>(makeHuffmanTree,seed,vrbs);
    
    ev.eval<3>(minCostSets,vrbs);
    h3 = ev.evalr<3>(minCostSets,seed,vrbs);

    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    cout << endl << "Siguiente seed: ";
  } while (cin>>seed);

  return 0;
}
