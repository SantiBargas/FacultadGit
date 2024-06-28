#include <iostream>
using namespace std;


class Racional {
	int num, den;
public:
	Racional(int n,int d):num(n),den(d){}
	int VerNum(){return num;}
	int VerDen(){return den;}
	
//si se devuelve el this es mejor trabajar por referencia	
	Racional &operator++(){ //pre incremento
		num+=den;			//no se le pasa nada por parametro pq ya trabaja con el this
		return *this;
	}
	Racional &operator++(int x){  //post incremento, se pone el int para diferenciar las operaciones
		Racional v=*this;        //primero guardo el racional 
		num+=den;				//despues lo incremento
		return v;				//devuelvo el valor principal
	}
};

Racional operator+(Racional a, Racional b){ ///funcion q devuelve un racional y le paso dos racionales
	
	int n=(a.VerNum()*b.VerDen()+b.VerNum()*a.VerDen());
	int d=(a.VerDen()*b.VerDen());
		
	Racional p(n,d);
	return p;
}

Racional operator*(Racional a, Racional b){
	
	int n=(a.VerNum()*b.VerNum());
	int d=(a.VerDen()*b.VerDen());
	Racional p(n,d);
	return p;
	
}
int main() {
	Racional r(1,2), p(2,4);
	cout<< r.VerNum() << "/" << r.VerDen()<<endl;
	
	Racional s=r*p;
	cout<<s.VerNum()<< "/ "<<r.VerDen();
	return 0;
}

