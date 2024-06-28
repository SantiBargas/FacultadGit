#include <iostream>
#include <vector>
using namespace std;

class Tecla{
private:
	string m_nota;
	bool m_presionada;
public:
	Tecla(string nota):m_nota(nota),m_presionada(false){};
	
	void Apretar(){m_presionada=true;}
	void Soltar(){m_presionada=false;}
	string VerNota(){return m_nota;}
	bool EstaApretada(){return m_presionada;}
};

class Pedal{
private:
	float m_presion;
public:
	Pedal():m_presion(0){};
	void CargarPresion(float presion){
		presion=m_presion;
	}
	float VerPresion(){return m_presion;}
};

class Instrumento{
	virtual string VerTipo(){return "sin_nombre";}
};

class Piano:public Instrumento{
private:
	vector<Tecla> t;
	Pedal pe;
public:
	Piano();
	string ApretarTecla(int tecla){
		t[tecla].Apretar();
		return t[tecla].VerNota();
	}
	void SoltarTecla(int tecla){
		t[tecla].Soltar();
	}
	void ApretarPedal(float presion){
		pe.CargarPresion(presion);
	}
	float VerEstadoPedal(){
		return pe.VerPresion();
	}
	string VerTipo(){return "Piano";}
	
	bool VerEstadoTecla(int tecla){
		return t[tecla].EstaApretada();
	}

	
};

Piano::Piano(){
	t.push_back(Tecla("do"));
	t.push_back(Tecla("re"));
	t.push_back(Tecla("mi"));
	t.push_back(Tecla("fa"));
	t.push_back(Tecla("so"));
	t.push_back(Tecla("la"));
	t.push_back(Tecla("si"));
}

int main() {
	
	Piano piano;
	int tecla;
	cout<<"tipo de instrumento: "<<piano.VerTipo()<<endl;
	
	cout<<"Estado original de las teclas y el pedal: "<<endl;
	for(int i=0;i<7;i++){
		cout<<piano.VerEstadoTecla(i)<<"   ";
	}
	cout<<"Pedal: "<<piano.VerEstadoPedal();
	
	return 0;
}

