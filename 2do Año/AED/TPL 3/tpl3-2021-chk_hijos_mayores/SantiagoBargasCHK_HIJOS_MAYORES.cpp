#define USECHRONO
#undef HAVE_MPI

typedef int (*mapfun_t)(int);

int f1(int x) { return x+1; }
int f2(int x) { return x-1; }
int f3(int x) { return 2*x; }
int f4(int x) { return x; }

#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace std;

// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Bargas, Santiago
int DNI=43538588;

bool chk_hijos_mayores(btree<int> &T,btree<int>::iterator it) {
    
  btree<int>::iterator itL=it.left();
  btree<int>::iterator itR=it.right();
  
  int sum=0;
  if(itL!=T.end() && itR!=T.end()){
    sum+=*itL;
    sum+=*itR;
    
    if(sum<=*it){
      return false;
    }
    if(!chk_hijos_mayores(T,itL)) return false;
    if (!chk_hijos_mayores(T,itR))return false;
    
  }
  
  if(itL!=T.end() && itR==T.end()){
    sum+=*itL;
    if(sum<=*it){
      return false;
      
    }
    if(!chk_hijos_mayores(T,itL)) return false;
  }
  
  if(itL==T.end() && itR!=T.end()){
    sum+=*itR;
    if(sum<=*it){
      return  false;
    }
    
    if(!chk_hijos_mayores(T,itR)) return false;
    
  }
  
  return true;
  
}
bool chk_hijos_mayores(btree<int> &T) {
  
  return chk_hijos_mayores(T,T.begin());
  
}
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(chk_hijos_mayores,vrbs);

  return 0;
}
