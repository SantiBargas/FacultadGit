#include <iostream>
#include <cstdlib>
using namespace std;

struct Punto{
	float x,y;
};

bool son_muy_muy_parecidos(float a, float b){
	return abs(a-b)<1e-5; //comparo si los puntos son casi igual a 0
}

class Recta{
public:
	virtual string ObtenerEcuacion()=0;
	virtual bool Pertenece(Punto p)=0;  ///Objetivo: decir que toda recta tiene una ecuacion y un punto que pertenece
	//al igualar a 0 cada clase trabaja a su manera en su clase
};

// y = m*x + b	
class RectaExplicita : public Recta{
private:
	float m, b;
public:
	RectaExplicita(Punto p, Punto q){
		
		m=(p.y-q.y)/(p.x-q.x);
		b= p.y - m*p.x;
	}
	float VerM(){return m;}
	float VerB(){return b;}
	string ObtenerEcuacion()override{
		return "y= " + to_string(m) + "x* + " + to_string(b);
		//to_string transforma el valor en string
	}
	bool Pertenece(Punto p)override{
		if( p.y ==m*p.x+b) return true;
		else 				return false;
	}
};

// a*x + b*y + c = 0
class RectaGeneral : public Recta{
private:
	float a, b, c;
public:
	RectaGeneral(Punto p, Punto q){
		a= q.y-p.y;
		b= p.x -q.x;
		c= -a*p.x - b*p.y;
	}
	float VerA(){return a;}
	float VerB(){return b;}
	float VerC(){return c;}
	string ObtenerEcuacion()override{
		return " "+to_string(a) + "*x + " + to_string(b)+ " *y + " + to_string(c);
		//to_string transforma el valor en string
	}
	bool Pertenece(Punto p)override{
		return son_muy_muy_parecidos(a*p.x+b*p.y,0);
	}
};

void HacerAlgoConLaRecta(Recta &r){
	cout<<" La ecuacion es: "<<r.ObtenerEcuacion()<<endl;
	Punto a;
	cout<<"ingrese los valores del punto a evaluar si pertenece"<<endl;
	cin>>a.x>>a.y;
	if(r.Pertenece(a)) cout<<"Pertenece";
	else "No pertenece";
}

int main() {
	
	
	Punto p = {1,2}, q={3,4}; ///Asigno los puntos al struct con x e y
	cout<<"tipo 1 = explicita, 2=general, ingrese: "<<endl;
	int tipo;
	cin>>tipo;
	
	
	if(tipo==1){
		RectaExplicita r2(p,q);
		HacerAlgoConLaRecta(r2);
	}else{
		RectaGeneral r1(p,q);
		HacerAlgoConLaRecta(r1);
	}
	
	
	
	
	
	return 0;
}

