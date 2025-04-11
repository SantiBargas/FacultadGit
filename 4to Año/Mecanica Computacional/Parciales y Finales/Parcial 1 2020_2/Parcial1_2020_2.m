close all; clear all; more off;

xnode=[
      0 0;
      1/6 0;
      1/3 0;
      1/2 0;
      2/3 0;
      5/6 0;
      1 0;

      0 1/6;
      1/6 1/6;
      1/3 1/6;
      1/2 1/6;
      2/3 1/6;
      5/6 1/6;
      1 1/6;

      0 1/3;
      1/6 1/3;
      1/3 1/3;
      1/2 1/3;
      2/3 1/3;
      5/6 1/3;
      1 1/3;

      0 1/2;
      1/6 1/2;
      1/3 1/2;
      2/3 1/2;
      5/6 1/2;
      1 1/2;

      0 2/3;
      1/6 2/3;
      1/3 2/3;
      1/2 2/3;
      2/3 2/3;
      5/6 2/3;
      1 2/3;

      0 5/6;
      1/6 5/6;
      1/3 5/6;
      1/2 5/6;
      2/3 5/6;
      5/6 5/6;
      1 5/6;

      0 1;
      1/6 1;
      1/3 1;
      1/2 1;
      2/3 1;
      5/6 1;
      1 1;
      ];

plot(xnode(:,1),xnode(:,2),'o');

icone = [

 1,2,9,8;
 2,3,10,9;
 3,4,11,10;
 4,5,12,11;
 5,6,13,12;
 6,7,14,13;

 8,9,16,15;
 9,10,17,16;
 10,11,18,17;
 11,12,19,18;
 12,13,20,19;
 13,14,21,20;

 15,16,23,22;
 16,17,24,23;
 19,20,26,25;
 20,21,27,26;

 22,23,29,28;
 23,24,30,29;

 25,26,33,32;
 26,27,34,33;

 28,29,36,35;
 29,30,37,36;
 30,31,38,37;
 31,32,39,38;
 32,33,40,39;
 33,34,41,40;

 35,36,43,42;
 36,37,44,43;
 37,38,45,44;
 38,39,46,45;
 39,40,47,46;
 40,41,48,47;
];

DIR=[
    1,20;
    8,20;
    15,20;
    22,20;
    28,20;
    35,20;
    42,20;

    7,100;
    14,100;
    21,100;
    27,100;
    34,100;
    41,100;
    48,100;

];

NEU=[
     17,0,3;
     18,0,3;
     19,0,3;

     17,0,2;
     24,0,2;
     30,0,2;

     30,0,1;
     31,0,1;
     32,0,1;

     32,0,4;
     25,0,4;
     19,0,4;

     1,0,1;
     2,0,1;
     3,0,1;
     4,0,1;
     5,0,1;
     6,0,1;
     7,0,1;
];

ROB=[
      42,5,20,3;
      43,5,20,3;
      44,5,20,3;
      45,5,20,3;
      46,5,20,3;
      47,5,20,3;
      48,5,20,3;

];


model.nnodes = size(xnode,1);
model.k = 0.5*ones(1,length(xnode));
model.c = zeros(1,length(xnode));

model.G = zeros(length(xnode));
for i=1:length(xnode)
  x = xnode(i,1);
  y = xnode(i,2);
  model.G(i) = 1000*(x+y);
endfor

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 1;
model.dt = 0.25;

% Parámetros para esquemas temporales
model.rho = 1;
model.cp = 1;
model.maxit = 1000;
model.tol = 1e-7;

% Condición inicial
model.PHI_n = zeros(model.nnodes,1);
disp('Iniciando el método numérico...');

% Llamada principal al Método de Diferencias Finitas
[PHI,Q] = fdm2d(xnode, icone, DIR, NEU, ROB, model);
##
##mode = 0;
##graph = 0;
##fdm2d_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);

##########################################

disp("\n Temperatura en x=1/2 y=1/6");
T11=PHI(11,:);

% Vector de tiempos con dt = 0.25
dt = 0.25;
times = 0:dt:(length(T11)-1)*dt;
% Crear la matriz emparejada
resultadoT11 = [times', T11']

disp("\n Temperatura en x=1/2 y=5/6");
T38=PHI(38,:);
resultadoT38 = [times', T38']

figure;  % Crear una nueva figura
plot(times, T38, 'b-', 'LineWidth', 2);  % Graficar tiempo vs temperatura

% Añadir etiquetas a los ejes y título
xlabel('Tiempo');
ylabel('Temperatura');
title('Evolución de la Temperatura en x=1/2 y=5/6');

% Mostrar la cuadrícula en la gráfica
grid on;

################################################

disp("\n Temperatura en x=5/6 y=1/2 nodo 26");
disp("T=1 -> 1/dt -> 1/0.25 -> 4 en la iteracion 4 se encuentra para t=1 ")
T26_1=PHI(26,4)
disp("\n T=3 -> 3/dt -> 3/0.25 -> 12 en la iteracion 12 se encuentra para t=3 ")
T26_3=PHI(26,12)
disp("\n T=5 -> 1/dt -> 5/0.25 -> 20 en la iteracion 20 se encuentra para t=5 ")
T26_5=PHI(26,20)

