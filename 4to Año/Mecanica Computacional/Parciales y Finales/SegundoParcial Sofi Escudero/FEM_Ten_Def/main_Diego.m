close all; clear all; more off; clc;

xnode = [
  -0.60, 0.00;
  0.00, 0.00;
  0.6, 0.00;
  -0.45, 0.30;
  0.0, 0.30;
  0.45, 0.30;
  -0.3, 0.60;
  0.0, 0.60;
  0.3, 0.60;
];

icone = [
       1,2,5,-1;
       2,3,6,5;
       5,6,9,-1;
       5,9,8,-1;
       4,5,8,7;
       1,5,4,-1;


];

Fixnodes = [
       1,      1, 0.00;
       1,      2, 0.00;
       3,      2, 0.00;
];

Sideload = [
7,8,127.5,322.5;
8,9,-127.5,277.5;
];

# En la definición de la fuente puntual, cualquiera de los elementos que tocan
# los nodos con dichas fuerzas pueden ser utilizados, pero solo debe asociarse
# cada fuerza puntual a un único elemento. En este caso se considera que la
# fuerza puntual sobre el nodo 2 está en el elemento 1 (no hay otra opción) y
# las fuerzas puntuales de los nodos 4 y 6 están en el elemento 2
Pointload = [
];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.young = 2.1e8;
model.poiss = 0.28;
model.gravity = 9.81*7850.00;
model.pstrs = 1;
model.thick = 0.1;

disp('Iniciando el método numérico...');

% Llamada principal al Método de Elementos Finitos
[U,reaction,Def,Ten,Ten_VM] = fem2d_pstr(xnode,icone,Fixnodes,Sideload,Pointload,model);
U_res = full(U)*1000

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
scale = 1;
U = scale * U;
fem2d_pstr_graph_mesh(U,reaction,Ten_VM,xnode,icone,mode,graph);

disp('Finalizado el post-procesamiento.');
