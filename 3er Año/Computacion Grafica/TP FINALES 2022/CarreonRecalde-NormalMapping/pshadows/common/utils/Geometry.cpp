#include <glm/ext.hpp>
#include "Geometry.hpp"
#include "Debug.hpp"

template<typename vector>
static void updateBuffer(GLenum type, GLuint &id, vector &v, bool realloc, bool dynamic) {
	if (id==0) {
		cg_assert(realloc,"Texture coordinates not initialized");
		glGenBuffers(1, &id);
	}
	glBindBuffer(type, id);
	if (realloc) {
		glBufferData(type, v.size()*sizeof(typename vector::value_type), v.data(), dynamic?GL_DYNAMIC_DRAW:GL_STATIC_DRAW);
	} else
		glBufferSubData(type, 0, v.size()*sizeof(typename vector::value_type), v.data());
}

GeometryRenderer::GeometryRenderer(const Geometry &geo, bool dynamic) {
	
	cg_assert(geo.positions.size(),"Empty Geometry");
	
	glGenVertexArrays(1,&VAO);
	glBindVertexArray(VAO);
	
	updateBuffer(GL_ARRAY_BUFFER,VBO_pos,geo.positions,true,dynamic);
	
	// acá carga la información a la placa de video
	if (not geo.normals.empty()) {
		cg_assert(geo.normals.size()==geo.positions.size(),"Wrong normals count");
		updateBuffer(GL_ARRAY_BUFFER,VBO_norms,geo.normals,true,dynamic);  
	}
	if (not geo.tangents.empty()) {
		cg_assert(geo.tangents.size()==geo.positions.size(),"Wrong tangents count");
		updateBuffer(GL_ARRAY_BUFFER,VBO_tangents,geo.tangents,true,dynamic);  
	}
	if (not geo.bi_tangents.empty()) {
		cg_assert(geo.bi_tangents.size()==geo.positions.size(),"Wrong biTangents count");
		updateBuffer(GL_ARRAY_BUFFER,VBO_bi_tangents,geo.bi_tangents,true,dynamic);  
	}
	if (not geo.tex_coords.empty()) {
		cg_assert(geo.tex_coords.size()==geo.positions.size(),"Wrong texture coordinates count");
		updateBuffer(GL_ARRAY_BUFFER,VBO_tcs,geo.tex_coords,true, dynamic);  
	}
	if (not geo.triangles.empty()) {
		updateBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO,geo.triangles,true,dynamic);
		count = geo.triangles.size();
	} else 
		count = geo.positions.size();
	
	glBindVertexArray(0);
}

GeometryRenderer::GeometryRenderer(GeometryRenderer &&geo) {
	*this = static_cast<const GeometryRenderer&>(geo);
	geo = static_cast<const GeometryRenderer&>(GeometryRenderer());
}

GeometryRenderer &GeometryRenderer::operator=(GeometryRenderer &&geo) {
	freeResources();
	*this = static_cast<const GeometryRenderer&>(geo);
	geo = static_cast<const GeometryRenderer&>(GeometryRenderer());
	return *this;
}

void GeometryRenderer::draw() const {
	glBindVertexArray(VAO);
	if (EBO) glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
	else glDrawArrays(GL_TRIANGLES, 0,count);
	glBindVertexArray(0);
}

void GeometryRenderer::freeResources() {
	// tambien debo liberar los recursos de la tangente y la bitangente
	if (VAO==0) return;
	if (VBO_pos) glDeleteBuffers(1,&VBO_pos);
	if (VBO_norms) glDeleteBuffers(1,&VBO_norms);
	if (VBO_tangents) glDeleteBuffers(1,&VBO_tangents);
	if (VBO_bi_tangents) glDeleteBuffers(1,&VBO_bi_tangents);
	if (VBO_tcs) glDeleteBuffers(1,&VBO_tcs);
	if (EBO) glDeleteBuffers(1,&EBO);
	glDeleteVertexArrays(1,&VAO);
}
GeometryRenderer::~GeometryRenderer() {
	freeResources();
}

void GeometryRenderer::updateTexCoords (const std::vector<glm::vec2> &vtc, bool realloc, bool dynamic) {
	updateBuffer(GL_ARRAY_BUFFER, VBO_tcs,vtc,realloc,dynamic);
}

void GeometryRenderer::updatePositions (const std::vector<glm::vec3> &vp, bool realloc, bool dynamic) {
	updateBuffer(GL_ARRAY_BUFFER, VBO_pos,vp,realloc,dynamic);
}

void GeometryRenderer::updateNormals (const std::vector<glm::vec3> &vn, bool realloc, bool dynamic) {
	updateBuffer(GL_ARRAY_BUFFER, VBO_norms,vn,realloc,dynamic);
}

// Acá implemento los updates de tangente y bitangente
void GeometryRenderer::updateTangents (const std::vector<glm::vec3> &vn, bool realloc, bool dynamic) {
	updateBuffer(GL_ARRAY_BUFFER, VBO_tangents,vn,realloc,dynamic);
}

void GeometryRenderer::updateBiTangents (const std::vector<glm::vec3> &vn, bool realloc, bool dynamic) {
	updateBuffer(GL_ARRAY_BUFFER, VBO_bi_tangents,vn,realloc,dynamic);
}

void GeometryRenderer::updateElements(const std::vector<int> &ve, bool realloc, bool dynamic) {
	updateBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO,ve,realloc,dynamic);
}

void Geometry::generateNormals(){
	normals.clear();
	normals.resize(positions.size());
	if (triangles.empty()) {
		for(size_t i=0;i<positions.size();i+=3)
			normals[i] = normals[i+1] = normals[i+2] = 
				glm::normalize(
					glm::cross(
						(positions[i+2]-positions[i+1]),
						(positions[i+0]-positions[i+1]) ) );
	} else {
		for(size_t i=0;i<triangles.size();i+=3) {
			auto n = glm::cross( (positions[triangles[i+2]]-positions[triangles[i+1]]),
								 (positions[triangles[i+0]]-positions[triangles[i+1]]) );
			normals[triangles[i+0]] += n;
			normals[triangles[i+1]] += n;
			normals[triangles[i+2]] += n;
		}
		for(auto &n : normals) 
			if (glm::dot(n,n)!=0) 
				n = glm::normalize(n);
	}	
}

// Acá se debe calcular el vector tangente. 
void Geometry::generateTangents(){
	tangents.clear();
	tangents.resize(positions.size());
	if (triangles.empty()) {
		for(size_t i=0;i<positions.size();i+=3){
			tangents[i] =
				glm::normalize(		
				// para calcular la tangente hago el punto i+1 menos el punto i
				(positions[i+1]-positions[i+0]) 
			) ;
			tangents[i+1] = 
				glm::normalize(		
					// para calcular la tangente hago el punto i+1 menos el punto i
					(positions[i+2]-positions[i+1]) 
				) ;
			tangents[i+2] = glm::normalize(		
				// para calcular la tangente hago el punto i+1 menos el punto i
				(positions[i+0]-positions[i+2]) 
			) ;
		}
	} else {
		for(size_t i=0;i<triangles.size();i+=3) {
		
			tangents[triangles[i+0]] += glm::normalize((positions[triangles[i+1]]-positions[triangles[i+0]]));
			tangents[triangles[i+1]] += glm::normalize((positions[triangles[i+2]]-positions[triangles[i+1]]));
			tangents[triangles[i+2]] += glm::normalize((positions[triangles[i+0]]-positions[triangles[i+2]]));
		}
	}	
}

void Geometry::generateBiTangents(){}
