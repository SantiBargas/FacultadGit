clc
clear

format long;

f= @(x) (x.^3)+ (4*(x.^2))-10

g1 = @(x) 1/2*(10-(x.^3))^(1/2);
g2 = @(x) sqrt(10/(4+x));

x0=1.5;
tol=1e-3;

kmax=1000;

[x1, rh1, t1] = puntofijo(g1, x0, kmax, tol)
[x2, rh2, t2] = puntofijo(g2, x0, kmax, tol)

t=linspace(1,2,100);
plot(t,f(t))

