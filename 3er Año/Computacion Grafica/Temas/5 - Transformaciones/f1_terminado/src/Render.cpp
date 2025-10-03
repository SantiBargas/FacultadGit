#include <glm/ext.hpp>
#include "Render.hpp"
#include "Callbacks.hpp"

extern bool wireframe, play, top_view, use_helmet;

// matrices que definen la camara
glm::mat4 projection_matrix, view_matrix;

// funci�n para renderizar cada "parte" del auto
void renderPart(const Car &car, const std::vector<Model> &v_models, const glm::mat4 &matrix, Shader &shader) {
	// select a shader
	for(const Model &model : v_models) {
		shader.use();
		
		// matrixes
		if (play) {
			/// @todo: modificar una de estas matrices para mover todo el auto (todas
			///        las partes) a la posici�n (y orientaci�n) que le corresponde en la pista
			
			
			///POSICIONAMOS EL AUTO EN LA PISTA
			
			//multiplicar la matrix constante por otra
			float pos_x = car.x;
			float pos_z = car.y;
			float angulo = car.ang;
			
			///hacemos la traslacion en x de pos_x que es la posicion del auto y de z en pos_z que es la y del auto
			///guardamos el angulo del auto para ponerlo en la matriz
			
			///como rotamos en el eje y no tocamos el eje y, rotamos un angulo en x y un angulo en z

			glm::mat4 matrix2 =glm::mat4(cos(angulo),    0.f,        sin(angulo),   	0.0f,
										 0.f ,		     1.0f, 			0.0f, 			0.0f,
										 -sin(angulo),   0.f,           cos(angulo),    0.0f,
										 pos_x,          0.f,           pos_z,          1.0f);
			
			
			
			shader.setMatrixes(matrix2 * matrix, view_matrix , projection_matrix);
			
		
			///Multiplicamos matrix2 * matrix y no al reves pq la multiplicacion de matrices no es conmutativa
			
			///explicar porque si ponemos matrix delante solo se ve el chasis y no el auto completo
			///algo de efecto sobre las base
			
		} else {
			glm::mat4 model_matrix = glm::rotate(glm::mat4(1.f),view_angle,glm::vec3{1.f,0.f,0.f}) *
						             glm::rotate(glm::mat4(1.f),model_angle,glm::vec3{0.f,1.f,0.f}) *
			                         matrix;
			shader.setMatrixes(model_matrix,view_matrix,projection_matrix);
		}
		
		// setup light and material
		shader.setLight(glm::vec4{20.f,40.f,20.f,0.f}, glm::vec3{1.f,1.f,1.f}, 0.35f);
		shader.setMaterial(model.material);
		
		// send geometry
		shader.setBuffers(model.buffers);
		glPolygonMode(GL_FRONT_AND_BACK,(wireframe and (not play))?GL_LINE:GL_FILL);
		model.buffers.draw();
	}
}

// funci�n que renderiza la pista
void RenderTrack() {
	static Model track = Model::loadSingle("track",Model::fDontFit);
	static Shader shader("shaders/texture");
	shader.use();
	shader.setMatrixes(glm::mat4(1.f),view_matrix,projection_matrix);
	shader.setMaterial(track.material);
	shader.setBuffers(track.buffers);
	track.texture.bind();
	static float aniso = -1.0f;
	if (aniso<0) glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &aniso);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, aniso); 
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	track.buffers.draw();
}

// funci�n que actualiza las matrices que definen la c�mara
void setViewAndProjectionMatrixes(const Car &car) {
	projection_matrix = glm::perspective( glm::radians(view_fov), float(win_width)/float(win_height), 0.1f, 100.f );
	
	if (play) {
		if (top_view) {
			/// @todo: modificar el look at para que en esta vista el auto siempre apunte hacia arriba (modifico el vector de lookAt sen y cos)
			glm::vec3 pos_auto = {car.x, 0.f, car.y};
			
			///EL tercer argumento glm::vec3{cos(car.ang),0.f,sin(car.ang)} se utiliza para definir la direcci�n "arriba" 
			///de la c�mara en funci�n del �ngulo car.ang. Esto significa que la direcci�n "arriba" de la c�mara 
			///se encuentra en el plano XY y cambia seg�n la rotaci�n del objeto car en el plano XZ.
			///ANTES SE MANTENIA CONSTANTE Y APUNTABA SIN IMPORTAR LA ORIENTACION DEL AUTO
			
			view_matrix = glm::lookAt( pos_auto+glm::vec3{0.f,30.f,0.f}, pos_auto, glm::vec3{cos(car.ang),0.f,sin(car.ang)} );
		} else {
			/// @todo: definir view_matrix de modo que la camara persiga al auto desde "atras"
			glm::vec3 pos_auto = {car.x, 0.f, car.y};
				view_matrix = glm::lookAt( pos_auto+glm::vec3{cos(car.ang)*(-5.f),2.5,sin(car.ang)*(-5.f)}, 
									  ///posici�n de la c�mara, que est� ubicada a una distancia de 5 unidades detr�s del objeto car y 
									  ///elevada 2.5 unidades por encima de �l.
									  
									  pos_auto+glm::vec3{cos(car.ang)*(1.f),1.f,sin(car.ang)*(1.f)},
									  ///define el punto hacia el cual la c�mara est� mirando, que est� ubicado a 1 unidad delante del objeto 
									  ///Y a la misma altura.
									  glm::vec3{0.f,1.f,0.f});
			
		}
	} else {
		view_matrix = glm::lookAt( glm::vec3{0.f,0.f,3.f}, view_target, glm::vec3{0.f,1.f,0.f} );
	}

	
}

