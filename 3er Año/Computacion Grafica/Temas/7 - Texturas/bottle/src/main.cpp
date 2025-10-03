#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "ObjMesh.hpp"
#include "Shaders.hpp"
#include "Texture.hpp"
#include "Window.hpp"
#include "Callbacks.hpp"
#include "Model.hpp"

#define VERSION 20230925

Shader *shader_coords_ptr = nullptr;
bool show_wireframe = false, show_coords = false, shader_ok = false;

std::vector<glm::vec2> generateTextureCoordinatesForBottle(const std::vector<glm::vec3> &v) {
	/// @todo: generar el vector de coordenadas de texturas para los vertices de la botella
	///utilizamos coordenadas cilindricas
	/// x = r*cos(ang)
	/// y = r*sen(ang)
	/// z = z
	
	float minx , minz , maxx , maxz,miny,maxy;
	minx = v[0].x;
	minz = v[0].z;
	maxx = v[0].x;
	maxz = v[0].z;
	miny = v[0].y;
	maxy = v[0].y;
	
	///BUSCAMOS EL MIN Y MAX DE X Y EL MIN Y MAX DE Z	
	for (int i=0; i< v.size() ; i++){
		if(v[i].x < minx) minx= v[i].x;
		if(v[i].z < minz) minz= v[i].z;
		if(v[i].y < miny) miny= v[i].y;
		if(v[i].y > maxy) maxy= v[i].y;
		if(v[i].x > maxx) maxx= v[i].x;
		if(v[i].z > maxz) maxz= v[i].z;
	}
	
	std::vector<glm::vec2> vcil;
	
	///buscamos el delta y, para que vaya de 0 a 1
	float deltay = (maxy-miny);
	
	for (int i=0; i< v.size() ; i++){
		///el punto s va a ser el arctangente de x / z dividio pi para que mapee la circunferencia entera
		///atan2 puede dar s negativas
		///dividimos por pi para que la etiqueta se repita dos veces
		
		float s = atan2(v[i].x,v[i].z) / 3.1415f;

		///para t usamos una funcion que mapea que cuando sea 0 lo ponga en 0.4 y cuando sea 1 lo ponga en 0.6
		float t = (5*(1-((v[i].y-miny)/deltay)))-2;
		vcil.push_back({s,t});
	}
	return vcil;
	
	///El problema de la botella es que cuando usamos atan, 
	
	
	
	
	///El problema de la botella es que cuando usamos atan, cuando el denominador se acerca a 0 la division
	///nos da resultado mas de 2pi
	///una solucion posible es que cuando nos pasemos de 2pi cortemos 
	
}

std::vector<glm::vec2> generateTextureCoordinatesForLid(const std::vector<glm::vec3> &v) {
	/// @todo: generar el vector de coordenadas de texturas para los vertices de la tapa
	
	///Ax+By+Cz+D=0   Ax+D=s  By+D=t
	///A B Y C definen la normal del plano D es para correrlo en el espacio
	/// con x e y sacamos s
	
	///Si agrandamos o achicamos la normal cambia cuantas veces se repite la normal
	///Si la normal mide 1 ocupa todo el plano, si la normal mide 0.5 entra dos veces la imagen etc
	
	float min_x, max_x, min_z, max_z;
	min_x = v[0].x;
	max_x = v[0].x;
	min_z = v[0].z;
	max_z = v[0].z;

///BUSCAMOS EL MIN Y MAX DE X Y EL MIN Y MAX DE Z	
	for(int i=1;i<v.size();i++) { 
		if(v[i].x<min_x) min_x = v[i].x;
		if(v[i].x>max_x) max_x = v[i].x;
		if(v[i].z<min_z) min_z = v[i].z;
		if(v[i].z>max_z) max_z = v[i].z;
	}
	
	///definimos delta s y delta t
	///delta s = resta del max_x y min_x
	///delta t = resta del maximo de z y minimo de z
	
	///esto es para despues poder dividir los puntos y que queden entre 0 y 1
	float delta_s = max_x-min_x;  
	float delta_t = max_z-min_z;
	
	std::vector<glm::vec2> v_tex;
	
	for(int i=0;i<v.size();i++) { 
		///el punto s es el punto x del vector menos el punto min dividido delta s
		float s = (v[i].x-min_x)/delta_s;
		///el punto t es el punto z del vector menos el punto min dividido delta t
		float t = (v[i].z-min_z)/delta_t;
		
		//ESTO FUE HECHO PARA QUE QUEDE ENTRE 0 Y 1 EN los planos S y T
		v_tex.push_back({s,t});
	}
	
	return v_tex;
}



