#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

#include <tree.hpp>
using namespace aed;
using namespace std;

void fill_ordprev(tree<int> &T,tree<int>::iterator itT,
                  list<int> &L) {

  if(itT==T.end()) return;
  if(L.empty()) return;
  
  *itT=L.front();
  
  L.pop_front();
  auto c=itT.lchild();
  while(c!=T.end()){  
    fill_ordprev(T,c++,L);
  }
}
void fill_ordprev(tree<int> &T,list<int> &L) {
  fill_ordprev(T,T.begin(),L);
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void a_lo_ancho(const map<char,set<char>>& G,const char&n,tree<char>&T, tree<char>::iterator itT,set<char>&V){
  for(char c:G.find(n)->second){
    itT=T.insert(itT,c);
    if(!V.count(c)){
      V.insert(c);
      a_lo_ancho(G,c,T,itT,V);
    }
    ++itT;
  }
}
  void a_lo_ancho(const map<char,set<char>>& G, tree<char>& T){
    T.clear();
    set<char>V;
    a_lo_ancho(G,G.begin()->first,T,T.begin(),V);
  }

void intersect_map(map<int,list<int>> &A,map<int,list<int>> &B,map<int,list<int>> &C){
  // Recorre las claves de A
  for(auto &p :A){
    auto itB = B.find(p.first);
    if(itB!=B.end()){
      // la clave esta en A y en B
      // LB es una referencia a la lista en B
      auto &LB = itB->second;
      // eA es un elemento de la lista en A 
      for(auto &eA: p.second){
        // Si el elemento esta en LB lo inserta en C
        if(find(LB.begin(),LB.end(),eA)!=LB.end()){
          C[p.first].push_back(eA);
        }
      }
    }
  }    
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

int main() {

  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  cout << "seed: 123" << endl;
  do {
    ev.eval<1>(fill_ordprev,vrbs);
    h1 = ev.evalr<1>(fill_ordprev,seed,vrbs);

    ev.eval<2>(a_lo_ancho,vrbs);
   h2 = ev.evalr<2>(a_lo_ancho,seed,vrbs);
    
    ev.eval<3>(intersect_map,vrbs);
    h3 = ev.evalr<3>(intersect_map,seed,vrbs);
    
    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    cout << endl << "Siguiente seed: ";
  } while (cin>>seed);

  return 0;
}
