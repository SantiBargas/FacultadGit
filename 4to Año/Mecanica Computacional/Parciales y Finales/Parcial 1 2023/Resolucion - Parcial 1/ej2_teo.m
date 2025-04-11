clear all; clc; warning('off','all');
pkg load symbolic

syms x
G = x^2;
xnode = 0:pi/20:pi;
T_ex = (-1/12)*(xnode.^4)+(pi^3-6)*(xnode./3)+100;

figure(1,"position",get(0,"screensize"))
subplot(1,3,1)
plot(xnode,T_ex)
title('Con psi a izq.')
ylim([95 120]);
hold on

# Formulacion fuerte y uso de psi (cumpliendo solo cond. borde dirchilet)
psi = 100;
for m=2:5
  N = x.^(1:m); # Nm se anula en x=0
  dN_dx = diff(N,x);
  d2N_dx2 = diff(N,x,2);
  K = int(N'*d2N_dx2,x,0,pi) - subs(N'*dN_dx,x,pi);
  F = subs(2*N,x,pi) - int(N*G,x,0,pi);
  a = double(K)\double(F');

  # numerico
  N_num = @(x,m) x.^(m);
  T_ap = psi*ones(length(xnode),1);
  for i=1:m
    T_ap = T_ap + (a(i)*N_num(xnode, i))';
  endfor
  plot(xnode, T_ap, 'x-')
endfor

subplot(1,3,2)
plot(xnode,T_ex)
title('Con psi ambos lados')
ylim([95 120]);
hold on

# Formulacion fuerte y uso de psi (cumpliendo ambas condiciones de borde)
psi = 100-2*x;
for m=2:5
  N = x.^(2:(m+1))-(2:(m+1)).*(pi.^(1:m)).*x;
  # N = (x.^(1:m))*(x-pi); # Nm se anula en x=0 y dN_dx se anula en x=pi
  N = sin((2*(1:m)-1)*0.5*x);
  d2N_dx2 = diff(N,x,2);
  K = int(N'*d2N_dx2,x,0,pi);
  F = -int(N*G,x,0,pi);
  a = double(K)\double(F');

  # numerico
  psi_num = @(x) 100-2*x;
  N_num = @(x,m) x.^m-(m+1)*(pi^m).*x;
  # N_num = @(x,m) (x.^(m)).*(x-pi);
  N_num = @(x,m) sin((2*m-1)*0.5*x);
  T_ap = psi_num(xnode);
  for i=1:m
    T_ap = T_ap + (a(i)*N_num(xnode, i));
  endfor
  plot(xnode, T_ap, 'x-')
endfor

subplot(1,3,3)
plot(xnode,T_ex)
title('Sin psi')
ylim([95 120]);
hold on

# Formulacion fuerte sin psi
for m=2:5
  N = x.^(0:m-1);
  dN_dx = diff(N,x,1);
  d2N_dx2 = diff(N,x,2);
  K = int(N'*d2N_dx2,x,0,pi)-subs(N'*N,x,0)-subs(N'*dN_dx,x,pi);
  F = -int(N*G,x,0,pi)-100*subs(N,x,0)+2*subs(N,x,pi);
  a = double(K)\double(F');

  # numerico
  N_num = @(x,m) (x.^(m));
  T_ap = zeros(1,length(xnode));
  for i=0:m-1
    T_ap = T_ap + (a(i+1)*N_num(xnode, i));
  endfor
  plot(xnode, T_ap, 'x-')
endfor


