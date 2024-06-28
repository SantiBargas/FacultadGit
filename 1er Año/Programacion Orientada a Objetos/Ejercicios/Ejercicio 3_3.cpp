#include <iostream>
using namespace std;

struct Punto{
	float x,y;
};

class RectaExplicita{
private:
	float m, b;
public:
	RectaExplicita(Punto p, Punto q){
		m=(q.y-p.y)/(q.x-p.x);
		b=p.y-(m*p.y);
	}
	string obtenerEcuacion(){
		return "y= " + to_string(m) + "x* + " + to_string(b);
	}
	float verM(){return m;}
	float VerB(){return b;}
};

int main() {
	
	Punto p,q;
	cout<<"ingrese punto P"<<endl;
	cin>>p.x>>p.y;
	cout<<"ingrese punto Q"<<endl;
	cin>>q.x>>q.y;
	
	
	RectaExplicita r(p,q);///le paso los puntos p y q a la clase recta explicita
	
	cout<<"m= "<<r.verM()<<endl<<"b= "<<r.VerB()<<endl<<endl;
	cout<<"LA ECUACION ES: "<<r.obtenerEcuacion();
	return 0;
}

