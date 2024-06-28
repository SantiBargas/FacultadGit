#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
///Un delivery de pizzas las hace rectangulares y redondas. Cada pizza puede ser de un tipo diferente(muzzarella/palmitos/chocolate)
///Modele una clase base Pizza que permita guardar y consultar el tipo. Implemente las clases PizzaRectangular y PizzaRedonda
///reutilizando la clase Pizza para la cuadrada), Implemente un metodo calcularCosto(dolar), que reciba el precio del dolar y en base
///al mismo calcule el costo de una pizza.Para las cuadradas el costo es T x dolar x anchi x alto / 16
///Para las redondas como T x dolar x PI x radio.radio /20 . T vale 1.0 para la de muzarella, 1.45 para la de palmitos y 1.8 para la de chocolate
///Implemente una funcion CostoPedido que reciba un arreglo/vector de pizzas con todas las pizzas de un cierto pedido, y el valor del dolar
/// al momento de cobrar, y sume y retorne el total del mismo

class Pizza{
protected:
	string m_tipo;  //tipo=sabor chocolate, muzzarella, palmito
public:
	Pizza(string tipo) : m_tipo(tipo){}
	string VerTipo(){return m_tipo;}
	virtual float CalcularCosto(float dolar)=0;
	virtual ~Pizza() { }
};

class PizzaRectangular : public Pizza{
private:
	int m_ancho,m_alto;
public:
	PizzaRectangular(string tipo,int ancho, int alto):Pizza(tipo),m_ancho(ancho),m_alto(alto){}   ///le paso el tipo a la clase madre
	float CalcularCosto(float dolar){
		float T;
		if(m_tipo=="Chocolate"){
			T=1.8;
		}	
		else{
			if(m_tipo=="Palmitos"){
				T=1.45;
			}else{
				T=1.0;
			}
		}	
		return (T * dolar * 3.14 * m_alto*m_ancho)/16;
	}
};

class PizzaRedonda: public Pizza{
private:
	int m_radio;
public:
	PizzaRedonda(string tipo,int radio):Pizza(tipo), m_radio(radio){}
	float CalcularCosto(float dolar){
		float T;
		if(m_tipo=="Chocolate"){
			T=1.8;
		}else{
			if(m_tipo=="Palmitos"){
				T=1.45;
			}
		else{T=1.0;}}
		
		return (T*dolar*3.14*m_radio*m_radio)/20;
	}
};
float costoPedido(vector<Pizza*>&lista, float dolar){
	float sum=0;
	
	for(Pizza *p:lista){
		sum += p->CalcularCosto(dolar);
		//sum +=(*p)->CalcularCosto(dolar);
	}
	return sum;
}
int main() {
	///se usa el puntero, pq si uso un vector de tipo pizza no voy a poder acceder a las clases hijas
	vector<Pizza*>lista;
	lista.push_back(new PizzaRectangular("Chocolate",30,30));  ///ancho y alto pq es rectangular
	lista.push_back(new PizzaRedonda("Palmito",10));///radio pq es redonda
	
	float dolar=100.6;
	
	cout<<"El costo del pedido es: "<<costoPedido(lista,dolar)<<endl;
	
	for(size_t i=0;i<lista.size();i++){
		delete lista[i];
	}
	/*for(Pizza *p : lista) delete p;
	*/
	return 0;
}

