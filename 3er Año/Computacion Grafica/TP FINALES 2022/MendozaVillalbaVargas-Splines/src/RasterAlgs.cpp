#include <forward_list>
#include <iostream>
#include <GL/gl.h>
#include <cmath>
#include "RasterAlgs.hpp"


#include <array>
#include <vector>
using namespace std;
float redonn(float x) { return int(x)+.5f; }

//{ "-----", "-- --", "- - -","-  -"};
std::vector<bool>  patron1={true,true,true,true,true};
std::vector<bool>  patron2={true,true,false,true,true,false};
std::vector<bool>  patron3={true,false,true,false};
std::vector<bool>  patron4={true,false,false,true};
std::vector<int> tamanoPatron={5,6,4,4,0};


void drawSegment(paintPixelFunction paintPixel, glm::vec2 p0, glm::vec2 p1) {
	
	/// @todo: implementar algun algoritmo de rasterizacion de segmentos 
	
	int nx = std::abs(p1.x-p0.x); // Crecimiento en x
	int ny = std::abs(p1.y-p0.y); // Crecimiento en y
	int n = std::max(nx,ny); // Defino la tendencia.
	float dy = (p1.y - p0.y)/n;
	float dx = (p1.x - p0.x)/n;
	
	if (nx > ny){ // Tendencia HORIZONTAL ========
		
			
		if ( dx > 0 ) // crece a la derecha (1er y 4to cuadrante)
			for (float x=p0.x, y=p0.y; x<=p1.x; x++){
				y+=dy;
				glm::vec2 punto(x,y);
				paintPixel(punto);
		}
		else // Crece a la izq (2do y 3er cuadrante)
				for (float x=p0.x, y=p0.y; x>=p1.x; x--){
					y+=dy;
					glm::vec2 punto(x,y);
					paintPixel(punto);
			}
	} else { // TENDENCIA VERTICAL ========
		if ( dy > 0 ) // crece para arriba(1er y 2do cuadrante)
			for (float x=p0.x, y=p0.y; y<=p1.y; y++){
				x+=dx;
				glm::vec2 punto(x,y);
				paintPixel(punto);
		}
		else // Crece a la izq (3er y 4to cuadrante)
				for (float x=p0.x, y=p0.y; y>=p1.y; y--){
					x+=dx;
					glm::vec2 punto(x,y);
					paintPixel(punto);
			}
	}   
	glEnd();
}



void dibujaGrosor(paintPixelFunction paintPixel,glm::vec2 punto,auto p,int grosor){
	glm::vec2 puntoGrosor1=punto;
	glm::vec2 puntoGrosor2=punto;
	float norma=sqrt(p.d.x*p.d.x+p.d.y*p.d.y);///norma
	float dxxx=p.d.x/norma;
	float dyyy=p.d.y/norma;
	for(int i=1;i<grosor;i++){
		
		if(i%2!=0){///si es inpar, pinto por encima
			puntoGrosor1.x=puntoGrosor1.x-dyyy;
			puntoGrosor1.y=puntoGrosor1.y+dxxx;
			paintPixel(puntoGrosor1);
		}else{///si es par, pinto por abajo
			puntoGrosor2.x=puntoGrosor2.x+dyyy;
			puntoGrosor2.y=puntoGrosor2.y-dxxx;
			paintPixel(puntoGrosor2);
		}
		
	}
	
}


