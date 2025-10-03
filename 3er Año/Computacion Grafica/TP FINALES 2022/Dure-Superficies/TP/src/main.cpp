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
#include "SubDivMesh.hpp"
#include "SubDivMeshRenderer.hpp"
#include "Delaunay.hpp"
#include "DelaunayRenderer.hpp"
#include <fstream>
#include <iostream>
#include "Texture.hpp"
#include <vector>

#define VERSION 20221013
// models and settings
std::vector<std::string> models_names = {"Superficie0", "Superficie1", "Superficie2", "Superficie3"};
std::vector<std::string> texture_names = {"standart", "CMY", "fluor", "rgb", "spectrum", "kelvin"};
int current_model = 0;
int current_texture = 0;
bool 	fill = false, 
		nodes = true, 
		wireframe = true, 
		smooth = false, 
		reload_mesh = true, 
		reload_texture = true, 
		mesh_modified = false, 
		show_axis = true, 
		show_delaunay = false, 
		texture = true;

Delaunay delaunay = Delaunay({0.f,1.f,0.f},{0.f,0.f,0.f},{1.f,1.f,0.f},{1.f,0.f,0.f});
SubDivMesh mesh;

// extraa callbacks
void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods);

void subdivide(SubDivMesh &mesh);
bool isVecinoArista(int iP0, int iP1, int iElemento, SubDivMesh &mesh);
void imprimirElemento(int indexElemento, SubDivMesh &mesh);
int getPointByArista(int iP0, int iP1, Elemento &e);
void setPointByElement(Elemento &e, Elemento &v1, Elemento &v2, int &p1, int &p2);

//peso de butterfly
float w = 1.0f/16.0f;
//maximo y minimo de la altura para interpolacion de textura
glm::vec3 minMaxZ;

