clc;clear all;
##
xnode=[ 0,0; #Nodo 1
        1,0; #Nodo 2
        2,0; #Nodo 3
        0,1; #Nodo 4
        1,1; #Nodo 5
        2,1; #Nodo 6
        0,2; #Nodo 7
        1,2; #Nodo 8
        2,2 #Nodo 9
        ];

#PROBAMOS CON UNA MALLA MAS CHICA POR LAS DUDAS
##xnode=[ 0,0;  #Nodo 1
##        0.5,0 #Nodo 2
##        1,0;  #Nodo 3
##        1.5,0 #Nodo 4
##        2,0;  #Nodo 5
##
##        0,0.5;  #Nodo 6
##        0.5,0.5 #Nodo 7
##        1,0.5;  #Nodo 8
##        1.5,0.5 #Nodo 9
##        2,0.5;  #Nodo 10
##
##       0,1;  #Nodo 11
##        0.5,1 #Nodo 12
##        1,1;  #Nodo 13
##        1.5,1 #Nodo 14
##        2,1;  #Nodo 15
##
##       0,1.5;  #Nodo 16
##        0.5,1.5 #Nodo 17
##        1,1.5;  #Nodo 18
##        1.5,1.5 #Nodo 19
##        2,1.5;  #Nodo 20
##
##       0,2;  #Nodo 21
##        0.5,2 #Nodo 22
##        1,2;  #Nodo 23
##        1.5,2 #Nodo 24
##        2,2 #Nodo 25
##
##        ];

plot(xnode(:,1),xnode(:,2),'o');
##xnode(9,1)
##xnode(9,2)


NEU =[
      1, 0, 1;  % Nodo 1,
      2, 0, 1;  % Nodo 2,
      3, 0, 1   % Nodo 3,
      ];

ROB =[
      7, 10, 30, 3;  % Nodo 7,
      8, 10, 30, 3;  % Nodo 8,
      9, 10, 30, 3   % Nodo 9,
      ];
DIR =[
      3,50;
      6,50;
      9,50;

      1,100;
      4,100;
      7,100;
      ];
########################################################################
################################para malla mas refinada####################
##NEU =[
##      1, 0, 1;  % Nodo 1,
##      2, 0, 1;  % Nodo 2,
##      3, 0, 1   % Nodo 3,
##      4,0,1;
##      5,0,1
##      ];
##
##ROB =[
##      21, 10, 30, 3;
##      22, 10, 30, 3;
##      23, 10, 30, 3
##      24, 10, 30, 3;
##      25, 10, 30, 3;
##      ];
##DIR =[
##      5,50;
##      10,50;
##      15,50;
##      20,50;
##      25,50;
##
##      1,100;
##      6,100;
##      11,100;
##      16,100;
##      21,100
##      ];
#####################################################################3

nx = 3;  % Número de nodos en x
ny = 3;  % Número de nodos en y
% Inicializar la matriz icone
icone = [];

##icone=[
##        1 2 5 4;
##        2 3 6 5;
##        4 5 8 7;
##        5 6 9 8
##
##        ];

##% Crear los elementos
for j = 1:(ny-1)
    for i = 1:(nx-1)
        % Definir los nodos de cada cuadrado (elemento)
        n1 = i + (j-1)*nx;       % Nodo inferior izquierdo
        n2 = n1 + 1;             % Nodo inferior derecho
        n3 = n1 + nx;            % Nodo superior izquierdo
        n4 = n3 + 1;             % Nodo superior derecho
        % Añadir el elemento a la matriz icone
        icone = [icone; n1, n2, n4, n3];
    end
end



model.nnodes = size(xnode,1);
model.k = 1*ones(1,length(xnode));
model.c = zeros(1,length(xnode));
model.G = 100*ones(1,length(xnode));

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;

% Parámetros para esquemas temporales
model.rho = 0.0000000000000000;
model.cp = 0.0000000000000000;
model.maxit =            1;
model.tol = 1.000000e-05;

% Condición inicial
model.PHI_n = zeros(model.nnodes,1);
disp('Iniciando el método numérico...');

% Llamada principal al Método de Diferencias Finitas
[PHI,Q] = fdm2d(xnode, icone, DIR, NEU, ROB, model);

mode = 0;
graph = 0;
fdm2d_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);

#T1 = Temperatura en el nodo 8
disp('La temperatura en el nodo 8 es: ')
T8=PHI(8)

#T2 = Temperatura en el nodo 5
disp('La temperatura en el nodo 5 es: ')
T5=PHI(5) #Es 0 pq no llega temperatura

#T3 = Temperatura en el nodo 2
disp('La temperatura en el nodo 2 es: ')
T2=PHI(2) #Es 0 pq no llega temperatura


####################################################################
############PARA MALLA MAS REFINADA#################
###############################################################
############P###################################################
###T1 = Temperatura en el nodo 23
##disp('La temperatura en el nodo 8 es: ')
##T23=PHI(23)
##
###T2 = Temperatura en el nodo 13
##disp('La temperatura en el nodo 5 es: ')
##T13=PHI(13) #Es 0 pq no llega temperatura
##
###T3 = Temperatura en el nodo 3
##disp('La temperatura en el nodo 2 es: ')
##T2=PHI(3) #Es 0 pq no llega temperatura


