#include "V_EliminarAlumno.h"
#include <wx/msgdlg.h>

V_EliminarAlumno::V_EliminarAlumno(wxWindow *parent, Jardin *jardin) : MyDialog2(parent), m_Jardin(jardin) {
	
}


V_EliminarAlumno::~V_EliminarAlumno() {
	
}

void V_EliminarAlumno::ClickAceptar( wxCommandEvent& event )  {
	long dni;
	IngresoDni->GetValue().ToLong(&dni);
	bool m = m_Jardin->EliminarAlumno(dni);
	
	if (m == true) wxMessageBox(" Se borro un Alumno" );
	if (m == false) wxMessageBox("Ese DNI no existe"); 
	EndModal(1);
}

void V_EliminarAlumno::ClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void V_EliminarAlumno::Eliminar( wxInitDialogEvent& event )  {
	event.Skip();
}

