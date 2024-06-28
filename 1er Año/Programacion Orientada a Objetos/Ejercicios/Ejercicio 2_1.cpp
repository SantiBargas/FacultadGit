#include <iostream>
#include <cmath>
using namespace std;

class Cilindro{
	private:
		float m_radio;
		float m_altura;
	
	public:
	void AsignarDatos(float radio, float altura);
	float ObtenerVolumen();
	/*Cilindro(float radio, float altura);*/ ///constructor para asignar directamente las variables
};


int main() {
	Cilindro c1, c2;
	float r,h;
	
	/*Con constructor seria primer leer c1 para que compile y despues
	c2(5.3,10.2);*/
	
	cout<<"ingrese radio y altura"<<endl;
	cin>>r>>h;
	c1.AsignarDatos(r,h);
	c2.AsignarDatos(5.3,10.2);
	
	cout<<" Vol de c1: "<<c1.ObtenerVolumen()<<endl;
	cout<<" Vol de c2: "<<c2.ObtenerVolumen()<<endl;
	
	return 0;
}
float Cilindro::ObtenerVolumen(){
	return 3.14*m_radio*m_radio*m_altura;
}
void Cilindro::AsignarDatos(float radio, float altura){
	m_radio = radio;	///m_.... miembro de la clase
	m_altura = altura;
}
