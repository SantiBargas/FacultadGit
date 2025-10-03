#include <fstream>
#include <map>
#include <algorithm>
#include <glm/glm.hpp>
#include "ObjMesh.hpp"
#include "Debug.hpp"
#include "Misc.hpp"
#include <unordered_map>
#include <set>
#include <iostream>

namespace {

float readInt(const std::string &s, int &i) {
	char *p = const_cast<char*>(s.c_str())+i;
	int r = std::strtol(p,&p,10);
	i = p-s.c_str();
	return r;
}

float readFloat(const std::string &s, int &i) {
	char *p = const_cast<char*>(s.c_str())+i;
	float r = std::strtof(p,&p);
	i = p-s.c_str();
	return r;
}

float readFloat(const std::string &s, const int &i) {
	int j = i; return readFloat(s,j);
}

glm::vec3 readVec3(const std::string &s, int i) {
	glm::vec3 v;
	v.x = readFloat(s,i); ++i;
	v.y = readFloat(s,i); ++i;
	v.z = readFloat(s,i);
	return v;
}

glm::vec2 readVec2(const std::string &s, int i) {
	glm::vec2 v;
	v.x = readFloat(s,i); ++i;
	v.y = readFloat(s,i);
	return v;
}

std::map<std::string,Material> loadMaterialsLib(const std::string &path, const std::string &filename) {
	cg_info( "Reading mtl file: " + path+filename + "...");
	std::ifstream file(path+filename);
	cg_assert(file.is_open(),"Could not open mtl file");
	
	std::map<std::string,Material> lib;
	Material *current_material = nullptr;
	for(std::string line; std::getline(file,line); ) {
		if (line.empty() or line[0]=='#') continue;
		if (startsWith(line,"newmtl ")) {
			cg_assert(lib.count(line.substr(7))==0,"Duplicate material name");
			current_material = &lib[line.substr(7)];
		} else {
			cg_assert(current_material,"Material property before command newmtl");
			if (startsWith(line,"Ks ")) {
				current_material->ks = readVec3(line,3);
			} else if (startsWith(line,"Ka ")) {
				current_material->ka = readVec3(line,3);
			} else if (startsWith(line,"Kd ")) {
				current_material->kd = readVec3(line,3);
			} else if (startsWith(line,"Ke ")) {
				current_material->ke = readVec3(line,3);
			} else if (startsWith(line,"Ns ")) {
				current_material->shininess = readFloat(line,3);
			} else if (startsWith(line,"d ")) {
				current_material->opacity = readFloat(line,2);
			} else if (startsWith(line,"Tr ")) {
				current_material->opacity = 1.f-readFloat(line,3);				
			} else if (startsWith(line,"map_Kd ")) {
				current_material->texture = path+line.substr(7);
			}
		}
	}
	return lib;
}

}

ObjMesh readObj(const std::string &full_path) {
	cg_info( "Reading obj file: " + full_path + "..." );
	std::string path = extractFolder(full_path);
	std::ifstream file(full_path);
	cg_assert(file.is_open(),"Could not open obj file");
	
	ObjMesh meshes;
	ObjMesh::Part *current_part = nullptr;
	std::map<std::string,Material> materials_lib;
	std::string current_name;
	
	for(std::string line; std::getline(file,line); ) {
		if (line.empty() or line[0]=='#') continue;
		if (startsWith(line,"o ")) {
			meshes.parts.push_back({}); 
			current_part = &meshes.parts.back();
			current_name = current_part->name = line.substr(2);
		} else if (startsWith(line,"mtllib ")) {
			materials_lib = loadMaterialsLib(path,line.substr(7));
		} else {
			if (not current_part) {
				meshes.parts.push_back({});
				current_part = &meshes.parts.back();
			}
			if (startsWith(line,"v ")) {
				meshes.positions.push_back(readVec3(line,2));
				meshes.nodes.push_back({});
			} else if (startsWith(line,"vn ")) {
				meshes.normals.push_back(readVec3(line,3));
			} else if (startsWith(line,"vt ")) {
				meshes.tex_coords.push_back(readVec2(line,3));
			} else if (startsWith(line,"f ")) {
				ObjMesh::Element e;
				int is = 2, in = 0, l = line.size();
				int pos[4], norms[4], tcs[4];
				while(is<l) {
					cg_assert(in<4,"Face with more than 4 vertexes are not supported yet");
					pos[in] = readInt(line,is)-1;
					if (line[is]=='/') {
						if (line[++is]=='/') {
							tcs[in] = -1;
							norms[in] = readInt(line,++is)-1;
						} else {
							tcs[in] = readInt(line,is)-1;
							if (line[is]=='/') {
								norms[in] = readInt(line,++is)-1;
							} else {
								norms[in] = -1;
							}
						}
					} else {
						tcs[in] = -1;
						norms[in] = -1;
					}
					++in;
				}
				cg_assert(in>2,"Face with less than 3 vertexes");
				
				int i_e = current_part->elements.size();
				for(int i=0;i<3;i++) { 
					e.pos[i] = pos[i];
					e.norms[i] = norms[i];
					e.tcs[i] = tcs[i];
					meshes.nodes[pos[i]].push_back(i_e); 
				}
				
				current_part->elements.push_back(e);
				
				if (in==4) {
					ObjMesh::Element vecino;
					for(int i=0;i<3;i++) { 
						vecino.pos[i] = pos[(i+2)%4];
						vecino.norms[i] = norms[(i+2)%4];
						vecino.tcs[i] = tcs[(i+2)%4];
						
//						meshes.nodes[pos[(i+2)%4]].push_back(i_e+1); 
						meshes.nodes[pos[(i+2)%4]].push_back(i_e+1); 
					}
					
					current_part->elements.push_back(vecino);
				} 
			} else if (startsWith(line,"usemtl ")) {
				if (not current_part->elements.empty()) {
					meshes.parts.push_back({}); 
					current_part = &meshes.parts.back();
				}
				current_part->name = current_name+":"+line.substr(7);
				if  (line.substr(7)!="None") {
					cg_assert(materials_lib.count(line.substr(7)),"Material not found: "+line.substr(7));
					current_part->material = materials_lib[line.substr(7)];
				}
			}
		}
	}
	cg_assert(not meshes.parts.empty(),"No mesh object found in file");
	
	meshes.MakeVecinos();
	
	return meshes;
}

