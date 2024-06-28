#include <iostream>
#include <vector>
using namespace std;
int buscarpos(vector<int>lista,int borrar);
void eliminar(vector<int>&lista,int posi);
int main() {
	cout<<"cuantos enteros hay?"<<endl;
	int N;
	cin>>N;
	vector<int>lista(N);
	
	cout<<"ingrese valores"<<endl;
	for(int i=0;i<lista.size();i++){
		cin>>lista[i];
	}
	for(int i=0;i<lista.size();i++){
		cout<<lista[i]<<" ";
	}
	cout<<endl<<endl;
	
	
	cout<<"que numero desea eliminar?"<<endl;
	int borrar;
	cin>>borrar;
	
	
	int posi=buscarpos(lista,borrar);
	if(posi==-1){
		cout<<"no se encontro ese numero en la lista"<<endl;}
	else{
		cout<<"el elemento a borrar se encuentra en la posicion: "<<posi+1<<endl;
		eliminar(lista,posi);
	}
	cout<<endl<<endl;
	
	
	
	for(int i=0;i<lista.size();i++){
		cout<<lista[i];
	}
	return 0;
}

int buscarpos(vector<int>lista,int borrar){
	for (int i=0;i<lista.size();i++){
		if(lista[i]==borrar){
			return i;
			break;
		}
	}
	return -1;
}
void eliminar(vector<int>&lista, int posi){
	for(int i=posi+1;i<lista.size();i++){
		lista[i-1]=lista[i];
	}
	lista.resize(lista.size()-1);
}
