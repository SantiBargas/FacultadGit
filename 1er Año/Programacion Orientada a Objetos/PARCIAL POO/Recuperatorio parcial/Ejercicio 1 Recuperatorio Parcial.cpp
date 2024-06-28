#include <iostream>
#include <vector>
using namespace std;

class Viaje{
protected:
	string m_origen;
	string m_destino;
	string m_transporte;
	int m_distancia;
public:
	Viaje(string origen,string destino,string transporte,int distancia):m_origen(origen),m_destino(destino),m_transporte(transporte),m_distancia(distancia){}
	string VerOrigen(){return m_origen;}
	string VerDestino(){return m_destino;}
	string VerTransporte(){return m_transporte;}
	int VerDistancia(){return m_distancia;}
	float virtual timetravel()=0;
	virtual ~ Viaje(){}
	
};

class Auto : public Viaje{
public:
	Auto(string origen,string destino,string transporte,int distancia):Viaje(origen,destino,transporte,distancia){}
	float timetravel() override{
		float t=(m_distancia/110)+5*(m_distancia%110);
		return t;
	}

};
class Colectivo : public Viaje{
public:
	Colectivo(string origen,string destino,string transporte,int distancia):Viaje(origen,destino,transporte,distancia){}
	float timetravel() override{
		float t=(m_distancia/90);
		return t;
	}
};

class Avion : public Viaje{
public:
	Avion(string origen,string destino,string transporte,int distancia):Viaje(origen,destino,transporte,distancia){}
	float timetravel() override{
		float t=(2+(m_distancia/900));
		return t;
	}
};


float TotalViaje(vector<Viaje*>lista){
	
	float total;
	
	for( size_t i=0;i<lista.size();i++){
		total+=lista[i]->timetravel();
	}
	
	return total;
}

int main() {
	
	vector<Viaje*>lista;
	
	lista.push_back(new Auto("Rosario","Parana","Auto",200));
	lista.push_back(new Avion("Parana","Buenos Aires","Avion",400));
	lista.push_back(new Colectivo("Buenos Aires","Rosario","Colectivo",320));
	
	cout<<"El tiempo total de viaje es: "<<TotalViaje(lista);
	
	for(size_t i=0;i<lista.size();i++){
		delete lista[i];
	}
	
	
	return 0;
}

