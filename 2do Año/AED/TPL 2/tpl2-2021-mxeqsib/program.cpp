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
// Nombre: Bargas Santiago
int DNI=43538588;

void maxeqsiblings(tree<int> &T,tree<int>::iterator p,map<int,int>M) {
  if(p==T.end() return;
  
  auto c=p.lchild();
  
  M[level]++;
  
  while(c!=T.end()){
    maxeqsiblings(T,c++);
  }
}

int maxeqsiblings(tree<int> &T) {
  int nivel=0;
  count_level(T,T.end(),nivel);
  return 0;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(maxeqsiblings,vrbs);
  return 0;
}
