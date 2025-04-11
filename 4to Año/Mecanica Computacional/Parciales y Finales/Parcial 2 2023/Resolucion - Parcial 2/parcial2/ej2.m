clear all; clc; warning('off','all');
pkg load symbolic

syms x

xnode = -1:0.1:1;
T_ex = 0.25*(-xnode.^5+85*xnode+84);

K = zeros(4,4);
F = zeros(4,1);
G = 10*(x^3);

# ELEMENTO 1
N = [-x; x+1];
K_e1 = 2*[1 -1;-1 1]
F_e1 = double(int(G*N,x,-1,0))

# ELEMENTO 2
M = [1 0 0;1 0.5 0.5^2;1 1 1];
a = (M\[1; 0; 0]);
N1 = a(1)+a(2)*x+a(3)*x^2;
a = (M\[0; 1; 0]);
N2 = a(1)+a(2)*x+a(3)*x^2;
a = (M\[0; 0; 1]);
N3 = a(1)+a(2)*x+a(3)*x^2;
N = [N1 N2 N3];
K_e2 = double(2*int(diff(N)'*diff(N),x,0,1))
F_e2 = double(int(N'*G,x,0,1))

# CONDICION ROBIN
K_e2(3,3) += 5;
F_e2(3) += 250;

# ENSAMBLE
K(1:2,1:2) += K_e1;
K(2:4,2:4) += K_e2

F(1:2) += F_e1;
F(2:4) += F_e2

# CONDICION DIRICHLET
K(1,:) = 0 ; K(1,1) = 1
F(1) = 0

T = K\F

plot([-1 0 0.5 1], T, 'x')
hold on
plot(xnode,T_ex)

# TEMPERATURAS EN x=-0.25 y x=0.25
N = [-x x+1];
T_x1 = double(subs(N,x,-0.25))*T(1:2)

N = [N1 N2 N3];
T_x2 = double(subs(N,x,0.25))*T(2:4)

