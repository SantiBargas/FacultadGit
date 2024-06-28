#include <iostream>
#include <vector>
using namespace std;

template<typename T> T mayor(vector<T>&v){
	T mayor= v[0]; //T mayor=0; asigno al primer valor del arreglo, pq si viene un string no me funcionaria el 0
	for(size_t i=0;i<v.size();i++){
		if(v[i]>mayor){
			mayor=v[i];
		}
	}
	return mayor;
}

template<typename T> T mayor( T a, T b){
	if(a>b)return a;
	else return b;
}
	
struct Persona{
	string nombre;
	string apellido;
	int dni;
};

bool operator>(Persona p1, Persona p2){
	return p1.dni>p2.dni;
}

int main() {
	
	cout<<mayor(5,10)<<endl;
	cout<<mayor(3.14,6.19)<<endl;
	string s1="Zapata", s2="Arnaldo";
	cout<<mayor(s1,s2)<<endl;
	cout<<mayor<string>(s2,"fachero")<<endl;
	cout<<mayor<double>(5.4,19)<<endl;
	
	vector<int>v(5);
	for(size_t i=0;i<5;i++){
		v[i]=rand()%5;
		cout<<v[i]<<"   ";
	}
	cout<<"El menor de los int es: "<<mayor(v)<<endl;
	vector<float>x(5);
	for(size_t i=0;i<5;i++){
		x[i]=rand()%5;
		cout<<x[i]<<"   ";
	}
	cout<<"El menor de los float es: "<<mayor(x)<<endl;
	
	Persona p1={"Juan","Perez",43538588};
	Persona p2={"Santi","Bargas",44538798};
	cout<<mayor(p1,p2).nombre;
	
	return 0;
}

