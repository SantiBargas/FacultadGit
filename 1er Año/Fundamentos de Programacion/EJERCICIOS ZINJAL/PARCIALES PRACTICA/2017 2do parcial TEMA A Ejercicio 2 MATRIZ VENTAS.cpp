#include <iostream>
#include <matrix>
using namespace std;

int main() {
	matrix<int>Vendedores(15,30,0);
	
	int codigo,dia,jugos;
	
	cout<<"ingrese codigo del vendedor (1 a 15) en 0 termina"<<endl;
	cin>>codigo;
	
	while(codigo!=0){
		cout<<"ingrese dia de la venta (1 a 30)"<<endl;
		cin>>dia;
		
		cout<<"ingrese cant de jugos vendidas"<<endl;
		cin>>jugos;
		
		Vendedores[codigo-1][dia-1]+=jugos;
		
		cout<<"ingrese codigo del vendedor (1 a 15) en 0 termina"<<endl;
		cin>>codigo;
		
	}
	
	for(int i=0;i<Vendedores.size(0);i++){
		for (int j=0;j<Vendedores.size(1);j++){
			cout<<Vendedores[i][j]<<"    ";
		}
		cout<<endl;
	}
	
	int mayorvendedor=0,Vendedor10=0;
	
	for(int i=0;i<15;i++){
		
		if(Vendedores[i][9]>mayorvendedor){
			mayorvendedor=Vendedores[i][9];
			Vendedor10=i;
			
		}
	}
	cout<<"el codigo del vendedor q mas vendio el dia 10 es "<<Vendedor10+1<<" CON UN TOTAL DE "<<mayorvendedor<<endl;
	
	
	for(int i=0;i<Vendedores.size(0);i++){
		int total=0;
		for (int j=0;j<Vendedores.size(1);j++){
			total+=Vendedores[i][j];
		}
		cout<<"el vendedor "<<i+1<<" vendio "<<total<<" en los 30 dias"<<endl;
	}
	
	int vend=0;
	for(int j=0;j<Vendedores.size(1);j++){
		vend+=Vendedores[9][j];
	}
	cout<<"el vendedor 10 realizo "<<vend<<" ventas";
	return 0;
}

