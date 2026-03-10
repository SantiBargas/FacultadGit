%  Datos
%  =====
%     X0   : posiciones iniciales nodos 1 a nnod
%     mass : masas puntos 1 a nnod
%     conec: tabla de resortes y nodos conectados
%     rig  : constantes de resortes
clear all
global X0 mass conec rig Fext fixa;
X0    = [1 1 10 0.5 6 4 9 6 2 5]';
mass  = [0.5 0.5 2 0.5 2]';
conec = [1 2;
         1 3;
         1 5;
         2 3;
         3 5;
         2 4;
         3 4;
         4 5];
rig   = [20 20 20 20 20 20 20 20]';
fixa  = [1 2 9];
Fext  = [0 0 0 0 0 0 0 -5 0 0]';

nnod  = length(X0)/2;

Y0(1       :2*nnod,1) = X0(:,1);
Y0(2*nnod+1:4*nnod,1) = zeros(2*nnod,1);

[t,Y] = ode23s(@odefunejer6,[0 50],Y0);

X  = Y(       1:2*nnod,:);
Xp = Y(2*nnod+1:4*nnod,:);

%X  = Y(:,1:2*nnod);  % Corrección: No es necesario transponer Y
%Xp = Y(:,2*nnod+1:4*nnod);  % Corrección: No es necesario transponer Y

plot(t,Y(:,3),'-o')
grid
