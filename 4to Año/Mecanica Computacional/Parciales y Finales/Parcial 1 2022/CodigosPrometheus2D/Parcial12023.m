#FLUJO HACIA AFUERA DEL OBJETO
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

##plot(xnode(:,1),xnode(:,2),'o');
%     (1) Flujo en dirección eje-y, sentido negativo (S – South - Sur)
%     (2) Flujo en dirección eje-x, sentido positivo (E – East - Este)
%     (3) Flujo en dirección eje-y, sentido positivo (N – North - Norte)
%     (4) Flujo en dirección eje-x, sentido negativo (W – West – Oeste)

NEU =[
      1,0,1;
      2,0,1;
      3,0,1;
      4,0,1;
      5,0,1;
      16,0,3;
      17,0,3;
      18,0,3;
      19,0,3;
      20,0,3
      ];

ROB =[
      5,2,10,2;
      10,2,10,2;
      15,2,10,2;
      20,2,10,2
      ];

DIR = [
        1,20;
        6,20;
        11,20;
        16,20
        ];

model.nnodes = size(xnode,1);
model.k = 3*ones(1,length(xnode));
model.c = zeros(1,length(xnode));

model.G = zeros(length(xnode));
for i=1:length(xnode)
   model.G(i) = 100*xnode(i,1);
endfor

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 2;

% Parámetros para esquemas temporales
model.rho = 0;
model.cp = 0;
model.maxit = 0;
model.tol = 0;

% Condición inicial
model.PHI_n = zeros(model.nnodes,1);
disp('Iniciando el método numérico...');

% Llamada principal al Método de Diferencias Finitas
[PHI,Q] = fdm2d(xnode, icone, DIR, NEU, ROB, model);

mode = 0;
graph = 0;
fdm2d_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);

#Como el punto 0,0 no esta en la malla, sacamos la temperatura del nodo inferior y superior
# e interpolamos

disp('Temperatura en el nodo 8')
T8=PHI(8)
disp('Temperatura en el nodo 13')
T13=PHI(13)

disp('La temperatura en (0,0) es: ')
T00 = (T8 + T13) / 2 # -> Una forma de interpolar


############################
############INCISO B##########
################################

  L1 = -4; #long de la barra
  L2 = 4; #long final de la barra
  N = 21;   #Si la longitud de la barra tiene 8 y queremos 21 puntos

  dx = (L2-L1)/N
  xnode = L1:dx:L2;

  model.rho = 0; # No definido, se asume 1
  model.cp = 0; # No definido, se asume 1
  model.k = 3;
  model.c = 0; # No hay reaccion ni fuente interna
  model.G = 100.*(xnode);

  cb = [1 20 -1 ; 3 2 10]; #[dirichlet, u(0)=0, dirichlet; neumann, du(1)=0, neumann]
  et = [0 0 0 0]; # Estado estacionario
  T_ini = 0;
  [T] = difFinitas(xnode, model, cb, et);


  #Vemos que con esta nueva discretizacion tampoco hay un punto en (0,0)
  #identificamos nodo anterior y posterior e interpolamos de nuevo

  T11=T(11)
  T12=T(12)
  T00=T11 + T12 / 2


##
###INCISO B)
###DISCRETIZAMOS SOLO EN X YA QUE EL PROBLEMA ES MUY FACIL
###PARA USAR 21 NODOS EN UNA LONGITUD DE 8 21/8 = 0.3810 0.3810-> DELTA X
###PRINTEAMOS XNODE Y VEMOS ENTRE QUE NODOS ESTA EL 0, ENTRE 11 Y 12 ESTA
##
##


############################
############INCISO C##########
################################

#Pide el gradiente de la temperatura = derivada de la temperatura = cambio de temperatura
#Buscamos las ecuaciones en las slides

Fi_ficticio = T(21) - ((2*dx)*2/model.k) * (T(22)) + ((2*dx)*2/model.k)*10;

Fi_grad = (Fi_ficticio - T(21) )/ (2*dx)
