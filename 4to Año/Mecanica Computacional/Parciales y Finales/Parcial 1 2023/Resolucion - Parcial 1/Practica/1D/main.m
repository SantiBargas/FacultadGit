close all; clear all;

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

# EJERCICIO PARCIAL
L1=-4; L2=4;
N = 20;
dx = (L2-L1)/N;
xnode = L1:dx:L2;
cb = [1 20 -1;3 2 10];
model.rho = 1; model.cp = 1;
model.k = 3; model.c = 0;
model.G = 100*(xnode); et = [0 -1 -1 -1];
T = difFinitas(xnode, model, cb, et);

# Solucion analitica
a = 95*(xnode.^3);
b = -1982*xnode;
Tex = (-10*(a+b-2190))/171;

ind = N/2+1;
fprintf('Temperatura aproximada en (0,0): %f \n', T(ind));
fprintf('Temperatura exacta en (0,0): %f \n', Tex(ind));

q = cb(2,2)*(T(end)-cb(2,3));
fprintf('Flujo de calor: q=-k*graT, en (4,0): %f \n', q);

hold on
plot(xnode, Tex, 'r')
xlabel('x'); ylabel('Temp')
legend('Aproximada', 'Exacta')
