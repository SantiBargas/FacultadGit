#include <iostream>
#include <vector>
using namespace std;

void BuscarPromedio(vector<int>V,int promedio) {
	int total=0,contnegativos=0, contpositivos=0;
	float promedio=0;
	for (int i=0;i<V.size();i++){
		
		if(V[i]>=0){
			total+=V[i];
			contpositivos++;
		}
		else{
			contnegativos++;
		}
	}
	return total/contpositivos;
}

int main() {
	vector<int> V(20,0);
	
	for (int i=0;i<V.size();i++){
		V[i]= -10 + rand() %50; 
		cout<<V[i]<<"   ";
	}
	
	
	Promedio=BuscarPromedio(V,promedio);
	
	for (int i=0;i<V.size();i++){
		
		if (V[i]<=0){
			V[i]=promedio;
		}
	}
	
	cout<<"el nuevo vector es"<<endl;
	for (int i=0;i<V.size();i++){
		
		cout<<V[i]<<"   ";
	}
	
	cout<<"se realizaron "<<contnegativos<<" cambios";
	
	return 0;
}

