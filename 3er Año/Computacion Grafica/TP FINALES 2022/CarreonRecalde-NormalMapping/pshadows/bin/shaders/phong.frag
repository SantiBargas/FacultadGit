# version 330 core

in vec3 fragNormal;
in vec3 fragPosition;
in vec4 lightVSPosition;
in vec3 normal; // obtengo la normal-trucha del texture_shader

// propiedades del material

uniform vec3 ambientColor;
uniform vec3 specularColor;
uniform vec3 diffuseColor;
uniform vec3 emissionColor;
uniform float opacity;
uniform float shininess;

// propiedades de la luz
uniform float ambientStrength;
uniform vec3 lightColor;

out vec4 fragColor;

#include "funcs/calcPhong.frag"

void main() {
	
	vec3 phong = calcPhong(lightVSPosition, lightColor,
						   ambientColor, diffuseColor, specularColor, shininess,normal);
	fragColor = vec4(phong+emissionColor,opacity);
}
