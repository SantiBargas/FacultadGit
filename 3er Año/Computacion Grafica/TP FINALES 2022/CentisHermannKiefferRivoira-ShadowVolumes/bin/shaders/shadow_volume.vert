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
out mat4 vp;

void main() {
	lPos = lightPosition;
	vec4 worldPos = objectMatrix * vec4(vertexPosition,1.0);
	vPos = (worldPos.xyz)/worldPos.w;
	vp = projectionMatrix * viewMatrix * cameraMatrix;
} 
