#include <iostream>
#include <vector>
using namespace std;
/*Un delivery de Pizzas las hace rectangulares y redondas. Cada pizza puede ser de un tipo diferente (muzzarella/palmitos/chocolate). 
Modele una clase base Pizza que permita guardar y consultar el tipo. Implemente las clases PizzaRectangular y PizzaRedonda,
reutilizando la clase Pizza, que permitan definir en su constructor el tipo y sus dimensiones (ancho y alto para la rectangular, radio para la redonda).
	Implemente un método CalcularCosto(dólar) que reciba el precio del dólar y en base al mismo calcule el costo de una pizza. 
	Para las cuadradas, el costo es: T x dólar x ancho x alto / 16. Para las redondas: como T x dólar x PI x radio^2 / 20. T vale 1.0 para la de muzzarella, 
	1.45 para la de palmitos, y 1.8 para la de chocolate. Implemente una función CostoPedido que reciba un arreglo/vector de Pizzas con todas las pizzas de un
	cierto pedido, y el valor del dólar al momento de cobrar el pedido; y sume y retorne el costo total del mismo.*/

class Pizza{
protected:
	string m_tipo;
public:
	Pizza(string tipo):m_tipo(tipo){}
	string VerTipo(){return m_tipo;}
	float virtual CalcularCosto(float dolar)=0;
	virtual ~Pizza(){}
};

class PizzaRectangular : public Pizza{
private:
	float m_alto,m_ancho;
public:
	PizzaRectangular(float alto,float ancho,string tipo):Pizza(tipo),m_alto(alto),m_ancho(ancho){}
	float CalcularCosto(float dolar){
		if(m_tipo=="Muzarella"){
			return 1.0*dolar*m_ancho*m_alto;
		}else{
			if(m_tipo=="Palmito"){
				return 1.45*dolar*m_ancho*m_alto;
			}else{
				return 1.8*dolar*m_ancho*m_alto;
			}
		}
	}
	float VerAncho(){return m_ancho;}
	float VerAlto(){return m_alto;}
	~PizzaRectangular(){}
	
};

class PizzaRedonda : public Pizza{
private:
	float m_radio;
public:
	PizzaRedonda(float radio,string tipo):Pizza(tipo),m_radio(radio){}
	float CalcularCosto(float dolar){
		if(m_tipo=="Muzarella"){
			return 1.0*dolar*3.14*m_radio*m_radio;
		}else{
			if(m_tipo=="Palmito"){
				return 1.45*dolar*3.14*m_radio*m_radio;
			}else{
				return 1.8*dolar*3.14*m_radio*m_radio;
			}
		}
	}
	float VerRadio(){return m_radio;}
	~PizzaRedonda(){}
};

float CostoTotal(vector<Pizza*>lista, float dolar){
	
	int total=0;
	
	for(size_t i=0;i<lista.size();i++){
		
		total+=lista[i]->CalcularCosto(dolar);
		
	}
	
	
	return total;
}

int main() {
	
	float dolar=120;
	
	vector<Pizza*>lista;
	
	lista.push_back(new PizzaRectangular(2,3,"Chocolate"));
	lista.push_back(new PizzaRedonda(2,"Chocolate"));
	lista.push_back(new PizzaRectangular(2,3,"Palmito"));
	lista.push_back(new PizzaRedonda(2,"Muzarella"));
	
	cout<<"El costo total del pedido es: "<<CostoTotal(lista,dolar);
	
	for(size_t i=0;i<lista.size();i++){
		delete lista[i];
	}
	
	
	
	return 0;
}

