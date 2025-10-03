#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <vector>
#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

struct Geometry {
	// posiciones
	// En posiciones tenes las posiciones de los vértices del triángulo
	std::vector<glm::vec3> positions;
	// normales
	std::vector<glm::vec3> normals;
	// coordenadas de textura
	std::vector<glm::vec2> tex_coords;
	// Tangente	
	std::vector<glm::vec3> tangents;
	// Bitangente	
	std::vector<glm::vec3> bi_tangents;
		
	std::vector<int> triangles;
	
	void generateNormals();
	
	// Declaro el método para calcular la tangente
	void generateTangents();
	void generateBiTangents();
};

class GeometryRenderer {
public:
	GeometryRenderer() = default;
	GeometryRenderer(const Geometry &geo, bool dynamic=false);
	GeometryRenderer(GeometryRenderer &&geo);
	GeometryRenderer &operator=(GeometryRenderer &&geo);
	void draw() const;
	
	// Acá agrego los VAO tangente y bitangente
	GLuint vertexArray() const { return VAO; }
	GLuint positionsVBO() const { return VBO_pos; }
	GLuint normalsVBO() const { return VBO_norms; }
	GLuint texCoordsVBO() const { return VBO_tcs; }
	GLuint tangentsVBO() const { return VBO_tangents; }
	GLuint bi_tangentsVBO() const { return VBO_bi_tangents; }
	
	// Creo el update para tangente y bitangente
	void updateTexCoords(const std::vector<glm::vec2> &vtc, bool realloc=false, bool dynamic=false);
	void updatePositions(const std::vector<glm::vec3> &vp, bool realloc=false, bool dynamic=false);
	void updateNormals(const std::vector<glm::vec3> &vn, bool realloc=false, bool dynamic=false);
	void updateTangents(const std::vector<glm::vec3> &vn, bool realloc=false, bool dynamic=false);
	void updateBiTangents(const std::vector<glm::vec3> &vn, bool realloc=false, bool dynamic=false);
	void updateElements(const std::vector<int> &ve, bool realloc=false, bool dynamic=false);
	
	~GeometryRenderer();
	
private:
	GeometryRenderer(const GeometryRenderer &) = delete;
	GeometryRenderer &operator=(const GeometryRenderer &) = default;
	void freeResources();
	
	// identificadores de textura
	// add 1 identificador VBO para tangente y otro para bitrangente
	GLuint VAO=0, VBO_pos=0, VBO_tcs=0, VBO_norms=0, EBO=0, VBO_tangents=0, VBO_bi_tangents=0;
	int count = 0;
};

#endif

