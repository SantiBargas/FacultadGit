// GITVERSION: tpl-recup-2018-11-22-7-gc4b22c4a
#ifndef EVAL_HPP
#define EVAL_HPP
#include "aedtools/evalbase.hpp"
#include "aedtools/str_convs.hpp"
#include "aedtools/make_random.hpp"
#include <forward_list>
#include <sstream>
#include <algorithm>
using namespace std;

namespace aed {

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  //   FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

  template<typename TKey, typename TValue>
  void str2map(std::map<TKey,TValue> &M, const std::string &s) {
    TKey clave; TValue valor;
    for(size_t i=1, p0=1;i<s.size();i++) { 
      if (s[i]==','||s[i]==')') {
        string spar = s.substr(p0,i-p0);
        spar.replace(spar.find("->"),2," ");
        std::stringstream ss(spar);
        ss>>clave>>valor;
        M[clave] = valor;
        p0=i+1;
      }
    }
  }
  
  template<typename T>
  std::string tree2lisp(tree<T> &A, typename tree<T>::iterator it) {
    std::stringstream ss;
    if (it.lchild()==A.end()) ss << *it;
    else {
      ss << "(" << *it;
      for(auto it2=it.lchild();it2!=A.end();++it2)
        ss << " " << tree2lisp(A,it2);
      ss << ")";
    }
    return ss.str();
  }
  
  template<typename T>
  std::string tree2lisp(tree<T> &A) {
    // if (A.begin()==A.end()) return "()";
    if (A.begin()==A.end()) return "";
    // return std::string("("+tree2lisp(A,A.begin())+")");
    return tree2lisp(A,A.begin());
  }
  
  string btree2lisp(btree<int>::iterator n,btree<int> &T) {
    btree<int>::iterator r,l;
    stringstream ss;
    if (n==T.end()) { ss << "." ;return ss.str();}
    bool is_leaf;
    r=n.right();
    l=n.left();
    is_leaf=(r==T.end() && l==T.end());
    if (is_leaf==true) {
      ss << *n;}
    else { ss << "(" << *n << " ";
    ss << btree2lisp(l,T);
    ss << " ";
    ss << btree2lisp(r,T) ;
    ss << ")";
    }
    return ss.str();
  }
  // -------------------------------------------------------------
  string btree2lisp(btree<int>&T) { 
    return btree2lisp(T.begin(),T); 
  } 
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> CLASSIFY_RELATIVE
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t
  typedef bool (*tree_less_t)(tree<int> &T1,tree<int> &T2);
  class EVAL : public eval_base_t {
  public:
    tree_less_t F;
    EVAL() { dumptests=0; F=NULL; ejerc=EJERC; testfile="./tl.json"; }
    void run_case(json &data,json &outuser) {
      tree<int> T1;
      tree<int> T2;
      // Unpack the data.
      lisp2tree(data["T1"],T1);
      lisp2tree(data["T2"],T2);
      // Call the user function
      bool o = F(T1,T2);
      // Store the user output
      outuser["retval"] = o;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outref==outuser;
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      tree<int> T1,T2;
      int m = 5+rnd.rand()%3; int nn = 3, z=1+rnd.rand()%2;
      // Generate a random tree
      make_random_tree2(T1,z,m,nn,rnd);
      make_random_tree2(T2,z,m,nn,rnd);
      
      // Load in the Json data
      datain["T1"] = tree2lisp(T1);
      datain["T2"] = tree2lisp(T2);
    }
  };

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> PROM_PATH
#undef EJERC
#undef EVAL
#define EJERC 2
#define EVAL eval2_t
  // static std::string float2string(float f) {
  //   std::stringstream ss; ss << std::setprecision(2)
  //                            << std::fixed << f; return ss.str();
  // }
  
  typedef void (*xcommon_t)(list<int> &L1,list<int> &L2,list<int> &Lcommon);
  class EVAL : public eval_base_t {
  public:
    xcommon_t F;
    EVAL() { dumptests=0; F=NULL; ejerc=EJERC; testfile="./xc.json"; }
    void run_case(json &data,json &outuser) override {
      list<int> L1 = data["L1"];
      list<int> L2 = data["L2"];
      list<int> Lcommon;
      F(L1,L2,Lcommon);
      outuser["L1out"] = L1;
      outuser["L2out"] = L2;
      outuser["Lcommon"] = Lcommon;
    }

    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outref==outuser;
    }
    
