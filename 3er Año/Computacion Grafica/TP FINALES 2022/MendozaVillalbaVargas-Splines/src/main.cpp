#include <glad/glad.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <array>
#include "Window.hpp"
#include "Debug.hpp"
#include "Shaders.hpp"
#include "Bezier.hpp"
#include "Renderer.hpp"
#include "ScreenCapture.hpp"
#include "RasterAlgs.hpp"
#include "Callbacks.hpp"

#define VERSION 20220909.1
#include <iostream>
#include "Spline.hpp"
using namespace std;

// model data
//Bezier<glm::vec2,3> curve = { {60.5f,60.5f}, {100.5f,310.5f}, {200.5f,70.5f}, {498.5f,150.5f} };
std::vector<glm::vec3>points({ {60.5f,60.5f,0.f}, {100.5f,310.5f,0.f}, {400.5f,350.5f,0.f}, {498.5f,150.5f,0.f},{800.5f,800.5f,0.f}});

Spline spline(points);
std::vector<glm::vec2> segments;

//lista para los combo
std::vector<std::string> tipoContinuidad = { "parametrica", "geometrica","libre","custom"};
std::vector<std::string> tipoContinuidadCustom = { "parametrica", "geometrica"};
int currentTipoContinuidad = 0;
std::vector<std::string> tipoLinea = { "-----", "-- -- ", "- - ","-  -","Custom"};
std::vector<std::string> tipoPunta = { "Triangulo","Triangulo invertido", "Cuadrado","Reloj de arena"};///@@@pata agrega esto
int currentTipoPunta = 1;///@@@pata agrega esto
int currentTipoLinea = 0;
int currentTipoContinuidadCustom = 0;
int grosor=1;///grosor default de la curva

char texto[10]="00110011";
bool is_close = false;
int splineGetPieces_size;

bool checkSplineUwu=false;///es para que me remapee bien

//para hacer patrones necesito saber en que parte del patron estoy para decirle como inicia la siguiente curva
//y saber cual es el tamaño del patron
int contadorPixelCurva=0;
int cantidadPtosInter = points.size();
int ctrl_pt=-1,degree=3;
int ctrl_pt_local=-1;

static const glm::vec4 color_curve_int = { 0.f, 0.2f, 1.0f, 1.0f };
static const glm::vec4 color_curve_ext = { 0.2f, 0.0f, 0.8f, 1.0f };
static const glm::vec4 color_curve_pol = { 0.0f, 0.0f, 0.0f, 0.2f };
static const glm::vec4 color_zoom_area = { 0,0,0,.35 };


struct MainWin {
	int width = 1200, height = 900;
	Window ptr;
	glm::mat4 matrix;
} main_win;
struct ZoomWinInfo {
	Window ptr;
	int width = 500, height = 600;
	glm::mat4 matrix;
	glm::vec2 p0 = {75.f,140.f};
	int factor = 10;
} zoom_win;

struct controlPointCustom{
	int continuidad;
	glm::vec3 puntos;
};

std::vector<controlPointCustom>listControlPointCustom;



void viewResizeCallback(GLFWwindow *ptr, int w, int h) {
	glfwMakeContextCurrent(ptr);
	glViewport(0,0,w,h); 
	if (ptr==main_win.ptr) {
		main_win.width = w; main_win.height = h;
		main_win.matrix = glm::ortho<float>(0,w,0,h);
	} else {
		zoom_win.width = w; zoom_win.height = h;
		zoom_win.matrix = glm::ortho<float>(0,w,0,h);
	}
};

float redon(float x) { return int(x)+.5f; }
glm::vec2 redon(glm::vec2 p) { return {redon(p.x),redon(p.y)}; }

// callbacks
void mainMouseMoveCallback(GLFWwindow* window, double xpos, double ypos);
void mainMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void zoomMouseMoveCallback(GLFWwindow* window, double xpos, double ypos);
void zoomMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void zoomScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
void characterCallback(GLFWwindow* window, unsigned int code);

std::vector<glm::vec2> fragments;
void paintPixel(glm::vec2 p) { 
	fragments.push_back(p); 
}
curveRetVal evalCurve(float t) { 
	curveRetVal ret;
	glm::vec3 derv;
	glm::vec3 p=spline.at(t,derv); 
	glm::vec2 aux={p.x,p.y};
	ret.p=aux; 
	glm::vec2 auxD={derv.x,derv.y};
	ret.d=auxD;
	return ret; 
}

