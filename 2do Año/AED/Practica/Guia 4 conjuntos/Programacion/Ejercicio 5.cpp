#include <iostream>
using namespace std;
/*5) CubreTodo. Escribir una funci´on predicado cubre_todo(vector<set<T>>&v, set<T>& W) que
verifica si todos los conjuntos en el vector de conjuntos v est´an incluidos en W.*/


template <typename T>void set_intersection(set<T> &A,set<T> &B,set<T> &C){for(auto i = A.begin(); i != A.end(); i++){	auto it = B.find(*i);	if(it != B.end()){		C.insert(*i);	}}}template <typename T>	bool cubre_todo(vector<set<T>> &v, set<T> &W){		for(int i = 0; i < v.size(); i++){		set<T> aux;		set_intersection(v[i], W, aux);				if(aux.size() != v[i].size()){			return false;		}	}		return true;}
	
///FORMA 2

bool cubre_todo(vector<set<int>>&V, set<int>& W){	auto itV = V.begin();	while( itV != V.end() ){		auto itS = (*itV).begin();		while( itS != (*itV).end() ){			if( W.find(*itS) == W.end() )				return false;			itS++;		}		itV++;	}		return true;}
	

int main() {
	
	return 0;
}







