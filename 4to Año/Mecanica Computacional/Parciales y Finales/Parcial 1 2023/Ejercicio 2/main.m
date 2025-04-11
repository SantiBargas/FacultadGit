close all; clear all; more off;

xnode = [
 -4.00, -3.00;
 -2.00, -3.00;
  0.00, -3.00;
  2.00, -3.00;
  4.00, -3.00;
 -4.00, -1.00;
 -2.00, -1.00;
  0.00, -1.00;
  2.00, -1.00;
  4.00, -1.00;
 -4.00,  1.00;
 -2.00,  1.00;
  0.00,  1.00;
  2.00,  1.00;
  4.00,  1.00;
 -4.00,  3.00;
 -2.00,  3.00;
  0.00,  3.00;
  2.00,  3.00;
  4.00,  3.00;
];
% Graficar los nodos
##figure;
##plot(xnode(:,1), xnode(:,2), 'bo', 'MarkerFaceColor', 'b');
##hold on;
##
##% Etiquetar los nodos con su número correspondiente
##for i = 1:size(xnode, 1)
##  text(xnode(i, 1) + 0.01, xnode(i, 2), num2str(i), 'FontSize', 10, 'Color', 'red');
##end

icone = [
  1, 2, 7, 6;
  2, 3, 8, 7;
  3, 4, 9, 8;
  4, 5, 10, 9;
  6, 7, 12, 11;
  7, 8, 13, 12;
  8, 9, 14, 13;
  9, 10, 15, 14;
  11, 12, 17, 16;
  12, 13, 18, 17;
  13, 14, 19, 18;
  14, 15, 20, 19;
];

DIR = [
  1,20;
  6,20;
  11,20;
  16,20;
];

NEU = [
    1,0,1;
    2,0,1;
    3,0,1;
    4,0,1;
    5,0,1;

    16,0,3;
    17,0,3;
    18,0,3;
    19,0,3;
    20,0,3;
];

ROB = [
  5,2,10,2;
  10,2,10,2;
  15,2,10,2;
  20,2,10,2;
];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);

model.k = 3*ones(1,length(xnode));

model.c = [
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
    0.0000000000000000;
];

model.G = zeros(length(xnode));
for i=1:length(xnode)
   model.G(i) = 100*xnode(i,1);
endfor

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;

% Parámetros para esquemas temporales
model.rho = 1.0000000000000000;
model.cp = 1.0000000000000000;
model.maxit =            1;
model.tol = 1.000000e-05;

% Condición inicial
model.PHI_n = mean(DIR(:,2))*ones(model.nnodes,1);

disp('Iniciando el método numérico...');

% Llamada principal al Método de Diferencias Finitas
[PHI,Q] = fdm2d(xnode, icone, DIR, NEU, ROB, model);

disp('Finalizada la ejecución del método numérico.');

disp('---------------------------------------------------------------');
disp('Iniciando el post-procesamiento...');

% mode ---> modo de visualización:
%           [0] 2D - Con malla
%           [1] 3D - Con malla
%           [2] 2D - Sin malla
%           [3] 3D - Sin malla
% graph --> tipo de gráfica:
%           [0] Temperatura (escalar)
%           [1] Flujo de Calor (vectorial)
%           [2] Flujo de Calor eje-x (escalar)
%           [3] Flujo de Calor eje-y (escalar)
%           [4] Magnitud de Flujo de Calor (escalar)
mode = 0;
graph = 0;
fdm2d_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);

disp('Finalizado el post-procesamiento.');


###INCISO A####
#Como el punto 0,0 no esta en la malla, sacamos la temperatura del nodo inferior y superior
# e interpolamos

##disp('Temperatura en el nodo 8')
T8=PHI(8);
##disp('Temperatura en el nodo 13')
T13=PHI(13);

disp('La temperatura en (0,0) es: ')
T00 = (T8 + T13) / 2 # -> Una forma de interpolar

############################
############INCISO B##########
################################

#Usamos diferencias finitas 1D

% L1 y L2: extremos izquierdo y derecho respectivamente
% N: cantidad de puntos
% cb: condiciones de borde [tipo valor1 valor2]
  % tipo==1 -> Dirichet -- valor1 = Temp. impuesta
  % tipo==2 -> Neumann -- valor1 = q (flujo impuesto)
  % tipo==3 -> Robin -- valor1 = h (conveccion) -- valor2 = Temp. ext.
% model: struct con los parametros del modelo incluida la fuente
%        punto a punto
% et: esquema temporal [tipo val1 val2 val3]
  % tipo==0 -> Estacionario
  % tipo==1 -> Explicito
  % tipo==2 -> Implicito
  % Si tipo==1 o tipo==2: val1=maxIt, val2=tolError
  % Si tipo==2 val3=dt

L1 = -4 ;
L2 = 4;
N=21;
dx=(L2-L1)/N;
xnode = L1:dx:L2;
model.rho = 1;
model.cp = 1;
model.k = 3;
model.c = 0;
model.G =100.*(xnode);
cb = [1 20 -1;3 2 10];
et = [0 -1 -1 -1];
T_ini = 0;
[T] = difFinitasProfe(xnode, model, cb, et);
figure;
plot(xnode, zeros(size(xnode)), 'bo', 'MarkerFaceColor', 'b'); % Dibujar los nodos en el eje X
hold on;

% Etiquetar los nodos con su número correspondiente
for i = 1:length(xnode)
  text(xnode(i), 0.02, num2str(i), 'FontSize', 10, 'Color', 'red', 'HorizontalAlignment', 'center');
end

%%% EL NODO (0,0) ESTA ENTRE EL NODO 11 Y 12
##disp('Temperatura en el nodo 11')
T11=T(11);
##disp('Temperatura en el nodo 13')
T12=T(12);

disp('La temperatura en (0,0) es: ')
T00 = (T11 + T12) / 2 # -> Una forma de interpolar


############################
############INCISO C##########
################################

############################
############INCISO C##########
################################

#Pide el gradiente de la temperatura = derivada de la temperatura = cambio de temperatura
#Buscamos las ecuaciones en las slides

Fi_ficticio = T(21) - ((2*dx)*2/model.k) * (T(22)) + ((2*dx)*2/model.k)*10; #Slide 14

Fi_grad = (Fi_ficticio - T(21) )/ (2*dx) #Slide 2