void crearPuntasInicio(){/// funcion para las puntas 
	
	
	glm::vec3 deri;
	glm::vec3 nodo0=spline.at(0,deri);
	
	float norma=sqrt(deri.y*deri.y+deri.x*deri.x);///norma
	float xxx=deri.x/norma;
	float yyy=deri.y/norma;
	glm::vec2 punto1,punto2,punto3,punto4,nodo;
	switch(currentTipoPunta){
	case 0:///triangulo
		punto1={(-20)*xxx+nodo0.x,(-20)*yyy+nodo0.y};
		punto2={(10)*yyy+nodo0.x,(-10)*xxx+nodo0.y};
		punto3={(-10)*yyy+nodo0.x,(10)*xxx+nodo0.y};
		drawSegment(paintPixel,punto1,punto2);
		drawSegment(paintPixel,punto1,punto3);
		drawSegment(paintPixel,punto2,punto3);
		break;
		
	case 1: ///triangulo invertido
		nodo={ nodo0.x, nodo0.y};
		punto1={(10)*yyy+(-20)*xxx+nodo0.x,(-10)*xxx+(-20)*yyy+nodo0.y};
		punto2={(-10)*yyy+(-20)*xxx+nodo0.x,(10)*xxx+(-20)*yyy+nodo0.y};
		drawSegment(paintPixel,nodo,punto1);
		drawSegment(paintPixel,nodo,punto2);
		drawSegment(paintPixel,punto1,punto2);
		break;
		
	case 2: ///cuadrado
		punto1={(10)*yyy+nodo0.x,(-10)*xxx+nodo0.y};
		punto2={(-10)*yyy+nodo0.x,(10)*xxx+nodo0.y};
		punto3={(10)*yyy+(-20)*xxx+nodo0.x,(-10)*xxx+(-20)*yyy+nodo0.y};
		punto4={(-10)*yyy+(-20)*xxx+nodo0.x,(10)*xxx+(-20)*yyy+nodo0.y};
		drawSegment(paintPixel,punto1,punto2);
		drawSegment(paintPixel,punto1,punto3);
		drawSegment(paintPixel,punto2,punto4);
		drawSegment(paintPixel,punto3,punto4);
		break;
	case 3: ///reloj de arena
		punto1={(10)*yyy+nodo0.x,(-10)*xxx+nodo0.y};
		punto2={(-10)*yyy+nodo0.x,(10)*xxx+nodo0.y};
		punto3={(10)*yyy+(-20)*xxx+nodo0.x,(-10)*xxx+(-20)*yyy+nodo0.y};
		punto4={(-10)*yyy+(-20)*xxx+nodo0.x,(10)*xxx+(-20)*yyy+nodo0.y};
		drawSegment(paintPixel,punto1,punto2);
		drawSegment(paintPixel,punto1,punto4);
		drawSegment(paintPixel,punto2,punto3);
		drawSegment(paintPixel,punto3,punto4);
		break;
	}
}
	void crearPuntasFin(){/// funcion para las puntas 
		
		
		glm::vec3 deri;
		glm::vec3 nodo0=spline.at(1-(float)1/(cantidadPtosInter),deri);
		
		float norma=sqrt(deri.y*deri.y+deri.x*deri.x);///norma
		float xxx=deri.x/norma;
		float yyy=deri.y/norma;
		glm::vec2 punto1,punto2,punto3,punto4,nodo;
		switch(currentTipoPunta){
		case 0:///triangulo
			punto1={(20)*xxx+nodo0.x,(20)*yyy+nodo0.y};
			punto2={(10)*yyy+nodo0.x,(-10)*xxx+nodo0.y};
			punto3={(-10)*yyy+nodo0.x,(10)*xxx+nodo0.y};
			drawSegment(paintPixel,punto1,punto2);
			drawSegment(paintPixel,punto1,punto3);
			drawSegment(paintPixel,punto2,punto3);
			break;
			
		case 1: ///triangulo invertido
			nodo={ nodo0.x, nodo0.y};
			punto1={(-10)*yyy+(20)*xxx+nodo0.x,(10)*xxx+(20)*yyy+nodo0.y};
			punto2={(10)*yyy+(20)*xxx+nodo0.x,(-10)*xxx+(20)*yyy+nodo0.y};
			drawSegment(paintPixel,nodo,punto1);
			drawSegment(paintPixel,nodo,punto2);
			drawSegment(paintPixel,punto1,punto2);
			break;
			
		case 2: ///cuadrado
			punto1={(10)*yyy+nodo0.x,(-10)*xxx+nodo0.y};
			punto2={(-10)*yyy+nodo0.x,(10)*xxx+nodo0.y};
			punto3={(-10)*yyy+(20)*xxx+nodo0.x,(10)*xxx+(20)*yyy+nodo0.y};
			punto4={(10)*yyy+(20)*xxx+nodo0.x,(-10)*xxx+(20)*yyy+nodo0.y};
			drawSegment(paintPixel,punto1,punto2);
			drawSegment(paintPixel,punto1,punto4);
			drawSegment(paintPixel,punto2,punto3);
			drawSegment(paintPixel,punto3,punto4);
			break;
		case 3: ///reloj de arena
			punto1={(10)*yyy+nodo0.x,(-10)*xxx+nodo0.y};
			punto2={(-10)*yyy+nodo0.x,(10)*xxx+nodo0.y};
			punto3={(-10)*yyy+(20)*xxx+nodo0.x,(10)*xxx+(20)*yyy+nodo0.y};
			punto4={(10)*yyy+(20)*xxx+nodo0.x,(-10)*xxx+(20)*yyy+nodo0.y};
			drawSegment(paintPixel,punto1,punto2);
			drawSegment(paintPixel,punto1,punto3);
			drawSegment(paintPixel,punto2,punto4);
			drawSegment(paintPixel,punto3,punto4);
			break;
		}
	}
