clc;
clear all;

u0=[1;0;-1]; %valores iniciales
intervalo=[0,15];
L=60; %USAMOS 60 PORQUE AL DIVIDIR EL INTERVALO EN 6O NOS DA EL VECTOR DEL TIEMPO CON EL VALOR 2.5 PARA EL INCISO C)

%Funcion con u como solucion
f=@(t,u) [u(2);u(3);-4*u(3)-5*u(2)-2*u(1)-4*sin(t)-2*cos(t)];

%[t1,u2] = euler_adelante_multi(f,0,15,u0,L);
[t1,u2] = RungeKuttaMulti(f,0,15,u0,L);
%[t1,u2]=rk4(f, intervalo, u0, L);
u2

figure(1)
plot(t1,u2(1,:))
hold on;
plot(t1,u2(2,:))
plot(t1,u2(3,:))

%buscamos la posicion i
for i=1:length(t1)
  if(t1(i)==2.5)
    pos=i
    break;
  end
  end

  %obtenemos el valor de la variable de estado y en t = 2.5,
y25=u2(1,pos);
disp('El valor de la variable de estado y en t = 2.5, es:')
disp(y25)



