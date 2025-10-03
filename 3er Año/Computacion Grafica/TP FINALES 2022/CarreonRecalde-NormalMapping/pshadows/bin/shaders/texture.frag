# version 330 core
precision mediump float;

in vec3 fragNormal;
in vec3 fragPosition;
in vec2 fragTexCoords;
in vec4 lightVSPosition;

uniform sampler2D myNormal; // obtengo la textura con normales
uniform sampler2D colorTexture; // obtengo la textura
uniform float bump;

// propiedades del material
uniform vec3 ambientColor;
uniform vec3 diffuseColor;
uniform vec3 specularColor;
uniform float shininess;
uniform float opacity;

// propiedades de la luz
uniform float ambientStrength;
uniform vec3 lightColor;

out vec4 fragColor;
out vec3 normal; //esta la retorno para usarla en phong

#include "funcs/calcPhong.frag"

void main() {
	// se transforma de [-1,1] a [0,1]
	// vec3 rgb_normal = normal * 0.5 + 0.5;
	
	// obtener normal del mapa normal en el rango [0,1]
	vec3 normal = texture(myNormal, fragTexCoords).rgb;
	// transformar vector normal a rango [-1,1]
	normal = normalize(normal * 2.0 - 1.0);
	
	if(bump < 1.f) { normal = fragNormal; }
	
	vec3 tex = texture(colorTexture,fragTexCoords).rgb;
	
	vec3 phong = calcPhong(lightVSPosition, lightColor,
						   mix(ambientColor,ambientColor*vec3(tex),1.f),
						   mix(diffuseColor,diffuseColor*vec3(tex),1.f),
						   specularColor, shininess,normal);
	fragColor = vec4(phong,opacity);
}

