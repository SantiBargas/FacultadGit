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
/*[Ej. 1] [sign-split] Implemente una función
  void sign_split(list<int> &L,vector< list<int> > &VL); que dada una lista L, retornar el un
    vector de listas VL las sublistas contiguas del mismo signo (el caso 0 es considerado junto con los
   positivos, es decir separa negativos de no-negativos).
    Ejemplos:
    L:[4,-3,-5,-4,-5,-1,4,-1,-5,-5,1,-5,3,3,0,2,2],
    => VL:[[4],[-3,-5,-4,-5,-1],[4],[-1,-5,-5],[1],[-5],[3,3,0,2,2]],
    L:[0,4,-2,4,1,-1,-4,-4,-3,-1,-4,4,1],
    => VL:[[0,4],[-2],[4,1],[-1,-4,-4,-3,-1,-4],[4,1]],
    L:[2,-1,3,-3,3,-3,0,-1,-2,0],
    => VL:[[2],[-1],[3],[-3],[3],[-3],[0],[-1,-2],[0]],
    Ayuda:
    Chequear el signo s del primer elemento y extraer tantos elementos de ese signo como se pueda
    para ponerlos en VL[0].
    Invertir el signo (s=-s) y repetir, para poner la siguiente sublista en VL[1].
    Seguir así, invirtiendo s en cada iteración hasta que se acaben los elementos de L.
    El algoritmo puede ser destructivo sobre L es decir puede modificar a L o no, da igual.
    Probablemente la solución más simple es la destructiva, extrayendo los elementos de L a medida
    que se insertan en los VL[j].
    Tal vez convenga escribir una función int sign(int x); que retorna el “signo” de acuerdo a la
      convención establecida, es decir sign(0) debe retornar 1.*/


// Funcion `signo' pero modificada. El 0 se considera junto
// con los positivos.
int sign(int x) { 
  return (x>=0? 1: -1); 
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void sign_split(list<int> &L,vector< list<int> > &VL) {
  // Limpiar el contenedor de salida por las dudas
  VL.clear();
  // Si L esta vacia VL tambien lo esta
  if (L.empty()) return;
  // Ver el signo del primer elemento
  int s=sign(*L.begin());
  // Iterador sobre L
  auto q = L.begin();
  while (q != L.end()) {
    // Poner elementos en tmp mientras tengan el mismo signo
    // que estamos buscando actualmente
    list<int> tmp;
    while (q!= L.end() && sign(*q)==s)
      tmp.push_back(*q++);
    // Llegamos al final o bien se acabaron los de este signo.
    // Poner la lista temporaria en VL
    VL.push_back(tmp);
    // Invertir el signo
    s = -s;
  }
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void sign_join(vector< list<int> > &VL,list<int> &L) {
  // COMPLETAR AQUI....
}

void reverseStack(stack<int>&S){
  // COMPLETAR AQUI....
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  ev.eval<1>(sign_split,vrbs);
  
 /* do {

    ev.eval<1>(sign_split,vrbs);
    h1 = ev.evalr<1>(sign_split,seed,vrbs);

    ev.eval<2>(sign_join,vrbs);
    h2 = ev.evalr<2>(sign_join,seed,vrbs);

    ev.eval<3>(reverseStack,vrbs);
    h3 = ev.evalr<3>(reverseStack,seed,vrbs);

    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);*/

  return 0;
}
