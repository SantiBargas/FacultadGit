#ifndef MODEL_HPP
#define MODEL_HPP
#include <vector>
#include "Geometry.hpp"
#include "Material.hpp"
#include "Texture.hpp"
#include "Model.hpp"
#include "ObjMesh.hpp"


void centerAndResize(std::vector<glm::vec3> &v);

// auxiliar struct for loading all model-related data
struct Model {
	Geometry geometry;
	GeometryRenderer buffers;
	Material material;
	Texture texture;
	ObjMesh mesh;
	float angle=0.f;
	
	Model() = default;
	Model(const Geometry &g, const Material &m, ObjMesh mesh) 
		: buffers(g), material(m), 
		  texture(m.texture.empty() ? Texture() : Texture(m.texture)),
		  mesh(mesh)
	{
		
	}
	Model(Geometry &&g, const Material &m, ObjMesh mesh,bool keep_geometry=false) 
		: buffers(g), material(m), 
		  texture(m.texture.empty() ? Texture() : Texture(m.texture)),
			mesh(mesh)
	{
		if (keep_geometry) geometry = std::move(g);
	}
	
	enum Flags { fNone=0, fDontFit=1, fKeepGeometry=2, 
				 fRegenerateNormals=4, fDynamic=8, fNoTextures=16 };
	static std::vector<Model> load(const std::string &name, int flags = 0);
	static Model loadSingle(const std::string &name, int flags = 0);
};


#endif