// funci�n que rendiriza todo el auto, parte por parte
void renderCar(const Car &car, const std::vector<Part> &parts, Shader &shader) {
	const Part &axis = parts[0], &body = parts[1], &wheel = parts[2],
	           &fwing = parts[3], &rwing = parts[4], &helmet = parts[use_helmet?5:6];

	/// @todo: armar la matriz de transformaci�n de cada parte para construir el auto
	
	if (body.show or play) {
		
		
		glm::mat4 transformationMatrix = glm::mat4(1.0f, 0.0f, 0.0f, 0.0f,
												   0.0f, 1.0f, 0.0f, 0.0f,
												   0.0f, 0.0f, 1.0f, 0.0f,
												   0.0f, 0.1f, 0.0f, 1.0f);
		///trasladamos 0.1 en el eje y y mantenemos su tama�o
		renderPart(car, body.models, transformationMatrix, shader);
		
	}
	
	if (wheel.show or play) {
	
		float y = -car.rang1; //como gira la rueda con respecto al eje x
		float x = -car.rang2; //como gira la rueda con respecto al eje z
		
		///RUEDA DE ATRAS
		
		///El ultimo factor 10.0f aplica una escala 10 veces mas peque�a del tama�o original
		glm::mat4 transformationMatrix1 = glm::mat4(cos(x), sin(x), 0.0f, 	0.0f,         ///como queremos que gire en el eje z modificamos los x e y
												   -sin(x), cos(x), 0.0f, 	0.0f,
												   -0.0f, 	-0.0f, 	-1.0f, 	-0.0f,
												   -9.f, 	1.f, 	3.f, 	10.0f);
			///la ultima fila traslada primero en x luego en y y luego en z, el ultimo elemento escala 
	
		renderPart(car, wheel.models, transformationMatrix1, shader);
		
		glm::mat4 transformationMatrix1_esp = glm::mat4(cos(x), sin(x), 0.0f, 	0.0f,     ///como queremos que gire en el eje z modificamos los x e y
														-sin(x),cos(x), 0.0f, 	0.0f,
														0.0f, 	0.0f, 	1.0f, 	0.0f,
														-9.f, 	1.f, 	-3.f, 	10.0f);
		///la ultima fila traslada primero en x luego en y y luego en z, el ultimo elemento escala 
		
		renderPart(car, wheel.models, transformationMatrix1_esp, shader);
		
		///RUEDA DE ADELANTE
		glm::mat4 transformationMatrix2 = glm::mat4(cos(x)*cos(y), 		sin(x), 	-sin(y)*cos(x), 	0.0f,  ///como queremos que gire en el eje y modificamos los x y z
													-cos(y)*sin(x), 	cos(x), 	sin(y)*sin(x), 		0.0f,
													-sin(y), 			0.f, 		-cos(y), 			0.0f,
													5.f, 				1.f, 		3.f, 				10.f);
		///la ultima fila traslada primero en x luego en y y luego en z, el ultimo elemento escala 
		renderPart(car, wheel.models, transformationMatrix2, shader);
		
		glm::mat4 transformationMatrix2_esp = glm::mat4(cos(x)*cos(y), 		sin(x), 	-sin(y)*cos(x), 	0.0f,   ///como queremos que gire en el eje y modificamos los x y z
														-cos(y)*sin(x), 	cos(x), 	sin(y)*sin(x), 		0.0f,
														sin(y), 			0.f, 		cos(y), 			0.0f,
														5.f, 				1.f, 		-3.f, 				10.f);
		///la ultima fila traslada primero en x luego en y y luego en z, el ultimo elemento escala 
		renderPart(car, wheel.models, transformationMatrix2_esp, shader);
	}
	
	if (fwing.show or play) {
		
		
		glm::mat4 transformationMatrix = glm::mat4(0.0f,  0.0f,  1.0f, 0.0f,
												   0.0f,  1.0f,  0.0f, 0.0f,
												   -1.0f, 0.0f,  0.0f, 0.0f,
												   2.6f,  0.15f, 0.0f, 3.0f);
		///la ultima fila traslada primero en x luego en y y luego en z, el ultimo elemento escala 
		///w=3 para escalar seria 0.3 cada componente 
		
		renderPart(car,fwing.models, transformationMatrix,shader);             
		
	}
	
	if (rwing.show or play) {
		float scl = 0.30f;
		
		/*glm::mat4 transformationMatrix = glm::translate(glm::rotate(glm::scale(glm::mat4(1.0f), glm::vec3(0.3f, 0.3f, 0.3f)), glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f)), glm::vec3(0.0f, 0.8f, 3.5f));
		///Escalado en 0.3 a la matriz de identidad         ///Rotacion de -90 grados en eje y                    ///Traslacion
		*/
		
		glm::mat4 transformationMatrix = glm::mat4(0.f, 0.0f, -1.0f, 0.0f,
												   0.f, 1.f, 0.0f, 0.0f,
												   -1.0f, 0.0f, 0.f, 0.f,
												   -3.2f, 0.7f, 0.f, 3.f);
		///la ultima fila traslada primero en x luego en y y luego en z, el ultimo elemento escala 
		renderPart(car,rwing.models, transformationMatrix,shader);
	}
	
	if (helmet.show or play) {
		
		glm::mat4 transformationMatrix = glm::mat4(0.f, 0.0f, 1.0f,0.0f,
												   0.f, 1.f, 0.0f, 0.0f,
												   -1.0f, 0.0f, 0.f, 0.f,
												   0.f, 2.f, 0.f, 10.f);
		///la ultima fila traslada primero en x luego en y y luego en z, el ultimo elemento escala 
		renderPart(car,helmet.models, transformationMatrix,shader);
	}
	
	if (axis.show and (not play)) renderPart(car,axis.models,glm::mat4(1.f),shader);
}
