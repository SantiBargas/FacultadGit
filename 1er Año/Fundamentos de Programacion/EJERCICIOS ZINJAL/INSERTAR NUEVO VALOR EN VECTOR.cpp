#include <iostream >
#include <vector>
using namespace std;
int buscarpos(vector<string>lista, string apellido);
void inserta(vector<string>&lista, int pos, string apellidoinsertar);
int main() {
	
	vector<string>lista;
	lista.push_back("ALARCON");
	lista.push_back("ARCE");
	lista.push_back("BASUALDO");
	lista.push_back("BELTRAME");
	lista.push_back("CACERES");
	lista.push_back("DAMICO");
	lista.push_back("FARIAS");
	lista.push_back("FERNANDEZ");
	lista.push_back("GAMARRA");
	lista.push_back("GOMEZ");
	lista.push_back("GUTIERREZ");
	lista.push_back("LAMBERTO");
	lista.push_back("LEME");
	lista.push_back("LOPEZ");
	lista.push_back("LUGUERCIO");
	lista.push_back("MANTARAS");
	lista.push_back("MENDEZ");
	lista.push_back("NARDI");
	lista.push_back("PASCULLI");
	lista.push_back("PEREZ");
	
	
	
	string apellidoinsertar;
	cout<<"ingrese apellido a insertar"<<endl;
	cin>>apellidoinsertar;
	
	
	int pos= buscarpos(lista,apellidoinsertar);
	cout<<pos<<endl;
	
	if(pos==-1){
		lista.push_back(apellidoinsertar);}
	else{
		inserta(lista,pos,apellidoinsertar);
	}
	
	for (int i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
	
	
	return 0;
}

int buscarpos(vector<string>lista, string apellido){
	for (int i=0;i<lista.size();i++){
		if(lista[i]>apellido){
			return i;
		}
	}
	return -1; ///en este caso solo se hace un push back
}
	
	void inserta(vector<string>&lista, int pos, string apellidoinsertar){
		
		for(int i=lista.size()-1;i>pos;i--){
			lista[i]=lista[i-1];
		}
		lista[pos]=apellidoinsertar;
	}
		
