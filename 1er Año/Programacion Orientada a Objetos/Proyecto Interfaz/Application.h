#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Jardin.h"

class Application : public wxApp {
	Jardin *m_Jardin;
public:
	
	virtual bool OnInit();
};

#endif
