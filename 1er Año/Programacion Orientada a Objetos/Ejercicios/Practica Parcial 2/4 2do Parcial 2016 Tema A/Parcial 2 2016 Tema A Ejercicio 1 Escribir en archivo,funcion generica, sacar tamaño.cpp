#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<typename T>
struct str{
	T valor;
	char pos;
};

template<typename T> void ampliar(string archname,vector<str<T>>&x){
	
	ofstream f(archname,ios::binary|ios::trunc);

	
	for(size_t i=0;i<x.size();i++){
		if(x[i].pos=='f'){
			f.write(reinterpret_cast<char*>(&x[i]),sizeof(x[i]));
		}
	}
	for(size_t i=0;i<x.size();i++){
		if(x[i].pos=='b'){
			f.write(reinterpret_cast<char*>(&x[i]),sizeof(x[i]));
			
		}
	}
	f.close();
}
int main() {
	
	srand(time(nullptr));
	
	vector<str<float>>v;
	for(int i=0;i<10;i++) { 
		str<float> P;
		P.valor = (rand()%200)*.6f;
		if(i%2==0){
			P.pos='f';
		}else{
			P.pos='b';
		}
		v.push_back(P);
	}
	
	cout<<"Vector: \n";
	for(str<float>x:v) cout<<x.valor<<"  "<<x.pos<<endl;
	
	ampliar("Datos.bin",v);
	
	ifstream f("Datos.bin",ios::binary);
	cout<<"\nBinario: \n";
	for(size_t i=0; i<v.size(); ++i){
		str <float> P;
		f.read(reinterpret_cast<char*>(&P), sizeof(P));
		cout<<P.valor<<"\t"<<P.pos<<endl;
	}
	
	return 0;
}

