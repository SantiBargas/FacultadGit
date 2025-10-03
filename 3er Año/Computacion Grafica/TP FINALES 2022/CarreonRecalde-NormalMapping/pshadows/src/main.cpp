#include <algorithm>
#include <stdexcept>
#include <vector>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "Model.hpp"
#include "Window.hpp"
#include "Callbacks.hpp"
#include "Debug.hpp"
#include "Shaders.hpp"
#include "Stencil.hpp"
#include <stdio.h>
//#include <stb_image.c>

#define VERSION 20220919
#include <GL/gl.h>
#include <fstream>
using namespace std;

GLuint texturas(string image);



// models and settings
std::vector<std::string> models_names = { "chookity", "teapot", "suzanne" };
int current_model = 0;
Shader shader_texture, shader_phong;
Model mobject, mfloor, mlight;
glm::vec4 lpos;
float angle_object = 0.f, angle_light = 0.f;
bool rotate_object = true, rotate_light = true, bump_mapping=true;

glm::mat4 rotacion = glm::rotate(glm::mat4(1.f),3.14f,glm::vec3(1.f,0.f,0.f));

// extra callbacks
void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods);

void drawObject(const glm::mat4 &m1);
void drawFloor(bool light_on);
void drawLight();

glm::mat4 getReflectionMatrix();
glm::mat4 getShadowMatrix();

int main() {
	
	
	// initialize window and setup callbacks
	Window window(win_width,win_height,"CG Demo",Window::fDefaults|Window::fBlend);
	setCommonCallbacks(window);
	glfwSetKeyCallback(window, keyboardCallback);
	
	// setup OpenGL state and load shaders
	glClearColor(0.1f,0.1f,0.1f,1.f);
	shader_texture = Shader ("shaders/texture");
	shader_phong = Shader("shaders/phong");
	
	// cargamos las nuevas texturas
	// --------------------
	Texture textura("models/floor.png");
	Texture texturaNormal("models/floor_normal.png");
	textura.bind(4);
	texturaNormal.bind(5);
	
	// le pasamos las texturas al shader_texture
	// --------------------
	shader_texture.use();

	shader_texture.setUniform("colorTexture", 4);
	shader_texture.setUniform("myNormal", 5);
	
	// main loop
	mfloor = Model::loadSingle("floor",Model::fDontFit);
	mlight = Model::loadSingle("light",Model::fDontFit);
	int loaded_model = -1;
	FrameTimer ftime;
	view_target.y = .75f;
	view_pos.z *= 2;
	do {
		
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
		
		// reload model if necessary
		if (loaded_model!=current_model) { 
			mobject = Model::loadSingle(models_names[current_model]);
			loaded_model = current_model;
		}
		
		view_angle = std::min(std::max(view_angle,0.01f),1.72f);
		
		// auto-rotate
		double dt = ftime.newFrame();
		if (rotate_object) angle_object += static_cast<float>(1.f*dt);
		if (rotate_light) angle_light += static_cast<float>(1.f*dt);
		
		// update ligth position
		lpos.x = 2.0f*std::sin(angle_light);
		lpos.y = 3.0f;
		lpos.z = 2.0f*std::cos(angle_light);
		lpos.w = 1.0f;
		
		// get matrixes for drawObject
		glm::mat4 identity(1.f);
		
		
		// prepare stencil
		/// @todo: generar valores diferentes en fondo, piso iluminado, sombra
		
		shader_texture.use();
		if(bump_mapping){
			shader_texture.setUniform("bump", 2.f);
		}else{
			shader_texture.setUniform("bump", 0.f);
		}
		// draw objects
		/// @todo: seleccionar la mascara y el valor de referencia adecuado para cada objeto
		
		drawFloor(true);
		drawFloor(false);
		drawLight();
		
		// settings sub-window
		window.ImGuiDialog("TP FINAL BUMP MAPPING",[&](){
			ImGui::Checkbox("Rotar Luz (L)",&rotate_light);
			ImGui::Checkbox("Activar Bump-Mapping (B)",&bump_mapping);
		});
		
		// finish frame
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	} while( glfwGetKey(window,GLFW_KEY_ESCAPE)!=GLFW_PRESS && !glfwWindowShouldClose(window) );
}

void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods) {
	if (action==GLFW_PRESS) {
		switch (key) {
		case 'O': case 'M': current_model = (current_model+1)%models_names.size(); break;
		case 'R': rotate_object = !rotate_object; break;
		case 'L': rotate_light = !rotate_light; break;
		case 'B': bump_mapping = !bump_mapping; break;
		}
	}
}

void drawModel(const Model &model, const glm::mat4 &m = glm::mat4(1.f)) {
	// select a shader
	Shader &shader = [&]()->Shader&{
		if (model.texture.isOk()) {
			model.texture.bind();
			return shader_texture;
		}
		return shader_phong;
	}();
	shader.use();
	
	auto mats = common_callbacks::getMatrixes();
	shader.setMatrixes(mats[0]*m,mats[1],mats[2]);
	
	// setup light and material
	shader.setLight(lpos, glm::vec3{1.f,1.f,1.f}, 0.4f);
	shader.setMaterial(model.material);
	
	// send geometry
	shader.setBuffers(model.buffers);
	model.buffers.draw();
}

void drawObject(const glm::mat4 &m1) {
	auto m2 = glm::translate( m1, glm::vec3(0.f,1.f,0.f) );
	auto m3 = glm::rotate( m2, 0.5f*angle_object, glm::vec3(std::sin(2.f*angle_object)/5.f,1.f,std::cos(2.f*angle_object)/5.f) );
	drawModel(mobject,m3);
}

void drawFloor(bool light_on) {
	static Material mat_orig = mfloor.material;
	if (light_on) {
		mfloor.material.kd = mat_orig.kd;
		mfloor.material.ks = mat_orig.ks;
	} else {
		mfloor.material.kd = mfloor.material.ks = glm::vec3(0.f,0.f,0.f);
	}
	
//	glm::mat4 rotacion = glm::rotate(glm::mat4(1.f),3.14f,glm::vec3(1.f,0.f,0.f));
	
	drawModel(mfloor);
}

void drawLight() {
	auto m1 = glm::translate( glm::mat4(1.f), glm::vec3(lpos) );
	auto m2 = glm::scale( m1, glm::vec3( 0.05f, 0.05f, 0.05f ) );
	auto m3 = glm::rotate( m2, angle_light, glm::vec3(0.f,1.f,0.f) );
	drawModel(mlight,m3);
}




