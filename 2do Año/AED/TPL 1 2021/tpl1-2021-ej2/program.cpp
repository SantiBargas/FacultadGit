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

// Ordena de menor a mayor los elementos de S
// por el metodo quick-sort (el menor en el tope)


int tamanio(stack<int>S){
  int cont=0;
  while(!S.empty()){
    
    S.pop();
    cont++;
    
  }
  return cont;
  
}
  
void qsort(stack<int> &S) {
  int aux1;
  int aux2;
  stack<int>temp;
  stack<int>S1;
  stack<int>S2;
  
  if(tamanio(S)<=1){
    return;
  }
  
  aux1=S.top();
  S.pop();
  aux2=S.top();
  int pivote;
  
  if(aux1>aux2){
    pivote=aux1;
  }else{
    pivote=aux2;
  }
  S.push(aux1);
  while(!S.empty()){
    int aux3=S.top();
    if(aux3<pivote){
      S1.push(aux3);
      S.pop();
    }else{
      S2.push(aux3);
      S.pop();
    }
  }
  if(tamanio(S1)>1){
    qsort(S1);
  }
  if(tamanio(S2)>1){
    qsort(S2);
  }
  
  while(!S1.empty()){
    int aux4=S1.top();
    S.push(aux4);
    S1.pop();
  }
  while(!S2.empty()){
    int aux5=S2.top();
    S.push(aux5);
    S2.pop();
  }
  while(!S.empty()){
    temp.push(S.top());
    S.pop();
  }
  
  swap(temp,S);
  
}
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs=0,seed=123;
  ev.eval<1>(qsort,vrbs);
  return 0;
}
