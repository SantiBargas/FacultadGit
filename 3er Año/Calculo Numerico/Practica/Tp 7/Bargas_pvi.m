clc;
clear all;
format long;

%L=1; longitud de la barra
u0=[pi/2;0]; %condicion inicial
inter=[0,5]; %intervalo para ver el angulo a tiempo t=3 Y para t=5 en el inciso b

%Funcion con w como solucion
%f=@(t,w) [w(1) ; 20*(cos(t))^2-w(1)-sin(t)];
f=@(t,w) [w(2);20*(cos(w(1)))^2 - sin(w(1))-w(2)]

%tomando un h=0.05
h=0.05
L=(5-0)/h;

%[t1,u2] = RungeKuttaMulti(f,0,3,u0,L);
%[t1,u2] = euler_adelante_multi(f,0,3,u0,L)
[t1,u2]=rk4(f, inter, u0, L);

%buscamos la posicion i en donde t1=3
for i=1:length(t1)
  if(t1(i)==3)
    pos=i
    break;
  end
 end
u2=u2';

 %obtenemos el valor de la variable de estado y en t = 2.5,
angulo_3seg=u2(1,pos);
disp('El angulo que forma el pendulo con la vertical a tiempo t=3 es:')
angulo_3seg

figure(1)
plot(u2(1,:),u2(2,:))
figure(2)
plot(u2(1,:))
figure(3)
plot(u2(2,:))



%----------INCISO B---------------


 %-------INCISO C-------------------
 %para el inciso c, buscamos un tiempo muy grande para ver que angulo tiene
 inter2=[0,500];
[tc,uc]=rk4(f, inter2, u0, L);
disp('El angulo que forma el pendulo con la vertical al cabo de un tiempo es:')
uc(1,end)
disp('Por tanto es menor a 45 grados')


