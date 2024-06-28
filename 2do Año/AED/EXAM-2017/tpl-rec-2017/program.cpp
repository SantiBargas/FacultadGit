#define USECHRONO
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>
#include <numeric>
#include "eval.hpp"

using namespace aed;
using namespace std;

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> sum_sublist (tpl 1)
/*[Ej. 1] [tpl1 - sum_sublist]
Implemente la función list<int> sum_sublist(list<int>& L,int S) que dada una lista de enteros L
y un entero S, encuentre y retorne una sublista cuya suma sea S. Si no existe ninguna sublista con dicha
suma, retorne una lista vacía. En caso de haber varias listas que cumplan retorne la primera y la más
corta.
Ejemplos:
Para L: [1,2,6,5,8,3,4,6] y S=13 debe retornar [2,6,5]
Para L: [1,2,6,5,8,3,4,6] y S=15 debe retornar [8,3,4]
Para L: [1,2,6,5,8,3,4,6] y S=17 debe retornar []*/

list<int> sum_sublist(list<int>& L, int S) {
  
  list<int>Lsuma;
  list<int>::iterator it=L.begin();
  list<int>::iterator itcomp=L.begin();
  list<int>Lvacia{};
  int sum;
  
  while(it!=L.end()){
    
    Lsuma.clear();
    itcomp=it;
    sum=0;
    while(itcomp!=L.end()){
      
      Lsuma.push_back(*itcomp);
      
      sum+=*itcomp;
        
      if(sum>S) break;
      if(sum==S){
        return Lsuma;
      }else{
        itcomp++;
      }
    }
    it++;
    
  }
  if(sum!=S){
    return Lvacia;
  }
  
}


//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> discrete_moving_mean (tpl 1)
/*[Ej. 2] [tpl1 - discrete_moving_mean] Implemente la función
  list<int> discrete_moving_mean(list<int>& L, int w) que dada una lista de enteros L y un
  entero w, retorne una lista con los valores de la media móvil con ventana fija de tamaño w. El primer
  elemento será el promedio (en división entera) de los primeros w elementos de L; el segundo será el
    promedio desde el 2 elemento al w+1; y en general, el elemento en la posición N de la lista resultado, será
      el promedio entre los elementos [N,w+N) de L.
        Ejemplos:
        Para L: [1,2,6,5,8,3,4,6] y w=2 debe retornar [1,4,5,6,5,3,5]
        Para L: [1,2,6,5,8,3,4,6] y w=3 debe retornar [3,4,6,5,5,4]
        Para L: [1,2,6,5,8,3,4,6] y w=4 debe retornar [3,5,5,5,5]*/
list<int> discrete_moving_mean(list<int>& L, int w){
  
  
 list<int> prom;
 list<int>::iterator it=L.begin();
 
  while(it!=L.end()){
   
    auto it2=it;
    int sum=0;
    for(int i=0;i<w;i++) { 
     
      sum+=*it2;
      it2++;
    }
    sum=sum/w;
    prom.push_back(sum);
    if(it2==L.end()){
      break;
    }
    
    it++;
    
  }
  
  return prom;
}


//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> d10s (tpl 2)

list<int> d10s(tree<int> &T){
  return {};
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> is_cycle (tpl 2)

bool is_cycle(graph_t &G) {
  return false;
}


//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> existe_subc (tpl 3)

bool existe_subc(set<int> &S, int n) {
  return false;
}


//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> replace_btree (tpl 3)

void replace_btree(btree<int>&T,bt_fun_t f){
  return;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=-1,h2=-1,h3=-1,h4=-1,h5=-1,h6=-1;
  
  do {
    ev.eval<1>(sum_sublist,vrbs);
//    h1 = ev.evalr<1>(sum_sublist,seed,vrbs);
    
    ev.eval<2>(discrete_moving_mean,vrbs);
//    h2 = ev.evalr<2>(discrete_moving_mean,seed,vrbs);
    
//    ev.eval<3>(d10s,vrbs);
//    h3 = ev.evalr<3>(d10s,seed,vrbs);
    
//    ev.eval<4>(is_cycle,vrbs);
//    h4 = ev.evalr<4>(is_cycle,seed,vrbs);
    
//    ev.eval<5>(existe_subc,vrbs);
//    h5 = ev.evalr<5>(existe_subc,seed,vrbs);
    
//    ev.eval<6>(replace_btree,vrbs);
//    h6 = ev.evalr<6>(replace_btree,seed,vrbs);
    
    printf("S=%03d  ->  H1=%03d H2=%03d  H3=%03d H4=%03d  H5=%03d H6=%03d\n",
           seed,h1,h2,h3,h4,h5,h6);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);
  
  return 0;
}
