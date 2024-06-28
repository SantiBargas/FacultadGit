// GITVERSION: aed-3.0-38-g6ed5e13
#ifndef EVAL_HPP
#define EVAL_HPP
#include "aedtools/evalbase.hpp"
#include <forward_list>
#include <sstream>
#include <algorithm>
using namespace std;
typedef map<int,list<int>> graph_t;

namespace aed {

  void rand(); // para que no compile si uso std::rand en lugar de randomg_t::rand
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> SUM SUBLIST
  
  typedef list<int> (*sum_sublist_t)(list<int>& L, int S);
  class eval1_t : public eval_base_t {
  public:
    sum_sublist_t F;
    eval1_t() { dumptests=0; F=NULL; ejerc=1; testfile="./ss.json"; }
    void run_case(json &data,json &outuser) {
      list<int> L = data["L"];
      int S = data["S"];
      list<int> R = F(L,S);
      outuser["R"] = R;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) 
    {
      return outref==outuser;
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      list<int> L;
      int n = 5+rnd.rand()%10, S=0;
      for(int i=0;i<n;i++) {
        int x = rnd.rand()%20;
        L.push_back(x);
        if (rnd.rand()%2==0) S+=x;
      }
      datain["L"] = L;
      datain["S"] = S;
    }
  };
  
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> DISCRETE MOVING MEAN
  
  typedef list<int> (*discrete_moving_mean_t)(list<int>& L, int S);
  class eval2_t : public eval_base_t {
  public:
    discrete_moving_mean_t F;
    eval2_t() { dumptests=0; F=NULL; ejerc=2; testfile="./dmm.json"; }
    void run_case(json &data,json &outuser) {
      list<int> L = data["L"];
      int S = data["w"];
      list<int> R = F(L,S);
      outuser["R"] = R;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) 
    {
      return outuser==outref;
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      list<int> L;
      int n = 5+rnd.rand()%10, S=0;
      for(int i=0;i<n;i++) {
        int x = rnd.rand()%20;
        if (rnd.rand()%2==0) S+=x;
        L.push_back(x);
      }
      datain["L"] = L;
      datain["w"] = std::min<int>(L.size(),2+rnd.rand()%5);
    }
  };
  
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> d10s
  
  typedef list<int> (*d10s_t)(tree<int> &T);
  class eval3_t : public eval_base_t {
  public:
    d10s_t F;
    eval3_t() { dumptests=0; F=NULL; ejerc=3; testfile="./d1.json"; }
    void run_case(json &data,json &outuser) {
      tree<int> T;
      lisp2tree(data["T"],T);
      list<int> C;
      C = F(T);
      outuser["C"] = C;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) 
    {
      return outref==outuser;
    }
    
    void rec(list<tree<int>::iterator > &L, tree<int> &T, tree<int>::iterator it) {
      if (T.end()==it) return;
      L.push_back(it);
      for(auto ic = it.lchild(); ic!=T.end(); ++ic) {
        rec(L,T,ic);
      }
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      tree<int> T;
      int m = 5+rnd.rand()%10; int n = 5+rnd.rand()%10;
      make_random_tree2(T,89,m,n,rnd);
      list<tree<int>::iterator> L; rec(L,T,T.begin());
      for(auto &it:L) *it += 11;
      list<tree<int>::iterator>::iterator it2 = L.begin();
      std::advance(it2,rnd.rand()%L.size());
      *(*it2) = 10;
      datain["T"] = lisp_print(T);
    }
  };
  
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> IS CYCLE
  
  void make_graph(graph_t &G,vector<int>&nodos,vector<vector<int>>&aristas){
    for(int i=0;i<aristas.size();i++){
      vector<int>&a = aristas[i];
      G[a[0]].push_back(a[1]);
    }
  }
  
  void read_graph(graph_t &M, const json &data, std::string name) {
    std::vector<int> nodos = data[name+"_nodos"];
    std::vector<vector<int>> aristas; // = data["aristas"];
    json aux = data[name+"_aristas"];
    for(vector<int> v:aux)
      aristas.push_back(v);
    make_graph(M,nodos,aristas);
  }
  
  void genCycle(graph_t &G,randomg_t &rnd){
    int n = rnd.rand()%25;
    for(int i=0;i<n;i++){
      G[i];
      if(i!=n-1)
        G[i].push_back(i+1);
      else G[i].push_back(0);
    }
  }
  void deCycle(graph_t &G,randomg_t &rnd){
    if(G.size()==0) return;
    int n = rnd.rand()%G.size();
    int x = rnd.rand()%G.size();
    if(n==x){
      if(x==G.size())
        x=n-1;
    }
    G[n].clear();
    G[n].push_back(x);
  }
  void genPosCycle(graph_t &G,randomg_t &rnd){
    genCycle(G,rnd);
    float f = (rnd.rand()%1001)/1000.f;
    if(f<0.5)
      deCycle(G,rnd);
  }
  
