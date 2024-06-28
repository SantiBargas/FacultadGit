#define USECHRONO
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include "eval.hpp"

using namespace aed;
using namespace std;

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void extract_range(list<int> &L1, list<int>::iterator p, 
                   list<int>::iterator q, list<int> &L2) 
{
  L2.clear();
  if (p==L1.end()) return;
  auto it1=p;
  while(it1!=L1.end() and it1!=q){
    ++it1;
  }
  if(it1!=q){return;}
  
  auto it2=p;
  while(it2!=q){
    L2.push_back(*it2);
    it2=L1.erase(it2);
  }
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int add_elements(list<int>& L, stack<int> &S) {
  
  while(!S.empty()) {
    int x = S.top(); S.pop();
    list<int>::iterator it = L.begin();
    while(it!=L.end() && *it<x) ++it;
    L.insert(it,x);
  }
  // Cuenta los valores repetidos
  int ret = 0;
  for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
    bool rep = false;
    while (next(it)!=L.end() && *it==*next(it)) {
      ++it; rep=true;
    }
    if (rep) ret++;
  }
  return ret;
  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
bool coprimos(list<int>&L) {
  
  
  // p,q recorren todos los pares distintos en L.
  // p recorre [begin,end)
  auto p=L.begin();
  while (p!=L.end()) {
    auto q=p; q++;
    // para cada p, q recorre [p+1,end)
    while (q!=L.end()) {
      // Determina si *p y *q son coprimos
      // recorre con k entre [2,min(*p,*q)] y para cada
      // k verifica si divide a *p y *q
      int k=2, min=(*p<*q? *p : *q);
      while (k<=min) {
        // Si k divide a *p y *q entonces no son coprimos
        if (*p%k==0 && *q%k==0) return false;
        k++;
      }
      q++;
    }
    p++;
  }
  
  
  return true;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  ev.eval<1>(extract_range,vrbs);
  h1 = ev.evalr<1>(extract_range,seed,vrbs);
  
  ev.eval<2>(add_elements,vrbs);
  h2 = ev.evalr<2>(add_elements,seed,vrbs);
  
  ev.eval<3>(coprimos,vrbs);
  h3 = ev.evalr<3>(coprimos,seed,vrbs);

  printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
         seed,h1,h2,h3);
  
  return 0;
}
