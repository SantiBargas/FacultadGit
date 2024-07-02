
%si anulamos la variable x1, x1=0 la funcion x'2 queda
%x'2 = -x2*0.5  -> decrece
%por tanto si la funcion decrece es pq no tiene de donde alimentarse
%x1 es la presa
%x2 es el predador

x0=[1600;800];
t=[0:0.1:20];

f = @(t,x) [x(1)*(3-0.002*x(2)); -x(2)*(0.5-0.0006*x(1))];

[x,w] = euler_adelante_multi(f,0,20,x0,60);
