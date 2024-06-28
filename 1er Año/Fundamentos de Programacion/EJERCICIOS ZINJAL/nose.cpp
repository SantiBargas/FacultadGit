#include <iostream>
using namespace std;


int difanios(int f1, int f2){
	int dif = (f2-f1)/10000;
	return dif;
	
}
	


int main() {
	int fecha1, fecha2;
	cout<<"ingrese la fecha inicial en format aaaammdd"<<endl;
	cin>>fecha1;
	cout<<"ingrese la fecha final en format aaaammdd"<<endl;
	cin>>fecha2;
		
	int anios= difanios(fecha1,fecha2);
	
	cout<<"La diferencia en años es: "<<anios;
	return 0;
}

