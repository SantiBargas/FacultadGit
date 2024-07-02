clear all;
clc
% number of segments is m, so the number of nodes n=(m+1)
m=10;
n=m+1;
dx=1.0/m;
x=[0:dx:1];
dt=0.003;
cr=dt/(dx*dx);
tmax=0.1; % the time when the simulation stops.
time=0;
t_crank=zeros(n); %i.c.
while (time<tmax)
 time=time+dt;
 % assemble the coef matrix
 [a,b,c,d]=coef_matrix_crank(n,dx,cr,tmax,t_crank);
 % solve by TDMA solver
 t_crank=solver_tdma(n,a,b,c,d);
end;
figure(1)
plot(x,t_crank,'o?b');
xlabel('distance, x');
ylabel('Temperature, T');
title('Temperature profile at time 0.2 (By implicit Crank?Nicloson scheme)');
