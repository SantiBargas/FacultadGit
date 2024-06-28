#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Monomio{
	int n;
	float coe;
public:
	Monomio(int gr, float co):n(gr),coe(co){}
	void Asignar(int gr,float co){n= gr;coe=co;}
	int VerGrado(){return n;}
	float VerCoe(){return coe;}
	float Evaluar(int x){return coe*pow(x,n);}
};

class Polinomio{
	vector<Monomio>v;
public:
	 Polinomio(){}
	 Polinomio(int x){
		 for(int i=0;i<=x;i++) { 
			 v.push_back(Monomio(i,0));
		 }
	 }
	 void ModificarMonomio(int gr,int co){v[gr].Asignar(gr,co);} 	 
	 float Evaluar(float x){
		 float vp= 0;
		 for(unsigned int i=0;i< v.size(); i++)
			 vp += v[i].Evaluar(x);
		 return vp;
	 } 
	 float VerCoef(int x){return v[x].VerCoe(); }     
	 int VerGrado(){return v.size()-1;}
};


int main(int argc, char *argv[]) {
 	Polinomio poli(5);
	
	//muestro el polinomio vacio
	cout<<"\nPolinomio creado: ";
	for (int k=poli.VerGrado();k>=0; k--){
		if(k!=poli.VerGrado())
			cout<<" + "<<poli.VerCoef(k)<<"x^"<<k;
		else
			cout<<poli.VerCoef(k)<<"x^"<<k;
	}
	cout<<endl;
	poli.ModificarMonomio(0,3);
	poli.ModificarMonomio(1,4);
	poli.ModificarMonomio(2,5);
	poli.ModificarMonomio(5,1);
	
	//muestro el polinomio con algunos valores cargados
	cout<<"\nPolinomio: ";
	for (int k=poli.VerGrado();k>=0; k--){
		if(k!=poli.VerGrado())
			cout<<" + "<<poli.VerCoef(k)<<"x^"<<k;
		else
			cout<<poli.VerCoef(k)<<"x^"<<k;
	}
	cout<<endl;
	
	cout<<endl<<poli.Evaluar(3);
	
	
	return 0;
}

