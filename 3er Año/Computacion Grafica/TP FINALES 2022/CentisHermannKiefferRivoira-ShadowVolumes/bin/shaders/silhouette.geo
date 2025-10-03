#version 330

layout (triangles_adjacency) in;
layout (line_strip, max_vertices = 6) out;

in vec4 lPos[];
in vec3 vPos[];

void EmitLine(int i_comienzo, int i_final) {
	gl_Position = gl_in[i_comienzo].gl_Position;
    EmitVertex();

    gl_Position = gl_in[i_final].gl_Position;
    EmitVertex();

    EndPrimitive();
}

void main() {
	vec3 e0 = normalize(vPos[2] - vPos[0]);
	vec3 e2 = normalize(vPos[4] - vPos[2]);
	vec3 e4 = normalize(vPos[0] - vPos[4]);
	
	vec3 e1 = normalize(vPos[1] - vPos[0]);
	vec3 e3 = normalize(vPos[3] - vPos[2]);
	vec3 e5 = normalize(vPos[5] - vPos[4]);
	
	vec3 normal_original = cross(e2,e0);
	vec3 normal_adj_derecha = cross(e0,e1);
	vec3 normal_adj_izquierda = cross(e4,e5);
	vec3 normal_adj_arriba = cross(e2,e3);
	
	vec3 direccion_luz = normalize(vPos[0] * lPos[0].w - lPos[0].xyz);
	if (dot(direccion_luz,normal_original) > 0) {
		if (dot(direccion_luz,normal_adj_derecha) <= 0) {
			EmitLine(2,0);
		}
	}
	
	direccion_luz = normalize(vPos[2] * lPos[0].w - lPos[0].xyz);
	if (dot(direccion_luz,normal_original) > 0) {
		if (dot(direccion_luz,normal_adj_arriba) <= 0) {
			EmitLine(4,2);
		}
	}
	
	direccion_luz = normalize(vPos[4] * lPos[0].w - lPos[0].xyz);
	if (dot(direccion_luz,normal_original) > 0) {
		if (dot(direccion_luz,normal_adj_izquierda) <= 0) {
			EmitLine(0,4);
		}
	}
}