void drawCurve(paintPixelFunction paintPixel, curveEvalFunction evalCurve, int &contadorPixelCurva,int currentTipoLinea,int cantidadPtosInter, char texto[],bool is_close,int grosor) {
	/// @todo: implementar algun algoritmo de rasterizacion de curvas
	float t0, t1 ;//para que no me pinte de fin a inicio
	float t,x,y,dx,dy,dt,xaux,yaux;
	
	/// Verifico si la curva se cierra o no
	
	if(!is_close){
		t0=0;
		t1=1-(float)1/(cantidadPtosInter) ;//para que no me pinte de fin a inicio
		t=t0;x;y;dx;dy;dt;xaux=0;yaux=0;
	}else{
		t0=0; t1=1 ;//para que no me pinte de fin a inicio
		t=t0;x;y;dx;dy;dt;xaux=0;yaux=0;
	}
	///para poner el tamaño de custom
	int contador=0;
	for(int i=0;i<10;i++){
		if(texto[i]=='0' ||texto[i]=='1' )
			contador++;
		else
			break;
	}
	tamanoPatron[4]=contador;
//	cout<<tamanoPatron[4]<<endl;
	
	
	
	do{
		auto p = evalCurve(t);//evaluo la curva en el "tiempo" t
		dx = p.d.x; //saco las derivadas
		dy = p.d.y;
		dt = 1/max(fabs(dx), fabs(dy)); // determino el paso del parametro t mediante el maximo de las derivadas
		float tNext = t+dt;     //busco cual es el siguiente paso
		auto pNext=evalCurve(tNext);//pido el siguiente punto
		
		int Ex=abs(redonn(pNext.p.x)-redonn(p.p.x));//calculo la diferencia entre el punto actual y el siguiente
		int Ey=abs(redonn(pNext.p.y)-redonn(p.p.y));
		
		while(Ex>1 or Ey>1){ // Para evitar discontinuidades 
			//reduzco t por la mita de su crecimiento para garantizar 
			//que no halla saltos de mas de 1 pixel
			dt=dt/2;
			tNext = t+dt;     //busco cual es el siguiente paso
			pNext=evalCurve(tNext);//pido el siguiente punto
			
			Ex=abs(redonn(pNext.p.x)-redonn(p.p.x));//calculo la diferencia entre el punto actual y el siguiente
			Ey=abs(redonn(pNext.p.y)-redonn(p.p.y));
		}
		
		if((Ex>0 || Ey>0) && grosor>0  ){ // Para evitar que pinte 2 veces el mismo pixel
			//aumento t para la siguiente iteracion
			t+=dt;
			glm::vec2 punto(redonn(p.p.x),redonn(p.p.y));
			
			
			
			
			switch(currentTipoLinea){
			case 0:
				if(patron1[contadorPixelCurva]){
					paintPixel(punto);
					if(grosor>1){///grosor de curva
						dibujaGrosor(paintPixel,punto,p,grosor);
					}
					
				}
				
				contadorPixelCurva=contadorPixelCurva+1;
				if(contadorPixelCurva>=tamanoPatron[0])
					contadorPixelCurva=0;
				break;
				
			case 1:
				if(patron2[contadorPixelCurva]){
					paintPixel(punto);
					if(grosor>1){///grosor de curva
						dibujaGrosor(paintPixel,punto,p,grosor);
					}
				}
				contadorPixelCurva=contadorPixelCurva+1;
				if(contadorPixelCurva>=tamanoPatron[1])
					contadorPixelCurva=0;
				break;
				
			case 2:
				if(patron3[contadorPixelCurva]){
					paintPixel(punto);
					if(grosor>1){///grosor de curva
						dibujaGrosor(paintPixel,punto,p,grosor);
					}
				}
				contadorPixelCurva=contadorPixelCurva+1;
				if(contadorPixelCurva>=tamanoPatron[2])
					contadorPixelCurva=0;
				break;
				
			case 3:
				if(patron4[contadorPixelCurva]){
					paintPixel(punto);
					if(grosor>1){///grosor de curva
						dibujaGrosor(paintPixel,punto,p,grosor);
					}
				}
				contadorPixelCurva=contadorPixelCurva+1;
				if(contadorPixelCurva>=tamanoPatron[3])
					contadorPixelCurva=0;
				break;
			case 4:
				
				if(texto[contadorPixelCurva]=='1'){
					paintPixel(punto);
					if(grosor>1){///grosor de curva
						dibujaGrosor(paintPixel,punto,p,grosor);
					}
				}
				contadorPixelCurva=contadorPixelCurva+1;
				if(contadorPixelCurva>=tamanoPatron[4])
					contadorPixelCurva=0;
				
				break;
			default:
				paintPixel(punto);
				
			}
			
		}else{
			t+=dt;
		}
		
		
	} while(t<t1);
	
	glEnd();
}




