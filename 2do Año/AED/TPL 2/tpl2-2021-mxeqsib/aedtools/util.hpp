// GITVERSION: aed-2021-109-ge54c528e
/* 
   COMIENZO DE DESCRIPCION 
   Utilitarios varios. 
   keywords: lista, cola
   FIN DE DESCRIPCION 
*/
#ifndef AED_UTIL_H
#define AED_UTIL_H

#include <cstdarg>
#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

// -----------------------------------------------------------------
// generates a double random between 0.0 <= d < 1.00
double drand();

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int modulo(int n,int m);

// -----------------------------------------------------------------
// generates an integer random between 0 <= i < M-1
int irand(int m);

// -----------------------------------------------------------------
// Genera una lista L de longitud N
// con elementos aleatorios en el rango [0, M-1]
void randl(std::list<int> &l,int m=10,int n=20);

// -----------------------------------------------------------------
// Genera una lista L de longitud promedio N
// con elementos aleatorios en el rango [0, M-1]
void randl(std::list<int> &l,int m=10,double n=20.0);

// -----------------------------------------------------------------
// Inserta elementos del vector v en la lista l en la posicion p. 
// Se detiene cuando encuentra el elemento term en v.
// Util para generar listas de la siguiente forma:
// int v [] = {1,2,3,4,3,2,1,2,3,4,-1};
// list <int> l ; insertl (l,v,-1);
// -----------------------------------------------------------------
template <class t>
void insertl(std::list<t> &l, 
              typename std::list<t>::iterator p,
	      t *x,t term) {
  while (*x!=term) {p=l.insert(p,*x++); p++;}
} 
template <class t>
void insertl(std::list<t> &l,t *x,t term) {
  insertl(l,l.begin(),x,term);
} 

// -----------------------------------------------------------------
// imprime en orden normal (de adelante para atras)
template <class t>
void printl(std::list<t> &l) {
  typename std::list<t>::iterator p; 
  p=l.begin();
  while (p!=l.end()) std::cout << *p++ << " ";
  std::cout << std::endl;
}

// -----------------------------------------------------------------
// imprime en orden inverso (por recursion, de atras para adelante)
template <class t>
void pinvers(std::list<t> &l, 
             typename std::list<t>::iterator p) {
  typename std::list<t>::iterator q; 
  if (p==l.end()) return;
  q=p; q++;
  pinvers(l,q);
  std::cout << *p << " ";
} 
template <class t>
void printl_inv(std::list<t> &l) { 
  pinvers(l,l.begin()); 
  std::cout << std::endl;
}

// -----------------------------------------------------------------
// Imprime cola sin destruirla (i.e. usa una cola auxiliar)
template <class t>
void printq(std::queue<t> &q) {
  std::queue<t>c;
  t x;
  while (!q.empty()) {
    x=q.front();
    std::cout << x << " ";
    q.pop();
    c.push(x);
  } 
  while (!c.empty()) {
    q.push(c.front());
    c.pop();
  } 
  std::cout << std::endl;
}

template<class T>
void set_union(const std::set<T> &A,const std::set<T> &B,
               std::set<T> &C) {
  C.clear();
  std::set_union(A.begin(),A.end(),
                 B.begin(),B.end(),
                 inserter(C,C.begin()));
}

template<class T>
void set_intersection(const std::set<T> &A,const std::set<T> &B,
               std::set<T> &C) {
  C.clear();
  std::set_intersection(A.begin(),A.end(),
                 B.begin(),B.end(),
                 inserter(C,C.begin()));
}

template<class T>
void set_difference(const std::set<T> &A,const std::set<T> &B,
               std::set<T> &C) {
  C.clear();
  std::set_difference(A.begin(),A.end(),
                 B.begin(),B.end(),
                 inserter(C,C.begin()));
}

void add_to_list(std::list<int> &L,int term,...);
void add_to_list(std::list<int> &L,int term,va_list elems);
void add_to_set(std::set<int> &L,int term,...);
void add_to_set(std::set<int> &L,int term,va_list elems);

// Imprime una correspondencia
void print_map(std::map<int,std::list<int> > &M,const char *s=NULL);

// Imprime una pila de enteros
void print_stack(std::stack<int> &S,const char *s=NULL);

// Imprime un conjunto de enteros
void print_set(std::set<int> &S,const char *s=NULL);

// Imprime un conjunto de enteros
void print_vset(std::vector<std::set<int> > &VS,const char *s=NULL);

#endif
// -----------------------------------------------------------------

