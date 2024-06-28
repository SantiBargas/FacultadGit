#include <wx/msgdlg.h>
#include "V_EliminarMaestra.h"
#include "Jardin.h"

V_EliminarMaestra::V_EliminarMaestra(wxWindow *parent, Jardin *jardin) : MyDialog1(parent), m_Jardin(jardin) {
	
}

V_EliminarMaestra::~V_EliminarMaestra() {
	
}

void V_EliminarMaestra::ClickAceptar( wxCommandEvent& event )  {
	
	long dni;
	IngresoDni->GetValue().ToLong(&dni);
	bool m = m_Jardin->EliminarMaestra(dni);
	
	if (m == true) wxMessageBox(" Se borro una Maestra" );
	if (m == false) wxMessageBox("Ese DNI no existe"); 
	EndModal(1);
}

void V_EliminarMaestra::ClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void V_EliminarMaestra::Eliminar( wxInitDialogEvent& event )  {
	event.Skip();
}

