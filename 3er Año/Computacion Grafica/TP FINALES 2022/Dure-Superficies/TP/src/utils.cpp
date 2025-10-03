#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "utils.hpp"
#include "Debug.hpp"

BoundingBox::BoundingBox(glm::vec3 &p1, glm::vec3 &p2) 
	: pmin({std::min(p1.x,p2.x),std::min(p1.y,p2.y),std::min(p1.z,p2.z)}),
	pmax({std::max(p1.x,p2.x),std::max(p1.y,p2.y),std::max(p1.z,p2.z)}) 
{
	
}

bool BoundingBox::contiene(glm::vec3 &p) const {
	return p.x>=pmin.x && p.x<=pmax.x &&
		p.y>=pmin.y && p.y<=pmax.y &&
		p.z>=pmin.z && p.z<=pmax.z;
}

Pesos calcularPesos(glm::vec3 x0, glm::vec3 x1, glm::vec3 x2, glm::vec3 &x) {
	/// @todo: implementar
	//cg_error("debe implementar la funcion calcularPesos (utils.cpp)");
	glm::vec3 areaT = cross((x1 - x0), (x2 - x0));
	
	glm::vec3 area1 = cross((x1 - x), (x2 - x));
	glm::vec3 area2 = cross((x2 - x), (x0 - x));
	glm::vec3 area3 = cross((x0 - x), (x1 - x));
	
	/*
	std::cout << "Peso1: " << (dot(area1, areaT))/(dot(areaT, areaT)) << "\n";
	std::cout << "Peso2: " << (dot(area2, areaT))/(dot(areaT, areaT)) << "\n";
	std::cout << "Peso3: " << (dot(area3, areaT))/(dot(areaT, areaT)) << "\n";
	*/
	
	return {(dot(area1, areaT))/(dot(areaT, areaT)), (dot(area2, areaT))/(dot(areaT, areaT)), (dot(area3, areaT))/(dot(areaT, areaT))};
}
