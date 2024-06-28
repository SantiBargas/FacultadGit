#include <iostream>
#include <vector>
using namespace std;

struct Compra{
	string codigo_producto;
	float precio_unitario;
	int cantidad;
};
struct Descuento{
	string descripcion;
	float monto;
};

class Promocion{
protected:
	string m_descripcion;
public:
	Promocion(string descripcion):m_descripcion(descripcion){}
	float virtual Aplicar(Compra &c)=0;
	string VerDescripcion(){return m_descripcion;}
};

class Promo3x2:public Promocion{
public:
	Promo3x2():Promocion("3x2 en todas las marcas"){}
	
	float Aplicar(Compra &c){
		if(c.cantidad>3){
			return (c.cantidad/3)*c.precio_unitario;    //resto 1 por cada 3 productos
		}else{
			cout<<"No Aplicable"<<endl;
		}
		return 0;
	}
};

class Promo1000:public Promocion{
public:
	Promo1000():Promocion("5% en compras superiores a 1000"){}
	
	float Aplicar(Compra &b){
		if(b.precio_unitario*b.cantidad>=1000){  //la compra es precio por cantidad
			return b.precio_unitario*b.cantidad * 0.05 ;   //al total de 5%
		}else{
			cout<<"No Aplicable"<<endl;
		}
		return 0;
	}

};

vector<Descuento> ListaDeDescuentos(vector<Compra>&lista, Promo3x2 a, Promo1000 b){
	
	vector<Descuento>V;
	
	for(int i=0;i<lista.size();i++){
		float aux1,aux2;
		
		aux1=a.Aplicar(lista[i]);
		aux1=b.Aplicar(lista[i]);
		
		if(aux1>0){
			V.push_back(Descuento{a.VerDescripcion(),aux1});
		}else{
			if(aux2>0){
			V.push_back(Descuento{b.VerDescripcion(),aux2});
			}
		}
		
	}
	
	return V;
}
	
	


int main() {
	
	vector<Compra>lista;
	vector<Descuento>datos;
	Promo3x2 a;
	Promo1000 b;

	//compra: codigo_producto, precio_unitario, cantidad
	lista.push_back(Compra{"P1082",20,4});
	lista.push_back(Compra{"P1083",130,2});
	lista.push_back(Compra{"P1084",100,6});
	lista.push_back(Compra{"P1085",200,7});
	

	datos=ListaDeDescuentos(lista,a,b);
	
	for(int i=0;i<datos.size();i++){
		cout<<datos[i].descripcion<<"  Monto: "<<datos[i].monto<<endl;  
	}
	
	return 0;
}

