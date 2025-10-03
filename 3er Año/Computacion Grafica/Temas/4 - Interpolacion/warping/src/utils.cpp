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
	
	/// x= a0 x0 + a1 x1 + a2 x2
	/// a0 = (area0 areaT) / (areaT areaT)
	
	/// areaT = (x1 - x0) x (x2 - x0)
	glm::vec3 areaT = glm::cross(x2-x1,x0-x1); //AREA TOTAL DEL TRIANGULO, haciendo un producto cruz con la resta del punto x2-x1 y x0-x1, no hace falta dividir por dos
												//ya que luego al dividir para encontrar los pesos se cancelan
												
	
	/// area0 = (x2 - x1) x (x - x1)
	glm::vec3 area0 = glm::cross(x2-x1,x-x1); //Area para el punto x0,obteniendo de la resta del punto x2-x1 y x-x1 (vectores)
	
	/// area1 = ...
	glm::vec3 area1 = glm::cross(x0-x2,x-x2); //Area para el punto x1,obteniendo de la resta del punto x0-21 y x-x2 (vectores)
	
	/// area2 = ...
	glm::vec3 area2 = glm::cross(x1-x0,x-x0); //Area para el punto x2,obteniendo de la resta del punto x1-x0 y x-01 (vectores)
	
	//CALCULO DE LOS PESOS: Division de producto puntos entre el area0,areatotal y el area total
	
	
	//PRODUCTO PUNTO PARA SABER DE QUE LADO ESTA 
	float w0 = (glm::dot(area0,areaT))/(glm::dot(areaT,areaT));  
	float w1 = (glm::dot(area1,areaT))/(glm::dot(areaT,areaT));
	float w2 = (glm::dot(area2,areaT))/(glm::dot(areaT,areaT));
	
	return {w0,w1,w2};
}
