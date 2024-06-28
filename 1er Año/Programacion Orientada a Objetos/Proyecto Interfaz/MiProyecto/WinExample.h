#ifndef WIN_EXAMPLE_H
#define WIN_EXAMPLE_H
#include "wxfb_project.h"
#include <wx/button.h>
#include "Jardin.h"

class WinExample : public wxfbExample {
protected:
	void Ficha( wxGridEvent& event )  override;
	void EliminarMaestra( wxCommandEvent& event )  override;
	void EliminarAlumno( wxCommandEvent& event )  override;
	void ClickBotonAgregarMaestra( wxCommandEvent& event )  override;
	void ClickBotonAgregarAlumno( wxCommandEvent& event )  override;
	Jardin *m_Jardin;

public:
	WinExample(Jardin * m_Jardin);
	void OnButtonClose(wxCommandEvent &evt);
};

#endif
