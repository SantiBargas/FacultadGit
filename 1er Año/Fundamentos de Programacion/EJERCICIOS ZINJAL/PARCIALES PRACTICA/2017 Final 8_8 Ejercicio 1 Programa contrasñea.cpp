#include <iostream>
#include <vector>
using namespace std;
void validar_contrasenia(string contra);
int buscar_pos(vector<string>Nom, string iden);
int main() {
	
	vector<string>contrasenia;
	vector<string>Nom;
	
	string nombre,contra;
	
	
	cout<<"ingrese nombre en ZZZ termina"<<endl;
	cin>>nombre;
	Nom.push_back(nombre);
	
	while(nombre!="ZZZ"){
		
		cout<<"ingrese contraseña"<<endl;
		cin>>contra;
		validar_contrasenia(contra);
		contrasenia.push_back(contra);
		
		cout<<"ingrese nombre en ZZZ termina"<<endl;
		cin>>nombre;
		Nom.push_back(nombre);
	}
	
	string iden;
	cout<<"Por favor identifiquese"<<endl;
	cin>>iden;
	
	int conta=0;
	int pos=buscar_pos(Nom, iden);
	if(pos==-1){
		cout<<"ingreso un usuario no registrado"<<endl;
	}
	else{
		string iden2;
		cout<<"ingrese contraseña"<<endl;
		cin>>iden2;
		
		while(conta<5){
			
			if(contrasenia[pos]==iden2){
				cout<<"Bienvenido al sistema Sr "<<Nom[pos];
				break;
			}
			else{
				cout<<"contraseña incorrecta"<<endl;
				conta++;
			}
			cout<<"ingrese contraseña"<<endl;
			cin>>iden2;
			
			if(conta==5){
				cout<<"fuera bicho"<<endl;
			}
		}
		
	}
	
	
	
	
	return 0;
}

void validar_contrasenia(string contra){
	if(contra=="1234" or contra=="asdf" or contra=="pass" or contra=="   "){
		cout<<"contraseña incorrecta, reingrese"<<endl;
		cin>>contra;
	}
}
int buscar_pos(vector<string>Nom, string iden){
	
	for(int i=0;i<Nom.size();i++){
		if(Nom[i]==iden){
			return i;
		}
	}
	return -1;
}
