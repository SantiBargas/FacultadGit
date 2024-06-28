
#include "Application.h"
#include "WinExample.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	m_Jardin = new Jardin() ;
	wxInitAllImageHandlers();
	WinExample *win = new WinExample(m_Jardin);
	win->Show();
	return true;
}

