#ifndef V_ELIMINARALUMNO_H
#define V_ELIMINARALUMNO_H
#include "wxfb_project.h"
#include "Jardin.h"

class V_EliminarAlumno : public MyDialog2 {
private:
	Jardin *m_Jardin;
protected:
	void Eliminar( wxInitDialogEvent& event )  override;
	void ClickAceptar( wxCommandEvent& event )  override;
	void ClickCancelar( wxCommandEvent& event )  override;
	
public:
	V_EliminarAlumno(wxWindow *parent, Jardin *jardin);
	~V_EliminarAlumno();
};

#endif

