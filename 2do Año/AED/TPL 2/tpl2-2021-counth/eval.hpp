// GITVERSION: aed-2021-91-ge02b1312
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
  
  typedef void (*countheight_t)(tree<int> &T,map<int,int> &count);
  class eval1_t : public eval_base_t {
  public:
    countheight_t F;
    eval1_t() { dumptests=0; F=NULL; ejerc=EJERC; testfile="./ch.json"; }
    void run_case(json &data, json &outuser) {
      check_dni();
      tree<int> T;
      map<int,int> M;
      lisp2tree(data["T"],T);
      F(T,M);
      json MJ;
      map2json(MJ,M);
      outuser["M"] = MJ;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outref==outuser;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      tree<int> T;
      int M=3;
      int m = 10+rnd.rand()%20; int n = 5+rnd.rand()%10;
      make_random_tree2(T,M+1,m,n,rnd);
      datain["T"] = tree2lisp(T);
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,countheight_t>;
}
#undef CSTR

#endif
