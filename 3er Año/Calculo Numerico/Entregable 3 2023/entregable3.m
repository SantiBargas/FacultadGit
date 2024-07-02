%Entregable 3
clc;
clear;
format long;
%----------------------------------------------------------------------------
%----INCISO A--------
%x(t) en funcion de t;
tx=[0,2,4,6];
x=[2,1.5,0.5,0];
df1=df2=0; %pq en x no tiene velocidad
[Sx,dSx,ax]=funcion_spline(tx,x,df1,df2);
ax=[ax,0];

%y(t) en funcion de t;
ty=[0,1,2,3,4,5,6];
y=[0,1.0,0.0,-1.0,0,1.0,0.0];
df1=pi/2;
df2=-pi/2;
[Sy,dSy,ay]=funcion_spline(ty,y,df1,df2);
ay=[ay,0];
%---------------------------------------------------------------------------

%------INCISO B----------

%grafico x(t) en funcion de t
tdx = [0 2 4 6];
xx = linspace(0,6,201);
figure(1)
plot(tdx,ax,'o',xx,Sx(xx));
title('Grafico x(t) en funcion de t')
xlabel('Eje X');
ylabel('Eje T(tiempo)');
legend('puntos','Funcion Spline Sx');
grid on;
grid minor;

%Grafico y(t) en funcion de t
tdy=[0 1 2 3 4 5 6 ];
yy=linspace(0,6,201);
figure(2)
plot(tdy,ay,'o',yy,Sy(yy))
title('Grafico y(t) en funcion de t');
xlabel('Eje T(tiempo)');
ylabel('Eje Y');
legend('puntos','Funcion Spline Sy');
grid on;
grid minor;

%graficamos X(t) en funcion y(t)
X=[x(1) Sx(1) x(2) Sx(3) x(3) Sx(5) x(4)]; %Sx son los valores de la tabla que no conocemos
figure(3)
%plot(Sx(xx),Sy(yy),'b-',X,y,'r*-');
plot(Sx(xx),Sy(yy),'b-',X,y,'r*-');
title('Grafico X(t) en funcion de y(t)')
xlabel('Eje X');
ylabel('Eje Y');
legend('Funcion Spline','Recta Aproximadora');
grid on;
grid minor;
disp("VALORES PARA LA TABLA")
X'
y'

%calculo para el tiempo de 3 segundos

disp("-------------------------------------------------------------------------------------------------")
disp('posicion en x para t=3 segundos');
posx3=Sx(3)
disp('componente velocidad en x');
vx3=dSx(3)

disp("-------------------------------------------------------------------------------------------------")
disp('posicion en y para t=3 segundos');
posy3=Sy(3)
disp('componente velocidad en y');
vy3=dSy(3)
disp("-------------------------------------------------------------------------------------------------")
disp('velocidad resultante en t=3 segundos')
Velocidad_3=sqrt(vx3^2+vy3^2)


%-----INCISO C--------
%para el calculo del punto c del entregable debemos usar integracion numerica
%Primero calculamos el integrando
%%%Integ=sqrt(dSx^2+dSy^2)
%luego integramos entre 0 y T: periodo a medir

f=@(t) sqrt(dSx(t).^2+dSy(t).^2);

%Aplicamos la integral para calcular la trayectoria
%Usamos Gauss-Legendre

disp("-------------------------------------------------------------------------------------------------")
a=0 ; b=6; L=20; n=6;
Q2=cuad_gauss_c(f,a,b,L,n);
disp('Valor de la trayectoria a los 6 segundos: Gauss L=20 n=6:')
Q2

disp("-------------------------------------------------------------------------------------------------")
a=0 ; b=6; L=40; n=6;
Q3=cuad_gauss_c(f,a,b,L,n);
disp('Valor de la trayectoria a los 6 segundos: Gauss L=40 n=6:')
Q3

disp("-------------------------------------------------------------------------------------------------")
a=0 ; b=6; L=80; n=6;
Q4=cuad_gauss_c(f,a,b,L,n);
disp('Valor de la trayectoria a los 6 segundos: Gauss L=80 n=6:')
Q4

disp("-------------------------------------------------------------------------------------------------")
a=0 ; b=6; L=160; n=6;
Q5=cuad_gauss_c(f,a,b,L,n);
disp('Valor de la trayectoria a los 6 segundos: Gauss L=160 n=6:')
Q5
disp("-------------------------------------------------------------------------------------------------")

%funcion quad de octave
QOCTAVE=quad(f,a,b,10^-6);
disp('el valor de la trayectoria a los 6 seg: Guass de Octave:')
QOCTAVE

disp("-------------------------------------------------------------------------------------------------")

%Trapezoidal compuesta
n=6000;
[T]=trap_comp(f,a,b,n);
disp('Valor de la trayectoria a los 6 seg: Trapezoidal compuesta n=6000')
T


disp("-------------------------------------------------------------------------------------------------")
%Simpson compuesta
L1=4000;
[S]= SimpsonCompuesto(f,a,b,L1);
disp('Valor de la trayectoria a los 6 seg: Simspon Compuesta L1=4000:')
S
disp("-------------------------------------------------------------------------------------------------")




