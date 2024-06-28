#include <iostream>
#include <vector>
using namespace std;

int buscarpos(vector<string>lista, string apellido);
void insertar(vector<string>&lista, int pos, string apellido);

int main() {
	vector<string>lista;
	lista.push_back("ALARCON");
	lista.push_back("ETCHEVERRIA");
	lista.push_back("OSOBLANCO");
	
	string apellido;
	
	cout<<"ingrese nuevo apellido a insertar"<<endl;
	cin>>apellido;
	
	int pos=buscarpos(lista,apellido);
	
	if(pos==-1){
		lista.push_back(apellido);
	}
	else{
		insertar(lista,pos,apellido);
	}
	
	for (int i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
	
	
	return 0;
}

int buscarpos(vector<string>lista, string apellido){
	
	for (int i=0;i<lista.size();i++){
		if(apellido<lista[i]){
			return i;
		}
	}
	return -1;
}

void insertar(vector<string>&lista, int pos, string apellido){	
	
	for (int i=pos;i>lista.size()-1;i--){
		lista[i]=lista[i-1];
	}
	lista[pos]=apellido;
	
}
	
