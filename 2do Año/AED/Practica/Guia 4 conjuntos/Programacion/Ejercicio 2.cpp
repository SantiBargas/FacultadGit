#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*2) Disjuntos. Escribir una funci´on predicado 
bool disjuntos(vector<set<T>>&v) que verifica si
todos los conjuntos Ai dentro del vector de conjuntos v son
disjuntos de a pares, esto es: si
Ai != Aj entonces Ai Interseccion Aj = vacio*/

template<typename T>
void set_intersection(set<T> &A,set<T> &B,set<T> &C){
	auto itA=A.begin();
	while(itA!=A.end()){
		if(B.find(*itA)!=B.end()){
			C.insert(*itA);
		}
		itA++;
	}
}
	

template<typename T>
bool disjuntos(vector<set<T>>&v){
	
	//el for asi para no comparar mismos elementos repetidas veces
	for(size_t i=0;i<v.size()-1;i++){
		
		for(size_t j=i+1;j<v.size();j++){
			
			set<T> C; //set auxiliar
			set_intersection(v[i],v[j],C);
			
			if(!C.empty()){
				return false;
			}
		}
		
	}
	
	return true;
	
}


int main() {
	
	vector<set<int>> v = { {1,2} , {3,4} , {5,6} , {7,8}};
	
	bool res=disjuntos(v);
	
	if(res==0){
		cout<<"NO SON DISJUNTOS";
	}else{
		cout<<"SON DISJUNTOS";
	}
	
	return 0;
}







