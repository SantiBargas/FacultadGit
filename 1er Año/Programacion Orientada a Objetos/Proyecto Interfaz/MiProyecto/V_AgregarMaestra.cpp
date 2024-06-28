#include "V_AgregarMaestra.h"
#include "Jardin.h"

V_AgregarMaestra::V_AgregarMaestra(wxWindow *parent, Jardin *jardin) : MyDialog6(parent), m_Jardin(jardin){
	
}

void V_AgregarMaestra::ClickSiguiente( wxCommandEvent& event )  {
	event.Skip();
}

void V_AgregarMaestra::ClickCancelar( wxCommandEvent& event )  {
	event.Skip();
}

V_AgregarMaestra::~V_AgregarMaestra() {
	
}

