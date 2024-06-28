#include <iostream>
#include <vector>
using namespace std;
struct Naipes{
	string palo;
	string valor;
};
class JuegoNaipes{
protected:
	vector<Naipes> v;
public:
	void virtual generar()=0;
	Naipes & operator [] (int x){
		string a=v[x].palo;
		string b=v[x].valor;
		Naipes n{a,b};
		return n;
	}
	void virtual Mostrar()=0;
};

class Truco : public JuegoNaipes{
public:
	void generar()override{
		for(int i=1;i<13;i++){
			if(i!=8 or i!=9){
				Naipes x;
				x.valor=i;
				x.palo=="BASTO";
				v.push_back(x);
			}
		}
		for(int i=1;i<13;i++){
			if(i!=8 or i!=9){
				Naipes x;
				x.valor=i;
				x.palo=="ESPADA";
				v.push_back(x);
			}
			
		}
		for(int i=1;i<13;i++){
			if(i!=8 or i!=9){
				Naipes x;
				x.valor=i;
				x.palo=="ORO";
				v.push_back(x);
			}
			
		}
		for(int i=1;i<13;i++){
			if(i!=8 or i!=9){
				Naipes x;
				x.valor=i;
				x.palo=="COPA";
				v.push_back(x);
			}
			
		}
		
	}	
	void Mostrar()override{
		for(size_t  i=0;i<v.size();i++) { 
			cout<<"Valor: "<< v[i].valor<<"Palo  "<<v[i].palo<<endl;
		}
	}
};

class BlackJack : public JuegoNaipes{
public:
	void generar() override{
		for(int i=1;i<14;i++) {
			Naipes x;
			x.palo="TREBOL";
			if(i!=11 or i!=12 or i!=13 or i!=1)x.valor=i;
			if(i==11)x.valor="J";
			if(i==12)x.valor="Q";
			if(i==13)x.valor="K";
			if(i==1)x.valor="A";
		}
		for(int i=1;i<14;i++) {
			Naipes x;
			x.palo="CORAZON";
			if(i!=11 or i!=12 or i!=13 or i!=1)x.valor=i;
			if(i==11)x.valor="J";
			if(i==12)x.valor="Q";
			if(i==13)x.valor="K";
			if(i==1)x.valor="A";
		}
		for(int i=1;i<14;i++) {
			Naipes x;
			x.palo="DIAMANTE";
			if(i!=11 or i!=12 or i!=13 or i!=1)x.valor=i;
			if(i==11)x.valor="J";
			if(i==12)x.valor="Q";
			if(i==13)x.valor="K";
			if(i==1)x.valor="A";
		}
		for(int i=1;i<14;i++) {
			Naipes x;
			x.palo="PICA";
			if(i!=11 or i!=12 or i!=13 or i!=1)	x.valor=i;
			if(i==11)x.valor="J";
			if(i==12)x.valor="Q";
			if(i==13)x.valor="K";
			if(i==1)x.valor="A";
		}
	}
	void Mostrar()override{
		for(size_t  i=0;i<v.size();i++) { 
			cout<<"Valor: "<< v[i].valor<<"Palo  "<<v[i].palo<<endl;
		}
	}
};

void GenerarYMostrar(JuegoNaipes *x){
	x=new Truco;
	x->generar();
	x->Mostrar();
}

int main() {
	
	JuegoNaipes *x;
	GenerarYMostrar(x);
	delete []x;
	
	
	
	
	return 0;
}

