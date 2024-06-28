#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


struct Puntaje{
	char nombre[32];
	int punto;
};

bool operator<(Puntaje a, Puntaje b){
	if(a.punto<b.punto){
		return true;
	}else{
		return false;
	}
	return false;
}

int main() {
	
	fstream archi("Ejercicio 6_5.dat",ios::binary|ios::in|ios::out|ios::ate);
	
	vector<Puntaje>v;
	int tam=(sizeof(Puntaje)/archi.tellg());
	
	archi.seekp(0);
	for(int i=0;i<tam;i++) { 
		Puntaje b;
		archi.read(reinterpret_cast<char*>(&b),sizeof(Puntaje));
		v.push_back(b);
	}
	//leo los datos del archivo y los guardo en el vector
	
	Puntaje x;
	cout<<"Ingrese nuevo nombre"<<endl;
	cin>>x.nombre;
	cout<<"Ingrese nuevo puntaje"<<endl;
	cin>>x.punto;
	
	v.push_back(x);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	for(size_t i=0;i<v.size();i++) {  
		cout<<v[i].nombre<<endl;
		cout<<v[i].punto<<endl;
	} 
	
	for(size_t i=0;i<v.size();i++){
		archi.write(reinterpret_cast<char*>(&v),sizeof(v));
	}
	
	
	return 0;
}

