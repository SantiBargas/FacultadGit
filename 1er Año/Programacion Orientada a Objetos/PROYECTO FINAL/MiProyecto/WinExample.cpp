#include "WinExample.h"
#include <wx/msgdlg.h>
#include "wxfb_project.h"
#include "Maestra.h"
#include "Jardin.h"
#include <vector>
#include <cstdlib>
#include "V_EliminarAlumno.h"
#include "V_EliminarMaestra.h"
#include "V_FichaMEdica.h"
#include "V_AgregarMaestra.h"
#include "V_AgregarAlumno.h"
#include "string_conv.h"
#include <algorithm>
#include "V_ModificarAlumno.h"
#include "V_ModificarMaestra.h"
#include <wx/object.h>
#include <wx/datetime.h>
using namespace std;

int CalcularEdad( wxDateTime fecha, Alumno x){
	
	int dia=fecha.GetDay();
	int mes=(fecha.GetMonth()+1)*100;
	int anio=fecha.GetYear()*10000;
	
	int fecha1=anio+mes+dia;
	
	string edad=x.VerFechaNac();
	int a=edad.find("/");
	int b=edad.find("/" ,a+1);
	int c = edad.size();
	
	int e=(b-a)-1;
	int d=(c-b)-1;
	
	string s1=edad.substr(0,a);
	string s2=edad.substr(a+1,e);
	string s3=edad.substr(b+1,d);
	
	int dia2=stoi(s1);
	int mes2=stoi(s2);
	int anio2=stoi(s3);
	
	mes2=mes2*100;
	anio2=anio2*10000;
	int fecha2=anio2+mes2+dia2;
	
	int total=fecha1-fecha2;
	return total/10000;
	
	return 0;
	
	
}
int CalcularEdad( wxDateTime fecha, Maestra x){
	
	int dia=fecha.GetDay();
	int mes=(fecha.GetMonth()+1)*100;
	int anio=fecha.GetYear()*10000;
	
	int fecha1=anio+mes+dia;
	
	string edad=x.VerFechaNac();
	int a=edad.find("/");
	int b=edad.find("/" ,a+1);
	int c = edad.size();
	
	int e=(b-a)-1;
	int d=(c-b)-1;
	
	string s1=edad.substr(0,a);
	string s2=edad.substr(a+1,e);
	string s3=edad.substr(b+1,d);
	
	int dia2=stoi(s1);
	int mes2=stoi(s2);
	int anio2=stoi(s3);
	
	mes2=mes2*100;
	anio2=anio2*10000;
	int fecha2=anio2+mes2+dia2;
	
	int total=(fecha1-fecha2)/10000;
	return total;
	
	return 0;
	
}

WinExample::WinExample(Jardin *jardin) : wxfbExample(nullptr), m_Jardin(jardin){
	
//	m_Jardin->Inicializar();

	vector<Maestra>V=m_Jardin->LeerDelArchivoMaestras();
	vector<Alumno>VA=m_Jardin->LeerDelArchivoAlumnos();
	
	RefrescarGrilla();
}

void WinExample::RefrescarGrilla(){
	
	GrillaSala->DeleteRows(0,GrillaSala->GetNumberRows());
	
	vector<Maestra>V=m_Jardin->LeerDelArchivoMaestras();
	vector<Alumno>VA=m_Jardin->LeerDelArchivoAlumnos();
	int pos = 0; 
	
	string sal = "Sala ";
	
	wxDateTime fecha = m_CuadroFecha->GetValue();
	
	for(int j=1;j<9;j++) {  
		sal = "Sala " + to_string(j);
		for(int i=0;i<V.size();i++){
			if(V[i].VerSala()== sal and V[i].VerTipo()=="Maestra"){
				GrillaSala->AppendRows();
				GrillaSala->SetCellValue(pos,0,V[i].VerSala());
				GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
				GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
				GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
				GrillaSala->SetCellValue(pos,4,(to_string(CalcularEdad(fecha,V[i]))));
				GrillaSala->SetCellValue(pos,5,"------------------");
				GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
				GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
				GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
				GrillaSala->SetCellValue(pos,9,"----------------");
				pos++;
			}
		}
		for(int i=0;i<V.size();i++){
			if(V[i].VerSala()== sal and V[i].VerTipo()=="Auxiliar"){
				GrillaSala->AppendRows();
				GrillaSala->SetCellValue(pos,0,V[i].VerSala());
				GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
				GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
				GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
				GrillaSala->SetCellValue(pos,4,(to_string(CalcularEdad(fecha,V[i]))));
				GrillaSala->SetCellValue(pos,5,"------------------");
				GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
				GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
				GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
				GrillaSala->SetCellValue(pos,9,"----------------");
				pos++;
			}
		}
		
		for(int i=0;i<VA.size();i++){
			if(VA[i].VerSala()== sal ){
				GrillaSala->AppendRows();
				GrillaSala->SetCellValue(pos,0,VA[i].VerSala());
				GrillaSala->SetCellValue(pos,1,VA[i].VerNombre());
				GrillaSala->SetCellValue(pos,2,"Alumno");
				GrillaSala->SetCellValue(pos,3,(to_string(VA[i].VerDni())));
				GrillaSala->SetCellValue(pos,4,(to_string(CalcularEdad(fecha,VA[i]))));
				GrillaSala->SetCellValue(pos,5,VA[i].VerNombreTutor());
				GrillaSala->SetCellValue(pos,6,VA[i].VerDireccion());
				GrillaSala->SetCellValue(pos,7,VA[i].VerFechaNac());
				GrillaSala->SetCellValue(pos,8,(to_string(VA[i].VerTel())));
				GrillaSala->SetCellValue(pos,9,"Ver ficha medica");
				pos++;
			}
		}
		GrillaSala->AppendRows();pos++;
	}
}

