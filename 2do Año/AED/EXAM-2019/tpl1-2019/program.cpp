#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

using namespace aed;
using namespace std;

list<vector<int>> Pareto(list<vector<int>>&L){
  // COMPLETAR AQUI...
  return list<vector<int>>();
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  /*[Ej. 2] [merge-kway] (cola)
    Implementar una función void merge_kway(vector< queue<int> > &qords,queue<int> &merged)
    que dado un vector de colas ordenadas ordqs, obtener la cola merged resultante de la fusión de todas
    las colas en una sola, de forma de que los elementos siguen ordenadas. Por ejemplo si
    ordqs=((1,3,5,6),(0,3,5,8),(6,9,10)) entonces debe dar merged=(0,1,3,3,5,5,6,6,8,9,10). El
    algoritmo puede ser destructivo sobre ordqs.
    Trabajo Práctico de Laboratorio 1. [2019-09-05] */
  
  
void merge_kway(vector< queue<int> > &qords,queue<int> &merged) {
  // COMPLETAR AQUI...
  int indice;
  int min_elemento;

  while(!qords.empty()){
    indice=0;
    min_elemento= qords[0].front();
    
    for(int i=1;i<qords.size();i++) {  
      
      if(qords[i].front()<min_elemento){
        min_elemento=qords[i].front();
        indice=i;
      }
    }
    merged.push(min_elemento);
    qords[indice].pop();
    if(qords[indice].empty()){
      qords.erase(indice+qords.begin());
    }
  }
  
  
 
}

bool is_balanced(string &expr){
  
  stack<char> S;
  
  for(int i=0;i<expr.size();i++){
    
    char ch=expr[i];
    if(ch == '{' || ch== '[' || ch == '('){
      S.push(ch);
    }
    else if(ch == '}' || ch== ']' || ch == ')'){
      
      if(S.empty()) return false;
      
      
      char ch1 = S.top();
      
      
      switch(ch){
        
      case '}': 
        if(ch1 == '{') S.pop();
        else return false;
        break;
      case ']':
          if(ch1 == '[') S.pop();
          else return false;
          break;
      case ')':
          if(ch1 == '(') S.pop();
          else return false;
          break;
      }
    }
  }
  return S.empty();//si esta vacia retorna true
}
 
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

int main() {

  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  cout << "seed: 123" << endl;
  do {
    ev.eval<1>(Pareto,vrbs);
    h1 = ev.evalr<1>(Pareto,seed,vrbs);

    ev.eval<2>(merge_kway,vrbs);
    h2 = ev.evalr<2>(merge_kway,seed,vrbs);
    
    ev.eval<3>(is_balanced,vrbs);
    h3 = ev.evalr<3>(is_balanced,seed,vrbs);
    
    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    cout << endl << "Siguiente seed: ";
  } while (cin>>seed);

  return 0;
}
