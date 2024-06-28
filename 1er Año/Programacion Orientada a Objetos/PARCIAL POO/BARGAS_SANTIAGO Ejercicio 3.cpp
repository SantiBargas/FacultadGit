#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Datos{
	string codigo;
	int enfermo;
};

void analizarResultados(){
	ifstream archi("estudio.txt");
	Datos a;
	if(!archi.is_open()){
		cout<<"No se pudo abrir el archivo ";
	}
	vector<Datos>v;
	while (archi>>a.codigo>>a.enfermo){
		v.push_back(a);
	}
	
	Datos buscar; buscar.enfermo=2; buscar.codigo="------";
	
	auto itera=find(v.begin(),v.end(),a);
	sort(itera,v.end());
	
	int cont1,size1=0;
	float porcentaje1;
	for(auto it=v.begin();it!=itera;it++){
		if(it->enfermo==1){
			cont1++;
			size1++;
		}else{
			size1++;
		}
		
	}
	porcentaje1=(cont1*100)/size1;
	
	int cont2,size2=0;
	float porcentaje2;
	for(auto it=itera;it!=v.end();it++){
		if(it->enfermo==1){
			cont2++;
			size2++;
		}else{
			size2++;
		}
	}
	porcentaje2=(cont2*100)/size2;
	
	
	ofstream archiout("reporte.txt",ios::app);
	archiout.clear();
	archiout<<"Cantidad de individuos grupo 1: "<<size1<<endl
		<<"Cantidad de individuos grupo 2: "<<size2<<endl
		<<"Porcentaje de infectados grupo 1: "<<porcentaje1<<endl
		<<"Porcentaje de infectados grupo 2: "<<porcentaje2<<endl<<endl<<endl
		<<"LISTA DE INFECTADOS: "<<endl;
	
	
	for(size_t i=0;i<v.size();i++){
		if(v[i].enfermo==1){
			archiout<<v[i].codigo<<endl;
		}
	}
	
	
}

bool operator==(Datos a, Datos b){
	return a.enfermo==b.enfermo;
}
bool operator <(Datos a, Datos b){
	return (a.codigo<b.codigo);
}

int main() {
	
	return 0;
}

/* 1 abc324
	0 bas421
	2 ------*/
	
	
	
