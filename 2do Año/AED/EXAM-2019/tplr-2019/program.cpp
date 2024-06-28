#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

#include <set>
#include <vector>
#include <list>
#include <numeric>

using namespace aed;
using namespace std;

//VALIDO TPL 1
/*[Ej. 1] [media-movil-entera] (TPL1) Implemente la función
  list<int> mediaMovilEntera(list<int>& L, int v) que dada una lista de enteros L, retorne una
  lista con los valores de la media móvil con ventana fija de tamaño v.
  El primer elemento de la lista resultado será el promedio (en división entera) de los primeros v elementos
  de L, el segundo será el promedio desde el 2do elemento al v+1. En general, el elemento en la posición j
  de la lista resultado será el promedio entre los elementos [j,j+v) de L
    Ejemplos:
    Para L=[1,2,6,5,8,3,4,6] y v=2 debe retornar [1,4,5,6,5,3,5]
    Para L=[1,2,6,5,8,3,4,6] y v=3 debe retornar [3,4,6,5,5,4]
    Para L=[1,2,6,5,8,3,4,6] y w=4 debe retornar [3,5,5,5,5]*/


list<int> mediaMovilEntera(list<int>& L, int v){
  
  if(v==0) return list<int>();
  
  list<int>::iterator it1=L.begin();
  list<int>::iterator it2=L.begin();
  list<int>::iterator itf=L.end();
  advance(itf,-v+1); //para no salirnos de la lista cuando ya no quedan v elementos para sumar
  //sumamos 1 para q no quede afuera el valor que debemos incluir
  
  list<int> Lprom;
  int sum;
  int c; //contador
  
  while(it1!=itf){
    
    sum=0;
    c=0;
    it2=it1;
    while(it2!=L.end() and c < v){ // el contador tiene q ser menor a la ventana
      
      sum += *it2;
      ++it2;
      c++;
      
    }
    Lprom.push_back(sum/v); //el promedio
    ++it1;
    
    
    
  }
  return Lprom;
}

//VALIDO TPL 3
int nSumaK(set<int> &S, int k) {
  return 0;
}


//VALIDO TPL 2
int nCaminosK(map<int,set<int>> &G, int a, int b, int k) {
  return 0;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
//VALIDO TPL 3
void make_heap(btree<int> &T) {
}


/*[Ej. 5] [sort-stack](TPL1) Escribir un programa que ordene una pila S utilizando recursión de forma tal que los
elementos de mayor valor se encuentren en el tope. No está permitido el uso de constructores iterativos
(while, for, etc) ni tampoco el uso estructuras de datos adicionales. Sólo pueden utilizarse métodos de
la pila, a saber:
S.empty()
S.top()
S.push(s)
S.pop()
Se propone el siguiente algoritmo recursivo:
Si la pila está vacía finalizar
Si no:
• Guardar una copia del elemento al tope.
• Quitarlo de la pila.
• Ordenar el resto de la pila.
• Insertar el elemento guardado al tope de la pila ordenada.
Para el último paso se requiere un método auxiliar, también recursivo, que reciba un elemento y una pila
e inserte dicho elemento en forma ordenada, siguiendo el siguiente algoritmo:
Si la pila está vacía o si el elemento a insertar es mayor al tope, insertar el elemento.
Si no:
• Almacenar una copia temporal del elemento al tope.
• Quitarlo de la pila.
• Insertar el elemento recibido en forma ordenada recursivamente.
• Apilar el elemento temporal en la pila resultado.*/

//VALIDO TPL 1

void insertar(int e, stack<int>&s){
  
  if(s.empty() or e > s.top()){
   
    s.push(e); //si esta vacia o es mayor al elemento del tope, insertamos el elemento para ordenar
    
  }else{
                      //si e es menor entra al else, se borra el tope y
    int aux= s.top();  //hacemos la llamada a la funcion recursiva para ver si puedo
    s.pop();          //meter e a la pila
    insertar(e,s);  
    s.push(aux);
  }
  
}

void sortStack(stack<int>& s) {
  
  if(s.empty())return;
  
  int aux1=s.top();
  s.pop();
  sortStack(s);
  insertar(aux1,s);

}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0,h4=0,h5=0;

  // Para el examen final
  cout << "seed: 123" << endl;
  do {
    ev.eval<1>(mediaMovilEntera,vrbs);
    h1 = ev.evalr<1>(mediaMovilEntera,seed,vrbs);
    
 //   ev.eval<2>(nSumaK,vrbs);
  //  h2 = ev.evalr<2>(nSumaK,seed,vrbs);

   // ev.eval<3>(nCaminosK,vrbs);
 //   h3 = ev.evalr<3>(nCaminosK,seed,vrbs);
    
  //  ev.eval<4>(make_heap,vrbs);
 //   h4 = ev.evalr<4>(make_heap,seed,vrbs);

    ev.eval<5>(sortStack,vrbs);
    h5 = ev.evalr<5>(sortStack,seed,vrbs);
    
    printf("S=%03d -> H1=%03d H2=%03d H3=%03d H4=%03d H5=%03d\n",
           seed,h1,h2,h3,h4,h5);
    
    cout << endl << "Siguiente seed: ";
  } while (cin>>seed);
  
  return 0;
}