int main() {
	// initialize window and setup callbacks
	Window window(win_width,win_height,"CG TP",true);
	setCommonCallbacks(window);
	glfwSetKeyCallback(window, keyboardCallback);
	view_fov = 50.f;
	
	// setup OpenGL state and load shaders
	glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LESS); 
	glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.8f,0.8f,0.9f,1.f);
	Shader shader_flat("shaders/flat"),
	       shader_smooth("shaders/smooth"),
		   shader_wireframe("shaders/wireframe"),
		   shader_texture("shaders/texture"),
		   shader_phong("shaders/phong");
		   
	auto axis = Model::load("axis",Model::fDontFit);
		
	SubDivMeshRenderer renderer;
	DelaunayRenderer delaunay_renderer;
	
	Texture texture1D = Texture("models/"+texture_names[current_texture]+".png",false,true);

	// main loop
	Material material;
	material.ka = material.kd = glm::vec3{.6f,.9f,.4f};
	material.ks = glm::vec3{.5f,.5f,.5f};
	material.shininess = 50.f;
	
	Material textureMaterial;
	textureMaterial.ka = glm::vec3{0.f,0.f,0.f};
	textureMaterial.kd = glm::vec3{0.1f,0.1f,0.1f};
	textureMaterial.ks = glm::vec3{0.5f,0.5f,0.5f};
	textureMaterial.ke = glm::vec3{0.f,0.f,0.f};
	textureMaterial.shininess = 300.f;
	textureMaterial.opacity = 1.f;
	
	//maximos y minimos de los puntos x e y para bounding box y centrar la superficie
	glm::vec2 minMaxX;
	glm::vec2 minMaxY;
	
	FrameTimer timer;
	do {
		glClearColor(1.f,1.f,1.f,1.f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		
		if (reload_mesh) {
			mesh = SubDivMesh("models/"+models_names[current_model]+".dat", delaunay, minMaxZ, minMaxY, minMaxX);
			reload_mesh = false; 
			mesh_modified = true;
		}
		
		if (reload_texture) {
			//mesh = SubDivMesh("models/"+models_names[current_model]+".dat", delaunay, minMaxZ, minMaxY, minMaxX);
			texture1D = Texture("models/"+texture_names[current_texture]+".png",false,false);
			reload_texture = false; 
			//mesh_modified = true;
		}
		
		if (mesh_modified) {
			renderer = makeRenderer(mesh);
			mesh_modified = false;
		}
		
		if (nodes) {
			shader_wireframe.use();
			setMatrixes(shader_wireframe, true, minMaxY, minMaxX);
			renderer.drawPoints(shader_wireframe);
		}
		
		if (wireframe) {
			shader_wireframe.use();
			setMatrixes(shader_wireframe, true, minMaxY, minMaxX);
			renderer.drawLines(shader_wireframe);
		}
		
		if (fill) {
			Shader &shader = smooth ? shader_smooth : shader_flat;
			shader.use();
			setMatrixes(shader, true);
			shader.setLight(glm::vec4{2.f,1.f,5.f,0.f}, glm::vec3{1.f,1.f,1.f}, 0.25f);
			shader.setMaterial(material);
			renderer.drawTriangles(shader);
		}
		
		if (texture) {
			shader_texture.use();
			shader_texture.setMaterial(textureMaterial);
			setMatrixes(shader_texture, true, minMaxY, minMaxX);
			shader_texture.setLight(glm::vec4{2.f,1.f,5.f,0.f}, glm::vec3{1.f,1.f,1.f}, 0.15f);
			shader_texture.setUniform("minmax", minMaxZ);
			texture1D.bind();
			
			renderer.drawTriangles(shader_texture);
		}
		
		if (show_axis) {
			//glDisable(GL_DEPTH_TEST);
			shader_phong.use();
			shader_phong.setLight(glm::vec4{-2.f,-2.f,-4.f,0.f}, glm::vec3{1.f,1.f,1.f}, 0.05f);
			setMatrixes(shader_phong, true, minMaxY, minMaxX);
		
			(GL_FRONT_AND_BACK,GL_FILL);
			for(const Model &model : axis) {
				setMatrixes(shader_phong, true, minMaxY, minMaxX);
				shader_phong.setBuffers(model.buffers);
				shader_phong.setMaterial(model.material);
				model.buffers.draw();
			}
			//glEnable(GL_DEPTH_TEST);
		}
		
		// dibujar la triangulacion
		if (show_delaunay) {
			//glDisable(GL_DEPTH_TEST);
			setMatrixes(delaunay_renderer.getShader(), true, minMaxY, minMaxX);
			delaunay_renderer.draw(delaunay.getPuntos(),
								   show_delaunay ? delaunay.getTriangulos() : std::vector<Triangulo>{},
								   -1);
			//glEnable(GL_DEPTH_TEST);
		}
		
		// settings sub-window
		window.ImGuiDialog("CG TP Final",[&](){
			if (ImGui::Combo(".dat (M)", &current_model,models_names)) reload_mesh = true;
			if (ImGui::Combo(".png (C)", &current_texture,texture_names)) reload_texture = true;
			//ImGui::Checkbox("Fill (F)",&fill);
			ImGui::Checkbox("Texture (T)",&texture);
			ImGui::Checkbox("Wireframe (W)",&wireframe);
			ImGui::Checkbox("Nodes (N)",&nodes);
			ImGui::Checkbox("Axis (A)",&show_axis);
			//ImGui::Checkbox("Smooth Shading (S)",&smooth);
			ImGui::Checkbox("Delaunay (D)",&show_delaunay);
			if (ImGui::Button("Subdivide (S)")) { subdivide(mesh); mesh_modified = true; }
			if (ImGui::Button("Reset (R)")) reload_mesh = true;
			//ImGui::Text("Nodes: %i, Elements: %i",mesh.n.size(),mesh.e.size());
		});
		
		// finish frame
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	} while( glfwGetKey(window,GLFW_KEY_ESCAPE)!=GLFW_PRESS && !glfwWindowShouldClose(window) );
}

