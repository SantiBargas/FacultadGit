#include <iostream>
#include <fstream>
#include "SubDivMesh.hpp"
#include "Debug.hpp"
#include "Delaunay.hpp"

SubDivMesh::SubDivMesh(const std::string &fname, Delaunay &delaunay, glm::vec3 &minMaxZ, glm::vec2 &minMaxY, glm::vec2 &minMaxX) {
	e.clear(); 
	n.clear();
	
	//Puntos cargados del archivo
	std::vector<glm::vec3> points;
	
	//Maximos y minimos
	float minZ = 9999999999.f;
	float maxZ = -9999999999.f;
	
	float minY = 9999999999.f;
	float maxY = -9999999999.f;
	
	float minX = 9999999999.f;
	float maxX = -9999999999.f;

	std::ifstream f(fname);
	if (!f.is_open()) return;
	int nv;
	f>>nv;
	float x,y,z;
	
	//cargo los puntos del archivo
	for (int i=0;i<nv;i++) {
		f>>x>>y>>z;
		
		points.push_back(glm::vec3{x,y,z});
		
		if(z > maxZ){
			maxZ = z;
		} else if (z < minZ){
			minZ = z;
		}
		
		if(y > maxY){
			maxY = y;
		} else if (y < minY){
			minY = y;
		}
		
		if(x > maxX){
			maxX = x;
		} else if (x < minX){
			minX = x;
		}
	}
	
	//Bounding Box para Delaunay
	glm::vec3 P0 = glm::vec3(minX-1, minY-1, 0.f);
	glm::vec3 P1 = glm::vec3(maxX+1, minY-1, 0.f);
	glm::vec3 P2 = glm::vec3(maxX+1, maxY+1, 0.f);
	glm::vec3 P3 = glm::vec3(minX-1, maxY+1, 0.f);
	
	delaunay = Delaunay(P0, P1, P2, P3);
	
	minMaxZ = glm::vec3(minZ, maxZ, 0.f);
	minMaxY = glm::vec2(minY, maxY);
	minMaxX = glm::vec2(minX, maxX);
	
	//inserto los puntos
	for (int i=0;i<points.size();i++) {
		n.push_back(points[i]);
	
		delaunay.agregarPunto(glm::vec3(points[i][0],points[i][1],0));
	}

	
	//genero los triangulos segun los genera delaunay
	auto &triangulos = delaunay.getTriangulos();
	
	for(int i = 0; i < triangulos.size(); i++){
		const std::vector<glm::vec3> &points = delaunay.getPuntos();
		
		int index0 = triangulos[i][0];
		int index1 = triangulos[i][1];
		int index2 = triangulos[i][2];
		
		if(points[index0] != P0 && points[index1] != P0 && points[index2] != P0 && 
		   points[index0] != P1 && points[index1] != P1 && points[index2] != P1 &&
		   points[index0] != P2 && points[index1] != P2 && points[index2] != P2 &&
		   points[index0] != P3 && points[index1] != P3 && points[index2] != P3){
			agregarElemento(index0 - 4, index1 -4, index2- 4);
		}
		
	}

	f.close();
	makeVecinos();
}

void SubDivMesh::agregarElemento(int n0, int n1, int n2, int n3) {

	int ie=e.size(); e.push_back(Elemento(n0,n1,n2,n3)); // agrega el Elemento
	// avisa a cada nodo que ahora es vertice de este elemento
	n[n0].e.push_back(ie); 
	n[n1].e.push_back(ie);
	n[n2].e.push_back(ie); 
	if (n3>=0) {
		n[n3].e.push_back(ie);
	};
	
}

void SubDivMesh::reemplazarElemento(int ie, int n0, int n1, int n2, int n3) {
	Elemento &ei=e[ie];
	// estos nodos ya no seran vertices de este elemento
	for (int i=0;i<ei.nv;i++) {
		std::vector<int> &ve=n[ei[i]].e;
		ve.erase(find(ve.begin(),ve.end(),ie));
	}
	ei.SetNodos(n0,n1,n2,n3);
	// estos nodos ahora son vertices
	n[n0].e.push_back(ie); n[n1].e.push_back(ie); n[n2].e.push_back(ie); 
	if (n3>=0) n[n3].e.push_back(ie); 
}

// Identifica los pares de elementos vecinos y las aristas de frontera
// Actualiza el atributo v (lista de vecinos) de cada elemento y el atributo es_frontera de cada nodo
void SubDivMesh::makeVecinos() {
	// inicializa
	for (size_t i=0;i<n.size();i++) n[i].es_frontera=false; // le dice a todos los nodos que son frontera
	for (size_t i=0;i<e.size();i++) e[i].v[0]=e[i].v[1]=e[i].v[2]=e[i].v[3]=-1; // le dice a todos los elementos que no tienen vecinos
	// identificacion de vecinos
	for (size_t ie=0;ie<e.size();ie++) { // por cada elemento
		for (int j=0;j<e[ie].nv;j++) { // por cada arista
			if (e[ie].v[j]>=0) continue; // ya se hizo
			int in0=e[ie][j], in1=e[ie][j+1]; // 1er y 2do nodo de la arista
			bool arista_frontera = true;
			for (size_t k=0;k<n[in0].e.size();k++) { // recorro los elementos del primer nodo
				int iev=n[in0].e[k];
				if (iev==ie) continue; // es este mismo
				// se fija si tiene a in1 (el 2do nodo)
				int ix=e[iev].Indice(in1);
				if (ix<0) continue; 
				// tiene al 2do
				e[ie].v[j]=n[in0].e[k]; // ese es el vecino
				e[iev].v[ix]=ie;
				arista_frontera = false;
				break; // solo dos posibles vecinos para una arista
			}
			if (arista_frontera) 
				n[in0].es_frontera = n[in1].es_frontera = true;
		}
	}
}