namespace std {
	
	template <> struct hash<std::tuple<int,int,int>> {
		std::size_t operator()(const std::tuple<int,int,int>& p) const {
			return ( ( hash<int>()(std::get<0>(p))
		               ^ (hash<int>()(std::get<1>(p)) << 1) ) >> 1)
				   ^ (hash<int>()(std::get<0>(p)) << 1);
		}
	};
	
}

Geometry toGeometry(const ObjMesh &obj, const ObjMesh::Part &part) {
	Geometry g;
	// tupla 3 indices (pos, norm, tex) -> indice en el vector de triangulos 
	std::unordered_map<std::tuple<int,int,int>,int> map;
	auto addVertex = [&g,&obj,&part,&map](int index, int inode) {
		const ObjMesh::Element &e = part.elements[index];
		auto t = std::make_tuple(e.pos[inode],e.norms[inode],e.tcs[inode]);
		auto p = map.insert({t,g.positions.size()});
		if (p.second) {
			g.positions.push_back(obj.positions[e.pos[inode]]);
			if (e.norms[inode]!=-1) g.normals.push_back(obj.normals[e.norms[inode]]);
			if (e.tcs[inode]!=-1) g.tex_coords.push_back(obj.tex_coords[e.tcs[inode]]);
		}
		
		g.triangles.push_back(p.first->second);
	};
	
	for(size_t i=0;i<part.elements.size();i++) { 
		const ObjMesh::Element &e = part.elements[i]; 
		
		// por cada vertice necesitamos:		
		// un vertex del elemento i
		addVertex(i,0); 
		// un vertex del vecino anterior al elemento i que
		// no pertenezca al elemento i
		int nbor0 = e.nbor[0];
		int nbor1 = e.nbor[1];
		int nbor2 = e.nbor[2];
		
		if (nbor2 != -1) {
			addVertex(e.nbor[2],part.NodoNoComun(i,e.nbor[2]));
		} else {
			g.triangles.push_back(-1);
		}
		
		
		addVertex(i,2); 
		if (nbor1 != -1) {
			addVertex(e.nbor[1],part.NodoNoComun(i,e.nbor[1]));
		} else {
			g.triangles.push_back(-1);
		}
		
		addVertex(i,1); 
		if (nbor0 != -1) {
			addVertex(e.nbor[0],part.NodoNoComun(i,e.nbor[0]));
		} else {
			g.triangles.push_back(-1);
		}
		// TODO: PARTIR EN OBJ MESH CUANDO ENCUENTRO CUADRILATEROS
	}
	
	return g;
}

Geometry toGeometry(const ObjMesh &obj, int ipart) {
	return toGeometry(obj,obj.parts[ipart]);
}

Geometry toGeometry(const ObjMesh &obj, const std::string &name) {
	return toGeometry(obj,obj.getPart(name));
}

const ObjMesh::Part &ObjMesh::getPart(const std::string &name) const {
	auto it = std::find_if(parts.begin(),parts.end(),
						   [name](const ObjMesh::Part &p) {
							   return p.name==name; 
						   });
	cg_assert(it!=parts.end(),"Part name not found");
	return *it;
}

void ObjMesh::MakeVecinos ( ) {
	for(size_t i=0;i<parts.size();i++) { 
		for(size_t j=0;j<parts[i].elements.size();j++) { 
			for(size_t k=0;k<3;k++) { 
				parts[i].elements[j].nbor[k] = -1; // ningun vecino
			}
		}
		
		for(size_t j=0;j<parts[i].elements.size();j++) { 
			int nv = 3;
			for(size_t k=0;k<nv;k++) { 
				int n0 = parts[i].elements[j].pos[k];
				int n1 = parts[i].elements[j].pos[(k+1)%nv];
				
				std::vector<int> &ne = nodes[n0]; // initial node elements
				for(size_t w=0;w<ne.size();w++) {
					Element & vecino = parts[i].elements[ne[w]];
					int i_nbor = vecino.TieneA(n1);
					if (i_nbor != -1 && ne[w] != j) {
						parts[i].elements[ne[w]].nbor[i_nbor] = j;
						parts[i].elements[j].nbor[k] = ne[w];
					}
				}
			}
		}	
	}
}
