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
void prom_nivel(tree<int> &T,tree<int>::iterator it,int level,map<int,int>&N,map<int,int>&S){
  
  if(it == T.end()) return;
  S[level]+=*it;
  N[level]++;
  level++;
  auto it2=it.lchild();
  while(it2!=T.end()){
    prom_nivel(T,it2++,level,N,S);
    
  }
  
}
void prom_nivel(tree<int> &T, list<float> &P) {
  
 if(T.begin()==T.end()) return;
 map<int,int>N;
 map<int,int>S;
 prom_nivel(T,T.begin(),0,N,S);
  
 for(auto p:N) {
   P.push_back(float(S[p.first])/p.second);
 }
 
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
bool pertenece(list<int>&L,int x){
  
  for(auto y:L)
    if(y==x) return true;
  return false;
}
bool es_circuito(map<int,list<int>>&G,list<int>&L){
  
  list<int>::iterator it=L.begin();
  
  while(it!=L.end()){
    
    auto itg=G.find(*it);
    it++;
    
    auto z= (it==L.end() ? *L.begin():*it);
    if(!pertenece(itg->second,z)) return false;
    
    
  }
  return true;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void map_graph(map<int,vector<int> > &Gin,map<int,int> &P,
               map<int,vector<int> > &Gout) {
  // COMPLETAR AQUI...
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