void WinExample::ClickBotonAgregarMaestra( wxCommandEvent& event )  {
	V_AgregarMaestra * win = new V_AgregarMaestra(this, m_Jardin);
	if (win->ShowModal()==1){
		RefrescarGrilla();
	}
	
}

void WinExample::ClickBotonAgregarAlumno( wxCommandEvent& event )  {
	V_AgregarAlumno * win = new V_AgregarAlumno(this, m_Jardin);
	if (win->ShowModal()==1){
		RefrescarGrilla();
	}
}

void WinExample::EliminarMaestra( wxCommandEvent& event )  {
	V_EliminarMaestra * win = new V_EliminarMaestra(this, m_Jardin);
	if (win->ShowModal()==1){
		RefrescarGrilla();
	}
}

void WinExample::EliminarAlumno( wxCommandEvent& event )  {
	V_EliminarAlumno* win = new V_EliminarAlumno(this, m_Jardin);
	if (win->ShowModal()==1){
		RefrescarGrilla();
	}
}

bool operator== (Alumno c1, int dni){
	return c1.VerDni()==dni;
}

void WinExample::Ficha( wxGridEvent& event )  {

	int fila = GrillaSala->GetGridCursorRow();
	long dni ;
	GrillaSala->GetCellValue(fila,3).ToLong(&dni);
	
	vector<Alumno>V = m_Jardin->LeerDelArchivoAlumnos();
	
	auto it=find(V.begin(),V.end(),dni);
	
	if (it==V.end()) wxMessageBox("No hay ficha medica");
	else{
		V_FichaMEdica *win = new V_FichaMEdica(this, m_Jardin, dni,V);
		win->ShowModal();
	}
	
}

