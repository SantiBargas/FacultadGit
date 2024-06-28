#ifndef V_ELIMINAR_H
#define V_ELIMINAR_H
#include "wxfb_project.h"
#include "Jardin.h"

class V_EliminarMaestra : public MyDialog1 {
	
private:
	Jardin *m_Jardin;
protected:
	void Eliminar( wxInitDialogEvent& event )  override;
	void ClickAceptar( wxCommandEvent& event )  override;
	void ClickCancelar( wxCommandEvent& event )  override;

	
public:
	V_EliminarMaestra(wxWindow *parent, Jardin *jardin);
	~V_EliminarMaestra();
};

#endif

