#include <iostream>
#include <vector>
using namespace std;

class CoutLogger{
public:
	string registrarMensaje(string mensaje){return mensaje;}
};

class VectorLogger{
	vector<string>lista;
public:
	void MensajeAgrega(string mensaje){lista.push_back(mensaje);}
	vector<string>finalizar(vector<string>lista){
		return lista; 
	}
};



void obtenerBeneficiados(int n, LogSystem log){
	log.registrarMensaje("Cargando archivo de datos");
	vector<Alumnos>v=cargarDatos("alumnos.dat");
	log.registrarMensaje("Filtrando Suficientes");
	
	for(Alumno &a:v)
		filtrarInsuficientes(a.notas);
	log.registrarMensaje("Recalculando promedios");
	
	for(Alumno &a:v)
		a.prom=calcularPromedio(a.notas);
	
	log.registrarMensaje("Ordenando por promedio");
	ordenarVector(v,comparaPorPromedio);
	
	log.registrarMensaje("Guardando los to_string(n)+mejores");
	v.resize(n);
	guardarDatos("becarios.dat");
	log.finalizar();
}

int main() {
	int n;
	cout<<"Cantidad de becarios: "<<endl;
	cin>>n;
	
	obtenerBeneficiados(n,log);
	
	///Los cambios que hacen falta son:
	///Hacer un puntero de LogSystem ya que es polimorfismo y acceder a los metodos en vez de notacion con puntos con ->
	///No se declara la clase madre que seria LogSystem
	///No se declara en la funcion obtenerBeneficiados objetos para utilizar los metodos
	
	
	return 0;
}