  typedef bool (*is_cycle_t)(graph_t &G);
  class eval4_t : public eval_base_t {
  public:
    is_cycle_t F;
    eval4_t() { dumptests=0; F=NULL; ejerc=4; testfile="./ic.json"; }
    void run_case(json &data,json &outuser){
      graph_t M;
      read_graph(M,data,"G");
      list<int> & A0 = M[0];
      list<int> & A1 = M[1];
      list<int> & A2 = M[2];
      list<int> & A3 = M[3];
      outuser["ret"] = F(M);
    }
    int check_case(json &datain,json &outref,json &outuser){
      return outref == outuser;
    }
    void generate_case(randomg_t &rnd, json &datain){
      graph_t G;
      genPosCycle(G,rnd);
      //nodos
      int nnodos = G.size();
      vector<int> vnodos(nnodos);
      for(size_t i=0;i<vnodos.size();i++) vnodos[i] = i;
      datain["G_nodos"] = vnodos;
      //aristas
      vector< vector<int> > varistas;
      vector<int> p(2);
      
      for(int i=0;i<G.size();i++){
        list<int>&A = G[i];
        list<int>::iterator it = A.begin();
        while(it != A.end()){
          p[0] = i;
          p[1] = *it;
          varistas.push_back(p);
          it++;
        }
      }
      datain["G_aristas"] = varistas;      
    }
  };
  
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> EXISTE_SUB_C
  
  typedef bool (*existe_subc_t)(set<int>& S, int n);
  class eval5_t : public eval_base_t {
  public:
    existe_subc_t F;
    eval5_t() { dumptests=0; F=NULL; ejerc=5; testfile="./es.json"; }
    void run_case(json &data,json &outuser) {
      set<int> S = data["S"];
      int n = data["n"];
      bool ret = F(S,n);
      outuser["ret"] = ret;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) 
    {
      return outref==outuser;
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      set<int> S;
      int c = 4+rnd.rand()%5, n=0;
      for(int i=0;i<c;i++) {
        int x = rnd.rand()%21-10;
        S.insert(x);
        if (rnd.rand()%2) n+= x;
      }
      if (rnd.rand()%3==0) n+=rnd.rand()%21-10;
      datain["S"] = S;
      datain["n"] = n;
    }
  };
  
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> REPLACE_BTREE
  
  typedef bool (*bt_fun_t)(int);
  bool es_impar(int x) {return (x%2==1);}
  bool es_par(int x) {return (x%2==0);}
  bool es_multiplo_de_4(int x) {return (x%4==0);}
  bool es_cero(int x) {return (x==0);}
  bool es_menor_que_10(int x) {return (x<10);}
  bool es_primo(int x) {
    if(x%2==0 && x!=2)
      return false;
    else{
      for(int i = 3 ;i<x-1;i+=2){
        if(x%i == 0)
          return false;
      }
      return true;
    }
  }
  
  static std::map<std::string,bt_fun_t> &GetBFuncMap() {
    static std::map<std::string,bt_fun_t> m;
    if (m.empty()) {
      m["es_impar"] = es_impar;
      m["es_par"] = es_par;
      m["es_primo"] = es_primo;
      m["es_cero"] = es_cero;
      m["es_menor_que_10"] = es_menor_que_10;
      m["es_multiplo_de_4"] = es_multiplo_de_4;
    }
    return m;
  }
  
  static std::map<std::string,bt_fun_t> bfuncs;
  
  typedef void (*replace_btree_t)(btree<int>&T, bt_fun_t f);
  class eval6_t : public eval_base_t {
    
  public:
    replace_btree_t F;
    eval6_t() {dumptests=0;F=NULL;ejerc=6; testfile="./rep.json";}
    void run_case(json &data,json &outuser){
      btree<int> T;
      lisp2btree(data["T"],T);
      std::string func_name = data["pred"];
      F(T,GetBFuncMap()[func_name]);
      outuser["T"] = lisp_print(T);
    }
    int check_case(json &datain,json &outref,json &outuser){
      return (outref==outuser);
    }
    void generate_case(randomg_t &rnd, json &datain){
      btree<int> T;
      int m = 16;
      double s = 1.5;
      make_random_btree(T,m,s,rnd);
      auto it = GetBFuncMap().begin();
      std::advance(it,rnd.rand()%GetBFuncMap().size());
      datain["pred"] = it->first;
      datain["T"] = lisp_print(T);
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<
    eval1_t,sum_sublist_t,
    eval2_t,discrete_moving_mean_t,
    eval3_t,d10s_t,
    eval4_t,is_cycle_t,
    eval5_t,existe_subc_t,
    eval6_t,replace_btree_t
    >;
  

}
#undef CSTR

#endif
