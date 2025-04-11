close all; clear all; more off;

dy=0.5;
dx= 1;
xnode = [
  0,0;  #1
  1,0;  #2
  2,0;  #3
  3,0;  #4
  4,0;  #5
  5,0;  #6
  #6,0 #no va
  7,0;  #7
  8,0;  #8
  9,0;  #9
  10,0; #10
  11,0; #11
  12,0; #12

  0,1;  #13
  1,1;  #14
  2,1;  #15
  3,1;  #16
  4,1;  #17
  5,1;  #18
  #6,1; #no va
  7,1;  #19
  8,1;  #20
  9,1;  #21
  10,1; #22
  11,1; #23
  12,1; #24

  0,2;  #25
  1,2;  #26
  2,2;  #27
  3,2;  #28
  4,2;  #29
  5,2;  #30
  6,2;  #31
  7,2;  #32
  8,2;  #33
  9,2;  #34
  10,2; #35
  11,2; #36
  12,2; #37

  0,3;  #38
  1,3;  #39
  2,3;  #40
  3,3;  #41
  4,3;  #42
  5,3;  #43
  6,3;  #44
  7,3;  #45
  8,3;  #46
  9,3;  #47
  10,3; #48
  11,3; #49
  12,3; #50

  0,4;  #51
  1,4;  #52
  2,4;  #53
  3,4;  #54
  4,4;  #55
  5,4;  #56
  #6,4; #No va
  7,4;  #57
  8,4;  #58
  9,4;  #59
  10,4; #60
  11,4; #61
  12,4; #62

  0,5;  #63
  1,5;  #64
  2,5;  #65
  3,5;  #66
  4,5;  #67
  5,5;  #68
  #6,5; no va
  7,5;  #69
  8,5;  #70
  9,5;  #71
  10,5; #72
  11,5; #73
  12,5; #74
];


plot(xnode(:,1),xnode(:,2),'o');

icone =[

    1    2   14  13;
    2    3   15   14;
    3    4   16   15;
    4    5   17   16;
    5    6   18  17;
    7    8   20  19;
    8    9   21   20;
    9    10   22   21;
    10   11   23   22;
    11    12   24  23;

    13 14 26 25;
    14 15 27 26;
    15 16 28 27;
    16 17 29 28;
    17 18 30 29;
    19 20 33 32;
    20 21 34 33;
    21 22 35 34;
    22 23 36 35;
    23 24 37 36;

    25 26 39 38;
    26 27 40 39;
    27 28 41 40;
    28 29 42 41;
    29 30 43 42;
    30 31 44 43;
    31 32 45 44;
    32 33 46 45;
    33 34 47 46;
    34 35 48 47;
    35 36 49 48;
    36 37 50 49;

    38 39 52 51;
    39 40 53 52;
    40 41 54 53;
    41 42 55 54;
    42 43 56 55;
    45 46 58 57;
    46 47 59 58;
    47 48 60 59;
    48 49 61 60;
    49 50 62 61;

    51 52 64 63;
    52 53 65 64;
    53 54 66 65;
    54 55 67 66;
    55 56 68 67;
    57 58 70 69;
    58 59 71 70;
    59 60 72 71;
    60 61 73 72;
    61 62 74 73;
    ];

DIR = [(1:74)', zeros(74, 1)];

%   - Columna 1: índice del nodo donde se aplica la condición de borde.
%   - Columna 2: valor de flujo térmico (q) asociado al lado del elemento.
%   - Columna 3: dirección y sentido del flujo:
%     (1) Flujo en dirección eje-y, sentido negativo (S – South - Sur)
%     (2) Flujo en dirección eje-x, sentido positivo (E – East - Este)
%     (3) Flujo en dirección eje-y, sentido positivo (N – North - Norte)
%     (4) Flujo en dirección eje-x, sentido negativo (W – West – Oeste)
NEU=[];
NEU = [
      63,0 , 4;
      51, 0, 4;
      38, 0, 4;
      25,0 , 4;
      13, 0, 4;
      1, 0, 4;

      67,0 , 2;
      56, 0, 2;
      43, 0, 2;

      44, 0, 3;

      69, 0, 3;
      70, 0 ,3;
      71, 0 ,3;
      72, 0, 3;
      73, 0 ,3;
      74, 0 ,3;

      19, 0 , 4;
      7, 0 , 4;

    ];


ROB = [
    ];

model.nnodes = size(xnode,1);
model.k = 10*ones(1,length(xnode)); #k = 10W/m/c
model.c = zeros(1,length(xnode));
model.G = 100*ones(length(xnode)); #G = 100w

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 0; #Inciso a) explicito
##model.ts = 1; #Inciso c) implicito

% Parámetros para esquemas temporales
model.rho = 1;
model.cp = 1;
model.maxit = 600; #600 iteraciones
model.tol = 1e-5;
model.dt=0.25;

% Condición inicial
model.PHI_n = zeros(model.nnodes,1);
disp('Iniciando el método numérico...');

% Llamada principal al Método de Diferencias Finitas
[PHI,Q] = fdm2d(xnode, icone, DIR, NEU, ROB, model);

mode = 0;
graph = 0;
fdm2d_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);


##TEMPERATURA PARA (x=2.5 y=4)
#interpolamos entre nodo52(x=2 y=4) y nodo53(x=3 y=4)
T52=PHI(52);
T53=PHI(53);
T1=T52+T53 / 2;

##TEMPERATURA PARA (x=9.5 y=4)
#interpolamos entre nodo59(x=9 y=4) y nodo60(x=10 y=4)
T59=PHI(59);
T60=PHI(60);
T1=T59+T60 / 2;

#A) USANDO METODO EXPLICITO SE UTILIZAN EL TOTAL DE ITERACIONES
#B) SI SE UTILIZA UN METODO EXPLICITO EL PASO DEL TIEMPO DEFINIDO ES: dt = 0.012500
#C) EN IMPLICITO CON UN DT=0.25 SE LLEGA A LA MAXIMA ITERACION