    void generate_case(randomg_t &rnd,json &datain) override {
      list<int> L1;
      list<int> L2;
      int n1 = 1+rnd.rand()%5; int n2 = 1+rnd.rand()%5;
      for(int i=0;i<n1;i++){
        L1.push_back(rnd.rand()%3);
      }
      for(int i=0;i<n2;i++){
        L2.push_back(rnd.rand()%3);
      }
      datain["L1"] = L1;
      datain["L2"] = L2;
    }
  };

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> MAP_GRAPH
#undef EJERC
#undef EVAL
#define EJERC 3
#define EVAL eval3_t
  typedef void (*xsubtrees_t)(btree<int> &T, int depth,list< btree<int> > &subtrees);
  class EVAL : public eval_base_t {
    
  public:
    xsubtrees_t F;
    EVAL() { dumptests=0; F=NULL; ejerc=EJERC; testfile="./xs.json"; }
    void run_case(json &data,json &outuser) override {
      /*auto G = str2graph<std::list<std::string>>(data["G"]);
      std::list<std::string> L = str2cont<std::list<std::string>>(data["L"]);
      F(G,L);
      outuser["G"] = graph2str(G);*/
      btree<int> T;
      lisp2btree(data["T"],T);
      int depth = data["depth"];
      list< btree<int> > LT;
      F(T,depth,LT);
      list<string> LTs;
      for(auto t:LT){
        LTs.push_back(btree2lisp(t));
      }
      outuser["LTs"] = LTs;
    }
    
    int check_case(json &data, json &outuser, json &outref) override {
      // para que no importe el orden en la lista
      list<string> LTuser = outuser["LTs"];
      list<string> LTref = outref["LTs"];
      LTuser.sort();
      LTref.sort();
      return LTuser==LTref;      
    }

    void generate_case(randomg_t &rnd,json &datain) {
      btree<int> T;
      // Generate a random tree
      int m = 9;
      double s = 1.5;
      make_random_btree(T,m,s,rnd);
      int d = rnd.rand()%m;
      // Load in the Json data
      datain["T"] = btree2lisp(T);
      datain["depth"] = d;
    }
  };
  
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> MAP_GRAPH
#undef EJERC
#undef EVAL
#define EJERC 4
#define EVAL eval4_t
  typedef int (*maxsubk_t)(set<int> S, int k);
  class EVAL : public eval_base_t {
    
  public:
    maxsubk_t F;
    EVAL() { dumptests=0; F=NULL; ejerc=EJERC; testfile="./msk.json"; }
    void run_case(json &data,json &outuser) override {
      set<int> S = data["S"];
      int k = data["k"];
      int o = F(S,k);
      outuser["o"] = o;
    }
    
    int check_case(json &data, json &outuser, json &outref) override {
      return outref==outuser;     
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      set<int> S;
      // Generate a random tree
      int n = 2+rnd.rand()%5;
      for(int i=0;i<n;i++){
        while(1){
          int trial = rnd.rand()%20-10;
          if(!S.count(trial)){
            S.insert(trial);
            break;
          }
        }
      }
      // Load in the Json data
      datain["S"] = S;
      datain["k"] = 1+rnd.rand()%(S.size()-1);
    }
  };
  
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> MAP_GRAPH
#undef EJERC
#undef EVAL
#define EJERC 5
#define EVAL eval5_t
  typedef int (*num_path_t)(map<int,set<int>>& G, int i, int j);
  class EVAL : public eval_base_t {
    
  public:
    num_path_t F;
    EVAL() { dumptests=0; F=NULL; ejerc=EJERC; testfile="./np.json"; }
    void run_case(json &data,json &outuser) override {
      auto G = str2graph<set<int>>(data["G"]);
      int i = data["i"];
      int j = data["j"];
      int o = F(G,i,j);
      outuser["o"] = o;
    }
    
    int check_case(json &data, json &outuser, json &outref) override {
      return outref==outuser;     
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      auto lbl_gen = [&rnd](){return rnd.rand()%80;}; // para generar las etiquetas
      auto st_gen = [&rnd](int x){return rnd.rand()%x;}; // para generar los arcos
      map<int,set<int>> G = make_random_graph<set<int>>(rnd.rand()%4+4,.5,lbl_gen,st_gen);
      datain["G"] = graph2str(G);
      int N = G.size();
      int i = rnd.rand()%N;
      int j = rnd.rand()%N;
      int k=0;
      for(auto x:G){
        if(i==k) datain["i"] = x.first;
        if(j==k) datain["j"] = x.first;
        k++;
      }
    }
  };
  
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*> MAP_GRAPH
#undef EJERC
#undef EVAL
#define EJERC 6
#define EVAL eval6_t
  typedef bool (*super_stable_partition_t)(list<int> &L, 
                                          list<int> &L_low, list<int> &L_geq);
  class EVAL : public eval_base_t {
    
  public:
    super_stable_partition_t F;
    EVAL() { dumptests=0; F=NULL; ejerc=EJERC; testfile="./ssp.json"; }
    void run_case(json &data,json &outuser) override {
      list<int> L = data["L"];
      list<int> L_low, L_geq;
      bool ret = F(L,L_low,L_geq);
      outuser["L_out"] = L;
      outuser["L_low"] = L_low;
      outuser["L_geq"] = L_geq;
      outuser["ret"] = ret;
    }
    
    int check_case(json &data, json &outuser, json &outref) override {
      return outref==outuser;     
    }
    
    void generate_case(randomg_t &rnd,json &datain) {
      vector<int> V;
      int n = 3+rnd.rand()%7;
      for(int i=0;i<n;i++){
        V.push_back(rnd.rand()%10);
      }
      //forzar que ocurra la mitad de las veces
      if(rnd.rand()%2){
        sort(V.begin(),V.end());
        int ii = 1+rnd.rand()%(n-2);
        random_shuffle(rnd,V,0,ii);
        random_shuffle(rnd,V,ii+1,V.size());
      }
        
      datain["L"] = V;
    }
  };
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,tree_less_t,
                      eval2_t,xcommon_t,
                      eval3_t,xsubtrees_t,
                      eval4_t,maxsubk_t,
                      eval5_t,num_path_t,
                      eval6_t,super_stable_partition_t>;
}
#undef CSTR

#endif