void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods);

bool reload_shader_coords();

int main() {
	
	// initialize window and setup callbacks
	Window window(win_width,win_height,"CG Texturas");
	setCommonCallbacks(window);
	glfwSetKeyCallback(window, keyboardCallback);
	
	// setup OpenGL state and load shaders
	glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LESS);
	glEnable(GL_BLEND); glad_glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.6f,0.6f,0.8f,1.f);
	Shader shader_texture("shaders/texture");
	Shader shader_coords("shaders/texture");
	Shader shader_lines("shaders/lines");
	shader_coords_ptr = &shader_coords;
	reload_shader_coords();
	
	// load model and assign texture
	auto models = Model::load("models/bottle",Model::fKeepGeometry|Model::fTextureDontFlipV);
	Model &bottle = models[0], &lid = models[1];
	bottle.buffers.updateTexCoords(generateTextureCoordinatesForBottle(bottle.geometry.positions),true);
	bottle.texture = Texture("models/label.png", Texture::fClampT|Texture::fY0OnTop);
	lid.buffers.updateTexCoords(generateTextureCoordinatesForLid(lid.geometry.positions),true);
	lid.texture = Texture("models/lid.png", Texture::fClampT|Texture::fClampS|Texture::fY0OnTop);
	
	// main loop
	glPolygonOffset(-1.f,1.f);
	glEnable(GL_POLYGON_OFFSET_LINE);
	do {
		
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		for(int j=0;j<2;++j) {
			Shader &shader = j ? shader_lines : ( show_coords ? shader_coords : shader_texture );
			glPolygonMode(GL_FRONT_AND_BACK,j?GL_LINE:GL_FILL);
			shader.use();
			setMatrixes(shader);
			shader.setLight(glm::vec4{1.f,-1.f,5.f,0.f}, glm::vec3{1.f,1.f,1.f}, 0.15f);
			for(Model &mod : models) {
				mod.texture.bind();
				shader.setMaterial(mod.material);
				shader.setBuffers(mod.buffers);
				mod.buffers.draw();
			}
			if (not show_wireframe) break;
		}
		
		// settings sub-window
		window.ImGuiDialog("CG Example",[&](){
			ImGui::Checkbox("Show wireframe (W)",&show_wireframe);
			ImGui::Checkbox("Use shader coords(C)",&show_coords);
			if (ImGui::Button("Reload shader coords (F5)")) reload_shader_coords();
			if (!shader_ok) ImGui::Text("   Error compiling shader coords");
		});
		
		// finish frame
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	} while( glfwGetKey(window,GLFW_KEY_ESCAPE)!=GLFW_PRESS && !glfwWindowShouldClose(window) );
}

void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods) {
	if (action==GLFW_PRESS) {
		switch (key) {
		case 'W': show_wireframe = !show_wireframe; break;
		case 'C': show_coords = !show_coords; break;
		case GLFW_KEY_F5: reload_shader_coords(); break;
		}
	}
}

bool reload_shader_coords() {
	try {
		Shader new_shader("shaders/coords");
		*shader_coords_ptr = std::move(new_shader);
		return (shader_ok = true);
	} catch (std::runtime_error &e) {
		std::cerr << e.what() << std::endl;
		return (shader_ok = false);
	}
}
