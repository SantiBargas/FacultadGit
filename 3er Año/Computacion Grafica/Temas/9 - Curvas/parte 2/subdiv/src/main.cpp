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

#define VERSION 20221013

// models and settings
std::vector<std::string> models_names = { "cubo", "icosahedron", "plano", "suzanne", "star" };
int current_model = 0;
bool fill = true, nodes = true, wireframe = true, smooth = false, 
	 reload_mesh = true, mesh_modified = false;

// extraa callbacks
void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods);

SubDivMesh mesh;
void subdivide(SubDivMesh &mesh);

int main() {
	
	// initialize window and setup callbacks
	Window window(win_width,win_height,"CG Demo",true);
	setCommonCallbacks(window);
	glfwSetKeyCallback(window, keyboardCallback);
	view_fov = 60.f;
	
	// setup OpenGL state and load shaders
	glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LESS); 
	glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.8f,0.8f,0.9f,1.f);
	Shader shader_flat("shaders/flat"),
	       shader_smooth("shaders/smooth"),
		   shader_wireframe("shaders/wireframe");
	SubDivMeshRenderer renderer;
	
	// main loop
	Material material;
	material.ka = material.kd = glm::vec3{.8f,.4f,.4f};
	material.ks = glm::vec3{.5f,.5f,.5f};
	material.shininess = 50.f;
	
	FrameTimer timer;
	do {
		
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		
		if (reload_mesh) {
			mesh = SubDivMesh("models/"+models_names[current_model]+".dat");
			reload_mesh = false; mesh_modified = true;
		}
		if (mesh_modified) {
			renderer = makeRenderer(mesh);
			mesh_modified = false;
		}
		
		if (nodes) {
			shader_wireframe.use();
			setMatrixes(shader_wireframe);
			renderer.drawPoints(shader_wireframe);
		}
		
		if (wireframe) {
			shader_wireframe.use();
			setMatrixes(shader_wireframe);
			renderer.drawLines(shader_wireframe);
		}
		
		if (fill) {
			Shader &shader = smooth ? shader_smooth : shader_flat;
			shader.use();
			setMatrixes(shader);
			shader.setLight(glm::vec4{2.f,1.f,5.f,0.f}, glm::vec3{1.f,1.f,1.f}, 0.25f);
			shader.setMaterial(material);
			renderer.drawTriangles(shader);
		}
		
		// settings sub-window
		window.ImGuiDialog("CG Example",[&](){
			if (ImGui::Combo(".dat (O)", &current_model,models_names)) reload_mesh = true;
			ImGui::Checkbox("Fill (F)",&fill);
			ImGui::Checkbox("Wireframe (W)",&wireframe);
			ImGui::Checkbox("Nodes (N)",&nodes);
			ImGui::Checkbox("Smooth Shading (S)",&smooth);
			if (ImGui::Button("Subdivide (D)")) { subdivide(mesh); mesh_modified = true; }
			if (ImGui::Button("Reset (R)")) reload_mesh = true;
			ImGui::Text("Nodes: %i, Elements: %i",mesh.n.size(),mesh.e.size());
		});
		
		// finish frame
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	} while( glfwGetKey(window,GLFW_KEY_ESCAPE)!=GLFW_PRESS && !glfwWindowShouldClose(window) );
}

