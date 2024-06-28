#include <iostream>
using namespace std;

class Fraccion{
private:
	float m_num;
	float m_den;
public:
	Fraccion():m_num(1),m_den(0){}
	Fraccion(float num,float den):m_num(num),m_den(den){}
	float VerNum(){return m_num;}
	float VerDen(){return m_den;}	
};

Fraccion operator+(Fraccion a, Fraccion b){
	
	int v1=a.VerNum()*b.VerDen();
	int v2=a.VerDen()*b.VerNum();
	int num=v1+v2;
	
	int den=a.VerDen()*b.VerDen();
	
	Fraccion p(num,den);
	return p;
}
Fraccion operator*(Fraccion a, Fraccion b){
	
	int num=a.VerNum()*b.VerNum();
	
	int den=a.VerDen()*b.VerDen();
	
	Fraccion p(num,den);
	return p;
}
Fraccion operator-(Fraccion a, Fraccion b){
	
	int v1=a.VerNum()*b.VerDen();
	int v2=a.VerDen()*b.VerNum();
	int num=v1-v2;
	
	int den=a.VerDen()*b.VerDen();
	
	Fraccion p(num,den);
	return p;
}
bool operator==(Fraccion a, Fraccion b){
	
	int v1=a.VerNum()*b.VerDen();
	int v2=a.VerDen()*b.VerNum();
	
	if(v1==v2) return true;
	else return false;
}
bool operator!=(Fraccion a, Fraccion b){
	
	int v1=a.VerNum()*b.VerDen();
	int v2=a.VerDen()*b.VerNum();
	
	if(v1!=v2) return true;
	else return false;
}
ostream &operator<<(ostream &o, Fraccion a){
	o<<a.VerNum()<<" / "<<a.VerDen();
	return o;
}
int main() {
	
	Fraccion a(2,5);
	Fraccion b(5,6);
	cout<<"Fraccion 1: "<<a<<endl;
	cout<<"Fraccion 2: "<<b<<endl;
	
	Fraccion p=a+b;
	cout<<"SUMA: "<<p<<endl;
	
	p=a*b;
	cout<<"MULTIPLICACION: "<<p<<endl;
	p=a-b;
	cout<<"RESTA: "<<p<<endl;
	
	if(a==b)cout<<"Son equivalentes"<<endl;
	if(a!=b)cout<<"Son diferentes";
	
	
	
	return 0;
}

