# version 330 core

in vec3 fragNormal;
in vec3 fragPosition;
in vec4 lightVSPosition;

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
vec3 color;

void calcularColor( float intensidad){
	color=ambientColor;
	color+= diffuseColor * intensidad;
}
void main() {
	vec3 lightDir = normalize(vec3(lightVSPosition));
	float intensidad =  max(0.0, dot(normalize(fragNormal), lightDir));
	calcularColor(intensidad);
	vec3 aux=vec3(color);
	vec3 viewDir = normalize(-fragPosition);
	float silueta = max(0.0,dot(normalize(fragNormal),viewDir));
	if (silueta <= 0.2) {aux = vec3(0,0,0);}
	if (intensidad>=0.97 ){aux*=shininess;}
	if (intensidad>0.2 && intensidad<0.97){color =aux*0.7;}
	else {color=aux *0.3;}	
	fragColor=vec4(color,1.f);
}