void keyboardCallback(GLFWwindow* glfw_win, int key, int scancode, int action, int mods) {
	if (action==GLFW_PRESS) {
		switch (key) {
		case 'D': subdivide(mesh); mesh_modified = true; break;
		case 'F': fill = !fill; break;
		case 'N': nodes = !nodes; break;
		case 'W': wireframe = !wireframe; break;
		case 'S': smooth = !smooth; break;
		case 'R': reload_mesh=true; break;
		case 'O': case 'M': current_model = (current_model+1)%models_names.size(); reload_mesh = true; break;
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

bool aristaEsFrontera(Arista arista, SubDivMesh &mesh){
	std::vector<int> elem_n0 = mesh.n[arista.n[0]].e;
	std::vector<int> elem_n1 = mesh.n[arista.n[1]].e;
	int cant_elem = 0;
	for(int i=0;i<elem_n0.size();i++) { 
		if (find(elem_n1.begin(),elem_n1.end(),elem_n0[i]) != elem_n1.end()) cant_elem++;
	}
	if(cant_elem<2) return true;
	return false;
}

void subdivide(SubDivMesh &mesh) {
	
	/// @@@@@: Implementar Catmull-Clark... lineamientos:
	//  Los nodos originales estan en las posiciones 0 a #n-1 de m.n,
	//  Los elementos orignales estan en las posiciones 0 a #e-1 de m.e
	
	///LA IDEA PRINCIPAL DE CATMULL-CLARK ES TOMAR UNA MALLA Y SUBDIVIDIRLA EN CARAS MAS PEQUEÑAS PARA OBTENER UNA SUPERFICIE MAS SUAVE
	///SUBDIVIDIR EN CARAS MAS PEQUEÑAS PARA OBTENER UNA SUPERFICIE MAS SUVE PARA SUAVIZAR LOS VERTICES Y LUEGO VOLVER A CONECTARLOS
	
	//  1) Por cada elemento, agregar el centroide (nuevos nodos: #n a #n+#e-1)
	
	Mapa mymap;
	Mapa mymap2;
	
	int mesh_n_size_start = mesh.n.size(); // Cantidad de nodos al comenzar
	int mesh_e_size_start = mesh.e.size(); // Cantidad de elementos al comenzar
	
	
	///Para cada elemento agregamos un nodo en el centro sumando la posicion del nodo y haciendo el promedio
	
	for(int e_i=0;e_i<mesh.e.size();e_i++) { // Para cada elemento e_i
		glm::vec3 sum_centroide(0.f,0.f,0.f);	// Defino el vector para sumar la posición de los nodos del elemento
		for(int nv_i=0;nv_i<mesh.e[e_i].nv;nv_i++) { 	// Para cada nodo del elemento e_i
			sum_centroide = sum_centroide + mesh.n[mesh.e[e_i].n[nv_i]].p; //Sumo la posición del nodo nv_i del elemento e_i 
		}
		sum_centroide = sum_centroide * (1.f/mesh.e[e_i].nv); // Divido el vector por la cantidad de nodos sumados para conseguir la posición del centroide
		mesh.n.push_back(Nodo(sum_centroide));	// Agrego el centroide del elemento e_i como nuevo nodo
	}
	
	///nos guardamos la cantidad de nodos al haber agregado los centroides
	int mesh_n_size_cent = mesh.n.size(); // Cantidad de nodos al haber agregado los centroides
	
	//  2) Por cada arista de cada cara, agregar un pto en el medio que es
	//      promedio de los vertices de la arista y los centroides de las caras 
	//      adyacentes. Aca hay que usar los elementos vecinos.
	//      En los bordes, cuando no hay vecinos, es simplemente el promedio de los 
	//      vertices de la arista
	//      Hay que evitar procesar dos veces la misma arista (como?)
	//      Mas adelante vamos a necesitar determinar cual punto agregamos en cada
	//      arista, y ya que no se pueden relacionar los indices con una formula simple
	//      se sugiere usar Mapa como estructura auxiliar
	
	
	///Agregamos  por cada arista de cada cara un punto medio calculando el promedio de diferente forma depende si es frontera o no lo es
	///si es frontera calcula el promedio con los dos nodos de la arista
	///si no es frontera calcula el promedio con los dos nodos de la arista y los dos centroides
	///y lo vamos guardando en el mapa de aristas
	for(int e_i=0;e_i<mesh.e.size();e_i++) { // Para cada elemento e_i (int e_i=0;e_i<mesh.e.size();e_i++)
		for(int nv_i=0;nv_i<(mesh.e[e_i].nv);nv_i++) { 	// Para cada nodo del elemento e_i (int nv_i=0;nv_i<(mesh.e[e_i].nv);nv_i++)
			int nv_aux = nv_i+1;
			if (nv_aux == mesh.e[e_i].nv) nv_aux = 0;
			Arista n_i1_i2(mesh.e[e_i].n[nv_i],mesh.e[e_i].n[nv_aux]);		// Definir arista con nodo n_i y n_i+1
			if (mymap.find(n_i1_i2) == mymap.end()){			// Buscar si la arista NO está en el mapa
				
				///caso que es frontera calcula el promedio y no entra al if
				glm::vec3 arista_midpoint = (mesh.n[mesh.e[e_i].n[nv_i]].p + mesh.n[mesh.e[e_i].n[nv_aux]].p)/2.f; //Sumo la posición del nodo nv_i del elemento e_i 
				glm::vec3 midpoint = arista_midpoint;
				if(!aristaEsFrontera(n_i1_i2,mesh)){ ///como no es frontera calcula el promedio con el centroide tambien
					midpoint = (arista_midpoint*2.f + mesh.n[mesh.e[e_i].v[nv_i]+mesh_n_size_start].p + mesh.n[e_i+mesh_n_size_start].p)/4.f;
				}
				mymap[n_i1_i2] = mesh.n.size();				// Agregar arista y nodo al mapa
				mesh.n.push_back(Nodo(midpoint));			// Agrego el nuevo nodo midpoint
			}
		}
		
	}
	
	//  3) Armar los elementos nuevos
	//      Los quads se dividen en 4, (uno reemplaza al original, los otros 3 se agregan)
	//      Los triangulos se dividen en 3, (uno reemplaza al original, los otros 2 se agregan)
	//      Para encontrar los nodos de las aristas usar el mapa que armaron en el paso 2
	//      Ordenar los nodos de todos los elementos nuevos con un mismo criterio (por ej, 
	//      siempre poner primero al centroide del elemento), para simplificar el paso 4.
	
	
	///primero chequeamos si es triangulo o cuadrilatero
	for(int e_i=0;e_i<mesh_e_size_start;e_i++) {
		if(mesh.e[e_i].nv==4){
			Arista e_a_0(mesh.e[e_i].n[0],mesh.e[e_i].n[1]);
			Arista e_a_1(mesh.e[e_i].n[1],mesh.e[e_i].n[2]);
			Arista e_a_2(mesh.e[e_i].n[2],mesh.e[e_i].n[3]);
			Arista e_a_3(mesh.e[e_i].n[3],mesh.e[e_i].n[0]);
			int midpoint_01 = mymap[e_a_0];
			int midpoint_12 = mymap[e_a_1];
			int midpoint_23 = mymap[e_a_2];
			int midpoint_30 = mymap[e_a_3];
			
			///agregar elemento recibe 4 nodos. el nodo, el centroide y los dos de la arista mas cercana
			mesh.agregarElemento(mesh.e[e_i].n[1],midpoint_12,e_i+mesh_n_size_start,midpoint_01);
			mesh.agregarElemento(mesh.e[e_i].n[2],midpoint_23,e_i+mesh_n_size_start,midpoint_12);
			mesh.agregarElemento(mesh.e[e_i].n[3],midpoint_30,e_i+mesh_n_size_start,midpoint_23);
			mesh.reemplazarElemento(e_i,mesh.e[e_i].n[0],midpoint_01,e_i+mesh_n_size_start,midpoint_30);
			mesh.makeVecinos();
		}
		if(mesh.e[e_i].nv==3){
			Arista e_a_0(mesh.e[e_i].n[0],mesh.e[e_i].n[1]);
			Arista e_a_1(mesh.e[e_i].n[1],mesh.e[e_i].n[2]);
			Arista e_a_2(mesh.e[e_i].n[2],mesh.e[e_i].n[0]);
			int midpoint_01 = mymap[e_a_0];
			int midpoint_12 = mymap[e_a_1];
			int midpoint_20 = mymap[e_a_2];
			
			///agregar elemento recibe 3 nodos
			mesh.agregarElemento(mesh.e[e_i].n[1],midpoint_12,e_i+mesh_n_size_start,midpoint_01);
			mesh.agregarElemento(mesh.e[e_i].n[2],midpoint_20,e_i+mesh_n_size_start,midpoint_12);
			mesh.reemplazarElemento(e_i,mesh.e[e_i].n[0],midpoint_01,e_i+mesh_n_size_start,midpoint_20);
			mesh.makeVecinos();
		}
	}
	
	
	//  4) Calcular las nuevas posiciones de los nodos originales
	//      Para nodos interiores: (4r-f+(n-3)p)/n
	//         f=promedio de nodos interiores de las caras (los agregados en el paso 1)
	//         r=promedio de los pts medios de las aristas (los agregados en el paso 2)
	//         p=posicion del nodo original
	//         n=cantidad de elementos para ese nodo
	//      Para nodos del borde: (r+p)/2
	//         r=promedio de los dos pts medios de las aristas
	//         p=posicion del nodo original
	//      Ojo: en el paso 3 cambio toda la SubDivMesh, analizar donde quedan en los nuevos 
	//      elementos (¿de que tipo son?) los nodos de las caras y los de las aristas 
	//      que se agregaron antes.
	// tips:
	//   no es necesario cambiar ni agregar nada fuera de este método, (con Mapa como 
	//     estructura auxiliar alcanza)
	//   sugerencia: probar primero usando el cubo (es cerrado y solo tiene quads)
	//               despues usando la piramide (tambien cerrada, y solo triangulos)
	//               despues el ejemplo plano (para ver que pasa en los bordes)
	//               finalmente el mono (tiene mezcla y elementos sin vecinos)
	//   repaso de como usar un mapa:
	//     para asociar un indice (i) de nodo a una arista (n1-n2): elmapa[Arista(n1,n2)]=i;
	//     para saber si hay un indice asociado a una arista:  ¿elmapa.find(Arista(n1,n2))!=elmapa.end()?
	//     para recuperar el indice (en j) asociado a una arista: int j=elmapa[Arista(n1,n2)];
	
	
	for(int i=0;i<mesh_n_size_start;i++) {  //mesh_n_size_start
		
		///calculos si es frontera
		if(mesh.n[i].es_frontera){
			glm::vec3 r_vec(0.f,0.f,0.f);
			int r_size = 0;
			for(int j=0;j<mesh_n_size_start;j++) {
				Arista arista_aux(i,j);
				if(mymap.find(arista_aux) != mymap.end()){
					int midpoint_arista_aux = mymap[arista_aux];
					if(mesh.n[midpoint_arista_aux].es_frontera){
						r_vec = r_vec + mesh.n[midpoint_arista_aux].p;
						r_size++;
					}
				}
			}
			r_vec = r_vec / float(r_size);
			glm::vec3 p_vec = mesh.n[i].p;
			
			//glm::vec3 nodo_nuevo = (f_vec+r_vec*2.f+(cant-3.f)*p_vec)/cant; (4r-f+(n-3)p)/n
			glm::vec3 nodo_nuevo = (r_vec+p_vec)/(2.f);
			mesh.n[i].p = nodo_nuevo;
		}else{
			glm::vec3 f_vec(0.f,0.f,0.f);
			for(int j=0;j<mesh.n[i].e.size();j++) { 
				int e_j = mesh.n[i].e[j];
				int cen_j = mesh.e[e_j].n[2];
				f_vec = f_vec + mesh.n[cen_j].p;
			}
			f_vec = f_vec / float(mesh.n[i].e.size());
			
			glm::vec3 r_vec(0.f,0.f,0.f);
			int r_size = 0;
			
			for(int j=0;j<mesh_n_size_start;j++) { 
				Arista arista_aux(i,j);
				if(mymap.find(arista_aux) != mymap.end()){
					int midpoint_arista_aux = mymap[arista_aux];
					r_vec = r_vec + mesh.n[midpoint_arista_aux].p;
					r_size++;
				}
			}
			
			r_vec = r_vec / float(r_size);
			float cant = float(mesh.n[i].e.size());
			glm::vec3 p_vec = mesh.n[i].p;
			
			//glm::vec3 nodo_nuevo = (f_vec+r_vec*2.f+(cant-3.f)*p_vec)/cant; (4r-f+(n-3)p)/n
			glm::vec3 nodo_nuevo = (r_vec*(4.f)-f_vec+(cant-3.f)*p_vec)/(cant);
			mesh.n[i].p = nodo_nuevo;
			
		}
	}
	mesh.makeVecinos();
	
}
