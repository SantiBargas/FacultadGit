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
	
	///BUSCAMOS LOS MINIMOS Y MAXIMOS DE X,Y,Z
	
	float min_x, max_x, min_y, max_y, min_z, max_z;
	min_x = v[0].x;
	max_x = v[0].x;
	min_y = v[0].y;
	max_y = v[0].y;
	min_z = v[0].z;
	max_z = v[0].z;
	
	for(int i=1;i<v.size();i++) { 
		if(v[i].x<min_x) min_x = v[i].x;
		if(v[i].x>max_x) max_x = v[i].x;
		if(v[i].y<min_y) min_y = v[i].y;
		if(v[i].y>max_y) max_y = v[i].y;
		if(v[i].z<min_z) min_z = v[i].z;
		if(v[i].z>max_z) max_z = v[i].z;
	}
	
	glm::vec2 center = {min_x+(max_x-min_x)/2,min_z+(max_z-min_z)/2};
	
	std::vector<glm::vec2> v_cil;
	/// v_cil: {ang,y}
	
	for(int i=0;i<v.size();i++){
		glm::vec2 c_xz = {v[i].x-center.x,v[i].z-center.y};
		float ang = atan2(c_xz.x,c_xz.y);
		v_cil.push_back({ang,v[i].y});
	}
	
	float delta_t = max_y-min_y;
	
	std::vector<glm::vec2> v_tex;
	for(int i=0;i<v.size();i++) { 
		float s = v_cil[i].x/3.1415f;
		float t = 5*(1-((v[i].y-min_y)/delta_t))-2;
		v_tex.push_back({s,t});
	}
	
	return v_tex;
}

std::vector<glm::vec2> generateTextureCoordinatesForLid(const std::vector<glm::vec3> &v) {
	/// @todo: generar el vector de coordenadas de texturas para los vertices de la tapa
	
	float min_x, max_x, min_z, max_z;
	min_x = v[0].x;
	max_x = v[0].x;
	min_z = v[0].z;
	max_z = v[0].z;
	
	for(int i=1;i<v.size();i++) { 
		if(v[i].x<min_x) min_x = v[i].x;
		if(v[i].x>max_x) max_x = v[i].x;
		if(v[i].z<min_z) min_z = v[i].z;
		if(v[i].z>max_z) max_z = v[i].z;
	}
	
	 /// Sacamos el delta s como la resta del max de x y el min de x
	float delta_s = max_x - min_x;
	
	///Sacamaos el delta t como la resta del max z y el min de z
	float delta_t = max_z - min_z;
	
	std::vector<glm::vec2> v_tex;
	
	for(int i=0;i<v.size();i++) { 
		
		///asignamos a cada S y T 
		
		
		float s = (v[i].x-min_x)/delta_s;   ///para poner entre 0 y 1
		float t = (v[i].z-min_z)/delta_t;   ///para poner entre 0 y 1
		
		///agramos al vector de texturas los s y t
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
