#include <iostream>
using namespace std;
/*Una fábrica de conservas hace envases de forma cilíndrica (lata) o de prisma recto (caja); en ambos
	envases debemos rotular el volumen en cm3 y el peso en gramos.
	Modele una clase base Envase con los atributos volumen y peso. Un método público AsignarPeso(p), un
	método virtual puro CalcularVolumen() que calcule el volumen de acuerdo a los parámetros de los hijos
	y otros 2 métodos para VerVolumen() y VerPeso().
	Modele la clase hija Lata que tendrá los atributos radio y altura, cuya fórmula de volumen es: área de la
	base x altura, donde el área de la base es PI*radio^2; y otra clase hija Caja que tendrá los atributos
	largo, ancho y alto, cuya fórmula de volumen es: largo x ancho x alto. Los atributos los debe cargar en
	sus respectivos constructores. Estos (los constructores de Caja y Lata) recibirán las medidas
	necesarias, y el peso.
	En el programa principal debe usar un único puntero de tipo Envase para crear primero una Lata y
	mostrar su volúmen, y luego una Caja y también mostrar su volúmen*/

class Envase{
protected:
	float m_volumen;
	float m_peso;
public:
	void AsignarPeso(float peso){m_peso=peso;}
	void virtual CalcularVolumen()=0;
	float VerVolumen(){return m_volumen;}
	float VerPeso(){return m_peso;}

};

class Lata:public Envase{
private:
	float m_radio;
	float m_altura;
public:
	Lata(float radio,float altura, float ppeso):m_radio(radio),m_altura(altura){
		AsignarPeso(ppeso);
	}
	
	void CalcularVolumen(){
		float area=3.14*m_radio*m_radio;
		m_volumen=area*m_altura;
	}
};

class Caja:public Envase{
private:
	float m_largo;
	float m_ancho;
	float m_alto;
public:
	Caja(float largo,float ancho,float alto, float peso):m_largo(largo),m_alto(alto),m_ancho(ancho){
		AsignarPeso(peso);
	}

	void CalcularVolumen(){
		m_volumen=m_largo*m_ancho*m_alto;
	}
};
int main() {
	
	Envase *p;
	
	p= new Caja(1,2,3,5);
	cout<<"Peso caja: "<<p->VerPeso()<<endl;
	p->CalcularVolumen();
	cout<<"Volumen caja: "<<p->VerVolumen()<<endl;
	
	p=new Lata(1,1,1);
	cout<<"Peso Lata: "<<p->VerPeso()<<endl;
	p->CalcularVolumen();
	cout<<"Volumen Lata: "<<p->VerVolumen()<<endl;
	
	delete p;
	
	return 0;
}

