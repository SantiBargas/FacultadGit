#include <iostream>
#include <cmath>
using namespace std;
class cuadratica
{ 
	private:
		int a,b,c,dis;
		float r1,r2;
		string tiporaices;

	public:
		void datos(int pa, int pb, int pc);
		void resolvente();
		float ver_r1(){return r1;};
		float ver_r2(){return r2;};
		float ver_dis(){return dis;};
		string ver_tiporaices(){return tiporaices;};
};
	
	
int main() {
	
	cuadratica c;
	int pa,pb,pc;
	cout<<"INGRESE LA FUNCION CUADRATICA"<<endl;
	cout<<"ingrese numero que acompaña x2"<<endl;
	cin>>pa;
	cout<<"ingrese numero que acompaña x"<<endl;
	cin>>pb;
	cout<<"ingrese termino independiente"<<endl;
	cin>>pc;
	
	c.datos(pa,pb,pc);
	c.resolvente();
	
	if(c.ver_dis()>=0){
		cout<<"raiz 1: "<<c.ver_r1()<<endl;
		cout<<"raiz 2: "<<c.ver_r2()<<endl;
		cout<<"tipo de raices: "<<c.ver_tiporaices()<<endl;
	}else{
		cout<<"tipo de raices: "<<c.ver_tiporaices()<<endl;
	}
	
	
	
	return 0;
}
void cuadratica::datos(int pa, int pb, int pc){
	a=pa; b=pb; c=pc;
}
void cuadratica::resolvente(){
	dis=b*b-4*a*c;
	
	if(dis<0){
		tiporaices="Raices complejas";
	}else{
		r1=(-b+sqrt(dis))/(2*a);
		r2=(-b-sqrt(dis))/(2*a);
		
		if(dis==0){
			tiporaices="Raices reales iguales";
		}else{
			tiporaices="Raices reales distintas";
		}
	}
}
