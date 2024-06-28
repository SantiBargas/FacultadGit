#include <iostream>
using namespace std;

class Rectangulo{
private:
	float area,base,perimetro,altura;
public:
	Rectangulo(float a, float b){altura=a; area=a*b; perimetro=(b*2)+(a*2);}
	Rectangulo(float x1, float y1, float x2, float y2){
		area=(x2-x1)*(y2-y1); perimetro=(x2-x1)*2+(y2-y1)*2;
	}
	float VerArea(){return area;}
	float VerPerimetro(){return perimetro;}
	bool EsCuadrado(float a,float b){if(b==a){return true;}else{return false;}}
	bool EsCuadrado(float x1,float y1,float x2,float y2){if((x1-y1)==(x2-y2)){return true;}else{return false;}
	}
};


int main() {
	float a,b,x1,x2,y1,y2;
	cout<<"INGRESE BASE Y ALTURA DEL CUADRADO"<<endl;
	cin>>a>>b;
	
	Rectangulo R(a,b);
	if(R.EsCuadrado(a,b)==true){
		cout<<"ES CUADRADO"<<endl;
	}
	cout<<"INGRESE COORDENADAS PUNTO 1:"<<endl;
	cin>>x1>>y1;
	cout<<"INGRESE COORDENADAS PUNTO 2:"<<endl;
	cin>>x2>>y2;
	
	Rectangulo T(x1,y1,x2,y2);
	if(R.EsCuadrado(x1,y1,x2,y2)==true){
		cout<<"ES CUADRADO"<<endl;
	}else{
		cout<<"NO ES CUADRADO"<<endl;
	}
	
	return 0;
}

