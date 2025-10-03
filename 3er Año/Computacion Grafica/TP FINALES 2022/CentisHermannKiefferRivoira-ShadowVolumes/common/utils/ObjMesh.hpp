#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <string>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include "ObjMesh.hpp"
#include "Material.hpp"
#include "Geometry.hpp"
#include <iostream>
#include <set>
#include <map>
#include "Debug.hpp"
#include <unordered_map>

struct ObjMesh {
	
	struct Element {
		int pos[3];
		int tcs[3];
		int norms[3];
		// AGREGADO: cada elemento tiene los indices de sus
		// tres vecinos
		int nbor[3];
		
		// AGREGADO: metodo para deterinar si un nodo pertenece al elemento
		int TieneA(int nodo) const {
			for(int i=0;i<3;i++) { 
				if (pos[i] == nodo) return i;
			}
			
			return -1;
		}
	};
	
	struct Part {
		std::string name;
		Material material;
		std::vector<Element> elements;
		
		// AGREGADO: dados dos elementos vecinos, 
		// determina el nodo no comun entre ellos
		int NodoNoComun(int elemento, int i_vecino) const {
			const Element & e = elements[elemento];
			const Element & v = elements[i_vecino];
			
			int r, c = 0;
			for(int i=0;i<3;i++) { 
				if (e.TieneA(v.pos[i]) == -1) {
					return i;
				}
			}
			
			// si c es mayor que uno hay mas de un nodo no comun
			// imposible si son triangulos y comparten dos nodos
			cg_assert(false, "son el mismo elemento");
			return r;
		}
	};
	
	std::vector<glm::vec3> positions;
	std::vector<std::vector<int>> nodes;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> tex_coords;
	std::vector<Part> parts;
	
	// AGREGADO: calcula que elementos son vecinos de cuales 
	// (actualiza nbor[j] para todo elements[i])
	void MakeVecinos();
	const Part &getPart(const std::string &name) const;
};

ObjMesh readObj(const std::string &full_path);

Geometry toGeometry(const ObjMesh &obj, const ObjMesh::Part &part);
Geometry toGeometry(const ObjMesh &obj, int ipart=0);
Geometry toGeometry(const ObjMesh &obj, const std::string &name);

#endif
