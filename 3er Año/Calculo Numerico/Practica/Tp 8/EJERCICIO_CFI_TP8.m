clc;clear all;
format long;
%rob=[-K0 -Hnewton -Hnewton*ue];
##%=======EJERCICIO 1==============================================================================================================================================================
##
##%ESTUDIO DIFUSION-REACCION DE CALOR
##Largo=5; %cm
##y0=6;   %Extremo izquierdo = 6 grados de temp
##Hnewton=15;    %coef convectivo en la frontera. Extremo derecho de la brarra rige la ley de enfriamiento de Newton, H=Coef de transferencia de calor
##K0=0.9;  %Conductividad termica
##ue=4;   %temperatura exterior
##
##fuente=@(x) 5*x.*(5-x);
##pR=@(x) 0.5*x + 0.5;   %proceso reactivo
##
##%DIFUSION REACCION : -K0*u''(x) + cr(x)*u(x) = f(x)  0<=x<=Largo
##%                     u''(x) =  -cr(x)*u(x)/-K0  -(f(x)/K0)
##
##f=@(x) [(0.*x)/K0   (pR(x)/K0)  -fuente(x)/K0];
##%           u'          u        term independiente
##%          p(x)*u'      q(x)*u        r(x)
##
##%LEY ENFRIAMIENTO DE NEWTON: -K0*u'(L) = H[u(L)-ue] (tipo robin)
##% PVC tipo Robin -K0*u'(L) = H(u(L)-ue);
##%                -K0*u'(L) = H*u(L) -H*ue;
##%               -0.9*u'(5)-15*u(5)= -15*4
##%               -0.9*u'(5)-15*u(5)= -60
##rob=[-K0 -Hnewton -Hnewton*ue];
##
##inter=[0 Largo];
##h=0.01;
##L=(5-0)/h;
##[xDFR yDFR]=dif_fin_rob(f,inter,y0,rob,L);
##disp("Temperatura en el punto medio de la barra")
##yDFR(L/2)
##
##
##%El flujo en el extremo izq esta dado por o(x)=-K0*u'(x)
##%para hallar u'(x)
##phi=(yDFR(2)-yDFR(1))/h
##Flujo_ExtIzq=phi*-K0;
##
##disp('Flujo Extremo Izquierdo:')
##disp(Flujo_ExtIzq)
##
##disp("=========================================================================================================================================")

%=======================EJERCICIO 2==============================================================================================================================================

##
##%DETERMINAMOS LA TEMPERATURA EN EL EXTREMO DERECHO DE LA BARRA.
##K0=1;  %Conductividad termica
##Largo = 3; %por tanto el intervalo es de 0 a 3
##inter=[0 3];
##y0=21;   %temperatura extremo izquierdo
##Hnewton = 0; %no da informacion acerca de Hnewton
##ue=0;  %no da informacion acerca de ue
##fuente= @(x) 20 * sin(5*(x-1));  %Fuente de calor "r"
##pR= @(x) 2 + 0.*x ;  %proceso reactivo, no hay por eso 0
##cR=2;
##
##%DIFUSION REACCION : -K0*u''(x) + cr(x)*u(x) = f(x)  0<=x<=Largo
##%                     u''(x) =  -cr(x)*u(x)/-K0  -(f(x)/K0)
##
##f=@(x) [(0.*x)/K0   ((pR(x))/K0)  -fuente(x)/K0];
##h=0.01;
##L=(3-0)/h;
##
##%ARMADO DE ROB : A*y'(b) + B*y(b) = C donde b es el extremo del intervalo
##             %  -K0*u'(L) = H*u(L) -H*ue;
##             %  -K0*u'(L) -H*u(L) =  -H*ue;
##             %   -1*u'(L) -0*u(L) = 0 ;
##
##rob=[-K0 0 0];
##
##[xDFR,yDFR]=dif_fin_rob(f,inter,y0,rob,L);
##disp('Temperatura en el extremo derecho:');
##yDFR(end)
##
##%El flujo en el extremo izq esta dado por o(x)=-K0*u'(x)
##%para hallar u'(x)
##phi=(yDFR(2)-yDFR(1))/h
##Flujo_ExtIzq=phi*-K0

%===========================EJERCICIO 3==========================================================================================================================================
%DETERMINAMOS LA TEMPERATURA EN EL EXTREMO DERECHO DE LA BARRA.
K0=1;  %Conductividad termica
Largo = 3 %por tanto el intervalo es de 0 a 3
inter=[0 3];
y0=21;   %temperatura extremo izquierdo
Hnewton = 5; %no da informacion acerca de Hnewton
ue=10;  %no da informacion acerca de ue
fuente= @(x) 20 * sin(5*(x-1));  %Fuente de calor "r"
pR= @(x) 0.*x ;  %proceso reactivo, no hay por eso 0
H=5;
ue=10;

