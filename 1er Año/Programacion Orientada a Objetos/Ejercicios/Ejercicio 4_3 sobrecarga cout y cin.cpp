#include <iostream>
using namespace std;


class Racional {
	int num, den;
public:
	Racional(int n=0,int d=1):num(n),den(d){}
	int VerNum(){return num;}
	int VerDen(){return den;}
	void CargarNum(int n){num=n;}
	void CargarDen(int d){den=d;}
	//friend istream& operator>>(istream &i, Racional &r);
};

ostream& operator<<(ostream &o, Racional r){ //flujo de salida output por eso ostream;
	o<<r.VerNum()<<" / "<<r.VerDen();
	return o;
}

istream& operator>>(istream &i,Racional &r){ //flujo de entrada input por eso istream
	int n,d;
	cin>>n>>d;
	r.CargarNum(n);
	r.CargarDen(d);  
	/*otra opcion es haciendo un friend en la clase
	r.num= n;
	r.den= d;
	*/
	return i;
}

int main() {
	Racional r;
	cin>> r;
	
	cout<< r << endl; // operator<<(cout,r)
	
	return 0;
}
	
