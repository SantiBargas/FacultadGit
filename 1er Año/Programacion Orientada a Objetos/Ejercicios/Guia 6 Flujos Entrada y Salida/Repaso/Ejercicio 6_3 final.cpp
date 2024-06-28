#include <iostream>
#include <fstream>
using namespace std;

class Archivo{
private:
	fstream f;
	
public:
	Archivo(string nom):f(nom,ios::binary|ios::in|ios::out){}
	int size(){
		f.seekg(0,ios::end);
		return f.tellg()/sizeof(int);
	}
	int leer(int p){
		f.seekg(p*sizeof(int));
		int i;
		f.read(reinterpret_cast<char*>(&i),sizeof(int));
		return i;
	}
	void AsignarDato(int pos,int num){
		f.seekp(pos*sizeof(int));
		f.write(reinterpret_cast<char*>(&num),sizeof(num));
	}
	int operator[](int i){
		return leer(i);
	}
};

int main() {
	
	Archivo v("Ejercicio 6_3.dat");
	
	int pos,num;
	cout<<"Ingrese posicion a insertar el numero"<<endl;
	cin>>pos;
	cout<<"Ingrese numero"<<endl;
	cin>>num;
	
	
	int p=0;
	while(num>v.leer(pos) and pos<v.size()){
		p++;
	}
	
	for(int i=v.size()-1;i>pos;i--){
		v.AsignarDato(i, v.leer(i-1));
	}
	
	v.AsignarDato(p,num);
	
	for(int i=0;i<v.size();i++) { 
		cout<<v[i]<<"  ";
	}
	
	
	return 0;
}

