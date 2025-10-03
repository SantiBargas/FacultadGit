#version 330 core

in vec3 vertexPosition;
in vec3 vertexNormal;
// Tangent and bitangent
in vec3 vertexTangents;
in vec3 vertexBiTangents;

in vec2 vertexTexCoords;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform vec4 lightPosition;

out vec3 fragPosition;
out vec3 fragNormal;
out vec2 fragTexCoords;
out vec4 lightVSPosition;

//out mat3 fragTBN;


void main() {
	mat4 vm = viewMatrix * modelMatrix;
	vec4 vmp = vm * vec4(vertexPosition,1.f);
	gl_Position = projectionMatrix * vmp;
	fragPosition = vec3(vmp);
	
	fragNormal = mat3(transpose(inverse(vm))) * vertexNormal;
	
	//vec3 T = normalize(vec3(vm * vec4(vertexTangents,   0.0)));
	//vec3 B = normalize(vec3(vm * vec4(vertexBiTangents, 0.0)));
	//vec3 N = normalize(vec3(vm * vec4(fagNormal,    0.0)));
	//mat3 fragTBN = mat3(T, B, N);
	
	
	lightVSPosition = vm * lightPosition;
	fragTexCoords = vertexTexCoords;
}
