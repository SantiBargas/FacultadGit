clc;
clear all;
format long;
%PREGUNTA 3-----------------------
m=10;
c=0.2;
g=9.81;
z0=[0;30;40;0];

inter=[0,2.5]; %para ver en que t toca el piso

f=@(t,z) [z(3);z(4); -(0.2/10).*z(3) ; -(9.81) - (0.2/10).*z(4)];

h=0.05;
L=(2.5-0)/h;

[t1,y1]=rk4(f, inter, z0, L);
posx=y1(:,1);
posy=y1(:,2);

figure(1)
plot(posx,posy);
title("Trayectoria del tiro parabolico")
xlabel("coord x")
ylabel("coord y")
grid on
grid minor

%%calculo del tiempo para el punto A
poli=polyfit(t1',posy,2); %genero los valores para un polinomio de grado 2
g = @(t) poli(3)+(poli(2).*t)+(poli(1).*(t.^2));
[piso, rh, it, t] = biseccion(g, 0,3 , 300, 0.00000001);
disp("El proyectil toca el piso a los")
piso

%como ahora sabemos a los cuantos segundos toca el piso, usamos esa t para otro rk4
inter2=[0,piso];
[t2,y2]=rk4(f, inter2, z0, L);
disp("El proyectil toca el piso a una distancia de")
pos=length(t2); %ya que es el ultimo valor de t2 el correspondiente a donde toca el piso
y2(pos)

##%buscamos la posicion i
##for i=1:length(t2)
##  if(t2(i)==piso)
##    pos2=i
##    break;
##  end
##  end
##pos2
##y2(pos)
disp("-----------------INCISO B------------------");

%buscamos la posicion para la cual t=2seg

for i=1:length(t1)
  if(t1(i)==2)
    pos2=i
    break;
  end
  end
pos2

compTray=sqrt ( (-t2.*y2(:,2)).^2 + (t2.*y2(:,1)-t2.*y2(:,2)).^2);
Tray=SimpsonCompuestoDatos(t2(1:pos2),compTray(1:pos2)); %pos es el valor para el cual t= 2.4927 q es donde toca el piso
disp("La trayectoria de la particula de 0 a 2.49 seg es")
Tray



##%PREGUNTA 4 -------------------------
##disp("-----------------Pregunta 4---------------")
##f=@(x) log(x^2+1)-exp(x/2)*cos(pi*x);
##x=linspace(-5,6,9);  %intervalo de -5 a 6 en 9 puntos
##xx=linspace(-5,6,201);
##%evaluamos en f para armar la tabla de los valores
##%y=[f(x(1)),f(x(2)),f(x(3)),f(x(4)),f(x(5)),f(x(6)),f(x(7)),f(x(8)),f(x(9))];
##y=arrayfun(f,x);
##disp("Tabla x e y")
##tabla=[x ; y]'
##
##[Sx,dSx]=funcion_spline(x,y,0,0);
##figure(1)
##plot(xx,Sx(xx),'r')
##grid on;
##hold on;
##%plot(xx,f(xx))
##
##%Evaluar el spline cúbico sujeto en x=4.2
##disp("El error es:")
##error=min(max(abs(y-Sx(4.2))))/2
##disp("--------------------------------------------")
##
##%PARA ENCONTRAR EL MAXIMO
##valor_max=-100000;
##for i=0:0.01:6
##  nuevo_max=Sx(i);
##  if(nuevo_max>valor_max)
##    xmax=i;
##    valor_max=nuevo_max;
##  end
##end
##format long;
##disp("El valor donde alcanza el maximo es")
##xmax
##disp("El maximo es:")
##valor_max
##
##
##[p, rh, it, t] = biseccion(dSx, 3, 5,10000,1e-5);
##disp("El valor donde alcanza el maximo es")
##p
##disp("Y su maximo es ")
##Sx(p)