void updateControlPointsAround(Spline &spline, int ctrl_pt, int tipoCont) {
	
	cout<<"---- continuidad "+tipoCont<<endl; 
	
	glm::vec3 ptoCtrlActual=spline.getControlPoint(ctrl_pt);
	
	// continuidad geometrica
	
	glm::vec3 ptoCtrlAnterior=spline.getControlPoint(ctrl_pt-3);
	glm::vec3 ptoCtrlPosterior=spline.getControlPoint(ctrl_pt+3);
	
	glm::vec3 derivada=(ptoCtrlPosterior-ptoCtrlAnterior)*0.5f*0.3f;
	
	//Calculamos la derivada geometrica
	
	glm::vec3 Pi= ptoCtrlActual;
	glm::vec3 Pant= ptoCtrlAnterior;
	glm::vec3 Psig= ptoCtrlPosterior;
	
	glm::vec3 derAnteorior =  (Pi - Pant)/glm::length(Pi - Pant);
	glm::vec3 derPosterior =  (Psig - Pi)/glm::length(Psig - Pi);
	
	glm::vec3 der = ((glm::length(Psig - Pi)*derAnteorior) + (glm::length(Pi - Pant)*derPosterior))/
		(glm::length(Pi - Pant) + glm::length(Psig - Pi));
	
	
	float min=	glm::length(Pi - Pant);
	if(glm::length(Psig - Pi) < min){
		min = glm::length(Psig - Pi);
	}
	
	//spline.setControlPoint(ctrl_pt-1,Pi - min*der*0.3f);
	//spline.setControlPoint(ctrl_pt+1,Pi + min*der*0.3f);
	
	if(tipoCont == 0){///elijo el tipo de continuidad
		spline.setControlPoint(ctrl_pt-1,ptoCtrlActual - derivada);
		spline.setControlPoint(ctrl_pt+1,ptoCtrlActual + derivada);
	}else if(tipoCont == 1) {
		spline.setControlPoint(ctrl_pt-1,Pi - min*der*0.3f);
		spline.setControlPoint(ctrl_pt+1,Pi + min*der*0.3f);
//		spline.setControlPoint(ctrl_pt-1,Pi - der*0.3f);
//		spline.setControlPoint(ctrl_pt+1,Pi + der*0.3f);
	}else if(tipoCont == 2){
		spline.setControlPoint(ctrl_pt-1,ptoCtrlActual - derivada*0.2f);
		spline.setControlPoint(ctrl_pt+1,ptoCtrlActual + derivada*0.2f);
	}
}

