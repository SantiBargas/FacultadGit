#include <iostream>
using namespace std;

class fecha{
private:
	int m_dia,m_mes,m_anio;
public:
	fecha(int dia, int mes, int anio){m_dia=dia; m_mes=mes; m_anio=anio;}
	int VerDia(){return m_dia;}
	int VerMes(){return m_mes;}
	int VerAnio(){return m_anio;}
	
	
};
Diferencia(int anio1,int anio2){	
	if(anio1>anio2){return anio1-anio2;}else{return anio2-anio1;}
}

int main() {
	int dia,mes,anio;
	
	cout<<"INGRESE DIA MES Y AÑO FECHA 1"<<endl;
	cin>>dia>>mes>>anio;
	fecha f1(dia,mes,anio);
	cout<<"INGRESE DIA MES Y AÑO FECHA 2"<<endl;
	cin>>dia>>mes>>anio;
	fecha f2(dia,mes,anio);
	
	int anio1=f1.VerAnio();
	int anio2=f2.VerAnio();
	
	cout<<"LA DIFERENCIA DE AÑOS ES: "<<Diferencia(anio1,anio2);
	
	return 0;
}

