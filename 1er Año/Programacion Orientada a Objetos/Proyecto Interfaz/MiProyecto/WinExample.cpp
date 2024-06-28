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
#include "V_AgregarAlumno.h"
#include "V_AgregarMaestra.h"
using namespace std;

WinExample::WinExample(Jardin *jardin) : wxfbExample(nullptr), m_Jardin(jardin){
	
	m_Jardin->Inicializar(); 
	
	vector<Maestra>V=m_Jardin->LeerDelArchivoMaestras();
	vector<Alumno>VA=m_Jardin->LeerDelArchivoAlumnos();
	int pos = 0; 
	
	
	for(int i=0;i<V.size();i++){
		if(V[i].VerSala()=="Sala 1" and V[i].VerTipo()=="Maestra"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,V[i].VerSala());
			GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
			GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(V[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,"------------------");
			GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"----------------");
			pos++;
		}
	}
	for(int i=0;i<V.size();i++){
		if(V[i].VerSala()=="Sala 1" and V[i].VerTipo()=="Auxiliar"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,V[i].VerSala());
			GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
			GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(V[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,"------------------");
			GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"----------------");
			pos++;
		}
	}

	for(int i=0;i<VA.size();i++){
		if(VA[i].VerSala()=="Sala 1"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,VA[i].VerSala());
			GrillaSala->SetCellValue(pos,1,VA[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,"Alumno");
			GrillaSala->SetCellValue(pos,3,(to_string(VA[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(VA[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,VA[i].VerNombreTutor());
			GrillaSala->SetCellValue(pos,6,VA[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,VA[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(VA[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"Ver ficha medica");
			pos++;
		}
	}
	
	GrillaSala->AppendRows();pos++;
	
	for(int i=0;i<V.size();i++){
		if(V[i].VerSala()=="Sala 2" and V[i].VerTipo()=="Maestra"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,V[i].VerSala());
			GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
			GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(V[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,"------------------");
			GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"----------------");
			pos++;
		}
	}
	
	for(int i=0;i<V.size();i++){
		if(V[i].VerSala()=="Sala 2" and V[i].VerTipo()=="Auxiliar"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,V[i].VerSala());
			GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
			GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(V[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,"------------------");
			GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"----------------");
			pos++;
		}
	}
	
	for(int i=0;i<VA.size();i++){
		if(VA[i].VerSala()=="Sala 2"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,VA[i].VerSala());
			GrillaSala->SetCellValue(pos,1,VA[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,"Alumno");
			GrillaSala->SetCellValue(pos,3,(to_string(VA[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(VA[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,VA[i].VerNombreTutor());
			GrillaSala->SetCellValue(pos,6,VA[i].VerDireccion());	
			GrillaSala->SetCellValue(pos,7,VA[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(VA[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"Ver ficha medica");
			pos++;
		}
	}
	
	GrillaSala->AppendRows();pos++;
	
	for(int i=0;i<V.size();i++){
		if(V[i].VerSala()=="Sala 3" and V[i].VerTipo()=="Maestra"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,V[i].VerSala());
			GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
			GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(V[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,"------------------");
			GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"----------------");
			pos++;
		}
	}
	
	for(int i=0;i<V.size();i++){
		if(V[i].VerSala()=="Sala 3" and V[i].VerTipo()=="Auxiliar"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,V[i].VerSala());
			GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
			GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(V[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,"------------------");
			GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"------------------");
			pos++;
		}
	}
	
	for(int i=0;i<VA.size();i++){
		if(VA[i].VerSala()=="Sala 3"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,VA[i].VerSala());
			GrillaSala->SetCellValue(pos,1,VA[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,"Alumno");
			GrillaSala->SetCellValue(pos,3,(to_string(VA[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(VA[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,VA[i].VerNombreTutor());
			GrillaSala->SetCellValue(pos,6,VA[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,VA[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(VA[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"Ver ficha medica");
			pos++;
		}
	}
	
	GrillaSala->AppendRows();pos++;
	
	for(int i=0;i<V.size();i++){
		if(V[i].VerSala()=="Sala 4" and V[i].VerTipo()=="Maestra"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,V[i].VerSala());
			GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
			GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(V[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,"------------------");
			GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"----------------");
			pos++;
		}
	}
	
	for(int i=0;i<V.size();i++){
		if(V[i].VerSala()=="Sala 4" and V[i].VerTipo()=="Auxiliar"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,V[i].VerSala());
			GrillaSala->SetCellValue(pos,1,V[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,V[i].VerTipo());
			GrillaSala->SetCellValue(pos,3,(to_string(V[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(V[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,"------------------");
			GrillaSala->SetCellValue(pos,6,V[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,V[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(V[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"----------------");
			pos++;
		}
	}
	
	for(int i=0;i<VA.size();i++){
		if(VA[i].VerSala()=="Sala 4"){
			GrillaSala->AppendRows();
			GrillaSala->SetCellValue(pos,0,VA[i].VerSala());
			GrillaSala->SetCellValue(pos,1,VA[i].VerNombre());
			GrillaSala->SetCellValue(pos,2,"Alumno");
			GrillaSala->SetCellValue(pos,3,(to_string(VA[i].VerDni())));
			GrillaSala->SetCellValue(pos,4,(to_string(VA[i].VerEdad())));
			GrillaSala->SetCellValue(pos,5,VA[i].VerNombreTutor());
			GrillaSala->SetCellValue(pos,6,VA[i].VerDireccion());
			GrillaSala->SetCellValue(pos,7,VA[i].VerFechaNac());
			GrillaSala->SetCellValue(pos,8,(to_string(VA[i].VerTel())));
			GrillaSala->SetCellValue(pos,9,"Ver ficha medica");
			pos++;
		}
	}
	
}


void WinExample::ClickBotonAgregarMaestra( wxCommandEvent& event )  {
	V_AgregarMaestra * win = new V_AgregarMaestra(this, m_Jardin);
	if (win->ShowModal()==1){
		///RefrescarGrilla
	}
	
}

void WinExample::ClickBotonAgregarAlumno( wxCommandEvent& event )  {
	V_AgregarAlumno * win = new V_AgregarAlumno(this, m_Jardin);
	if (win->ShowModal()==1){
		///RefrescarGrilla
	}
}

void WinExample::EliminarMaestra( wxCommandEvent& event )  {
	V_EliminarMaestra * win = new V_EliminarMaestra(this, m_Jardin);
	if (win->ShowModal()==1){
		///RefrescarGrilla
	}
}

void WinExample::EliminarAlumno( wxCommandEvent& event )  {
	V_EliminarAlumno* win = new V_EliminarAlumno(this, m_Jardin);
	if (win->ShowModal()==1){
		///RefrescarGrilla
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

