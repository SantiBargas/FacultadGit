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

/*[Ej. 2] [sign-join] Implemente una función
void sign_join(vector< list<int> > &VL,list<int> &L); que, dado un vector de listas VL
generar una lista L donde están
Primero concatenados todos la primera subsecuencia de no-negativos de VL[0], VL[1], ...
Después los negativos.
Después nuevamente los no-negativos.
Asi siguiendo hasta que se acaban todos los VL.
Ejemplos:
VL: [[1,2,-1,-2,3,4,-3,-4],[5,6,-5,-6,7,8,-7,-8],[-9,-10]],
=> L: [1,2,5,6,-1,-2,-5,-6,-9,-10,3,4,7,8,-3,-4,-7,-8],
VL: [[0,4,-2,4,1],[-1,-4,-4,-3,-1],[-4,4,1,3,-2],[0,3,-2,4,-5],[-5,-5,-1,-3,-2]],
=> L:[0,4,0,3,-2,-1,-4,-4,-3,-1,-4,-2,-5,-5,-1,-3,-2,4,1,4,1,3,4,-2,-5]
VL:[[-1,-1,-1,3],[-5,3,1,2],[0,2,4,-3],[-3,0,4,-3]],
=> L:[0,2,4,-1,-1,-1,-5,-3,-3,3,3,1,2,0,4,-3],
Ayuda:
Igual que en el ejercicio anterior recomendamos escribir una función int sign(int x); que
retorna el “signo” de acuerdo a la convención establecida, es decir sign(0) debe retornar 1.
Extraer todos los que tienen signo s=1 (o sea los no-negativos) de VL[0] y ponerlos en L, después
los de VL[1] y así siguiendo para todos los VL[j].
Cambiar el signo (s=-s) y realizar la misma operación.
Repetir hasta que todos los VL[j] estén vacíos.
El algoritmo puede ser destructivo sobre VL es decir puede modificar a VL o no, da igual.
Probablemente la solución más simple es la destructiva, extrayendo los elementos de los VL[j] a
medida que se insertan en L.*/
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void sign_join(vector< list<int> > &VL,list<int> &L) {

  
  // Limpiar el contenedor de salida por las dudas
  L.clear();
  // Empezamos con los no-negativos, despues alternadamente vamos
  // cambiando de signo. 
  int s=1;
  while (1) {
    // Esta bandera detecta cuando todos los contenedores
    // estan vacios para terminar
    bool all_empty = true;
    // Recorre los VL[j], *z es una lista
    auto z = VL.begin();
    while (z!=VL.end()) {
      // Actualiza el `all_empty' si algun VL[j] no esta vacio
      if(!z->empty()) all_empty=false;
      // Mientras haya elementos en *z ponerlos en L y
      // sacarlos de *z
      while (!z->empty() && sign(z->front())==s) {
        L.push_back(z->front());
        z->pop_front();
      }
      // Incrementar el iterador
      z++;
    }
    // Si estan todos vacios terminar
    if (all_empty) break;
    // Invertir el signo
    s = -s;
  }
  
  
}
/*[Ej. 3] [reverse-stack] Escribir un programa que invierta una pila S utilizando recursión. No está permitido el
  uso de constructores iterativos (while, for, etc) ni tampoco el uso estructuras de datos adicionales. Sólo
  pueden utilizarse métodos de la pila, a saber:
  S.empty()
  S.top()
  S.push(s)
  S.pop()
  Se propone el siguiente algoritmo recursivo:
  Si la pila está vacia finalizar
  Si no:
  • Guardar una copia del elemento al tope
  • Quitarlo de la pila
  • Invertir el resto de la pila
  • Insertar el elemento guardado al final de la lista invertida
  Para el último paso se requiere un método auxiliar, también recursivo, que reciba una lista e inserte un
  elemento en la base de la misma, siguiendo el siguiente algoritmo:
  Si la pila está vacía, insertar el elemento.
  Si no:
  • Almacenar una copia del elemento al tope
  • Quitarlo de la pila
  • Insertar el elemento recibido al final de la pila restante
  • Apilar el temporal en la pila resultado*/


void recursiva(stack<int>&S, int x){
  
  if(S.empty()){
    S.push(x);
  }else{
    int aux= S.top();
    S.pop();
    recursiva(S,x);
    S.push(aux);
  }

}

void reverseStack(stack<int>&S){
  
  if(!S.empty()){
  
    int aux1=S.top();
    S.pop();
    
    reverseStack(S);
    
    recursiva(S,aux1);
  
  }
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;
  
  do {

    ev.eval<1>(sign_split,vrbs);
    h1 = ev.evalr<1>(sign_split,seed,vrbs);

    ev.eval<2>(sign_join,vrbs);
    h2 = ev.evalr<2>(sign_join,seed,vrbs);

    ev.eval<3>(reverseStack,vrbs);
    h3 = ev.evalr<3>(reverseStack,seed,vrbs);

    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);

  return 0;
}
