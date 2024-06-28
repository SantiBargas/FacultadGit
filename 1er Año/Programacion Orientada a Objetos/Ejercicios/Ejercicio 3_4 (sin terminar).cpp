#include <iostream>
using namespace std;

struct Punto{
	float x,y;
};

bool muy_parecidos(float a, float b){
	
	
}
class Recta{
virtual string obtenerEcuacion()=0;
virtual bool pertenece(Punto P)=0;      //al igualar a 0 cada clase trabaja a su manera en su clase

///OBJETIVO: decir que toda recta tiene una ecuacion y un punto que pertenece
};



class RectaExplicita: public Recta{
private:
	float m, b;
public:
	RectaExplicita(Punto p, Punto q){
		m=(q.y-p.y)/(q.x-p.x);
		b=p.y-(m*p.y);
	}
	string obtenerEcuacion()override{
		return "y= " + to_string(m) + "x* + " + to_string(b);
	}
	bool pertenece(Punto p)override{
		if(p.y==m*p.x+b){
			return true;
		}else{return false;}
	}
	float verM(){return m;}
	float VerB(){return b;}
};

class RectaGeneral : public Recta{
private:
	float a,b,c;
public:
	RectaGeneral(Punto p, Punto q){
		a=q.y-p.y;
		b=p.x-q.x;
		c=(-a*p.x)-(b*p.y);
	}
	string obtenerEcuacion()override{
		return to_string(a)+ "*x  + " + to_string(b) + "y  + " + to_string(c) + "=0";
	}
	bool pertenece(){
		if(muy_parecidos==true){
			return true;
		}else{return false;}
	}
};

int main() {
	

	return 0;
}