void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods) {
	if (action==GLFW_PRESS) {
		switch (key) {
		case 'S': subdivide(mesh); mesh_modified = true; break;
		//case 'F': fill = !fill; break;
		case 'T': texture = !texture; break;
		case 'N': nodes = !nodes; break;
		case 'W': wireframe = !wireframe; break;
		case 'A': show_axis = !show_axis; break;
		//case 'S': smooth = !smooth; break;
		case 'D': show_delaunay = !show_delaunay; break;
		case 'R': reload_mesh=true; break;
		case 'M': current_model = (current_model+1)%models_names.size(); reload_mesh = true; break;
		case 'C': current_texture = (current_texture+1)%texture_names.size(); reload_texture = true; break;
		}
	}
}

// La struct Arista guarda los dos indices de nodos de una arista
// Siempre pone primero el menor indice, para facilitar la búsqueda en lista ordenada;
//    es para usar con el Mapa de más abajo, para asociar un nodo nuevo a una arista vieja
struct Arista {
	int n[2];
	Arista(int n1, int n2) {
		n[0]=n1; n[1]=n2;
		if (n[0]>n[1]) std::swap(n[0],n[1]);
	}
	Arista(Elemento &e, int i) { // i-esima arista de un elemento
		n[0]=e[i]; n[1]=e[i+1];
		if (n[0]>n[1]) std::swap(n[0],n[1]); // pierde el orden del elemento
	}
	const bool operator<(const Arista &a) const {
		return (n[0]<a.n[0]||(n[0]==a.n[0]&&n[1]<a.n[1]));
	}
};

// Mapa sirve para guardar una asociación entre una arista y un indice de nodo (que no es de la arista)
using Mapa = std::map<Arista,int>;
using MapaElementos = std::map<int,bool>;

