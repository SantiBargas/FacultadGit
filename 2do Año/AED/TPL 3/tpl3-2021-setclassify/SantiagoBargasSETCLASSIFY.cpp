#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <algorithm>
using namespace aed;
using namespace std;

// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Bargas,Santiago
int DNI=43538588;
  
void set_classify(vector<set<int>> &VS,set<int> &S0,
                  int &superset,int &subset,int &disjoint,
                  int &equal,int &other) {
  
  superset=0;
  subset=0;
  disjoint=0;
  equal=0;
  other=0;
  for(size_t i=0;i<VS.size();i++){
    
    
    set<int>aux1;
    set<int>aux2;
    set<int>aux3;
    
    set_difference(VS[i],S0,aux1);
    set_difference(S0,VS[i],aux2);
    set_intersection(VS[i],S0,aux3);
    
    if(aux1.empty() && aux2.empty()){
      equal++;
    }
    else if(aux1.empty()){
      subset++;
    }else if(aux2.empty()){
      superset++;
    }else if(aux3.empty()){
      disjoint++;
    }else{
      other++;
    }
    
  }
  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(set_classify,vrbs);
  return 0;
}
