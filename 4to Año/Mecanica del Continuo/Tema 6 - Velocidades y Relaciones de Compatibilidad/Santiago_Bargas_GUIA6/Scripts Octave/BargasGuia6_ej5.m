
pkg load symbolic;
clear;
close all;

%--------------------------------------------------------------
%----Inciso a---
%--------------------------------------------------------------

% Declaración de variables
syms a r theta c z;
syms e_r_r e_theta_theta e_r_theta e_z_r e_z_theta e_z_z;

% Campo de desplazamiento
u_r = a*r*log(theta);
u_theta = a*r^2 + c*sin(theta);
u_z = 0;

% Componentes del tensor
e_r_r = diff(u_r,r);
e_theta_theta = (u_r / r) + (1 / r)*diff(u_theta,theta);
e_r_theta = (1/2)*((1/r)*diff(u_r,theta) + diff(u_theta,r) - (u_theta / r));
e_z_r = (1/2)*(diff(u_r,z) + diff(u_z,r));
e_z_theta = (1/2)*((1/r)*diff(u_z,theta) + diff(u_theta,z));
e_z_z = diff(u_z,z);

% Verificación de compatibilidad
szz = (2/r)*diff(diff(e_r_theta,theta),r) -...
      diff(diff(e_theta_theta,r),r) -...
      (1/(r^2))*diff(diff(e_r_r,theta),theta) +...
      (1/r)*diff(e_r_r,r) +...
      (2/(r^2))*diff(e_r_theta,theta) -...
      (2/r)*diff(e_theta_theta,r);

f_szz = function_handle(szz);

a = 1;
c = 1;
r = 1;

theta = linspace(1,pi/2,2*pi-1); % 0 < theta < 2*pi
valor_szz = f_szz(a,c,r,theta) % Debe ser 0 para que el campo sea compatible


%---Inciso b---
%----------------------------------------------------
% Gráfico del campo de desplazamiento

rango = linspace(-3,3,50);
[x,y] = meshgrid(rango,rango);
r = x.^(2) + y.^(2);
theta = atan2(y,x);
a = 1;
c = 1;

u = a*r*log(theta)*cos(theta) + a*(r.^2)*sin(theta) + c*(sin(theta).^2);
v = -a*r*log(theta)*sin(theta) + a*(r.^2)*cos(theta) + c*sin(theta)*cos(theta);

% Gráfico
figure(1);
quiver(x,y,u,v);
title('Campo de Desplazamiento');
xlabel("x");
ylabel("y");
axis tight;