void remapSpline(Spline &spline, int cant_pts, int tipoCont) {
	
	if (cant_pts<3) return;

	if (static_cast<int>(spline.getPieces().size()) == cant_pts && checkSplineUwu) return;
	std::vector<glm::vec3> vp;
	double dt = 1.0/cant_pts;
	for(int i=0;i<cant_pts;++i)
		vp.push_back(spline.at(i*dt));
	spline = Spline(vp);
	
	
	for(int i=0;i<spline.getControlPointsCount();i+=3){
		if(tipoCont==3){
			cout<<i+" continuidad "+listControlPointCustom[i].continuidad <<endl;
			int continuidadPoint=listControlPointCustom[i].continuidad;
			updateControlPointsAround(spline,i,continuidadPoint);
		}else{
			listControlPointCustom[i].continuidad=tipoCont;
			updateControlPointsAround(spline,i,tipoCont);
		}
		
		
	}
	
		
	
	
	checkSplineUwu=true;///para que no entre al segundo if
}

int main() {
	
	
	
	
	// initialize main window and setup callbacks
	main_win.ptr = Window(main_win.width+zoom_win.width,main_win.height,"Area de trabajo",true);
	glfwSetFramebufferSizeCallback(main_win.ptr, viewResizeCallback);
	glfwSetCursorPosCallback(main_win.ptr, mainMouseMoveCallback);
	glfwSetMouseButtonCallback(main_win.ptr, mainMouseButtonCallback);
	glfwSetWindowSize(main_win.ptr,main_win.width,main_win.height);
	viewResizeCallback(main_win.ptr,main_win.width,main_win.height);
//	glfwSetCharCallback(main_win.ptr, characterCallback);///esto me rompe el ImGui::InputText
	
	// auxiliars for rendering
	Renderer renderer;
	constexpr float pi = 4.f*atan(1), r = 17;
	glm::vec2 c = {450.5f, 380.5f};
	for(int i=0;i<10;i++) {
		float ang = i*(2*pi)/10;
		glm::vec2 p = {std::cos(ang), std::sin(ang)};
		segments .push_back(redon(c+r*p));
		segments .push_back(redon(c+r*p*10.f));
	}
	std::array<glm::vec2,4> zoom_rect;
	
	
	
	// initialize zoom window and setup callbacks
	zoom_win.ptr = Window(zoom_win.width,zoom_win.height,"Zoom",0,main_win.ptr);
	viewResizeCallback(zoom_win.ptr,zoom_win.width,zoom_win.height);
	glfwSetFramebufferSizeCallback(zoom_win.ptr, viewResizeCallback);
	glfwSetCursorPosCallback(zoom_win.ptr, zoomMouseMoveCallback);
	glfwSetMouseButtonCallback(zoom_win.ptr, zoomMouseButtonCallback);
	glfwSetScrollCallback(zoom_win.ptr, zoomScrollCallback);
	
	int main_x, main_y;
	glfwGetWindowPos(main_win.ptr, &main_x, &main_y);
	glfwSetWindowPos(zoom_win.ptr,main_x+main_win.width,main_y);
	
	// auxiliars for capturing and zooming main windows content
	ScreenCapture capture;

	
	
	int ultimoTipoContinuidad=currentTipoContinuidad;///lo voy a usar para checkear y tirar un refrag
	
	for(int xx=0;xx<points.size();xx++){
		controlPointCustom cpc;
		cpc.continuidad = 0;
		cpc.puntos = points[xx];
		listControlPointCustom.push_back(cpc);
	};
	
	
	// main loop
	do {
		contadorPixelCurva=0;/// cuando inicie el loop, que el contador para el patron este en 0
		// --- main window ---
		glfwMakeContextCurrent(main_win.ptr);
		glClearColor(1.f,1.f,1.f,1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		renderer.getShader().setUniform("matrix",main_win.matrix);
		
		// control points and control polygon 
		//@@@cambio solo dejo estos 2 renders para ver el punto de control y la rectas
		fragments.clear();
		
		
		
		
		if(!is_close){
			splineGetPieces_size = spline.getPieces().size()-1;
		}else{
			splineGetPieces_size = spline.getPieces().size();
		}
		
		
		
		for(int i=0;i<splineGetPieces_size;i++){
			Bezier<> curve=spline.getPieces()[i];
			renderer.drawPoint(curve[0],color_curve_ext,3);
			renderer.drawPoint(curve[1],color_curve_ext,3);
			renderer.drawPoint(curve[2],color_curve_ext,3);
			renderer.drawPoint(curve[3],color_curve_ext,3);
		
			
			drawSegment(paintPixel,curve[0],curve[1]);
			drawSegment(paintPixel,curve[2],curve[3]);
		}
		crearPuntasInicio();/// pongo las puntas 
		crearPuntasFin();
		if(ctrl_pt%3==0 && currentTipoContinuidad==3){
			
			listControlPointCustom[ctrl_pt/3].continuidad=currentTipoContinuidadCustom;
		
		}	
		
		if(ultimoTipoContinuidad!=currentTipoContinuidad){///para que me recalcule los frags al cambiar la continuidad
			checkSplineUwu=false;
			cout<<"tipo de continuidad valor: "<<currentTipoContinuidad<<endl;
			ultimoTipoContinuidad=currentTipoContinuidad;
			
		}
		
		
		cantidadPtosInter = points.size();//lo calculo de nuevo x si agrego puntos nuevos
		remapSpline(spline,cantidadPtosInter,currentTipoContinuidad);
		
		
		
		// rasterized lines
		
		drawCurve(paintPixel,evalCurve,contadorPixelCurva, currentTipoLinea, cantidadPtosInter, texto,is_close,grosor);
		renderer.drawPoints(fragments,color_curve_int,1);
		
		// capturar el contenido de la ventana principal
		int zw = zoom_win.width/zoom_win.factor+1, 
			zh = zoom_win.height/zoom_win.factor+1;
		capture.take(zoom_win.p0.x,zoom_win.p0.y,zw,zh,zoom_win.factor);
		
		// zoom area
		// marcar el area del zoom en la ventana principal
		zoom_rect[0] = zoom_win.p0;
		zoom_rect[1] = zoom_win.p0+glm::vec2{zw,0.f};
		zoom_rect[2] = zoom_win.p0+glm::vec2{zw,zh};
		zoom_rect[3] = zoom_win.p0+glm::vec2{0.f,zh};;
		renderer.drawPolygon(zoom_rect,color_zoom_area);
		renderer.drawPoint(zoom_win.p0,color_zoom_area,5);
		
		main_win.ptr.ImGuiDialog("TP Final",[&](){//@@@ seteo los combo
			ImGui::Combo("Tipo de continuidad", &currentTipoContinuidad,tipoContinuidad);
			ImGui::Combo("Tipo de linea", &currentTipoLinea,tipoLinea);
			ImGui::Combo("Tipo de punta", &currentTipoPunta,tipoPunta);///para que me dibuje en el display  @@@pata 
//			ImGui::InputInt("codigo",&codigo,textoTam);
			ImGui::Text("Grosor de la curva");
			ImGui::InputInt("##grosor",&grosor);
			ImGui::Text("Codigo de patron");
			ImGui::InputText("##texto",texto,sizeof(texto));
			
			//tipoContinuidadCustom
			if(currentTipoContinuidad == 3){
			 ImGui::Combo("Tipo de continuidad custom", &currentTipoContinuidadCustom,tipoContinuidadCustom);
			}
			
			
			
			
			//			ImGui::Checkbox("Spline (S)",&show_spline);
			//			ImGui::Checkbox("Pol. Ctrl. (C)",&show_poly);
			
		});
		glfwSwapBuffers(main_win.ptr);
		
		// --- zoom window ---
		glfwMakeContextCurrent(zoom_win.ptr);
		
		// mostrar la captura aumentada en la ventana de zoom con su grilla
		// (a la grilla la hace el shader con estos parametros que le pasamos)
		auto &shader = capture.getShader();
		shader.setUniform("matrix",zoom_win.matrix);
		shader.setUniform("width",float(zoom_win.width));
		shader.setUniform("height",float(zoom_win.height));
		shader.setUniform("factor",float(zoom_win.factor));
		shader.setUniform("ate",.6f+0.4f*std::max(0.f,std::min(10-(zoom_win.factor-3),10)*.1f) );
		capture.draw();
		
		glfwSwapBuffers(zoom_win.ptr);
		
		
		
		
		
		// --- finish frame ---
		//		glfwSwapBuffers(main_win.ptr);
		glfwPollEvents();
		
	} while( glfwGetKey(main_win.ptr,GLFW_KEY_ESCAPE)!=GLFW_PRESS and (not glfwWindowShouldClose(main_win.ptr)) and
			glfwGetKey(zoom_win.ptr,GLFW_KEY_ESCAPE)!=GLFW_PRESS and (not glfwWindowShouldClose(zoom_win.ptr)) );
}

//void characterCallback(GLFWwindow* window, unsigned int code) {
//	switch (code) {
//		
//	case 'c': case 'C':
//		if(cantidadPtosInter>4){
//			points.pop_back();
//			
//			Spline auxSpline(points);
//			spline=auxSpline;
//			cout<<"se borro el ultimo nodo, quedan "<<cantidadPtosInter<<endl;
//			checkSplineUwu=false;///para que no me quede todo en modo recta
//		}
//		break;
//	}
//}


// en la ventana principal: drag=mover un vertice/pto de control
glm::vec2 *current_selection = nullptr;
glm::vec2 *closestPoint(glm::vec2 p) {
	float min_d2 = std::numeric_limits<float>::max();
	glm::vec2 *sel;
	auto process = [&](glm::vec2 *v, int n) {
		for(size_t i=0;i<n;++i) {
			auto aux_v = v[i]-p;
			float aux_d2 = glm::dot(aux_v,aux_v);
			if (aux_d2<min_d2) {
				sel = v+i;
				min_d2 = aux_d2;
			}
		}
	};
	//process(curve.data(),curve.size());
	process(segments.data(),segments.size());
	process(&zoom_win.p0,1);
	if (min_d2>100) sel = nullptr;
	return sel;
}void mainMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	
	
	if (ImGui::GetIO().WantCaptureMouse) return;//@@cambio
	
	int der = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);//detecto si hago click derecho
	int izq = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);//detecto si hago click izquierdo
	int med = glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_MIDDLE);//para borrar nodos 
	
	ctrl_pt=-1;
	
	///para mover nodos
	if (action == GLFW_PRESS && izq==1) {
		
		// pasar de coords de la ventana a coords del modelo
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		
		/// buscar punto cercano al click
		current_selection = closestPoint(glm::vec2{xpos,main_win.height-ypos});
		
		
		float dmin = 4.f;
		float yy=((float)main_win.height)-ypos;//dado que en lo lee de arriba a abajo
		glm::vec2 puntoClick={xpos,yy};//punto en la pantalla
		
		for(int i=0;i<spline.getControlPointsCount(); ++i) {
			
			glm::vec3 auxV3=spline.getControlPoint(i);
			glm::vec2 auxV3toV2={auxV3.x,auxV3.y};
			//			cout<<auxV3.x<<" "<<auxV3.y<<" "<<xpos<<" "<<ypos<<endl;
			double aux = glm::distance(puntoClick,auxV3toV2);
			if (aux < dmin) { 
				dmin = aux; ctrl_pt = i; 
				cout<<auxV3.x<<" "<<auxV3.y<<" "<<xpos<<" "<<ypos<<endl;
			}
			
			
		}
		
		if(ctrl_pt%3==0){
			
			listControlPointCustom[ctrl_pt/3].continuidad=currentTipoContinuidadCustom;
			cout<<"punto de control: "<<ctrl_pt<<endl;
			cout<<"currentTipoContinuidadCustom: "<<currentTipoContinuidadCustom<<endl;
		}	
		
		
		////		current_selection = closestPoint(glm::vec2{xpos,main_win.height-ypos});
	} else {
		current_selection = nullptr; // soltar el pto al soltar el boton
	}
	
	
	///para agregar nodos
	if (action == GLFW_PRESS && der==1 && is_close == false) {
		
		// pasar de coords de la ventana a coords del modelo
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		float yy=((float)main_win.height)-ypos;
		glm::vec3 aux = {(float) xpos,yy,0.f};
		cout<<izq<<" 1  "<<der<<"   "<<xpos<<"   "<< yy<<endl;
		points.push_back(aux);
		Spline auxSpline(points);
		spline=auxSpline;
		
		glm::vec3 auxV3=spline.getControlPoint(0);
		cout<<"No deberia cambiar: "<<auxV3.x<<" "<<auxV3.y<<" "<<xpos<<" "<<ypos<<endl;
		
		// cierro la curva si el punto que se agrega esta muy cerca de punto de inicio
		
		float distanciaY = abs(auxV3.y-yy);
		float distanciaX = abs(auxV3.x-xpos);
		cout<<"Distancia en x: "<<distanciaX<<" - Distancia en y: "<<distanciaY<<endl;
		float minimaDistancia = 15.f;
		
		if(distanciaX <= minimaDistancia && distanciaY<= minimaDistancia){
			is_close = true;
		}
		
		cout<<"Esta cerrado: "<<is_close<<endl;
		
		checkSplineUwu=false;///para que no me quede todo en modo recta
		
	} 
	if (action == GLFW_PRESS && med==1) {
		if(is_close == true && cantidadPtosInter>4){
			points.pop_back();
			Spline auxSpline(points);
			spline=auxSpline;
			is_close = false;
			
		}
		if(cantidadPtosInter>4){
			points.pop_back();
			
			Spline auxSpline(points);
			spline=auxSpline;
			cout<<"se borro el ultimo nodo, quedan "<<cantidadPtosInter<<endl;
			checkSplineUwu=false;///para que no me quede todo en modo recta
		}
	}
	
	if (ctrl_pt==-1) common_callbacks::mouseButtonCallback(window,button,action,mods);
}

