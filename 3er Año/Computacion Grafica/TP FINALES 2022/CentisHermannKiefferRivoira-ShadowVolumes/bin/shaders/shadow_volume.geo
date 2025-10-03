#version 330

layout (triangles_adjacency) in;
layout (triangle_strip, max_vertices = 18) out;

in vec4 lPos[];
in vec3 vPos[];
in mat4 vp[];

void EmitQuad(vec3 comienzo, vec3 final) {
	vec3 direccion_luz = normalize(comienzo * lPos[0].w - lPos[0].xyz);
	vec3 direccion_luz2 = normalize(final * lPos[0].w - lPos[0].xyz);
	
	// vertice uno: el comienzo un poquito en la direccion de la luz
	gl_Position = vp[0] * (vec4(comienzo - direccion_luz * 0.00015, 1.0));
    EmitVertex();
	// vertice dos: el comienzo en el infinito
	gl_Position = vp[0] * (vec4(direccion_luz,0.0));
    EmitVertex();
	
	// vertice cuatro: el final un poquito en la direccion de la luz
	gl_Position = vp[0] * (vec4(final - direccion_luz2 * 0.00015,1.0));
	EmitVertex();
	
	// vertice tres: el final en el infinito
	gl_Position = vp[0] * (vec4(direccion_luz2,0.0));
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
	if (dot(direccion_luz,normal_original) > 0.f) {
		if (dot(direccion_luz,normal_adj_derecha) <= 0.f) {
			EmitQuad(vPos[2],vPos[0]);
		}
		
		direccion_luz = normalize(vPos[2] * lPos[0].w - lPos[0].xyz);
		if (dot(direccion_luz,normal_adj_arriba) <= 0.f) {
			EmitQuad(vPos[4],vPos[2]);
		}
	
		direccion_luz = normalize(vPos[4] * lPos[0].w - lPos[0].xyz);
		if (dot(direccion_luz,normal_adj_izquierda) <= 0.f) {
			EmitQuad(vPos[0],vPos[4]);
		}
		
		direccion_luz = normalize(vPos[0] * lPos[0].w - lPos[0].xyz);
		gl_Position = vp[0] * vec4(vPos[0] + direccion_luz * 0.00015, 1.0);
		EmitVertex();
		
		direccion_luz = normalize(vPos[4] * lPos[0].w - lPos[0].xyz);
		gl_Position = vp[0] * vec4(vPos[4] + direccion_luz * 0.00015, 1.0);
		EmitVertex();
		
		
		direccion_luz = normalize(vPos[2] * lPos[0].w - lPos[0].xyz);
		gl_Position = vp[0] * vec4(vPos[2] + direccion_luz * 0.00015, 1.0);
		EmitVertex();
		EndPrimitive();
		
		direccion_luz = normalize(vPos[0] * lPos[0].w - lPos[0].xyz);
		gl_Position = vp[0] * vec4(direccion_luz,0.0);
		EmitVertex();
		
		direccion_luz = normalize(vPos[2] * lPos[0].w - lPos[0].xyz);
		gl_Position = vp[0] * vec4(direccion_luz,0.0);
		EmitVertex();
		
		direccion_luz = normalize(vPos[4] * lPos[0].w - lPos[0].xyz);
		gl_Position = vp[0] * vec4(direccion_luz,0.0);
		EmitVertex();
		EndPrimitive();
	}
}
