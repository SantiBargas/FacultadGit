#ifndef V_AGREGARMAESTRA_H
#define V_AGREGARMAESTRA_H
#include "wxfb_project.h"
#include "Jardin.h"

class V_AgregarMaestra : public MyDialog6 {
	
private:
	Jardin *m_Jardin;
protected:
	void ClickAceptar( wxCommandEvent& event )  override;
public:
	V_AgregarMaestra(wxWindow *parent, Jardin *jardin);
	~V_AgregarMaestra();
};

#endif

