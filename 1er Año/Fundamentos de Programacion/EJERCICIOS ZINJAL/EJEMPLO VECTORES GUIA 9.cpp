#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int>CrearVector(int CantElementos, int ValorInicial= 0);
void LlenaVector(vector<int>&lista);
int main() {
	vector<int>lista= CrearVector(20,0);
	LlenaVector(lista);
	for (int i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
	return 0;
}


vector<int>CrearVector(int CantElementos, int ValorInicial){
	vector<int>aux(CantElementos,ValorInicial);
	return aux;
}
void LlenaVector(vector<int>&lista){
	for (int i=0;i<lista.size();i++){
		lista[i] = 100+rand()%600;
	}
}
