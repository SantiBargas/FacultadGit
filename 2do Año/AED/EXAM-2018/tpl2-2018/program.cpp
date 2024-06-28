#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

#include <tree.hpp>
using namespace aed;
using namespace std;
void get_path(tree<int> &T,int n,list<int> &L,tree<int>::iterator it){
  if(*it == n){
    L.push_back(*it);
    return;
  }
  auto c = it.lchild();
  while(c != T.end()){
    get_path(T,n,L,c);
    if(L.size() != 0){
      L.push_back(*it);
      return;
    }
    c++;
  }
  return;
}
  
void get_path(tree<int> &T,int n,list<int> &L){
  get_path(T,n,L,T.begin());
  L.reverse();
  
}
void classify_relative(tree<int> &T,int n1,int n2,int &m1, int&m2) {
  list<int> L1;
  list<int> L2;
  get_path(T,n1,L1);
  get_path(T,n2,L2);
  int k;
  
  if(L1.size() > L2.size()){
    k = L1.size();
  }
  else{
    k = L2.size();
  }
  
  auto it1 = L1.begin();
  auto it2 = L2.begin();
  m1 = 0;
  m2 = 0;
  for(int i=0;i<k;i++) {
    if(it1 != L1.end()){
      m1++;
    }
    if(it2 != L2.end()){
      m2++;
    }
    if(*it1 == *it2 and it1 != L1.end() and it2 != L2.end()){
      m1 = 0;
      m2 = 0;
    }
    if(it1 != L1.end()){
      advance(it1,1);
    }
    if(it2 != L2.end()){
      advance(it2,1);
    }
    
    
  }
  return;
  
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
/*[Ej. 2] [prom-path] Dado un árbol T, escribir una función float prom_path(tree<int> &T); que retorne la
 longitud promedio de los caminos desde la raíz a las hojas. Por ejemplo, para el árbol
 T=(1 (2 3 4 (5 6)) 7 8), los 5 posibles caminos desde la raiz a una hoja son:
 {1,2,3}, {1,2,4}, {1,2,5,6}, {1,7}, {1,8}; cuyas longitudes son 2, 2, 3, 1 y 1; lo cual da un
 promedio de (2+2+3+1+1)/5 = 9/5 = 1.8*/

float prom_path(tree<int>&T, tree<int>::iterator it, int nivel,int &hojas){
  
  int sum = 0 ;

  auto it2=it.lchild();
  if(it2 == T.end()){ //es hoja
    hojas++;
    return nivel;
  }
  
  while(it2!=T.end()){
    
    sum+=prom_path(T,it2++,nivel+1,hojas);
    
  }
  
  return sum;
  
}
  

float prom_path(tree<int> &T) {
  int nivel=0;
  int sum=0;
  int hojas=0;
  auto it=T.begin();
 int a = prom_path(T,it,nivel,hojas);
  
return float(a)/hojas; 
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>


void necesario(map<string,list<string>> &G, list<string> &nece,map<string,list<string>>::iterator it){
  auto c = it->second.begin();
  while(c != it->second.end()){
    auto itt = find(nece.begin(),nece.end(),*c);
    if(itt == nece.end()){
      nece.push_back(*c);
      auto aux = G.find(*c);
      necesario(G,nece,aux);
    }
    c++;
  }
  return;
}
  
void necesario(map<string,list<string>> &G,list<string> &L, list<string> &nece){
  auto itt = L.begin();
  auto itt2 = L.begin();
  while(itt2 != L.end()){
    nece.push_back(*itt2);
    itt2++;
  }
  while(itt != L.end()){
    auto aux = G.find(*itt);
    necesario(G,nece,aux);
    itt++;
  }
  return;
}

void filtra_deps(map<string,list<string>> &G,list<string> &L) {
  list<string> nece;
  necesario(G,L,nece);
  auto itt = G.begin();
  while(itt != G.end()){
    auto itt2 = find(nece.begin(),nece.end(),itt->first);
    if(itt2 == nece.end()){
      itt = G.erase(itt);
    }
    else{
      itt++;
    }
  }
  return;
}


//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;
//
//  do {
//
    ev.eval<1>(classify_relative,vrbs);
    h1 = ev.evalr<1>(classify_relative,seed,vrbs);

    ev.eval<2>(prom_path,vrbs);
    h2 = ev.evalr<2>(prom_path,seed,vrbs);

    ev.eval<3>(filtra_deps,vrbs);
    h3 = ev.evalr<3>(filtra_deps,seed,vrbs);
//
//    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
//           seed,h1,h2,h3);
//    
//    printf("\n\nIngrese un valor para la semilla:");
//  } while (cin>>seed);

  return 0;
}
