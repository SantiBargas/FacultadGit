#include <stdexcept>
#include <algorithm>
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

#define VERSION 20220919

// models and settings
enum Shading {Wireframe=0, Silhouette=1, Volumes=2};
bool active_shaders[3], active_before[3];
bool show_model1 = true, show_model2 = true, show_shadows=true;

// en orden de complejidad: teapot es una superficie no cerrada que no contempla el algoritmo
std::vector<std::string> models_names = { "cube", "esfera", "spot", "chookity","bottle", "teapot" };
std::vector<std::string> models_names2 = { "cube", "esfera", "spot", "chookity", "bottle","teapot" };
std::vector<std::string> floor_names = {"floor","walls","NURBS"};
int current_model = 3, current_model2 = 0, current_floor = 2;
Shader shader_texture, shader_phong;
std::vector<Shader> shaders;
Model mobject, mobject2, mfloor, mlight;
glm::vec4 lpos;
float angle_light = 0.001f;
bool rotate_object1 = false, rotate_object2 = true, rotate_light = false, show_stencil = false;
bool directional_light = false;
glm::vec3 pos1=glm::vec3(0.f,2.f,-1.5f), pos2=glm::vec3(0.f,2.f,1.5f); 
// extra callbacks
void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods);

void drawObject(const Model & object, const glm::mat4 &m1,glm::vec3 pos, bool show,bool light_on);
void drawFloor(bool light_on);
void drawLight();
void drawShadows();

