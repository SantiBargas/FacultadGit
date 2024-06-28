#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	
	vector<string>v;
	
	ifstream archi("PROSA.txt");
	
	if(!archi.is_open()){
		cerr<<"No se pudo abrir";
		return 1;
	}
	string s;
	cout<<"ARCHIVO SIN MODIFICAR: "<<endl; 
	while(archi>>s){
		cout<<s<<"  ";
		v.push_back(s);
	}
	archi.close();
	
	int cont=0;
	for(size_t i=0;i<v.size();i++){
		if(v[i]=="software"){
			cont++;
			v[i]="programa";
		}
	}
	
	ofstream archiout("PROSA.txt",ios::trunc);
	for(size_t i=0;i<v.size();i++){
		archiout<<v[i]<<endl;
	}
	archi.close();
	cout<<endl<<"Se realizaron: "<<cont<<" cambios";
	return 0;
}

