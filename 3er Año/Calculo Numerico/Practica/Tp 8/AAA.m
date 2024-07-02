%Ej6TP8
clc
clear
L=5;
ko=0.9;
u0=6;
H=15;
ue=4;
N=4;
f = @(x) [ zeros(size(x)) ((1.05.x + 2)/ko) ((5 .x .* (5-x))/-ko) ];
[x,u]=dif_fin_rob(f,[0 L],u0,[-0.9 -15 -60],N);

pmedio=2.5;

for i=1:100
  N = N*2;
  [x,u1] = dif_fin_rob(f,[0 L],u0,[-0.9 -15 -60],N);
    if ( abs(u1(end) - u(end) ) < 1e-4)
      u=u1;
      break
    endif
  u=u1;
endfor
u(N/2)
plot(x,u)
grid on
grid minor
