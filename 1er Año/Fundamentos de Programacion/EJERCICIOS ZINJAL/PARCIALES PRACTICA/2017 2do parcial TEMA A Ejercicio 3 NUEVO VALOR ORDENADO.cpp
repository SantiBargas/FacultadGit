#include <iostream>
#include <vector>
using namespace std;

int buscarpos(vector<int>datos, int nuevo);
void inserta(vector<int>&datos, int nuevo,int pos);

int main() {
	
	int n;
	cout<<"ingrese cant de datos"<<endl;
	cin>>n;
	vector<int>datos(n);
	
	for(size_t i=0;i<datos.size();i++){
		cin>>datos[i];
		
	}
	
	cout<<"la lista es"<<endl;
	for(int i=0;i<datos.size();i++){
		cout<<datos[i]<<endl;
	}
	
	int nuevo;
	cout<<"ingrese nuevo valor"<<endl;
	cin>>nuevo;
	
	datos.resize(datos.size()+1);
	
	int pos=buscarpos(datos,nuevo);
	
	if(pos==-1){
		datos.push_back(nuevo);
	}
	else{
		inserta(datos,nuevo,pos);
	}
	
	cout<<"la nueva nota es"<<endl;
	for(int i=0;i<datos.size();i++){
		cout<<datos[i]<<endl;
		
	}
	
	return 0;
}


int buscarpos(vector<int>datos, int nuevo) {
	for (int i=0;i<datos.size();i++){
		if(datos[i]<nuevo){
			return i;
		}
	}

	return -1;
}

void inserta(vector<int>&datos, int nuevo,int pos){
	for(int i=datos.size()-1;i>pos;i--){
		datos[i]=datos[i-1];
	}
	datos[pos]=nuevo;
}
