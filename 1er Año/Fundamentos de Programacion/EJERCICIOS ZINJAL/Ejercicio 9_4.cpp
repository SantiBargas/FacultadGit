#include <iostream>
#include <vector>
using namespace std;

int main() {
	int nota;
	
	cout<<"ingrese la nota en 0 finaliza"<<endl;
	cin>>nota;
	
	vector<string> aprob, noaprob;
	
	while(nota!=0){
		cout<<"ingrese nombre"<<endl;
		string nombre;
		cin.ignore();
		getline(cin, nombre);
		
		if(nota>=6){
			aprob.push_back(nombre);
		}
		else{
			noaprob.push_back(nombre);
		}
		
		
		
		cout<<"ingrese la nota en 0 finaliza"<<endl;
		cin>>nota;
		
	}
	
	cout<<"los aprobados son:"<<endl;
	for(int i=0;i<aprob.size();i++){
		cout<<aprob[i]<<endl;
	}
	
	cout<<"los no aprobados son:"<<endl;
	for(int i=0;i<noaprob.size();i++){
		cout<<noaprob[i]<<endl;
	}
	
	return 0;
}

