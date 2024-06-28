#include <iostream>
using namespace std;

template<typename T> T clamp( T vmin, T vmax, T v){
	if(v<vmin) return vmin;
	if(vmax<v) return vmax;
	return v;
}

int main() {
	double f;
	cout<<"ingrese valor doble (00.00)"<<endl;
	cin>>f;
	cout<<clamp(0.0,1.0,f);
	
	//si ingreso un numero mayor a 1.0 devuelve 1.0
	//si ingreso uno menor a 0.0 devuelve 0.0
	return 0;
}

