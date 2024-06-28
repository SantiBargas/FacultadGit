#define USECHRONO
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>

using namespace aed;
using namespace std;

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
void transpose(vector<list<int> > &M,vector<list<int> > &Mt) {
  // COMPLETAR...
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
/*[Ej. 2] [homogeniza (33pt)]: Implemente una función
void homogeniza(list<int> &C, int hmin, int hmax);
que recibe una lista C de enteros ordenados en forma ascendente y la modifica de tal manera de que
entre cada elemento no exista una diferencia menor a hmin ni mayor a hmax. Se deben seguir los
siguientes lineamientos:
Se recorre la lista desde el primer elemento.
Dado un elemento a_j:
• Eliminar todos los elementos siguientes hasta que el a_{j+1} sea a_{j+1}>=a_j+hmin.
• Si a_{j+1}>a_j+hmax entonces insertar después de a_j los elementos a_j+hmax,
a_j+2*hmax, a_j+3*hmax,... mientras sean menores que a_{j+1}.
Ejemplo:
1) recibe-> C = [0, 1, 4, 5, 10, 18], hmin=2, hmax=3
sale-> C = [0, 3, 5, 8, 10, 13, 16, 18]
2) recibe-> C = [1, 10], hmin=2, hmax=3
sale-> C = [1, 4, 7, 10]
3) recibe-> C = [1, 2, 3, 4, 5], hmin=2, hmax=3
sale-> C = [1, 3, 5]*/

void homogeniza(list<int>& C, int hmin, int hmax) {

  
  
  
  
  
}
/*[Ej. 3] [bool-opers (34pt)]: Dadas dos listas ordenadas L1 y L2, escribir una función
void bool_opers(list<int> &Lxor, list<int> &Land, list<int> &L1, list<int> &L2); el
algoritmo debe generar en Lxor una nueva lista ordenada con todos los elementos que estén en sólo
una de las dos listas originales, y en Land una nueva lista ordenada con todos los elementos que estén
en ambas.
Por ejemplo, si L1=(1,3,5,7,9) y L2=(3,4,5,6,7), entonces el algoritmo debe generar las listas
Lxor=(1,4,6,9), y Land=(3,5,7).*/
//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>


void bool_opers(list<int> &Lxor, list<int> &Land, list<int> &L1, list<int> &L2) {
  
  
  auto it1=L1.begin();
  auto it2=L2.begin();
  
  while(it1!=L1.end() && it2!=L2.end()){
    
    if(*it2<*it1){
      Lxor.push_back(*it2);
      it2++;
    }else{
      if(*it1<*it2){
        Lxor.push_back(*it1);
        it1++;
      }else{
        Land.push_back(*it1);
        it1++;it2++;
      }
    }
    
    
  }
  Lxor.insert(Lxor.end(),it1,L1.end());
  Lxor.insert(Lxor.end(),it2,L2.end());
  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

 // ev.eval<1>(transpose,vrbs);
 //  h1 = ev.evalr<1>(transpose,seed,vrbs);
  
  // ev.eval<2>(homogeniza,vrbs);
  // h2 = ev.evalr<2>(homogeniza,seed,vrbs);
  
   ev.eval<3>(bool_opers,vrbs);
  // h3 = ev.evalr<3>(bool_opers,seed,vrbs);

  // Debe dar para S=123 -> H1=028 H2=361 H3=840
  // printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
  //        seed,h1,h2,h3);
  
  return 0;
}
