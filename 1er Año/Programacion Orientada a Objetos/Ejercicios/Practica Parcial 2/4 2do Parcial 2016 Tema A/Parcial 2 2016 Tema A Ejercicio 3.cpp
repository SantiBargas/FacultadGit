#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


struct ficha{
	bool borrado;
	char nombre[64], apellido[64];
	float h;
};



bool es_borrado(ficha f){ return f.borrado;}

int main() {

	
	vector<ficha>v;
	ifstream archi("Arch.bin",ios::binary|ios::ate);
	
	v.resize(archi.tellg()/sizeof(ficha)); //le asigno al vector el tamaño de fichas q tiene el archivo
	
	archi.seekg(0);
	
	for(ficha &f:v){
		archi.read(reinterpret_cast<char*>(&f),sizeof(f));
	}
	archi.close();
	
	auto it=remove_if(v.begin(),v.end(),es_borrado);
	v.erase(it,v.end());
	
	ofstream archi2("Archi.bin",ios::binary|ios::trunc);
	
	for(ficha f:v){
		
		archi.write(reinterpret_cast<char*>(f),sizeof(f));
	}
	
	
	return 0;
}

