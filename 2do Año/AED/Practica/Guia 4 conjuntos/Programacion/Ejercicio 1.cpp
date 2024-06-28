#include <iostream>
#include <set>
using namespace std;
/*a) [Set]
1) Operaciones. Escribir las funciones
a) void set_union(set<T> &A,set<T> &B,set<T> &C);
b) void set_intersection(set<T> &A,set<T> &B,set<T> &C);
c) void set_difference(set<T> &A,set<T> &B,set<T> &C);
en t´erminos de los restantes m´etodos de la interfase de set.*/

template<typename T>void show_set(const set<T> &A) {	for(T x:A) cout << x << " ";}

template<typename T>
void set_union(set<T> &A,set<T> &B,set<T> &C){
	
	C.insert(A.begin(),A.end());
	C.insert(B.begin(),B.end());
	
	
}
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
void set_difference(set<T> &A,set<T> &B,set<T> &C){
	
	auto itA=A.begin();
	
	while(itA!=A.end()){
		if(B.find(*itA)==B.end()){
			C.insert(*itA);
		}
		itA++;
	}
}

int main() {
	
	set<int>s1= {1,2,3,};
	set<int>s2={4,5,6};
	set<int>s3={7,8,9};
	set_union(s1,s2,s3);
	cout<<"UNION: "<<endl;
	show_set(s3);cout<<endl<<endl<<endl;
	
	s1={1,2,3};
	s2={2,3};
	s3={};
	set_intersection(s1,s2,s3);
	cout<<"INTERSECCION: "<<endl;
	show_set(s3);cout<<endl<<endl<<endl;
	
	s1={1,2,3,4,5,6};
	s2={1,2,3,5,7};
	s3={};
	set_difference(s1,s2,s3);
	cout<<"DIFERENCIA: "<<endl;
	show_set(s3);cout<<endl<<endl<<endl;
	
	
	return 0;
}







