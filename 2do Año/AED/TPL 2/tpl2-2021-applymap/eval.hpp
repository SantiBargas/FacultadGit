// GITVERSION: aed-2021-92-gc614c4fe
#ifndef EVAL_HPP
#define EVAL_HPP
#include "aedtools/evalbase.hpp"
#include "aedtools/str_convs.hpp"
#include <forward_list>
#include <sstream>
using namespace std;

namespace aed {

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  //   FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>

  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  // END FUNCTIONS FOR THIS EXAM
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
#undef EJERC
#undef EVAL
#define EJERC 1
#define EVAL eval1_t
  
  typedef void (*applymap_t)(tree<int> &T,map<int,int> &M);
  class eval1_t : public eval_base_t {
  public:
    applymap_t F;
    eval1_t() { dumptests=1; F=NULL; ejerc=EJERC; testfile="./am.json"; }
    void run_case(json &data, json &outuser) {
      check_dni();

      tree<int> T;
      json2tree(data["T"],T);
      map<int,int> M;
      json2map(data["M"],M);
      F(T,M);
      outuser["T"] = tree2json(T);
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outref==outuser;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      tree<int> T;
      int M=3;
      int m = 5+rnd.rand()%10; int n = 5+rnd.rand()%10;
      make_random_tree2(T,M+1,m,n,rnd);
      *T.begin() = rnd.rand()%M;
      datain["T"] = tree2json(T);
      json Map;
      int z=rnd.rand()%M;
      for (int j=0; j<M; j++) {
        json p;
        p.push_back(j);
        p.push_back((j+z)%M);
        Map.push_back(p);
      }
      datain["M"] = Map;
      // cout << datain << endl;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,applymap_t>;
}
#undef CSTR

#endif
