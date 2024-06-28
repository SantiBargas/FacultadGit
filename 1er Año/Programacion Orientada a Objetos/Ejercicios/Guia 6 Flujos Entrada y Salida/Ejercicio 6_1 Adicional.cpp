#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void CreateDummyFilePosta(string nom,int tam){
	fstream archi(nom,ios::binary|ios::trunc);
	
	for(int i=0;i<tam;i++) { 
		int x=rand()%100;
		archi.write(reinterpret_cast<char*>(&x),sizeof(x));
	}
}

void CreateDummyFile(string nom,string tam){
	string unid= tam.substr(tam.size()-2); //si es 10Mb extraigo Mb;
	
	int aux=0;
	if(unid=="Mb") aux=3;
	else if(unid=="Gb") aux=2;
	else if(unid=="Kb") aux=1;
	
	int x=1; if(aux!=0) x=2; //gb,mb,kb extraigo 2, si es b 1 solo
	long double n= stoll(tam.substr(0,tam.size()-x));
	
	CreateDummyFilePosta(nom,n*pow(1024,aux));
	
}

int main() {
	
	CreateDummyFile("Basura_de_10Gb.dat","3.25mb");
	
	return 0;
}