void subdivide(SubDivMesh &mesh) {
	//cantidad de nodos iniciales
	int nodosInicialesSize = mesh.n.size();
	//cantidad de elementos iniciales
	int elementosInicialesSize = mesh.e.size();
	//mapa de aristas recorridad
	Mapa recorridos;
	MapaElementos ignorados;
	
	//recorro los elementos
	for (int i = 0; i < mesh.e.size(); i++) {
		//formo las aristas
		for(int j = 0; j < mesh.e[i].nv; j++){
			int index1 = mesh.e[i][j];
			int index2 = mesh.e[i][j+1];
			int indexOpuesto2 = mesh.e[i][j+2];
			int indexOpuesto1 = -1;
			int indexEsquina1 = -1;
			int indexEsquina2 = -1;
			int indexEsquina3 = -1;
			int indexEsquina4 = -1;
			
			Arista arista = Arista(index1, index2);
			
			//Verfifico si ya recorrí la arista
			if(recorridos.find(arista) == recorridos.end()){
				glm::vec3 puntoMedio = glm::vec3(0.f, 0.f, 0.f);

				//agrego la arista al mapa de recorridos
				recorridos[arista] = mesh.n.size();
				
				//indices de los elementos vecinos al elemento de la pos i
				int indexVecino1 = mesh.e[i].v[0];
				int indexVecino2 = mesh.e[i].v[1];
				int indexVecino3 = mesh.e[i].v[2];
				//indices de los elemenos vecinos al elementos vecinos al opuesto del elemento de la pos i
				int indexVecino4 = -1;
				int indexVecino5 = -1;
				
				//verifico cual de los 3 elementos vecinos es el vecino opuesto
				if(isVecinoArista(index1, index2, indexVecino1, mesh)){
					//obtenego  el indice del punto opuesto
					indexOpuesto1 = getPointByArista(index1, index2, mesh.e[indexVecino1]);
					
					//indices de los elementos vecinos del vecino opuesto
					int i1 = mesh.e[indexVecino1].v[0];
					int i2 = mesh.e[indexVecino1].v[1];
					int i3 = mesh.e[indexVecino1].v[2];
					
					//descarto el indice del elemento igual al elemento de la pos i (para no repetir)
					if(i1 != i && i2 != i){
						indexVecino4 = i1;
						indexVecino5 = i2;
					} else if (i1 != i && i3 != i) {
						indexVecino4 = i1;
						indexVecino5 = i3;
					} else if (i2 != i && i3 != i){
						indexVecino4 = i2;
						indexVecino5 = i3;
					}
					
					//verifico si puedo aplicar butterfly
					if(indexVecino1 != -1 && indexVecino2 != -1 && indexVecino3 != -1 && indexVecino4 != -1 && indexVecino5 != -1){
						setPointByElement(mesh.e[i], mesh.e[indexVecino2], mesh.e[indexVecino3], indexEsquina1, indexEsquina2);
						setPointByElement(mesh.e[indexVecino1], mesh.e[indexVecino4], mesh.e[indexVecino5], indexEsquina3, indexEsquina4);
						
						float w1 = 2.f*w;
						float w2 = -1.f*w;
						
						puntoMedio += (0.5f)*(mesh.n[index1]).p; 
						puntoMedio += (0.5f)*(mesh.n[index2]).p; 
						
						puntoMedio += (w1)*(mesh.n[indexOpuesto1]).p; 
						puntoMedio += (w1)*(mesh.n[indexOpuesto2]).p; 
						
						puntoMedio += (w2)*(mesh.n[indexEsquina1]).p; 
						puntoMedio += (w2)*(mesh.n[indexEsquina2]).p; 
						puntoMedio += (w2)*(mesh.n[indexEsquina3]).p; 
						puntoMedio += (w2)*(mesh.n[indexEsquina4]).p; 
						
					} else {
						//caso en donde no tengo los 5 triangulos extras para butterfly
						puntoMedio += (3/8.f)*(mesh.n[index1]).p;
						puntoMedio += (3/8.f)*(mesh.n[index2]).p;
						puntoMedio += (1/8.f)*(mesh.n[indexOpuesto1]).p;
						puntoMedio += (1/8.f)*(mesh.n[indexOpuesto2]).p;
					}
					
				} else if (isVecinoArista(index1, index2, indexVecino2, mesh)){
					indexOpuesto1 = getPointByArista(index1, index2, mesh.e[indexVecino2]);
					
					int i1 = mesh.e[indexVecino2].v[0];
					int i2 = mesh.e[indexVecino2].v[1];
					int i3 = mesh.e[indexVecino2].v[2];
					
					if(i1 != i && i2 != i){
						indexVecino4 = i1;
						indexVecino5 = i2;
					} else if (i1 != i && i3 != i) {
						indexVecino4 = i1;
						indexVecino5 = i3;
					} else if (i2 != i && i3 != i){
						indexVecino4 = i2;
						indexVecino5 = i3;
					}
					
					if(indexVecino1 != -1 && indexVecino2 != -1 && indexVecino3 != -1 && indexVecino4 != -1 && indexVecino5 != -1){
						setPointByElement(mesh.e[i], mesh.e[indexVecino1], mesh.e[indexVecino3], indexEsquina1, indexEsquina2);
						setPointByElement(mesh.e[indexVecino2], mesh.e[indexVecino4], mesh.e[indexVecino5], indexEsquina3, indexEsquina4);
					
						float w1 = 2.f*w;
						float w2 = -1.f*w;
						
						puntoMedio += (0.5f)*(mesh.n[index1]).p; 
						puntoMedio += (0.5f)*(mesh.n[index2]).p; 
						
						puntoMedio += (w1)*(mesh.n[indexOpuesto1]).p; 
						puntoMedio += (w1)*(mesh.n[indexOpuesto2]).p; 
						
						puntoMedio += (w2)*(mesh.n[indexEsquina1]).p; 
						puntoMedio += (w2)*(mesh.n[indexEsquina2]).p; 
						puntoMedio += (w2)*(mesh.n[indexEsquina3]).p; 
						puntoMedio += (w2)*(mesh.n[indexEsquina4]).p;
					} else {
						puntoMedio += (3/8.f)*(mesh.n[index1]).p;
						puntoMedio += (3/8.f)*(mesh.n[index2]).p;
						puntoMedio += (1/8.f)*(mesh.n[indexOpuesto1]).p;
						puntoMedio += (1/8.f)*(mesh.n[indexOpuesto2]).p;
					}
					
				} else if (isVecinoArista(index1, index2, indexVecino3, mesh)){
					indexOpuesto1 = getPointByArista(index1, index2, mesh.e[indexVecino3]);
					
					int i1 = mesh.e[indexVecino3].v[0];
					int i2 = mesh.e[indexVecino3].v[1];
					int i3 = mesh.e[indexVecino3].v[2];
					
					if(i1 != i && i2 != i){
						indexVecino4 = i1;
						indexVecino5 = i2;
					} else if (i1 != i && i3 != i) {
						indexVecino4 = i1;
						indexVecino5 = i3;
					} else if (i2 != i && i3 != i){
						indexVecino4 = i2;
						indexVecino5 = i3;
					}
					
					if(indexVecino1 != -1 && indexVecino2 != -1 && indexVecino3 != -1 && indexVecino4 != -1 && indexVecino5 != -1){
						setPointByElement(mesh.e[i], mesh.e[indexVecino1], mesh.e[indexVecino2], indexEsquina1, indexEsquina2);
						setPointByElement(mesh.e[indexVecino3], mesh.e[indexVecino4], mesh.e[indexVecino5], indexEsquina3, indexEsquina4);
						
						float w1 = 2.f*w;
						float w2 = -1.f*w;
						
						puntoMedio += (0.5f)*(mesh.n[index1]).p; 
						puntoMedio += (0.5f)*(mesh.n[index2]).p; 
						
						puntoMedio += (w1)*(mesh.n[indexOpuesto1]).p; 
						puntoMedio += (w1)*(mesh.n[indexOpuesto2]).p; 
						
						puntoMedio += (w2)*(mesh.n[indexEsquina1]).p; 
						puntoMedio += (w2)*(mesh.n[indexEsquina2]).p; 
						puntoMedio += (w2)*(mesh.n[indexEsquina3]).p; 
						puntoMedio += (w2)*(mesh.n[indexEsquina4]).p;
					} else {
						puntoMedio += (3/8.f)*(mesh.n[index1]).p;
						puntoMedio += (3/8.f)*(mesh.n[index2]).p;
						puntoMedio += (1/8.f)*(mesh.n[indexOpuesto1]).p;
						puntoMedio += (1/8.f)*(mesh.n[indexOpuesto2]).p;
					}
					
				} else {
					//no tiene un elemento vecino opuesto (borde)
					puntoMedio = ((mesh.n[index1]).p + (mesh.n[index2]).p) * 0.5f;
				}
				
				
				/*
				std::cout << index1 << "" << index2 << " " << indexOpuesto1 << " " << indexOpuesto2 << " " << indexEsquina1 << " " << indexEsquina2 << " " << indexEsquina3 << " " << indexEsquina4 << std::endl;
				std::cout << "GENERADO: " << puntoMedio[0] << "," << puntoMedio[1] << "," << puntoMedio[2] << std::endl;
				std::cout << std::endl;
				*/
		
				/*
				std::cout << "Elemento en el que estoy: " << std::endl;
				imprimirElemento(i, mesh);
				std::cout << "Arista: " << (mesh.n[index1]).p[0] << "," << (mesh.n[index1]).p[1] << " " << (mesh.n[index2]).p[0] << "," << (mesh.n[index2]).p[1] << std::endl;
				std::cout << "p3: " << (mesh.n[index3]).p[0] << "," << (mesh.n[index3]).p[1] << std::endl;
				std::cout << "index vecinos: " << indexVecino1 << " " << indexVecino2 << " " << indexVecino3 << std::endl;
				std::cout << "Vecinos: " << std::endl;
				imprimirElemento(indexVecino1, mesh);
				imprimirElemento(indexVecino2, mesh);
				imprimirElemento(indexVecino3, mesh);
				std::cout << std::endl;
				*/
		
				//actualizo altura maxima y minima
				if(puntoMedio[2] > minMaxZ[1]){
					minMaxZ[1] = puntoMedio[2];
				} else  if(puntoMedio[2] < minMaxZ[0]){
					minMaxZ[0] = puntoMedio[2];
				}
				
				//inserto el nuevo punto
				mesh.n.push_back(puntoMedio);
			}
		}
	}
	
	//Genero los nuevos elementos uniendo los puntos medios
	for(int i = 0; i < elementosInicialesSize; i++){
		
		
		
		int index1 = mesh.e[i][0];
		int index2 = mesh.e[i][1];
		int index3 = mesh.e[i][2];
		
		Arista arista1 = Arista(index1, index2);
		Arista arista2 = Arista(index2, index3);
		Arista arista3 = Arista(index3, index1);
		
		int indexPuntoMedio1 = recorridos[arista1];
		int indexPuntoMedio2 = recorridos[arista2];
		int indexPuntoMedio3 = recorridos[arista3];
		
		//agrego los tres tringulos generados a partir de los puntos medios
		mesh.agregarElemento(index2, indexPuntoMedio2, indexPuntoMedio1);
		mesh.agregarElemento(index3, indexPuntoMedio3, indexPuntoMedio2);
		mesh.agregarElemento(indexPuntoMedio1, indexPuntoMedio2, indexPuntoMedio3);
		
		//reemplazo el elemento con el primer triangulo
		mesh.reemplazarElemento(i, index1, indexPuntoMedio1, indexPuntoMedio3);
	}
	mesh.makeVecinos();
}

