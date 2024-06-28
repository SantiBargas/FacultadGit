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
// Nombre: Bargas, Santiago
int DNI=43538588;


void xparity(list<int> &L,int parity,vector<list<int>> &VL) {
  
  
  list<int>::iterator it=L.begin();
  list<int>tmp;
  if(L.empty()) return;
  
  if(parity==0){
    while(it!=L.end()){
      if(*it%2==0){
        while(*it%2==0 && it!=L.end()){
          tmp.push_back(*it);
          it++;
        }
        if(!tmp.empty()){
          VL.push_back(tmp);
          tmp.clear();
        }
      }else{
        it++;
      }
    }
  }  
  
  if(parity==1){
    while(it!=L.end()){
      if(*it%2!=0){
        while(*it%2!=0 && it!=L.end()){
          tmp.push_back(*it);
          it++;
        }
        if(!tmp.empty()){
          VL.push_back(tmp);
          tmp.clear();
        }
      }else{
        it++;
      }
    }
  }
  
}
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  ev.eval<1>(xparity,vrbs);
  return 0;
}
