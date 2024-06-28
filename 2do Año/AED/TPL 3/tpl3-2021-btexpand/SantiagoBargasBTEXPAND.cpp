#define USECHRONO
#undef HAVE_MPI

typedef int (*mapfun_t)(int);

int f1(int x) { return x-3; }
int f2(int x) { return x-2; }
int f3(int x) { return (x>20? -1 : 2*x); }

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
void btexpand(btree<int> &B,int root,mapfun_t f,btree<int>::iterator it) {
  
  
  btree<int>::iterator itL=it.left();
  btree<int>::iterator itR=it.right();

  
  int x=(f(*it));
  if(x>=0){
    itL=B.insert(itL,x);
    btexpand(B,root,f,itL);
    
  }

  int c=f(*it+1);
  if(c>=0){
    itR=B.insert(itR,c);
    btexpand(B,root,f,itR);
  }
  
}
void btexpand(btree<int> &B,int root,mapfun_t f) {

  B.insert(B.begin(),root);
  btexpand(B,root,f,B.begin());
  
  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(btexpand,vrbs);
  return 0;
}