//determina si un elemento es vecino de otro dada una arista (2 puntos)
bool isVecinoArista(int iP0, int iP1, int iElemento, SubDivMesh &mesh){
	if(iElemento < 0){
		return false;
	}
	
	int index1 = mesh.e[iElemento].n[0];
	int index2 = mesh.e[iElemento].n[1];
	int index3 = mesh.e[iElemento].n[2];
	
	int flag = 0;
	
	if(iP0 == index1 || iP0 == index2 || iP0 == index3){
		flag++;
	}
	
	if(iP1 == index1 || iP1 == index2 || iP1 == index3){
		flag++;
	}
	
	if(flag == 2){
		return true;
	}
	
	return false;
}

//retorna el indice el punto opuesto de una arista (2 puntos) de un elemento
int getPointByArista(int iP0, int iP1, Elemento &e){
	int index1 = e.n[0];
	int index2 = e.n[1];
	int index3 = e.n[2];
	
	if((iP0 == index1 && iP1 == index2) || (iP0 == index2 && iP1 == index1)){
		return index3;
	}
	
	if((iP0 == index2 && iP1 == index3) || (iP0 == index3 && iP1 == index2)){
		return index1;
	}
	
	return index1;
}

//dado un elemento y sus 2 vecinos, setea en los puntos pasados por parametro los puntos de los vecinos que no estan en el elemento
void setPointByElement(Elemento &e, Elemento &v1, Elemento &v2, int &p1, int &p2){
	int e1 = e.n[0];
	int e2 = e.n[1];
	int e3 = e.n[2];
	
	int v11 = v1.n[0];
	int v12 = v1.n[1];
	int v13 = v1.n[2];
	
	int v21 = v2.n[0];
	int v22 = v2.n[1];
	int v23 = v2.n[2];
	
	if(v11 != e1 && v11 != e2 && v11 != e3){
		p1 = v11;
	} else if(v12 != e1 && v12 != e2 && v12 != e3){
		p1 = v12;
	} else {
		p1 = v13;
	}
	
	if(v21 != e1 && v21 != e2 && v21 != e3){
		p2 = v21;
	} else if(v22 != e1 && v22 != e2 && v22 != e3){
		p2 = v22;
	} else {
		p2 = v23;
	}
}


void imprimirElemento(int iElemento, SubDivMesh &mesh){
	if(iElemento < 0){
		return;
	}
	
	int index1 = mesh.e[iElemento].n[0];
	int index2 = mesh.e[iElemento].n[1];
	int index3 = mesh.e[iElemento].n[2];

	std::cout << "P1: " << mesh.n[index1].p[0] << "," << mesh.n[index1].p[1] << std::endl; 
	std::cout << "P2: " << mesh.n[index2].p[0] << "," << mesh.n[index2].p[1] << std::endl; 
	std::cout << "P3: " << mesh.n[index3].p[0] << "," << mesh.n[index3].p[1] << std::endl; 
}




	

	


