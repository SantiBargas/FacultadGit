#include <iostream>
using namespace std;

class latag
	{	private :
			float radio, altura, volumen;
		public :
			void datosclase(float r, float a);
			void calculo_vol(); ///no necesita argumentos pq puede usar los parametros d la clase
			float muestra_resultado(){return volumen;};
	};		
	
int main() {
	
	float r,a;
	latag l; ///latag es un tipo de variable
	
	cout<<"ingrese radio"<<endl;
	cin>>r;
	cout<<"ingrese altura"<<endl;
	cin>>a;
	
	l.datosclase(r,a); ///defino r y a en radio y altura con la funcion
	l.calculo_vol(); ///se calcula el volumen con la funcion
	
	cout<<"El volumen de la lata es: "<<l.muestra_resultado();
	
	return 0;
}

void latag::datosclase(float r, float a){
radio=r; altura=a;}

void latag::calculo_vol(){
	volumen=3.14*radio*radio*altura;
}
