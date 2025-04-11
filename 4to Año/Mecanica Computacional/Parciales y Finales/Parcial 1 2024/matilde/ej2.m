clear all; clc; warning('off','all');
pkg load symbolic

syms x

xnode = 2:0.5:4;

K = zeros(5,5);
M = zeros(5,5);
F = zeros(5,1);
G = 100*(4-x);

# ELEMENTO
N1 = [(2.5-x)/0.5; (x+2)/0.5];
N2 = [(3-x)/0.5; (x+2.5)/0.5];
N3 = [(3.5-x)/0.5; (x+3)/0.5];
N4 = [(4-x)/0.5; (x+3.5)/0.5];
K_el = [4 -4;-4 4]
M_el=[1/16 1/12; 1/12 1/6];

F_e1 = double(int(G*N1,x,2,2.5))
F_e2 = double(int(G*N2,x,2.5,3))
F_e3 = double(int(G*N3,x,3,3.5))
F_e4 = double(int(G*N4,x,3.5,4))


# ENSAMBLE
K(1:2,1:2) += K_el;
K(2:3,2:3) += K_el
K(3:4,3:4) += K_el;
K(4:5,4:5) += K_el


M(1:2,1:2) += M_el;
M(2:3,2:3) += M_el;
M(3:4,3:4) += M_el;
M(4:5,4:5) += M_el;

F(1:2) += F_e1;
F(2:3) += F_e2;
F(3:4) += F_e3;
F(4:5) += F_e4;

# CONDICION DIRICHLET
K(1,:) = 0 ; K(1,1) = 1;
F(1) = 10;

# CONDICION NEUMANN
F(5) += 1;

T=[10; 39.848; 52.149; 54.173; 52.852]
T_n_mas_1 = (M+0.1*K)\(M*T+0.1*F)



# TEMPERATURAS EN x=3.2
T_x1 = double(subs(N3,x,3.2))'*T(3:4)


%T_x2 = double(subs(N,x,0.25))*T(2:4)

