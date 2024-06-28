#include <iostream>
#include <vector>
using namespace std;

struct Licencia{
	string software;
	string licencia;
	int costo;
};
int calcular_costos(vector<Licencia>Licencias,int
int main() {
	int N;
	cout<<"ingrese cant de programas"<<endl;
	cin>>N;
	vector<Licencia>Licencias(N);
	Lic L;
	
	for(int i=0;i<Licencias.size();i++){
		cout<<"ingrese nombre del software"<<endl;
		cin>>Licencia[i].software;
		
		cout<<"ingrese nombre de licencia"<<endl;
		cin>>Licencias[i].licencia;
		
		cout<<"ingrese costo en dolares"<<endl;
		cin>>Licencias[i].costo;
		
		
	}
	
	
	
	
	return 0;
}

