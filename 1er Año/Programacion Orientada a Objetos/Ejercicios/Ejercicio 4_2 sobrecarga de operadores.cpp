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

bool operator==(Racional a,Racional b){
	return (a.VerNum()*b.VerDen() == b.VerNum()*a.VerDen());
}
	
bool operator!=(Racional a,Racional b){
	return not (a == b); //uso la sobrecarga del igual y si es distinto lo retorno
}
bool operator < (Racional a,Racional b){
	return (a.VerNum()*b.VerDen() < b.VerNum()*a.VerDen());
}
bool operator <= (Racional a,Racional b){
	return (a<b) or (a==b);
}
bool operator >= (Racional a,Racional b){
	return not (a<b);
}
bool operator > (Racional a,Racional b){
	return not (a<=b);
}

int main() {
	Racional r(1,2), p(5,4);
	cout<<"R: " <<r.VerNum() << "/" << r.VerDen()<<endl;
	cout<<"P: "<< p.VerNum() << "/" << p.VerDen()<<endl;
	
	Racional s=r*p;
	Racional b=r+p;
	cout<<"R*P: "<<s.VerNum()<< "/ "<<s.VerDen()<<endl;
	cout<<"R+P: "<<b.VerNum()<< "/ "<<b.VerDen()<<endl;
	
	if(r==p)cout<<"r es igual a p"<<endl;
	if(r<p)cout<<"r es menor a p"<<endl;
	if(r>p)cout<<"r es mayor a p"<<endl;
	if(r!=p)cout<<"r es distinto a p"<<endl;
	
	
	
	return 0;
}
