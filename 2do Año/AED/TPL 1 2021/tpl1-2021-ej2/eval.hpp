// GITVERSION: aed-2021-26-g6b49601e
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
  
  typedef void (*qsort_t)(stack<int> &S);
  class eval1_t : public eval_base_t {
  public:
    qsort_t F;
    eval1_t() { dumptests=0; F=NULL; ejerc=EJERC; testfile="./qs.json"; }
    void run_case(json &data, json &outuser) {
      check_dni();

      list<int> L = data["S"];
      L.reverse();
      stack<int> S;
      for (auto x:L) S.push(x);
      F(S);
      L.clear();
      while (!S.empty()) {
        L.push_front(S.top()); S.pop();
      }
      L.reverse();
      outuser["S"] = L;
    }
    
    int check_case(json &datain,
                   json &outref,json &outuser) {
      return outref==outuser;
    }

    void generate_case(randomg_t &rnd,json &datain) {
      int n=10+rnd.rand()%10;
      set<int> w;
      for (int j=0; j<n; j++) w.insert(rnd.rand()%20);
      vector<int> v;
      for (auto x:w) v.push_back(x);
      random_shuffle(rnd,v);
      datain["S"] = v;
      // cout << datain["S"] << endl;
    }
  };
  
  //---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
  using Eval = eval_t<eval1_t,qsort_t>;
}
#undef CSTR

#endif
