#define USECHRONO
#undef HAVE_MPI
#include "aedtools/evalbase.hpp"
#include "aedtools/str_convs.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace aed;
using namespace std;

// COMPLETAR DNI y NOMBRE AQUI:
// Nombre: Bob Esponja
int DNI=98765432;

typedef tree<int>::iterator node_t;
int suma(tree<int> &T,node_t n) {
  if (n==T.end()) return 0;
  int sum=*n;
  auto c = n.lchild();
  // cout << *c << endl;
  while (c!=T.end()) sum += suma(T,c++);
  return sum;
}

int suma(tree<int> &T) {
  if (T.empty()) return 0;
  return suma(T,T.begin());
}

int cuenta_pares(tree<int> &T,node_t n) {
  if (n==T.end()) return 0;
  int count=(*n%2==0);
  auto c = n.lchild();
  // cout << *c << endl;
  while (c!=T.end()) count += cuenta_pares(T,c++);
  return count;
}

int cuenta_pares(tree<int> &T) {
  if (T.empty()) return 0;
  return cuenta_pares(T,T.begin());
}

int suma_pares(tree<int> &T,node_t n) {
  if (n==T.end()) return 0;
  cout << *n << endl;
  int suma=(*n%2==0? *n : 0);
  auto c = n.lchild();
  while (c!=T.end()) suma += suma_pares(T,c++);
  return suma;
}

int suma_pares(tree<int> &T) {
  if (T.empty()) return 0;
  return suma_pares(T,T.begin());
}

node_t find(tree<int> &T,node_t n,int x) {
  if (*n==x) return n;
  auto c = n.lchild();
  while (c!=T.end()) {
    node_t z = find(T,c,x);
    if (z!=T.end()) return z;
    c++;
  }
  return T.end();
}

node_t find(tree<int> &T,int x) {
  if (T.empty()) return T.end();
  return find(T,T.begin(),x);
}

node_t findpost(tree<int> &T,node_t n,int x) {
  auto c = n.lchild();
  while (c!=T.end()) {
    node_t z = findpost(T,c,x);
    if (z!=T.end()) return z;
    c++;
  }
  if (*n==x) return n;
  return T.end();
}

node_t findpost(tree<int> &T,int x) {
  if (T.empty()) return T.end();
  return findpost(T,T.begin(),x);
}

int count_level(tree<int> &T,node_t n,int level) {
  if (level<0 || n==T.end()) return 0;
  if (level==0) return 1;
  int count=0;
  auto c=n.lchild();
  while (c!=T.end()) 
    count += count_level(T,c++,level-1);
  return count;
}

int count_level(tree<int> &T,int level) {
  if (T.empty()) return 0;
  return count_level(T,T.begin(),level);
}

void get_path(tree<int> &T,tree<int>::iterator n,int x,list<int> &L) {
  if (n==T.end()) return;
  if (*n==x) {
    L.push_back(x);
    return;
  }
  auto c = n.lchild();
  while (c!=T.end()) {
    get_path(T,c,x,L);
    if (!L.empty()) {
      L.push_back(*n);
      return;
    }
    c++;
  }
}

void get_path(tree<int> &T,int x,list<int> &L) {
  if (T.empty()) return;
  get_path(T,T.begin(),x,L);
}

void make_mirror(tree<int> &T,node_t n) {
  if (n==T.end()) return;
  tree<int> Q;
  node_t q=Q.insert(Q.begin(),324);
  auto c = n.lchild();
  auto qc = q.lchild();
  while (c!=T.end()) {
    qc=Q.splice(qc,c);
  }
  
  c = n.lchild();
  qc = q.lchild();
  while (qc!=T.end()) {
    c=T.splice(c,qc);
    make_mirror(T,c);
    c++;
  }
}

void make_mirror(tree<int> &T) {
  if (T.empty()) return;
  make_mirror(T,T.begin());
}

int main() {
  tree<int> T;
  lisp2tree("(0 3 (8 3) (9 3) (2 (2 3 1)) (4 (8 7) 7))",T);
  T.lisp_print(); cout << endl;
#if 0  
  cout << "Suma de todo el arbol " << suma(T) << endl;
  node_t n=T.find(4);
  cout << "Suma del subarbol de 4 " << suma(T,n) << endl;
  cout << "Cuenta pares " << cuenta_pares(T,T.begin()) << endl;
  node_t n=T.find(4);
  cout << "Cuenta pares del subarbol de 4 " << cuenta_pares(T,n) << endl;
  cout << "Suma pares " << suma_pares(T) << endl;
  
  int x=2;
  node_t z= find(T,x);
  cout << "Suma subarbol de 2 (preorder) " << suma(T,z) << endl;
  z= findpost(T,x);
  cout << "Suma subarbol de 2 (postorder) " << suma(T,z) << endl;
  for (int l=0; l<10; l++) 
    cout << "Conteo nodo a nivel " << l << ": " << count_level(T,l) << endl;
  
  for (int x=0; x<20; x++) {
    list<int> L;
    get_path(T,x,L);
    cout << "Path a " << x << ": ";
    for (auto z:L) cout << z << " ";
    cout << endl;
  }
#endif
  make_mirror(T);
  cout << "T invertido: " << endl;
  T.lisp_print(); cout << endl;
  
  return 0;
}
