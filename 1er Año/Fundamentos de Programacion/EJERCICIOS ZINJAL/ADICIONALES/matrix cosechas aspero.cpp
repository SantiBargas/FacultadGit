#include <iostream>
#include <matrix>
using namespace std;

struct tipocultivo{
	int soja,trigo,maiz;
};

int mayorprov(matrix<tipocultivo>ventas,int aniobuscar);

int main() {
	matrix<tipocultivo>ventas(8,10);
	
	int codprov,anio,indiceanio,cant;
	string tipo;
	
	
	for(int i=0;i<240;i++){
		cout<<"ingrese provinvia "<<endl;
		cin>>codprov;
		
		cout<<"ingrese anio de la venta"<<endl;
		cin>>anio;
		indiceanio=2014-anio;
		cout<<"ingrese tipo de cosecha: soja,trigo,maiz"<<endl;
		cin>>tipo;
		cout<<"ingrese cant de venta"<<endl;
		cin>>cant;
		
		if(tipo=="soja"){
			ventas[codprov-1][indiceanio].soja=cant;
		}
		if(tipo=="trigo"){
			ventas[codprov-1][indiceanio].trigo=cant;
		}
		if(tipo=="maiz"){
			ventas[codprov-1][indiceanio].maiz=cant;
		}
		
	}
	
	/// 2005 -> col 0       2014 -> col 9
	for(int codprov=0;codprov<ventas.size(0);codprov++){
		if(ventas[codprov][9].trigo<ventas[codprov][0].trigo){
			cout<<"la provincia: "<<codprov<<" tuvo menor produccion de trigo en 2014 que en 2005"<<endl;
		}
	}
	
	int aniobuscar;
	cout<<"ingrese año que desea saber mayor produccion"<<endl;
	cin>>aniobuscar;
	cout<<"la provincia con mayor prod de soja en el año: "<<aniobuscar<<" es :"<<mayorprov(ventas,aniobuscar)<<endl;
	
	int suma;
	for(int i=0;i<ventas.size(0);i++){
		suma+=ventas[i][8].maiz;
	}
	cout<<"la venta de maiz en 2013 es "<<suma;
	
	return 0;
}
int mayorprov(matrix<tipocultivo>ventas,int aniobuscar){
	int mayoranio,mayorventa;
	int indiceanio=2014-aniobuscar;
	
	for(int i=0;i<ventas.size(0);i++){
		if(ventas[i][indiceanio].soja>mayorventa){
			mayorventa=ventas[i][indiceanio].soja;
			mayoranio=i;
		}
	}
	return mayoranio;
}
