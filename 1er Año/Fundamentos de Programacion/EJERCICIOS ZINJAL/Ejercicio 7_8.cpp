#include <iostream>
using namespace std;

int main() {
	
	int MesNac, DiaNac, AnioNac;
	int MesVot, DiaVot, AnioVot;
	
	/// 11/09//2001   aaaammdd Anio*10000 + Mes + 100 + Dia = 20010911
	
	
	cout<<"ingrese dia votacion"<<endl;
	cin>>DiaVot;
	cout<<"ingrese mes voracion"<<endl;
	cin>>MesVot;	
	cout<<"ingrese año voracion"<<endl;
	cin>>AnioVot;
	
	
	cout<<"ingrese dia nacimiento"<<endl;
	cin>>DiaNac;			
	cout<<"ingrese mes nacimiento"<<endl;
	cin>>MesNac;	
	cout<<"ingrese año nacimiento"<<endl;
	cin>>AnioNac;
	
	int sumafechanac = AnioNac * 10000 + MesNac*100 + DiaNac;
	int sumafechavot = AnioVot * 10000 + MesVot*100 + DiaVot;
	int resta = sumafechavot - sumafechanac;
	int edad= resta/1000;
	
	if (edad>= 18) {
		cout<<edad<<" años. Puede votar"<<endl;
	}
	else{
		cout<<edad<<" años. No puede votar"<<endl;
	}
	
	return 0;
}

