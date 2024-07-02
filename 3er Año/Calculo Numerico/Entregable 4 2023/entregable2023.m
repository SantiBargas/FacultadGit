clc;
clear all;

 f=@(t,z) [z(2);20*(cos(z(1)))^2 - sin(z(1))-z(2)];

%el pendulo se suelta del reposo en la posicion horizontal alpha(0)=pi/2

z0=[pi/2;0];
%posicion ; velocidad

h=0.05;
L=(3-0)/h;
inter=[0,3];

[t,y]=rk4(f, inter, z0, L)

figure(1)
plot(y(:,1),'b')
figure(2)
plot(y(:,2),'r');
figure(3)
plot(y(:,1),y(:,2))

for i=1:length(t)
  if (t(i)==3)
    posi=i;
    angulo=y(i,1);
  endif
end
%Inciso A
disp("El agulo que forma a t=3 segundos es")
 angulo
 angulo=y(end,1)


%Inciso B
disp("Para saber como se mueve, nos fijamos en y(:,1) que es la posicion")

%para saber cuantas veces cambio de direccion en 5 segundos
inter=[0,5];
[t2,y2]=rk4(f, inter, z0, L);
figure(2)
plot(y2(:,1),'b')
figure(2)
plot(y2(:,2),'r');

%fijandonos en y2(:,2) que es la velocidad cambia de signo 4 veces, por tanto cambia 4 veces de direccion
cont=0;
comparador=y2(1,2);

for i=1:length(y2)
  if (y2(i,2)>0 && comparador <0)
    cont=cont+1;
    comparador=y2(i,2);
  else if(y2(i,2)<0 && comparador>0)
      cont=cont+1;
    comparador=y2(i,2);
  endif
end
end
cont


%Inciso c
inter=[0,100];
[t3,y3]=rk4(f, inter, z0, L);

angulo_final=y3(end,1)*(180/pi)
velocidad_final=y3(end,2)