void WinExample::ClickBuscar( wxCommandEvent& event )  {
	string buscar=wx_to_std(m_Buscar->GetValue());
	
	GrillaSala->DeleteRows(0,GrillaSala->GetNumberRows());
	
	vector<Maestra>V=m_Jardin->LeerDelArchivoMaestras();
	vector<Alumno>VA=m_Jardin->LeerDelArchivoAlumnos();
	int pos = 0; 
	wxDateTime fecha = m_CuadroFecha->GetValue();
	for(int i=0;i<V.size();i++){
		string nombre = V[i].VerNombre();
		int j=nombre.find(buscar);
		if(j!=-1){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,V[i].VerSala());
			GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
			GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(CalcularEdad(fecha,V[i]))));
			GrillaSala->SetCellValue(pos,5,"------------------");
			GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"----------------");
			pos++;
		}
	}
	
	for(int i=0;i<VA.size();i++){
		string nombre = VA[i].VerNombre();
		int j=nombre.find(buscar);
		if(j!=-1){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,VA[i].VerSala());
			GrillaSala->SetCellValue(pos,1,VA[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,"Alumno");
			GrillaSala->SetCellValue(pos,3,(to_string(VA[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(CalcularEdad(fecha,VA[i]))));
			GrillaSala->SetCellValue(pos,5,VA[i].VerNombreTutor());
			GrillaSala->SetCellValue(pos,6,VA[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,VA[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(VA[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"Ver ficha medica");
			pos++;
		}
	}
}

void WinExample::ClickFiltrar( wxCommandEvent& event )  {
	string filtrar=wx_to_std(m_Filtrar->GetValue());
	
	GrillaSala->DeleteRows(0,GrillaSala->GetNumberRows());
	
	vector<Maestra>V=m_Jardin->LeerDelArchivoMaestras();
	vector<Alumno>VA=m_Jardin->LeerDelArchivoAlumnos();
	wxDateTime fecha = m_CuadroFecha->GetValue();
	int pos = 0;
	string sal = "Sala ";
	
	if(filtrar=="Alumno"){
		for(int j=1;j<9;j++) {  
			sal = "Sala " + to_string(j);
			for(int i=0;i<VA.size();i++){
				if(VA[i].VerSala()==sal){
					GrillaSala->AppendRows();
					GrillaSala->SetCellValue(pos,0,VA[i].VerSala());
					GrillaSala->SetCellValue(pos,1,VA[i].VerNombre());
					GrillaSala->SetCellValue(pos,2,"Alumno");
					GrillaSala->SetCellValue(pos,3,(to_string(VA[i].VerDni())));
					GrillaSala->SetCellValue(pos,4,(to_string(CalcularEdad(fecha,VA[i]))));
					GrillaSala->SetCellValue(pos,5,VA[i].VerNombreTutor());
					GrillaSala->SetCellValue(pos,6,VA[i].VerDireccion());
					GrillaSala->SetCellValue(pos,7,VA[i].VerFechaNac());
					GrillaSala->SetCellValue(pos,8,(to_string(VA[i].VerTel())));
					GrillaSala->SetCellValue(pos,9,"Ver ficha medica");
					pos++;
				}
			}
			GrillaSala->AppendRows();pos++;
		}
	}
	
	if(filtrar=="Maestra"){
		for(int j=1;j<9;j++) {  
			sal = "Sala " + to_string(j);	
			for(int i=0;i<V.size();i++){
				if(V[i].VerSala()== sal and V[i].VerTipo()=="Maestra"){
					GrillaSala->AppendRows();
					GrillaSala->SetCellValue(pos,0,V[i].VerSala());
					GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
					GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
					GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
					GrillaSala->SetCellValue(pos,4,(to_string(CalcularEdad(fecha,V[i]))));
					GrillaSala->SetCellValue(pos,5,"------------------");
					GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
					GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
					GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
					GrillaSala->SetCellValue(pos,9,"----------------");
					pos++;
				}
			}
			GrillaSala->AppendRows();pos++;
		}
	}
	
	if(filtrar=="Auxiliar"){
		for(int j=1;j<9;j++) {  
			sal = "Sala " + to_string(j);
			for(int i=0;i<V.size();i++){
				if(V[i].VerSala()== sal and V[i].VerTipo()=="Auxiliar"){
					GrillaSala->AppendRows();
					GrillaSala->SetCellValue(pos,0,V[i].VerSala());
					GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
					GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
					GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
					GrillaSala->SetCellValue(pos,4,(to_string(CalcularEdad(fecha,V[i]))));
					GrillaSala->SetCellValue(pos,5,"------------------");
					GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
					GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
					GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
					GrillaSala->SetCellValue(pos,9,"----------------");
					pos++;
				}
			}
			GrillaSala->AppendRows();pos++;
		}
	}
	
	if(filtrar=="Todo"){
		RefrescarGrilla();	
	}
	
}

void WinExample::Modificar( wxGridEvent& event )  {
	
	int fila = GrillaSala->GetGridCursorRow();
	long dni ;
	GrillaSala->GetCellValue(fila,3).ToLong(&dni);
	string tipo = wx_to_std(GrillaSala->GetCellValue(fila,2));
	wxDateTime fecha = m_CuadroFecha->GetValue();
	
	if(tipo=="Alumno"){
		vector<Alumno>V = m_Jardin->LeerDelArchivoAlumnos();
		V_ModificarAlumno *win = new V_ModificarAlumno(this, m_Jardin, dni,V,fecha);
		win->ShowModal();
	}
	if(tipo=="Maestra" or tipo=="Auxiliar" ){
		vector<Maestra>V = m_Jardin->LeerDelArchivoMaestras();
		V_ModificarMaestra *win = new V_ModificarMaestra(this, m_Jardin, dni,V);
		win->ShowModal();
	}
	RefrescarGrilla();
}
