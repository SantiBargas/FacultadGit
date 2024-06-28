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
// Nombre: Bob Esponja
int DNI=43538588;

bool is_strange(list<int>& List){
  
  if(List.size()==1){
    return true;
  }
  
  auto itmax=max_element(List.begin(),List.end());
  int max=*itmax;
  
 
  for(auto it=List.begin();it!=prev(List.end());++it){
    auto itcomp=next(it);
    for(auto it2=itcomp;it2!=List.end();++it2){
      
      if(abs(*it-*it2)<max){
        return false;
      }
      
    }
  }
  return true;
}

void strange_sublist(list<int>& L,list<int>& SL)
{
  if(L.empty()) return;
  
  for(auto it=L.begin();it!=prev(L.end());++it){
    list<int>temp={*it};
    for(auto it2=next(it);it2!=L.end();++it2){
      temp.push_back(*it2);
      if(is_strange(temp) && temp.size()>SL.size()){
        SL=temp;
      }
    }
  }

  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  ev.eval<1>(strange_sublist,vrbs);
  return 0;
}
