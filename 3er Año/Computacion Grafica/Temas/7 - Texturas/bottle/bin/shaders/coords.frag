# version 330 core

in vec3 fragNormal;
in vec3 fragPosition;
in vec2 fragTexCoords;
in vec4 lightVSPosition;

// propiedades del material
uniform sampler2D colorTexture;
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
	float s_tex = fragTexCoords.x;
	float t_tex = fragTexCoords.y;
	float b_tex = 0.f;
	float a_tex = 1.f;
	if (t_tex < 0.f){
		//s_tex = 1.f;
		//t_tex = 1.f;
		//b_tex = 1.f;
		//a_tex = 0.5f;
	}
	if (t_tex > 1.f){
		//s_tex = 1.f;
		//t_tex = 1.f;
		//b_tex = 1.f;
		//a_tex = 0.5f;
	}
	
	///el negro es 0 el rojo es 1
	
	vec4 tex = {s_tex-floor(s_tex),t_tex,b_tex,a_tex};
	fragColor = tex;
}

