// debe tener el complemento para wxWidgets 2.8 instalado en ZinjaI para 
// compilar este ejemplo y utilizar la biblioteca

#include <wx/app.h>
#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;
#include "wxExcelManipulator.h"

class mxApplication : public wxApp {
public:
	virtual bool OnInit() {
		
		// pedirle datos al usuario
		string nombre;
		cout<<"Ingrese su nombre: ";
		getline(cin,nombre);
		int dia_nac,mes_nac,anio_nac;
		cout<<"Ingrese el dia de su nacimiento: ";
		cin>>dia_nac;
		cout<<"Ingrese el mes de su nacimiento: ";
		cin>>mes_nac;
		cout<<"Ingrese el año de su nacimiento: ";
		cin>>anio_nac;
		
		// obtener fecha actual y calcular edad
		if (anio_nac<100) anio_nac += anio_nac<50?2000:1900;
		int dia_act,mes_act,anio_act;
		time_t fecha_act = time(NULL);
		dia_act=(gmtime(&fecha_act))->tm_mday;
		mes_act=(gmtime(&fecha_act))->tm_mon+1;
		anio_act=(gmtime(&fecha_act))->tm_year+1900;
		int i_act=anio_act*10000+mes_act*100+dia_act;
		int i_nac=anio_nac*10000+mes_nac*100+dia_nac;
		int edad=(i_act-i_nac)/10000;
		cout<<endl; cin.ignore();
		
		// cargar la planilla (reemplazar false por true en el constructor 
		// de e para que no se muestre la ventana de Excel)
		cout<<"Presione enter para abrir la planilla";
		cin.get();
		wxExcelManipulator e("ejemplo.xls",true);
		if (!e.IsOpen()) { cerr<<"No se pudo abrir el archivo"<<endl; return 1; }
		
		// completar la planilla con los datos del usuario
		cout<<"Presione enter para completar los datos";
		cin.get();
		e.SetValue(4,4,nombre.c_str());
		e.SetValue(5,4,dia_nac);
		e.SetValue(5,5,mes_nac);
		e.SetValue(5,6,anio_nac);
		e.SetValue(6,4,dia_act);
		e.SetValue(6,5,mes_act);
		e.SetValue(6,6,anio_act);
		stringstream ss;
		ss<<"Usted tiene "<<edad<<" años, y contando...";
		e.SetValue(8,3,ss.str().c_str());
		
		// imprimir y cerrar
		cout<<"¿Desea imprimir (s/n)? ";
		if (cin.get()=='s') 
			e.Print();
		e.Close();
		
		cin.get();
		
		return false;
	}
};

IMPLEMENT_APP(mxApplication)
