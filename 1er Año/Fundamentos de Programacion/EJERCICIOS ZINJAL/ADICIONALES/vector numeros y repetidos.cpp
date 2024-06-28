#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

bool existenum(vector<int>lista,int num);
tuple<int,int> masrepetido(vector<int>repetidos);

int main() {
	vector<int>lista;
	vector<int>repetidos(81,0); ///Vector de 1 a 80, sacando el 0
	int num;
	
	for(int i=0;i<500;i++){
		num=1+rand()%80;
		if( existenum(lista,num)==false){
			lista.push_back(num);
		}
		
		repetidos[num]++;  ///si la funcion es verdadera, no suma el numero a la lista
							///y voy contando cuantas veces se repitio
		
	}
	cout<<"vector d numeros sin repetir"<<endl;
	for(int i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}cout<<endl<<endl<<endl;
	
	cout<<"NUMEROS REPETIDOS"<<endl;
	for(int i=1;i<81;i++){
		cout<<i<<" : "<<repetidos[i]<<" veces"<<endl;
	}
	
	cout<<endl<<endl;
	int veces,numayor;
	tie(veces,numayor)=masrepetido(repetidos);
	cout<<"el numero: "<<numayor<<" se repitio: "<<veces;
	
	return 0;
}
bool existenum(vector<int>lista,int num){
	
	for(int i=0;i<lista.size();i++){
		if(lista[i]==num){
			return true;
		}
	}
	return false;
}
tuple<int,int> masrepetido(vector<int>repetidos){
	int veces=0, numayor;
	
	for(int i=0;i<repetidos.size();i++){
		if(repetidos[i]>veces){
			veces=repetidos[i];
			numayor=i;
		}
	}
	return make_tuple(veces,numayor);
}
