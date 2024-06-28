#define USECHRONO
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include "eval.hpp"

using namespace aed;
using namespace std;
/*[Ej. 1] [extract-range] Dada una lista de enteros L1 y dos iteradores en la misma p,q, extraer el rango [p,q) de
L1 en la lista L2. Por ejemplo si L1=(0,4,3,5,2,7,1,8) y *p=4, *q=1, entonces
extract_range(L1,p,q,L2) debe dejar L1=(0,1,8), L2=(4,3,5,2,7).
Nota1: Ambos p,q pueden ser end()
Nota2: Puede ocurrir que q esté antes de p en cuyo caso L2 debe retornar vacío. Por ej.: si
L1=(0,4,3,5,2,7,1,8) y *p=7, *q=5, entonces debe quedar: L1=(0,4,3,5,2,7,1,8), L2=().
Consigna: Escribir una función
void extract_range(list<int> &L1, list<int>::iterator p,
list<int>::iterator q, list<int> &L2);*/
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

void extract_range(list<int> &L1, list<int>::iterator p, 
                   list<int>::iterator q, list<int> &L2) 
{
  L2.clear();
  if (p==L1.end()) return;
  auto it1=p;
  while(it1!=L1.end() and it1!=q){
    ++it1;
  }
  if(it1!=q){return;}
  
  auto it2=p;
  while(it2!=q){
    L2.push_back(*it2);
    it2=L1.erase(it2);
  }
}


/*[Ej. 2] [add-elements] Insertar cada uno de los elementos de la pila S en la lista ordenada L, la cual debe
permanecer ordenada luego de la inserción. La función debe retornar la cantidad de números repetidos
en la lista L luego de la inserción. Tener en cuenta que si hay más de dos ocurrencias del mismo número,
dicho número cuenta una única vez en la suma de elementos repetidos.
Ejemplos:
(ej1): S=[-3,4], L=[-1,4,4,7] --> L = [-3,-1,4,4,4,7], ret=1
(ej2): S=[-3,4], L=[-3,4,7] --> L = [-3,-3,4,4,7], ret=2.
(ej3): S=[-3,4], L=[-3,4,7,10,10] --> L = [-3,-3,4,4,7,10,10], ret=3.
Nota: La cantidad de elementos distintos es independiente de si estos elementos duplicados se
originaron al insertar los nuevos elementos o existían previamente o ambas cosas a la vez.
Consigna: Escribir una función int addElements(list<int>& L, stack<int> &S);
que realiza la tarea indicada.*/
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int add_elements(list<int>& L, stack<int> &S) {
 
  // Inserta todos los elementos de S en L
  // manteniendo L ordenada
  while(!S.empty()) {
    int x = S.top(); S.pop();
    list<int>::iterator it = L.begin();
    while(it!=L.end() && *it<x) ++it;
    L.insert(it,x);
  }
  // Cuenta los valores repetidos
  int ret = 0;
  for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
    bool rep = false;
    while (next(it)!=L.end() && *it==*next(it)) {
      ++it; rep=true;
    }
    if (rep) ret++;
  }
  return ret;
}
}
/*[Ej. 3] [coprimos] Escribir una función bool coprimos(list<int> &L); que retorna true si todos los
elementos de L son coprimos entre sí. Recordemos que dos enteros son coprimos entre sí el único
entero que divide a ambos es 1.
Por ejemplo:
12,15 no son coprimos ya que 3 es divisor de ambos.
10,21 son coprimos ya que no tienen ningún divisor (>1) común.
Nota: Todos los enteros x en L son x>1.
Ayuda:
Escribir una función auxiliar
void divisors(int x,list<int> &divs); que retorna en divs los divisores del entero x. Para
ello recorre todos los enteros en [2,x] y los incluye en divs si dividen a x.
Escribir una función bool coprimos(int x,int y); que chequea si x,y son coprimos. Para ello
genera los divisores de x y los de y y verificar si no hay elementos comunes en ambos.
Recorrer todos los pares de valores xi,xj en L (con i!=j) chequear si son coprimos entre sí.*/

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void divisors(int x,list<int> &divs){
  
  int i=2;
  while(i<=x){
    if(x%i==0){
      divs.push_back(i);
      i++;
    }
  }
  
}
  // Retorna true si x esta en la lista divs
bool contiene(int x, list<int>&divs){
  
  for(auto it=divs.begin();it<divs.end();it++){
    if(*it==x){
      return true;
    }
    
  }
  return false;
  
}

bool repetidos(list<int>::iterator it1,list<int>::iterator it2){
 
  if(it1 == it2) return false;
  list<int>::iterator ita = it1;
  ita++;
  while(ita != it2){
    if(*ita == *it1)
      return true;
    ita++;
  }
  it1++;
  return repetidos(it1,it2);
  
}
  
bool coprimos(list<int>&L) {
  list<int>::iterator it = L.begin(),it2;
  it2 = it;it2++;
  if(repetidos(L.begin(),L.end()))return false;
  list<int> divs;
  divisores(*(L.begin()), divs);
  it++;
  while(it!= L.end()){
    list<int> aux;
    divisores(*it, aux);
    for(auto x : aux){
      if(contiene(x,divs))
        return false;
      else divs.push_back(x);
    }
    it++;
  }
  
  return true;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  ev.eval<1>(extract_range,vrbs);
  h1 = ev.evalr<1>(extract_range,seed,vrbs);
  
  ev.eval<2>(add_elements,vrbs);
  h2 = ev.evalr<2>(add_elements,seed,vrbs);
  
  ev.eval<3>(coprimos,vrbs);
  h3 = ev.evalr<3>(coprimos,seed,vrbs);

  printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
         seed,h1,h2,h3);
  
  return 0;
}
