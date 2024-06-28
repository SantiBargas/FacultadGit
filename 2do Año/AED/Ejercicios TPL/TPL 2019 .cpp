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
    if(qords[indice].empty()){  //elimino pq sino el while no termina nunca
      qords.erase(indice+qords.begin());
    }
  }
  
  
 
}

/*[Ej. 3] [is-balanced] (stack) Dado un string expr, implementar una función
bool is_balanced(string &expr); que determine si el par y orden de {, }, (, ), [, ] está balanceado.
Ejemplos:
[ ( ) ] { } { [ ( ) ( ) ] ( ) } está balanceado
[ ( ] ) no está balanceado.
Ayuda: Se propone el siguiente algoritmo:
Declarar una pila de char S.
Recorrer el string expr.
Si el caracter actual es un símbolo de apertura, entonces apilarlo.
Si el caracter actual es un símbolo de cierre y matchea con su símbolo de apertura, entonces
quitarlo de la pila. Si no retornar falso. Atención: Chequear que la pila no esté vacía.
Una vez recorrido todo el string, si la pila está vacía, entonces la expresión está balanceada*/


bool is_balanced(string &c) {
  
  stack<char> S;
  stack<char> Q;
  
	for(size_t i=0;i<c.size();i++){
		
		char ch=c[i];
		
		if(ch=='(' or ch=='[' or ch=='{'){
			
			S.push(ch);
			
		}else if(ch==')' or ch==']' or ch=='}'){
			if(S.empty())return false;
			
			char ch1 = S.top();
			
			switch (ch1){
				case '}': 
					
					if(ch=='{') S.pop();
					else return false;
					break; //por si se cumple el if
					
				case ']':
					
					if(ch=='[') S.pop();
					else return false;
					break;
					
				case ')':
					
					if(ch=='(') S.pop();
					else return false;
					break;
					
			}
			
		}
		
		
	}
	
	if(S.empty()) return true;
    
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
