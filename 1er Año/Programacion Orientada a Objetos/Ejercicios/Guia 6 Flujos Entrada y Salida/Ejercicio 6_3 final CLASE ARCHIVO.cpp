#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Archivo{
	fstream f;
public:
	Archivo(string nom): f(nom,ios::binary|ios::in|ios::out){}
	int leer(int p){
		f.seekg(p*sizeof(int));
		int i;
		f.read(reinterpret_cast<char*>(&i),sizeof(int));
		return i;
	}
	int operator[](int i) { return leer(i); }
	void escribir(int p,int x){
		f.seekp(p*sizeof(int));
		f.write(reinterpret_cast<char*>(&x),sizeof(int));
	}
	int size(){
		f.seekg(0,ios::end);
		return f.tellg()/sizeof(int);
	}
};

int main() {
	
	Archivo v("Ejercicio 6_3.dat");
	cout<<"ingrese dato a reemplazar"<<endl;
	int dato;cin>>dato;
	// determinar la pos
	
	int pos=0;
	while(pos<v.size() and dato>v.leer(pos)) pos++; //comparo el dato con la posicion hasta q sea mayor
	// p tiene q ser menor al tamaño del vector para q no se salga, asi obtengo la posicion
	
	
	//inserto
	for(int i=v.size()-1;i>pos;i--){
		v.escribir(i, v.leer(i-1));
	}
	v.escribir(pos,dato);
	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	
	return 0;
}

/* ASI SERIA USANDO VECTORES, PERO EL ENUNCIADO ME PIDE QUE NO USE VECTORES

	fstream archi("Ejercicio 6_3.dat",ios::binary|ios::in|ios::out|ios::ate);

	vector<int> v(archi.tellg()/sizeof(int)); ///archi.tellg() es para obtener tamaño en bytes del archivo y lo divido por la cant de bytes que tiene un int y asi saco el tamaño

	archi.seekg(0);
	for(int i=0;i<v.size();i++){
		archi.read(reinterpret_cast<char*>(&i),sizeof(i));
	}

	int dato;cin>>dato;

	// determinar la pos

	int p=0;
	while(p<v.size() and d>v[p]) p++; //comparo el dato con la posicion hasta q sea mayor
	// p tiene q ser menor al tamaño del vector para q no se salga, asi obtengo la posicion
	v.resize(v.size()+1);

	//inserto
	for(int i=v.size()-1;i>pos;i--){
		v[i]=v[i-1];
	}
	v[pos]=dato;
*/

