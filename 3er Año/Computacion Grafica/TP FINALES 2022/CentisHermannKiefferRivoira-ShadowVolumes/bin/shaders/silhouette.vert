#version 330

in vec3 vertexPosition;
in vec3 vertexNormal;

uniform mat4 objectMatrix;
uniform mat4 cameraMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

uniform vec4 lightPosition;

out vec4 lPos;
out vec3 vPos;

void main() {
	mat4 modelMatrix = cameraMatrix * objectMatrix;
	lPos = lightPosition;
	vec4 pos = objectMatrix * vec4(vertexPosition, 1.0);
	gl_Position = projectionMatrix * viewMatrix * cameraMatrix * pos;
	vPos = pos.xyz/pos.w;
} 