void mainMouseMoveCallback(GLFWwindow* window, double xpos, double ypos) {
	if (ctrl_pt==-1){ 
		common_callbacks::mouseMoveCallback(window,xpos,ypos);
		//		cout<<"asd"<<endl;
	}else {
		float yy=((float)main_win.height)-ypos;
		glm::vec3 aux={xpos,yy,0};
		glm::vec3 puntoAux=spline.getControlPoint(ctrl_pt);
		spline.setControlPoint(ctrl_pt,aux);
		if(ctrl_pt%3==0){
			points[ctrl_pt/3]=aux;
			listControlPointCustom[ctrl_pt/3].puntos=aux;
		}
		
			
		if (ctrl_pt%degree==0 && currentTipoContinuidad!=2) { ////////@@@--------------------- si esta en modo libre no se actualizan los nodos adyacentes
			if(currentTipoContinuidad==3){
				updateControlPointsAround(spline,ctrl_pt,currentTipoContinuidadCustom);
				updateControlPointsAround(spline,ctrl_pt+degree,currentTipoContinuidadCustom);
				updateControlPointsAround(spline,ctrl_pt-degree,currentTipoContinuidadCustom);
			}else{
				updateControlPointsAround(spline,ctrl_pt,currentTipoContinuidad);
				updateControlPointsAround(spline,ctrl_pt+degree,currentTipoContinuidad);
				updateControlPointsAround(spline,ctrl_pt-degree,currentTipoContinuidad);
			}
			
			
		}else if(ctrl_pt%degree==1 && currentTipoContinuidad!=2){
			if(currentTipoContinuidad==0){//parametrica
				glm::vec3 pInterpolante=spline.getControlPoint(ctrl_pt-1);
				glm::vec3 derivada=aux-pInterpolante;
				glm::vec3 auxPunto=pInterpolante-derivada;
				spline.setControlPoint(ctrl_pt-2,auxPunto);
			}else if(currentTipoContinuidad==1){//geometrica
				glm::vec3 pInterpolante=spline.getControlPoint(ctrl_pt-1);
				glm::vec3 derivadaPositiva=puntoAux-pInterpolante;//puntoanterior - puntointerpolante=derivadaPositivaAnterior
				glm::vec3 otroPunto=spline.getControlPoint(ctrl_pt-2);//
				glm::vec3 derivadaNegativa=pInterpolante-otroPunto;
				float m1=glm::length(derivadaPositiva);
				float m2=glm::length(derivadaNegativa);
				glm::vec3 derivadaPositivaNueva=aux-pInterpolante;//puntoNuevo- puntointerpolante=derivadaPositivaNueva
				float c1=glm::length(derivadaPositivaNueva);
				float c2=m2*c1/m1;
				glm::vec3 puntoNuevo=pInterpolante-glm::normalize(derivadaPositivaNueva)*c2;
				spline.setControlPoint(ctrl_pt-2,puntoNuevo);
			}else if(currentTipoContinuidad ==3){
				if(currentTipoContinuidadCustom==0){
					glm::vec3 pInterpolante=spline.getControlPoint(ctrl_pt-1);
					glm::vec3 derivada=aux-pInterpolante;
					glm::vec3 auxPunto=pInterpolante-derivada;
					spline.setControlPoint(ctrl_pt-2,auxPunto);
				}else if(currentTipoContinuidadCustom==1){
					glm::vec3 pInterpolante=spline.getControlPoint(ctrl_pt-1);
					glm::vec3 derivadaPositiva=puntoAux-pInterpolante;//puntoanterior - puntointerpolante=derivadaPositivaAnterior
					glm::vec3 otroPunto=spline.getControlPoint(ctrl_pt-2);//
					glm::vec3 derivadaNegativa=pInterpolante-otroPunto;
					float m1=glm::length(derivadaPositiva);
					float m2=glm::length(derivadaNegativa);
					glm::vec3 derivadaPositivaNueva=aux-pInterpolante;//puntoNuevo- puntointerpolante=derivadaPositivaNueva
					float c1=glm::length(derivadaPositivaNueva);
					float c2=m2*c1/m1;
					glm::vec3 puntoNuevo=pInterpolante-glm::normalize(derivadaPositivaNueva)*c2;
					spline.setControlPoint(ctrl_pt-2,puntoNuevo);
					
				}
				
			}
		}else if(ctrl_pt%degree==2 && currentTipoContinuidad!=2){
			if(currentTipoContinuidad==0){//parametrica
				glm::vec3 pInterpolante=spline.getControlPoint(ctrl_pt+1);
				glm::vec3 derivada=aux-pInterpolante;
				glm::vec3 auxPunto=pInterpolante-derivada;
				spline.setControlPoint(ctrl_pt+2,auxPunto);
			}else if(currentTipoContinuidad==1){//geometrica
				glm::vec3 pInterpolante=spline.getControlPoint(ctrl_pt+1);
				glm::vec3 derivadaPositiva=puntoAux-pInterpolante;//puntoanterior - puntointerpolante=derivadaPositivaAnterior
				glm::vec3 otroPunto=spline.getControlPoint(ctrl_pt+2);//
				glm::vec3 derivadaNegativa=pInterpolante-otroPunto;
				float m1=glm::length(derivadaPositiva);
				float m2=glm::length(derivadaNegativa);
				glm::vec3 derivadaPositivaNueva=aux-pInterpolante;//puntoNuevo- puntointerpolante=derivadaPositivaNueva
				float c1=glm::length(derivadaPositivaNueva);
				float c2=m2*c1/m1;
				glm::vec3 puntoNuevo=pInterpolante-glm::normalize(derivadaPositivaNueva)*c2;
				spline.setControlPoint(ctrl_pt+2,puntoNuevo);
				
			}else if(currentTipoContinuidad==3){
				if(currentTipoContinuidadCustom==0){//parametrica
					glm::vec3 pInterpolante=spline.getControlPoint(ctrl_pt+1);
					glm::vec3 derivada=aux-pInterpolante;
					glm::vec3 auxPunto=pInterpolante-derivada;
					spline.setControlPoint(ctrl_pt+2,auxPunto);
				}else if(currentTipoContinuidadCustom==1){//geometrica
					glm::vec3 pInterpolante=spline.getControlPoint(ctrl_pt+1);
					glm::vec3 derivadaPositiva=puntoAux-pInterpolante;//puntoanterior - puntointerpolante=derivadaPositivaAnterior
					glm::vec3 otroPunto=spline.getControlPoint(ctrl_pt+2);//
					glm::vec3 derivadaNegativa=pInterpolante-otroPunto;
					float m1=glm::length(derivadaPositiva);
					float m2=glm::length(derivadaNegativa);
					glm::vec3 derivadaPositivaNueva=aux-pInterpolante;//puntoNuevo- puntointerpolante=derivadaPositivaNueva
					float c1=glm::length(derivadaPositivaNueva);
					float c2=m2*c1/m1;
					glm::vec3 puntoNuevo=pInterpolante-glm::normalize(derivadaPositivaNueva)*c2;
					spline.setControlPoint(ctrl_pt+2,puntoNuevo);
				}
			}
		}
	}
	if (current_selection)
		*current_selection = glm::vec2{xpos,main_win.height-ypos};
}
//void mainMouseMoveCallback(GLFWwindow* window, double xpos, double ypos) {
//	if (current_selection)
//		*current_selection = glm::vec2{xpos,main_win.height-ypos};
//	
//}

// en la ventana del zoom: drag=mover vista; scroll=cambiar nivel de zoom
glm::vec2 zoom_drag_p0; bool zoom_dragging = false;
void zoomMouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	
	if (action == GLFW_PRESS) {
		zoom_dragging = true;
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		zoom_drag_p0.x = xpos;
		zoom_drag_p0.y = zoom_win.height-ypos;
	} else {
		zoom_dragging = false;
	}
}
void zoomMouseMoveCallback(GLFWwindow* window, double xpos, double ypos) {
	if (not zoom_dragging) return;
	zoom_win.p0 -= (glm::vec2(xpos,zoom_win.height-ypos)-zoom_drag_p0)/float(zoom_win.factor);
	zoom_drag_p0.x = xpos; zoom_drag_p0.y = zoom_win.height-ypos;
}
void zoomScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	zoom_win.factor = std::max(3,zoom_win.factor+int(yoffset));
}






