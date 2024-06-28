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

bool tree_less(tree<int> &T1,tree<int> &T2) {
  //COMPLETAR
  return false;
}

/*[Ej. 2] [tpl1 - xcommon]
  Implemente una función void xcommon(list<int> &L1,list<int> &L2,list<int> &common) tal que
  dadas dos listas L1 y L2 extraiga la parte común del comienzo de Lcommon, de tal forma que
  L2=(Lcommon,Ltail1) y L2=(Lcommon,Ltail2). Adicionalmente, los argumentos L1, L2 deben quedar
  con las ”colas” correspondientes Ltail1 y Ltail2.
  Ejemplo: si L1=(0,3,2,1,5,6) y L2=(0,3,2,4) ? Lcommon=(0,3,2), L1=(1,5,6), L2=(4)*/
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void xcommon(list<int> &L1,list<int> &L2,list<int> &Lcommon) { //este
  
  list<int>::iterator itL1=L1.begin();
  list<int>::iterator itL2=L2.begin();
  
  while(itL1!=L1.end() && itL2!=L2.end()){
    
    if(*itL1==*itL2){
      Lcommon.push_back(*itL1);
      L1.erase(itL1);
      L2.erase(itL2);
    }else{
      break;
    }
    itL1++;
    itL2++;
    
    
  }
  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void xsubtrees(btree<int> &T, int depth,
               list< btree<int> > &subtrees) {
  //COMPLETAR
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int maxsubk(set<int> S, int k){
  //COMPLETAR
  return 0;
}
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

int num_path(map<int,set<int>>& G, int i, int j){
  //COMPLETAR
  return 0;
}


 /*[Ej. 6] [tpl1 - super-stable-partition]
  Escribir una función super_stable_partition que reciba una lista con enteros L y dos listas vacías
  L_low y L_geq, y:
  determine si existe alguna posición para particionar la lista en dos sublistas según el valor de dicha
  posición, sin reordenarla. Es decir, debe encontrar una posición tal que todos los elementos previos
  a la misma sean menores al valor que hay en dicha posición, y todos los elementos posteriores
  sean mayores o iguales.
  si existe tal posición (si hay más de una, tome la primera en la secuencia), mueva (splice) ambas
  partes a las listas L_low (menores) y L_geq (mayores o iguales) y retorne true; si no existe retorne
  false.
  Ejemplos
  L = {5,3,2,7,9,7,10} ? true, L = {} L_low = {5,3,2}, L_geq = {7,9,7,10}
  L = {1,3,2,7,9,7,1} ? true, L = {}, L_low = {}, L_geq = {1,3,2,7,9,7,1}
  L = {10,3,2,7,9,7,11} ? true, L = {}, L_low = {10,3,2,7,9,7}, L_geq = {11}
  L = {5,3,2,7,9,7,1} ? false, L = {1,3,2,7,9,7,1}, L_low = {}, L_geq = {}
  Ayuda
  Escribir una función auxiliar que dada una lista y una posición, determine si dicha posición es váida
  para generar la partición
  Recorrer la lista L determinando en cada posición si es o no válida con la función auxiliar:
  • Si una posición es válida:
  ? Mover (splice) a L_low desde el comienza hasta esa posición
  ? Mover (splice) a L_geq todo lo que queda en L
  ? Finalizar retornando true
  Si no se encontró posición válida, retornar false*/ 
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
int posicionvalida(list<int> &L, list<int>::iterator p) {
  for(auto it=L.begin();it!=p;++it)
    if (*it>=*p) return false;
  for(auto it=p;it!=L.end();++it)
    if (*it<*p) return false;
  return true;
}
  
bool super_stable_partition(list<int> &L,list<int> &L_low,list<int> &L_geq) {
  for(auto it=L.begin();it!=L.end();++it) {
    if (posicionvalida(L,it)) {
      L_low.splice(L_low.begin(),L,L.begin(),it);
      L_geq.splice(L_geq.begin(),L,it,L.end());
      return true;
    }
  }
  return false;
}

  
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0,h4=0,h5=0,h6=0;

  do {

    ev.eval<1>(tree_less,vrbs);
    h1 = ev.evalr<1>(tree_less,seed,vrbs);

    ev.eval<2>(xcommon,vrbs);
    h2 = ev.evalr<2>(xcommon,seed,vrbs);

    ev.eval<3>(xsubtrees,vrbs);
    h3 = ev.evalr<3>(xsubtrees,seed,vrbs);

    ev.eval<4>(maxsubk,vrbs);
    h4 = ev.evalr<4>(maxsubk,seed,vrbs);
   
    ev.eval<5>(num_path,vrbs);
    h5 = ev.evalr<5>(num_path,seed,vrbs);
    
    ev.eval<6>(super_stable_partition,vrbs);
    h6 = ev.evalr<6>(super_stable_partition,seed,vrbs);
    
    printf("S=%03d -> H1=%03d H2=%03d H3=%03d H4=%03d H5=%03d H6=%03d\n",
           seed,h1,h2,h3,h4,h5,h6);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);

  return 0;
}
