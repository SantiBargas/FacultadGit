#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace std;

// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Santiago Bargas
int DNI=43538588;

void applymap(tree<int> &T,tree<int>::iterator p,map<int,int> &M) {
  
  if(p==T.end()) return;
  
  if(M.find(*p)!=M.end()) *p=M[*p];
  
  auto itT = p.lchild();
  while(itT!=T.end()){
    if(M.find(*itT)==M.end()){
      itT = T.erase(itT);
    }
    else{
      applymap(T,itT++,M);
      
    }
  }  
}


void applymap(tree<int> &T,map<int,int> &M) {
  auto it1=M.begin();
  bool bandera=false;
  while(it1!=M.end()){
    if(it1->second==*T.begin()){
      bandera = true;
    }
    it1++;
  }
  if(bandera==false){
    T.erase(T.begin());
  }

  applymap(T,T.begin(),M);
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(applymap,vrbs);
  return 0;
}
