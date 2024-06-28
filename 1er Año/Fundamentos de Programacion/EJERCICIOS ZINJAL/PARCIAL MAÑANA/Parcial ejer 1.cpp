#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	vector<int>Sumatorias(6,0);          ///I sumatoria por comision	
	vector<int>Recuentos(6,0);           /// Asistencia por comision
	vector<int>Aprobados(6,0);           /// recuento de aprobados por comision
	int codComision,codAlumno,nota;
	
	cout<<"Ingrese comision 1 a 6 en 0 termina"<<endl;
	cin>>codComision;
	
	while (codComision !=0){
		cout<<"ingrese cod alumno"<<endl;
		cin>>codAlumno;
		
		cout<<"ingrese nota"<<endl;
		cin>>nota;
		
		Sumatorias[codComision -1] += nota; 
		Recuentos[codComision -1] ++;
		
		if (nota>=60) {
			Aprobados[codComision -1] ++;
		}
		
		cout<<"Ingrese comision 1 a 6 en 0 termina"<<endl;
		cin>>codComision;
	}
	
	///Inciso A
	float promedio;
	float porcentaje;
	
	for (codComision= 0; codComision<6;codComision++) {
		if (Recuentos[codComision]>0) {
		promedio= Sumatorias[codComision] / Recuentos[codComision];
		cout<<"Promedio comision "<<codComision+1<<" "<<promedio<<endl;
		}
		
		///Incisio B
		
		cout<<"La Comision "<<codComision+1<<" tiene "<<Aprobados[codComision]<<" APROBADDOS "<<endl;
		
		///Inciso C
		porcentaje = 100/30 * Recuentos[codComision];
		cout<<"La comision" <<codComision +1<<" tiene "<<porcentaje<< " % de asistencia"<<endl;
	}
	
	

	
	return 0;
}