%DIFUSION REACCION : -K0*u''(x) + cr(x)*u(x) = f(x)  0<=x<=Largo
%                     u''(x) =  -cr(x)*u(x)/-K0  -(f(x)/K0)
f=@(x) [(1/K0)*0.*x  (1/K0)*pR(x)  -(1/K0)*fuente(x)];
h=0.01;
L=(3-0)/h;

%ARMADO DE ROB : A*y'(b) + B*y(b) = C donde b es el extremo del intervalo
             %  -K0*u'(L) = H*u(L) -H*ue;
             %  -K0*u'(L) -H*u(L) =  -H*ue;
             %   -1*u'(L) -5*u(L) = -5*10 ;
rob=[-1 -5 -50];
inter=[0 Largo];

[xDFR,yDFR]=dif_fin_rob(f,inter,y0,rob,L);
disp("Temperatura en el extremo derecho")
yDFR(end)


Flujo_ExtDer=Hnewton*(yDFR(end)-ue);
disp('Flujo Extremo Derecho:');
disp(Flujo_ExtDer)


##%PARA QUE DE 2 DIGITOS EXACTOS
##N=2;
##for i=1:100
##  N = N*2;
##  [xDFR,yDFR1]=dif_fin_rob(f,inter,y0,rob,N);
##    if ( abs(yDFR1(end) - yDFR(end) ) < 1e-2)
##      yDFR=yDFR1;
##      break
##    endif
##     yDFR=yDFR1;
##endfor
##
##disp("Temperatura en el extremo derecho")
##yDFR(end)
##
##
##Flujo_ExtDer=Hnewton*(yDFR(end)-ue);
##disp('Flujo Extremo Derecho:');
##disp(Flujo_ExtDer)

##%==========EJERCICIO 4 y 6 =========================================================================================================================================================
##Largo = 2;
##A = 0.01; %area
##c=0.217;  %calor especifico
##p=2.7;    %densidad
##K0=0.57;   %Conductividad termica
##y0=6;     %Extremo izq temperatura
##H=15;     % Extremo derecho rige la ley de enfriamiento de newton, coef de trasnferencia de calor
##ue=4;     % Temperatura exterior
##fuente=@(x) 2*x.*(2-x)
##pR=@(x) 0.1*x.^3+2.5;  %Proceso reactivo
##
##
##
##%DIFUSION REACCION : -K0*u''(x) + cr(x)*u(x) = f(x)  0<=x<=Largo
##%                     u''(x) =  -cr(x)*u(x)/-K0  -(f(x)/K0)
##
##f=@(x) [(0.*x)/K0   (pR(x)/K0)  -fuente(x)/K0];
##
##
##%LEY ENFRIAMIENTO DE NEWTON: -K0*u'(L) = H[u(L)-ue] (tipo robin)
##% PVC tipo Robin -K0*u'(L) = H(u(L)-ue);
##%                -K0*u'(L) = H*u(L) -H*ue;
##%               -0.57*u'(2)-15*u(2)= -15*4
##%               -0.57*u'(2)-15*u(2)= -60
##
##rob=[-0.57 -15 -60];
##inter=[0 Largo];
##
##%PARA VER LAS CIFRAS DECIMALES EXACTAS VAMOS DUPLICANDO h HASTA Q NO CAMBIEN LOS 4 DIGITOS
##h=0.01;
##L=(Largo-0)/h;
##[xDFR,yDFR]=dif_fin_rob(f,inter,y0,rob,L);
##
##%TEMP EXTREMO DERECHO
##disp("La temperatura en el extremo derecho es:")
##yDFR(end)
##
####for i=1:3
####  h=h*2;
####  L=(Largo-0)/h;
####  [xDFR,yDFR]=dif_fin_rob(f,inter,y0,rob,L);
####yDFR(end)
####  end
##
##
##%FLUJO EXTREMO DERECHO
##Flujo_ExtDer=H*(yDFR(end)-ue);
##disp('Flujo Extremo Derecho:');
##disp(Flujo_ExtDer)
##
##%ENERGIA TOTAL
##%Dice que se calcula como A* integral de 0 a L (c*p*u(x) dx)
##Coef=c*A*p;
##Q = Coef*(SimpsonComp(xDFR,yDFR));
##disp('Energia Termica:');
##disp(Q)
##

%===EJERCICIO PENDULO===================

L=1;
h=3/4;

y0=[pi/2 0 ]; % suelta del reposo en posicion pi/2 ; velocidad 0

inter=[0 5]; %para buscar el tiempo t

f=@(x) -amor - sin(x);

[t2,y2]=rk4(f, inter2, z0, L);

[x,y]=disparo_lineal(f,inter,yc,L1)