int main() {
	// initialize window and setup callbacks
	Window window(win_width,win_height,"Shadow Volumes Demo",Window::fDefaults|Window::fBlend);
	setCommonCallbacks(window);
	glfwSetKeyCallback(window, keyboardCallback);
	
	// setup OpenGL state and load shaders
	glClearColor(0.8f,0.8f,0.7f,1.f);
	shader_texture = Shader ("shaders/texture");
	shader_phong = Shader("shaders/phong");
	
	shaders.resize(3);
	shaders[0] = Shader("shaders/wireframe");
	shaders[1] = Shader("shaders/silhouette",true);
	shaders[2] = Shader("shaders/shadow_volume",true);
	
//	 main loop
	mlight = Model::loadSingle("light",Model::fDontFit);
	int loaded_floor = -1;
	int loaded_model = -1;
	int loaded_model2 = -1;
	FrameTimer ftime;
	view_target.y = .75f;
	view_pos.z *= 3.5;
	do {
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
		
		// reload model if necessary
		if (loaded_model!=current_model) { 
			mobject = Model::loadSingle(models_names[current_model]);
			loaded_model = current_model;
		}
		
		if (loaded_model2!=current_model2) { 
			mobject2 = Model::loadSingle(models_names2[current_model2]);
			loaded_model2 = current_model2;
		}
		
		if (loaded_floor!=current_floor) {
			mfloor = Model::loadSingle(floor_names[current_floor],Model::fDontFit);
			loaded_floor = current_floor;
		}
		
		view_angle = std::min(std::max(view_angle,0.01f),1.72f);
		
		// auto-rotate
		double dt = ftime.newFrame();
		if (rotate_object1) mobject.angle +=static_cast<float>(0.5f*dt);
		if (rotate_object2) mobject2.angle +=static_cast<float>(0.5f*dt);
		if (rotate_light) angle_light += static_cast<float>(0.5f*dt);
		
		// update ligth position
		if (current_floor == 0) {
			// circulo
			lpos.x = 3.f * std::sin(angle_light);
			lpos.y = 3.f;
			lpos.z = 3.f * std::cos(angle_light);
		} else if (current_floor == 1) {
			// rodea la escena entre las paredes
			lpos.x = 2.f * -std::fabs(std::sin(angle_light * 0.3f));
			lpos.y = 3.5f * std::fabs(std::sin(angle_light * 0.3f));
			lpos.z = 2.f * -std::fabs(std::cos(angle_light));
		} else {
			// lemniscata
			lpos.x = 5.f * std::sin(angle_light);
			lpos.y = 3.5f;
			lpos.z = 7.f * std::cos(angle_light) * std::sin(angle_light);
		}
		
		lpos.w = directional_light ? 0.f : 1.f;
		
		// get matrixes for drawObject
		glm::mat4 identity(1.f);
		
		if (show_shadows) {
			drawShadows();
		} else {
			drawFloor(true);
			drawLight();
			drawObject(mobject,identity,pos1,show_model1,true);
			drawObject(mobject2,identity,pos2,show_model2,true);
		}
		
		// mostrar el stencil solo cuando se muestren las sombras 
		// (si no se mezcla con shadow volumes/siluetas y no se entiende)
		if (show_stencil && show_shadows) {
			static ShowStencil ss;
			ss.draw(256);
		}
		
		// settings sub-window
		window.ImGuiDialog("Shadow Volumes Demo",[&](){
			if (ImGui::TreeNode("First Model")) {
				ImGui::Combo("##", &current_model,models_names);
				ImGui::Checkbox("Rotate",&rotate_object1);
				ImGui::Checkbox("Show",&show_model1); 
				ImGui::TreePop();
			}
			
			ImGui::Separator();
			if (ImGui::TreeNode("Second Model")) {
				ImGui::Combo("##", &current_model2,models_names2);
				ImGui::Checkbox("Rotate",&rotate_object2);
				ImGui::Checkbox("Show",&show_model2);
				ImGui::TreePop();
			}
			
			ImGui::Separator();
			ImGui::SetNextItemOpen(true,ImGuiCond_Once);
			if (ImGui::TreeNode("Scene")) {
				ImGui::Combo("##", &current_floor,floor_names);
				ImGui::Checkbox("Directional Light",&directional_light);
				ImGui::Checkbox("Rotate Light",&rotate_light);
				ImGui::TreePop();
			}
			
			ImGui::Separator();
			if (ImGui::TreeNode("Algorithm")) {
				ImGui::Checkbox("Silhouette",&active_shaders[Shading::Silhouette]);
				ImGui::Checkbox("Shadow Volumes",&active_shaders[Shading::Volumes]);
				ImGui::Checkbox("Shadows",&show_shadows);
				int v = getStencilValueUnderMouseCursor(window);
				ImGui::Text("Value under mouse: %i",v);
				ImGui::TreePop();
			}
		});
		
		// finish frame
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while( glfwGetKey(window,GLFW_KEY_ESCAPE)!=GLFW_PRESS && !glfwWindowShouldClose(window) );
}

void drawShadows() {
	/// PASO 0: desactivar los shaders de visualizacion
	for(int i=0;i<3;i++) { active_before[i] = active_shaders[i]; active_shaders[i] = false; }
	
	/// PASO 1: CARGAR LOS ELEMENTOS DE LA ESCENA EN EL Z BUFFER
	// se aprovecha que se va a hacer un paso por toda la escena para dibujarla
	// con solo luz ambiente
	glEnable(GL_DEPTH_CLAMP);
	glDisable(GL_STENCIL_TEST);
	glColorMask(false,false,false,false);
	
	drawObject(mobject,glm::mat4(1.f),pos1,true,false);
	drawObject(mobject2,glm::mat4(1.f),pos2,true,false);
	drawFloor(false);
	
	/// PASO 2: CONFIGURAR EL STENCIL BUFFER segun el agloritmo de z fail
	glEnable(GL_STENCIL_TEST);
	glDepthMask(false);
	
	// el stencil test va a pasar siempre, lo que lo actualiza es el z test
	glStencilFunc(GL_ALWAYS,0,~0);
	
	// el algoritmo de z fail:
	// renderizo las caras traseras de los shadow volumes, si fallan el z test
	// sumo 1 al valor actual del stencil
	glStencilOpSeparate(GL_BACK, GL_KEEP, GL_INCR_WRAP, GL_KEEP);
	
	// renderizo las caras delanteras de los shadow volumes, si fallan el z test
	// resto 1 al valor actual del stencil
	glStencilOpSeparate(GL_FRONT, GL_KEEP, GL_DECR_WRAP, GL_KEEP);
	
	/// PASO 3: DIBUJAR LOS SHADOW VOLUMES de los objetos sombreadores
	active_shaders[Shading::Volumes] = true;
	drawObject(mobject,glm::mat4(1.f),pos1,false,true);
	drawObject(mobject2,glm::mat4(1.f),pos2,false,true);
	active_shaders[Shading::Volumes] = false;
	
	/// PASO 4: dibujar normal donde stencil value = 0
	glColorMask(true,true,true,true);
	glDepthMask(true);
	glClear(GL_DEPTH_BUFFER_BIT);
	
	glStencilFunc(GL_NOTEQUAL, 0, ~0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
	drawObject(mobject,glm::mat4(1.f),pos1,true,false);
	drawObject(mobject2,glm::mat4(1.f),pos2,true,false);
	drawFloor(false);
	
	glStencilFunc(GL_EQUAL, 0, ~0);
	drawObject(mobject,glm::mat4(1.f),pos1,true,true);
	drawObject(mobject2,glm::mat4(1.f),pos2,true,true);
	drawFloor(true);
	
	glStencilFunc(GL_ALWAYS,0,~0);
	drawLight();
	
	/// PASO FINAL: desactivar configuraciones
	glDisable(GL_STENCIL_TEST);
	glDisable(GL_DEPTH_CLAMP);
	
	for(int i=0;i<3;i++) { 
		active_shaders[i] = active_before[i];
	}
}

void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods) {
	if (action==GLFW_PRESS) {
		switch (key) {
		case 'O': case 'M': current_model = (current_model+1)%models_names.size(); break;
		case 'R': rotate_object1 = !rotate_object1; break;
		case 'L': rotate_light = !rotate_light; break;
		case 'S': show_stencil = !show_stencil; break;
		}
	}
}

void drawShadedModel(const Model &model, const glm::mat4 &m,Shader &shader,GLenum mode) {
	// select a shader
	glPolygonMode(GL_FRONT_AND_BACK,mode);
	shader.use();
	
	auto mats = common_callbacks::getMatrixes();
	shader.setMatrixes(m,mats[0],mats[1],mats[2]);
	
	// setup light and material
	shader.setLight(lpos, glm::vec3{1.f,1.f,1.f}, 0.4f);
	shader.setMaterial(model.material);
	
	// send geometry
	shader.setBuffers(model.buffers);
	model.buffers.draw();
}

void drawModel(const Model &model, const glm::mat4 &m = glm::mat4(1.f),bool light_on=true) {
	// select a shader
	Shader &shader = [&]()->Shader&{
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
		if (model.texture.isOk()) {
			model.texture.bind();
			return shader_texture;
		}
		return shader_phong;
	}();
	shader.use();
	
	auto mats = common_callbacks::getMatrixes();
	shader.setMatrixes(m,mats[0],mats[1],mats[2]);
	
	// setup light and material
	shader.setLight(lpos, glm::vec3{1.f,1.f,1.f}, 0.4f);
	auto mat_mod = model.material;
	if (!light_on) {
		mat_mod.ks = mat_mod.kd = glm::vec3(0.f,0.f,0.f);
	}
	shader.setMaterial(mat_mod);
	
	// send geometry
	shader.setBuffers(model.buffers);
	model.buffers.draw();
}

void drawObject(const Model & object, const glm::mat4 &m1, glm::vec3 pos, bool show,bool light_on) {
	auto m2 = glm::translate( m1, pos );
	auto m3 = glm::rotate( m2, 0.5f*object.angle, glm::vec3(std::sin(2.f*object.angle)/5.f,1.f,std::cos(2.f*object.angle)/5.f) );
	if (show) { 
		drawModel(object, m3, light_on);
	}
	
	if (active_shaders[Shading::Wireframe]) {
		drawShadedModel(object,m3,shaders[Shading::Wireframe], GL_LINE);
	} 
	
	if (active_shaders[Shading::Silhouette]) {
		drawShadedModel(object,m3,shaders[Shading::Silhouette], GL_LINE);
	} 
	
	if (active_shaders[Shading::Volumes]) {
		drawShadedModel(object,m3,shaders[Shading::Volumes], GL_FILL);
	}
}

void drawFloor(bool light_on) {
	glm::mat4 m(1.f);
	m = glm::scale(m,{3.f,3.f,3.f});
	if (floor_names[current_floor] == "NURBS") {
		m = glm::translate(m,{-0.1f,-0.2f,-1.f});
	}
	
	drawModel(mfloor,m,light_on);
}

void drawLight() {
	auto m1 = glm::translate( glm::mat4(1.f), glm::vec3(lpos) );
	auto m2 = glm::scale( m1, glm::vec3( 0.05f, 0.05f, 0.05f ) );
	auto m3 = glm::rotate( m2, angle_light, glm::vec3(0.f,1.f,0.f) );
	drawModel(mlight,m3,false);
}
