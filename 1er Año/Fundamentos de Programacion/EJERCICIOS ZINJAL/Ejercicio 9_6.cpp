#include <iostream>
#include <vector>
using namespace std;

int MenorAporte(vector<int> Aporte) {
	int menormes=100000000000;
	for (size_t i=0;i<Aporte.size();i++){
		if(Aporte[i]<menormes){
			menormes=i;
		}
	}
return menormes;
}

void foo(vector<int> Aporte) {
	for (size_t i=0;i<Aporte.size();i++){
		cout<<"el mes "<<i<<"aporto "<<Aporte[i]<<endl;
	}
}

int main() {
	
	vector<int> Aporte(12,0);
	int monto,mes,dia;
	cout<<"ingrese el monto en 0 termina"<<endl;
	cin>>monto;
	
	while(monto!=0){
		cout<<"ingrese mes (1 a 12) y dia"<<endl;
		cin>>mes>>dia;
		
		Aporte[mes-1]+=monto;
		
		cout<<"ingrese el monto en 0 termina"<<endl;
		cin>>monto;
	}
	
	
	cout<<"el mes que menor aporte tuvo es el mes "<<MenorAporte(Aporte)<<"con un aporte de "<<Aporte[MenorAporte(Aporte)]<<endl;
	
	foo(Aporte);
	return 0;
}

