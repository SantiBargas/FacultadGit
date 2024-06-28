/**
* @brief Esta clase permite modificar e imprimir una planilla de Excel
*
* Esta clase permite abrir una planilla de calculo de Excel, modificarla, guardarla
* imprimirla, etc. La idea es que el programador diseñe el formulario que desea
* imprimir con Excel, y deje en blanco los campos a completar. Luego, desde la
* aplicacion que debe imprimir, se utiliza esta clase para completar esos campos.
*
* La clase utiliza al mismisimo Excel, cargandolo en memoria (de forma oculta si se 
* quiere, para que el usuario de la aplicacion no lo note) y le envia los comandos 
* para editar e imprimir la planilla. Todo se realiza a traves de un objeto OLE,
* razon por la cual la implementacion depende de la biblioteca wxAutomationObject,
* que es parte de wxWidgets.
*
* Lo bueno de esta biblioteca es que hace muy facil la impresion de formularios
* y planillas, ya que se las diseña con Excel directamente. Ademas, si hay que
* cambiar la planilla, basta con modificar el xls, y no es necesario recompilar.
* Como desventaja, es muy costoso levantar en memoria todo un Excel para imprimir
* cosas simples, y ademas depende de que este instalado. En consecuencia, tampoco
* funciona en GNU/Linux. Sin embargo, la biblioteca compila sin errores en GNU/Linux
* pero en ese caso ningun metodo hace nada.
*
* El procedimiento para usar esta biblioteca es entonces:
* -# Diseñar el formulario con Excel y guardarlo 
* -# Crear una instancia de wxExcelManipulator, pasandolo al constructor la ruta 
*    al archivo de xls creado en el punto anterior
* -# Utilizar los metodos SetValue para completar las celdas en blanco
* -# Utilizar el metodo Print para imprimir el formulario
* -# Utilizar el metodo Close para descargar la planilla de la memoria
*
*
* Para utilizar esta biblioteca en un proyecto de ZinjaI, simplemente debe 
* agregar los archivos wxExcelManipulator.h y wxExcelManipulator.cpp al 
* proyecto. Si el proyecto fue creado con la plantilla para wxWidgets no 
* necesita realizar ninguna otra configuración. En caso contrario, copie
* las opciones de compilación y enlazado de un proyecto wxWidgets.
*
* por Pablo Novara (zaskar_84@yahoo.com.ar), ultima modificacion: 07-04-2014
**/

#ifdef __WIN32__
#include <wx/msw/ole/automtn.h>
#endif

class wxExcelManipulator {
	bool opened; 
#ifdef __WIN32__
	wxAutomationObject xlApp, xlBook, xlSheet, xlSheets, xlCell;
	wxAutomationObject &GetCell(int x, int y);
#endif
public:
	
	/**
	* @brief Constructor, crea la instancia de Excel sin incializar nada
	*
	* Despues de utiliza este constructor se debe invocar al metodo Open para
	* comenzar a trabajar
	**/
	wxExcelManipulator();
	
	/**
	* @brief Constructor, crea la instancia de Excel y abre un documento
	*
	* @param fname    Ruta del archivo de excel (generalmente un .xls) que 
	*                 se debe abrir. Si esta en blanco se crea una planilla nueva.
	* @param visible  Si es true, la instancia de excel que realiza las
	*                 modificaciones sera visible, para poder observar
	*                 los cambios que la clase realiza en el documento. No
	*                 se debe cerrar manualmente esa ventana de Excel, sino
	*                 llamar al metodo Close, porque si se generara un error.
	*                 En general, este argumento deberia ser false en la version 
	*                 final del programa cliente, pero true durante la depuracion
	*                 del algoritmo que completa la planilla.
	**/
	wxExcelManipulator(wxString fname="", bool visible=false);
	
	/**
	* @brief Crea la instancia de Excel y abre un documento
	*
	* Se utiliza cuando se creo la instancia de la clase con el constructor por
	* defecto, o cuando se invoco a Close para reiniciar el estado del objeto.
	*
	* @param fname    Ruta del archivo de excel (generalmente un .xls) que 
	*                 se debe abrir. Si esta en blanco se crea una planilla nueva.
	* @param visible  Si es true, la instancia de excel que realiza las
	*                 modificaciones sera visible, para poder observar
	*                 los cambios que la clase realiza en el documento. No
	*                 se debe cerrar manualmente esa ventana de Excel, sino
	*                 llamar al metodo Close, porque si se generara un error.
	*                 En general, este argumento deberia ser false en la version 
	*                 final del programa cliente, pero true durante la depuracion
	*                 del algoritmo que completa la planilla.
	**/
	bool Open(wxString fname="", bool visible=false);
	
	/**
	* @brief Indica si el documento se pudo abrir correctamente y esta listo
	*        para ser editador/impreso.
	*
	* @retval true   si se abrio correctamente
	* @retval false  si no pudo abrirse (por ejemplo, porque excel no esta instalado)
	**/
	bool IsOpen();
	
	/**
	* @brief Selecciona una hoja en un archivo con muchas hojas
	*
	* @param number  número de hoja a seleccionar (base 1)
	* @retval true si la hoja existía y se pudo seleccionar
	* @retval false si el número de hoja no era válido
	**/
	bool SelectSheet(int number);
	
	/**
	* @brief Retorna la cantidad de hojas que tiene el archivo abierto actualmente
	*
	* @retval cantidad de hojas del archivo de Excel
	**/
	int GetSheetsCount();
	
	/**
	* @brief Asigna un valor de texto a una celda
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	* @param value  valor a colocar en esa celda
	**/
	void SetValue(int row, int col, wxString value);
	
	/**
	* @brief Asigna un valor entero a una celda
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	* @param value  valor a colocar en esa celda
	**/
	void SetValue(int row, int col, int value);
	
	/**
	* @brief Asigna un valor double a una celda
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	* @param value  valor a colocar en esa celda
	**/
	void SetValue(int row, int col, double value);
	
	/**
	* @brief Imprime la planilla 
	*
	* Este metodo imprime directamente en la impresora predeterminada sin pedir 
	* confirmacion ni mostrar dialogo alguno.
	**/
	void Print();
	
	/**
	* @brief Guarda la planilla modificada
	*
	* Este metodo imprime guarda la planilla modificada en el archivo que recibe
	* como argumento. Si el archivo ya existe lo sobreescribe sin preguntar.
	*
	* @param fname    Ruta del archivo de excel (generalmente un .xls) donde se 
	*                 debe guadar. No puede ser una cadena vacia.
	**/
	void SaveAs(wxString fname);
	
	/**
	* @brief Cierra la instancia de Excel utilizada por la clase
	*
	* Se pierden los cambios realizados a la planilla. Luego de llamar a Close
	* el objeto queda como si se hubiese construido con el constructor por
	* defecto, listo para utilizarse llamando al metodo Open.
	**/
	void Close();
	
	/**
	* @brief Obtiene el valor de una celda como wxString
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	*
	* @retval el valor de la celda como cadena
	**/
	wxString GetValue(int row, int col);
	
	/**
	* @brief Obtiene el valor de una celda como int
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	*
	* @retval el valor de la celda convertido a int
	**/
	int GetValueAsInt(int row, int col);
	
	/**
	* @brief Obtiene el valor de una celda como double
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	*
	* @retval el valor de la celda convertido a double
	**/
	double GetValueAsDouble(int row, int col);
	
	/**
	* @brief Llama a Close si no se ha llamado manualmente antes
	**/
	~wxExcelManipulator();
};

