#include <iostream>
using namespace std;

class Complejo{
private:
	float m_real,m_imaginario;
public:
	Complejo():m_real(0),m_imaginario(0){}
	Complejo(float real, float imaginario): m_real(real),m_imaginario(imaginario){}
	float VerReal(){return m_real;}
	float VerIm(){return m_imaginario;}
	Complejo operator+(Complejo a);
	Complejo operator-(Complejo a);
	bool operator==(Complejo a);
	bool operator!=(Complejo a);
	
};

Complejo Complejo :: operator+(Complejo a){
	float v1= this-> m_real + a.VerReal();
	float v2= this-> m_imaginario + a.VerIm();
	Complejo p(v1,v2);
	return p;
}
Complejo Complejo :: operator-(Complejo a){
	float v1= this-> m_real - a.VerReal();
	float v2= this-> m_imaginario - a.VerIm();
	Complejo p(v1,v2);
	return p;
}

bool Complejo :: operator==(Complejo a){
	
	return this ->m_real == a.VerReal() && this->m_imaginario==a.VerIm();

}

bool Complejo :: operator!=(Complejo a){
	
	return this ->m_real != a.VerReal() && this->m_imaginario!=a.VerIm();

}





ostream &operator<<(ostream &o, Complejo a){
	o<<a.VerReal()<<"  "<<a.VerIm()<<"i";
	return o;
}

int main() {
	
	Complejo a(5,7); Complejo b(2,8);
	cout<<"Complejo 1: "<<a<<endl;
	cout<<"Complejo 2: "<<b<<endl<<endl<<endl;
	
	cout<<"SUMA: "<<a+b<<endl;
	cout<<"RESTA: "<<a-b<<endl;
	if(a==b)cout<<"SON IGUALES"<<endl;
	if(a!=b)cout<<"SON DISTINTOS"<<endl;

	
	
	return 0;
}

