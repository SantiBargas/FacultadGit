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

void make_full(btree<int> &T, btree<int>::iterator it){
    
  if((it.left()==T.end()) != (it.right()==T.end())){ //Nodo q no es lambda = ITL
    
    btree<int>T2;
    
    auto itc = it.left()==T.end() ? it.right() : it.left();
    
    T2.splice(T2.begin(),itc);
    it=T.erase(it);
    
    auto it2=T2.begin();
    it=T.splice(it,it2);
    make_full(T,it);
  }else{
    if(it.left()!=T.end()) make_full(T,it.left());
    if(it.right()!=T.end())make_full(T,it.right());
  }
  

  
}

void make_full(btree<int> &T) {
  make_full(T,T.begin());
}

int aux(btree<int>&T,btree<int>::iterator it){
  if(it==T.end()) return 0;
  int l = aux(T,it.left());
  int r = aux(T,it.right());
  return *it+l+r;
}

int max_subbtree(btree<int>&T,btree<int>::iterator it){
  if(it==T.end()) return 0;
  int Ml = max_subbtree(T,it.left());
  int Mr = max_subbtree(T,it.right());
  int M = aux(T,it);
  return max(max(M,Ml),Mr);
}
  
int max_subbtree(btree<int>&T){

  return max_subbtree(T,T.begin());
}

bool connected(set<int> &s1,set<int> &s2){    

  auto it1=s1.begin();
  set<int>C;
  
  while(it1!=s1.end()){
    
    auto it2=s2.begin();
    
    while(it2!=s2.end()){
      if(s2.find(*it1)!=s2.end()){
        C.insert(*it1);
      }
      it2++;
    }
    it1++;
  }

  if(C.empty())return false;
  if(!C.empty()) return true;
  
}
  
int most_connected(vector< set<int> > &VS) {
  
  int nmax=-1;
  int jmax=-1;
  for(size_t j=0;j<VS.size();j++){
    
    int cont=0;
    for(size_t k=0;k<VS.size();k++){
      
     cont += connected(VS[j],VS[k]);
      
    }
    
    if(cont>nmax){
      nmax=cont;
      jmax=j;
    }
    
  }
  
  return jmax;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  do {

    ev.eval<1>(make_full,vrbs);
    h1 = ev.evalr<1>(make_full,seed,vrbs);

    ev.eval<2>(max_subbtree,vrbs);
    h2 = ev.evalr<2>(max_subbtree,seed,vrbs);

    ev.eval<3>(most_connected,vrbs);
    h3 = ev.evalr<3>(most_connected,seed,vrbs);

    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);

  return 0;
}
