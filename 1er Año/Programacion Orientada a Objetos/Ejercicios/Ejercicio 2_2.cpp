#include <iostream>
#include <cmath>
using namespace std;

class Polinomio{
private:
	float m_coefs[20];
	int m_grado;

public:
	Polinomio(int grado){
		m_grado = grado;
		for(int i=0;i<=m_grado;i++){
			m_coefs[i]=0;
		}
	}
	void CargarCoef(int i, int c){
		m_coefs[i]=c;
	}
	float Evaluar(float x){
		float sum=0;
		for(int i=0;i<=m_grado;i++){
			sum += m_coefs[i]*pow(x,i);
		}
		return sum;
	}
	int VerGrado(){return m_grado;}
	int VerCoef(int i){return m_coefs[i];}
	
	
	Polinomio Sumar(Polinomio p2){
		Polinomio ps( max( this->VerGrado() , p2.VerGrado() ) ); //Max funcion para sacar el mayor de los coefs
		for(int i=0;i<=ps.VerGrado();i++){
			ps.CargarCoef(i, VerCoef(i)+p2.VerCoef(i));
		}
	}
	return ps;

	
};


int main() {

	Polinomio p1(2); // 0*x^0 + 0*x^1 + 0*x^2
	p1.CargarCoef(0,3); //3*x^0 + 0*x^1 + 0*x^2
	p1.CargarCoef(2,1); //3*x^0 + 0*x^1 + 1*x^2
	
	Polinomio p2(2); // 0*x^0 + 0*x^1 + 0*x^2
	p2.CargarCoef(1,1); //3*x^0 + 0*x^1 + 0*x^2
	p1.CargarCoef(2,5); //3*x^0 + 0*x^1 + 1*x^2
	
	cout<<"El polinomio valuado en dos es: "<<p1.Evaluar(2)<<endl;  //3*2^0 + 0*2^1 + 1*2^2
	
	for(int i=0;i<=p1.VerGrado();i++){
		if(i!=0){
			cout<<"  "<< p1.VerCoef(i) << "*x^"<<i;
		}	
	}
	
	cout<<endl<<endl<<"SUMA DEL POLINOMIO:"<<endl;
	Polinomio ps = p1.Sumar(p2);
	for(int i=0;i<=ps.VerGrado();i++){
		if(i!=0){
			cout<< ps.VerCoef(i) << "*x " << i;
		}	
	}
	
	return 0;
}

