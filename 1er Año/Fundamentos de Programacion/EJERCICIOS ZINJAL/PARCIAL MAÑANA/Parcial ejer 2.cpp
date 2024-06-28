#include <iostream>
using namespace std;

int main() {
	int N;
	cout<<"ingrese cantidad de datos de caudales"<<endl;
	cin>>N

	
	vector<int>Caudales(N)
	
	
	int caudalMayor=0;
	
	for (int=0;i<N;i++){
		cout<<" ingrese caudal "<<i<<endl;
		cin>>Caudales[i];
		if(Caudales[i] > caudalMayor){
			caudalMayor=Caudales[i]
		}
	}
	
	for (int i= 0;i<N;i++){
		if (Caudales[i] = caudalMayor){
			recuento ++;
		}
	}
	
	cout<<"El caudal "<<caudalMayor<<" aparece "<<recuento<<" veces "<<endl;
	return 0;
}

