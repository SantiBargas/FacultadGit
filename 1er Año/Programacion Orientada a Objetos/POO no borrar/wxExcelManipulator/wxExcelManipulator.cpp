#include <wx/filename.h>
#include "wxExcelManipulator.h"

static wxString &fix_path(wxString &path) {
	// los paths son relativos a quien sabe que, asi que aca se convierten en absolutos
	wxFileName fn(path);
	if (!fn.IsAbsolute()) fn.MakeAbsolute(wxGetCwd());
	return path=fn.GetFullPath();
}

wxExcelManipulator::wxExcelManipulator() {
	opened=false;
}

wxExcelManipulator::wxExcelManipulator(wxString fname, bool visible) {
	opened=false;
	Open(fname,visible);
}

bool wxExcelManipulator::Open(wxString fname, bool visible) {
	if (opened) return false;
#ifdef __WIN32__
	if ( !wxFileName::FileExists(fix_path(fname)) ) { opened=false; return false; }
	// abrir excel
	opened = xlApp.CreateInstance("Excel.Application");
	if (visible) xlApp.PutProperty("Visible",1);
	wxAutomationObject xlBooks;
	xlApp.GetObject(xlBooks,"Workbooks");
	if (fname[0]=='\0') {
		xlBooks.GetObject(xlBook,"Add");
	} else {
		wxVariant var(fname);
		xlBooks.GetObject(xlBook,"Open",1,&var);
	}
	xlApp.GetObject(xlSheet,"ActiveSheet");
	opened=true;
#else
	opened=false;
#endif
	return opened;
}
bool wxExcelManipulator::IsOpen() { 
	return opened;
}

void wxExcelManipulator::SetValue(int x, int y, wxString value) {
#ifdef __WIN32__
	GetCell(x,y).PutProperty("Value", value);
#endif
}
void wxExcelManipulator::SetValue(int x, int y, int value) {
#ifdef __WIN32__
	GetCell(x,y).PutProperty("Value", value);
#endif
}
void wxExcelManipulator::SetValue(int x, int y, double value) {
#ifdef __WIN32__
	GetCell(x,y).PutProperty("Value", value);
#endif
}
void wxExcelManipulator::Print() {
#ifdef __WIN32__
	xlSheet.CallMethod("PrintOut");
#endif
}

void wxExcelManipulator::SaveAs(wxString fname) {
#ifdef __WIN32__
	xlApp.PutProperty("DisplayAlerts",0); // para que no moleste el comprobador de compatibilidad en los office nuevos
	xlBook.CallMethod("SaveAs",fix_path(fname));
#endif
}

void wxExcelManipulator::Close() {
#ifdef __WIN32__
	xlBook.PutProperty("Saved",1);
	xlApp.CallMethod("Quit");
	opened=false;
#endif
}
wxExcelManipulator::~wxExcelManipulator() {
	if (opened) Close();
}

bool wxExcelManipulator::SelectSheet (int number) {
#ifdef __WIN32__
	int n=GetSheetsCount(); // ademas de retornar la cantidad, setea xlSheets
	if (number<1||number>n) return false;
	wxAutomationObject xlItem;
	wxVariant var(number);
	xlSheets.GetObject(xlItem,"Item",1,&var);
	xlItem.CallMethod("Select");
	xlApp.GetObject(xlSheet,"ActiveSheet");
#endif
	return true;
}


#ifdef __WIN32__
wxAutomationObject &wxExcelManipulator::GetCell (int x, int y) {
	wxVariant vars[2]; vars[0]=wxVariant(x); vars[1]=wxVariant(y);
	xlSheet.GetObject(xlCell,"Cells",2,vars);
	return xlCell;
}
#endif

wxString wxExcelManipulator::GetValue (int i, int j) {
#ifdef __WIN32__
	return GetCell(i,j).GetProperty("Value").GetString();
#endif
}

int wxExcelManipulator::GetValueAsInt (int i, int j) {
#ifdef __WIN32__
	return GetCell(i,j).GetProperty("Value").GetLong();	
#endif
}

double wxExcelManipulator::GetValueAsDouble (int i, int j) {
#ifdef __WIN32__
	return GetCell(i,j).GetProperty("Value").GetDouble();
#endif
}

int wxExcelManipulator::GetSheetsCount ( ) {
#ifdef __WIN32__
	xlBook.GetObject(xlSheets ,"Sheets");
	return xlSheets.GetProperty("Count").GetLong();
#endif
}

