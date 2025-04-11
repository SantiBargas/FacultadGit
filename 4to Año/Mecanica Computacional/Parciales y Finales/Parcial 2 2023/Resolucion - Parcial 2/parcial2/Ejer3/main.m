close all; clear all; more off;

xnode = [
  0.00  0.00;
  0.60  0.00;
  1.20  0.00;
  0.15  0.30;
  0.60  0.30;
  1.05  0.30;
  0.30  0.60;
  0.60  0.60;
  0.90  0.60;
];
# xnode = xnode*100;

icone = [
       1,      2,      5,     -1;
       2,      3,      6,      5;
       5,      6,      9,     -1;
       5,      9,      8,     -1;
       4,      5,      8,      7;
       1,      5,      4,     -1;
];

Fixnodes = [
       1,      1,   0.00;
       1,      2,   0.00;
       3,      2,   0.00;
];

Sideload = [

];

Pointload = [
];

disp("---------------------------------------------------------------");
disp("Inicializando modelo de datos...");

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.young = 210000000.00;
model.poiss = 0.280;
model.gravity = 9.8*7850;
model.pstrs = 1;
model.thick = 0.10;

disp("Iniciando el método numérico...");

% Llamada principal al Método de Elementos Finitos
[U,reaction,Def,Ten,Ten_VM] = fem2d_pstr(xnode,icone,Fixnodes,Sideload,Pointload,model);

disp("Finalizada la ejecución del método numérico.");

disp("---------------------------------------------------------------");
disp("Iniciando el post-procesamiento...");

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

disp("Finalizado el post-procesamiento.");
