#include <iostream>
using namespace std;
/// Una Empresa de trasporte de pasajeros posee una boletería por cada destino
/// Diseñar una superclase empresa con un nombre y una clase boleteria, clase
/// hija de empresa que tenga una localidad de origen, una localidad destino
/// y una lista de boletos vendidos, cada boleto con 2 campos, hora, un valor
/// entero con formato hhmm y un importe.
/// La clase hija debe tener, ademas de los métodos para mostrar sus atributos, 
/// un método para cargar un boleto vendido y mostrar el total recaudado.
///
/// Haga sobrecarga de operadores para sumar importes de cajas, copiar cajas
/// con el operador = 

struct boleto{
	int hora;       /// hora de la venta formato hhmm = h*60 + m  1030   915
	float importe;  /// importe
};

class empresa{
	string nombre;
public:
	empresa(){nombre = "SIN NOMBRE";};
	empresa(string nom){nombre = nom;};
	string VerNombre(){return nombre;};
};

class boleteria:public empresa{
	string origen,destino;
	float total; /// total recaudado
	boleto *boletos;
	int cantidad;   /// cantidad de boletos vendidos
public:
	///(1)
	boleteria():empresa("SIN NOMBRE"){origen = "";destino="";total = 0;cantidad=0;boletos = nullptr;}
	/// (2)
	boleteria(string nomemp,string org,string dest):empresa(nomemp){
		origen = org;destino = dest;cantidad=0;total = 0;boletos = nullptr;
	}
	/// Métodos para setear los atributos
	void CargarOrigen(string org){origen = org;};
	void CargarDestino(string dest){destino = dest;};
	/// MÉTODOS PARA MOSTRAR ATRIBUTOS
	string VerOrigen(){return origen;};
	string VerDestino(){return destino;};
	
	/// MANEJO DE LA VENTA DE BOLETOS 
	void AgregarVentaBoleto(int hhmm,float importe){
		/// 1ro, traspaso los datos actuales de boletos a una lista auxiliar
		boleto *aux;
		boleto b;
		aux = new boleto[cantidad+1]; /// genero espacio con un lugar extra
		for (int i = 0;i<cantidad;i++){
			/// traspasar los boletos actuales a la nueva lista
			*(aux+i) = *(boletos+i);
		}
		b.hora=hhmm;b.importe=importe;
		*(aux+cantidad) = b;
		/// reasignar los punteros
		delete []boletos;
		boletos = aux;
		cantidad++;total+=importe;
	}
		/// para mostrar totales e importes
		float GetTotalCaja(){return total;};
		int GetCantBoletos(){return cantidad;};
		
};

int main() {
	boleteria b1("EL NORTE BIS","SANTA FE","HELVECIA");   
	boleteria b2("EL NORTE BIS","SANTA FE","RECONQUISTA"); /// (2)
	
	b1.AgregarVentaBoleto(930,350);
	b1.AgregarVentaBoleto(935,820);
	b1.AgregarVentaBoleto(1005,410);
	cout<<b1.GetTotalCaja()<<endl;
	
	
	b2.AgregarVentaBoleto(930,1300);
	b2.AgregarVentaBoleto(935,710);
	b2.AgregarVentaBoleto(1005,690);
	
	cout<<"La boleteria de "<<b2.VerOrigen()<<" a "<<b2.VerDestino()<<" recaudó $ "
		<<b2.GetTotalCaja()<<endl;
	
	return 0;
}
