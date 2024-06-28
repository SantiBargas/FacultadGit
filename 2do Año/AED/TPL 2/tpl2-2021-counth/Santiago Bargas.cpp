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

int countheight(tree<int> &T,tree<int>::iterator it,map<int,int> &count) {

  int altura=-1,alturamax=-1;
  if(it==T.end()) return -1;
  auto c=it.lchild();
  
  while(c!=T.end()){
    altura=countheight(T,c++,count);
    count[altura]=count[altura]+1;
    
    if(altura>alturamax){
      alturamax=altura;
    }
  }
 return (alturamax + 1);
  
}

void countheight(tree<int> &T,map<int,int> &count) {

  int alturaraiz=countheight(T,T.begin(),count);
  count[alturaraiz]++;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0;
  ev.eval<1>(countheight,vrbs);
  return 0;
}
