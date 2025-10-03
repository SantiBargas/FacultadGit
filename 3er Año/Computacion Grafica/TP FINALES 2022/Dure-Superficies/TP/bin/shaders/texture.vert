#version 330 core

in vec3 vertexPosition;
in vec3 vertexNormal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform vec4 lightPosition;
uniform vec3 minmax;

out vec3 fragPosition;
out vec3 fragNormal;
out vec2 fragTexCoords;
out vec4 lightVSPosition;

vec2 textureCoord(vec3 vertexPosition);

void main() {
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(vertexPosition,1.f);
	fragPosition = vec3(viewMatrix * modelMatrix * vec4(vertexPosition,1.f));
	fragNormal = mat3(transpose(inverse(viewMatrix*modelMatrix))) * vertexNormal;
	lightVSPosition = viewMatrix * lightPosition;
	
	fragTexCoords = textureCoord(vertexPosition);
}

vec2 textureCoord(vec3 vertexPosition){
	vec2 coord;
	
	float z = vertexPosition[2];
	float min = minmax[0];
	float max = minmax[1];

	if(z >= 0){
		coord[0] = (1.f - (z/max))*0.25f + (z/max)*0.99f;
		coord[1] = 0.5f;
	} else {
		coord[0] = (1-(z/min))*0.25f + (z/min)*0.f;
		coord[1] = 0.5f;
	}
	
	return coord;
}
