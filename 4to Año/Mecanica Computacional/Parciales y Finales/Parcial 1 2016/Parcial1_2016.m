xnode=[
       0,0 #Nodo 1
       0.15,0 #Nodo 2
       0.3,0 #Nodo 3

       0,0.05 #Nodo 4
       0.15,0.05 #Nodo 5
       0.3,0.05 #Nodo 6

       0,0.1 #Nodo 7
       0.15,0.1 #Nodo 8
       0.3,0.1 #Nodo 9
      ];

plot(xnode(:,1),xnode(:,2),'o');

nx = 3;  % Número de nodos en x
ny = 3;  % Número de nodos en y
% Inicializar la matriz icone
icone = [];

icone=[
        1 2 5 4;
        2 3 6 5;
        4 5 8 7;
        5 6 9 8
        ];
##
####% Crear los elementos
##for j = 1:(ny-1)
##    for i = 1:(nx-1)
##        % Definir los nodos de cada cuadrado (elemento)
##        n1 = i + (j-1)*nx;       % Nodo inferior izquierdo
##        n2 = n1 + 1;             % Nodo inferior derecho
##        n3 = n1 + nx;            % Nodo superior izquierdo
##        n4 = n3 + 1;             % Nodo superior derecho
##        % Añadir el elemento a la matriz icone
##        icone = [icone; n1, n2, n4, n3];
##    end
##end

DIR =[
      1,100;
      4,100;
      7,100

      3,50;
      6,50;
      9,50
      ];

NEU=[ 1,0,1;
      2,0,1;
      3,0,1
      ];

ROB =[7,10,30,3;
      8,10,30,3;
      9,10,30,3
      ];

model.nnodes = size(xnode,1);
model.k = 14*ones(1,length(xnode));
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










