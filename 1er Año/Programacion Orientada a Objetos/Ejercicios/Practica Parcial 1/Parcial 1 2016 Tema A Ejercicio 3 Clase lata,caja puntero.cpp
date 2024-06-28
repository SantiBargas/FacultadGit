#include <iostream>
using namespace std;
/*Una f�brica de conservas hace envases de forma cil�ndrica (lata) o de prisma recto (caja); en ambos
	envases debemos rotular el volumen en cm3 y el peso en gramos.
	Modele una clase base Envase con los atributos volumen y peso. Un m�todo p�blico AsignarPeso(p), un
	m�todo virtual puro CalcularVolumen() que calcule el volumen de acuerdo a los par�metros de los hijos
	y otros 2 m�todos para VerVolumen() y VerPeso().
	Modele la clase hija Lata que tendr� los atributos radio y altura, cuya f�rmula de volumen es: �rea de la
	base x altura, donde el �rea de la base es PI*radio^2; y otra clase hija Caja que tendr� los atributos
	largo, ancho y alto, cuya f�rmula de volumen es: largo x ancho x alto. Los atributos los debe cargar en
	sus respectivos constructores. Estos (los constructores de Caja y Lata) recibir�n las medidas
	necesarias, y el peso.
	En el programa principal debe usar un �nico puntero de tipo Envase para crear primero una Lata y
	mostrar su vol�men, y luego una Caja y tambi�n mostrar su vol�men*/

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

