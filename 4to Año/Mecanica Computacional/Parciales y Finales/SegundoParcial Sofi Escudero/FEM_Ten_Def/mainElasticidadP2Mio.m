close all; clear all; more off;

xnode = [
  0,0;
  1,0;
  0.25,0.25;
  1,0.25;
  0.5,0.5;
  1,0.5;
  0.5,1;
  0.75,1;
  1,1;
];

icone = [
  2,4,3,1;#e1
  4,6,5,3;#e2
  5,8,7,-1;#e3
  6,8,5,-1;#e4
  6,9,8,-1;#e5
];

#La represa se encuentra fijada sobre su base
  #nodos 1 y 2 empotrados
#Nodos empotrados
#numero de nodo, direccion (1->x,2->y), 0 #(0 si empotrado)
Fixnodes = [
 1, 1,0;
 1, 2,0;
 2, 1,0;
 2, 2,0;
];
#Fuerza superficial (agua) distribuida linealmente
  #Fuerzas nodales resultantes:
    #Fs2x = -150000
    #Fs4x = -82500
    #Fs0x = -10000

#Carga lateral
#nodo1,nodo2 (nodos que conforman la arista), Fx, Fy
Sideload = [
2,4,-150000,0;
4,6,-150000,0;
];

#cargas puntuales (si cae encima de un nodo el programa lo asigna a un elemento que lo contenga)
#numElemento, Fx, Fy, coorX, coorY
Pointload = [

];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.young = 210e5;
model.poiss = 0.3;
#Se lo considera como fuerza rho*g
#Fuerza volumetrica F_y=-3000
model.gravity = 3000;
model.pstrs = 2; #1: tensión plana, 2: deformación plana
model.thick = 1; #espesor

disp('Iniciando el método numérico...');

% Llamada principal al Método de Elementos Finitos
[U,reaction,Def,Ten,Ten_VM] = fem2d_pstr(xnode,icone,Fixnodes,Sideload,Pointload,model);

disp('Finalizada la ejecución del método numérico.');

disp('---------------------------------------------------------------');
disp('Iniciando el post-procesamiento...');

% mode ---> modo de visualización:
%           [0] 2D - Con malla
%           [1] 2D - Sin malla
% graph --> tipo de gráfica:
%           [0] Estado inicial vs. desplazamiento
%           [1] Von Misses (escalar)
%           [2] Reacciones (vectorial)
% scale --> factor de escala para U (en veces)
mode = 0;
graph = 0;
scale = 1;#Escalar desplazamientos para graficarlos más claramente
U = scale * U;
fem2d_pstr_graph_mesh(U,reaction,Ten_VM,xnode,icone,mode,graph);

disp('Finalizado el post-procesamiento.');

