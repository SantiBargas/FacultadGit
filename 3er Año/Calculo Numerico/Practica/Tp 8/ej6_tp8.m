clc;clear all;
%ESTUDIO DIFUSION-REACCION DE CALOR

Largo=5; %cm
y0=6;   %Extremo izquierdo = 6 grados de temp
Hnewton=15;    %coef convectivo en la frontera. Extremo derecho de la brarra rige la ley de enfriamiento de Newton, H=Coef de transferencia de calor
K0=0.9;  %Conductividad termica
ue=4;   %temperatura exterior

fuente=@(x) 5*x.*(5-x);
pR=@(x) 1.05*x + 2;   %proceso reactivo

%DIFUSION REACCION : -K0*u''(x) + cr(x)*u(x) = f(x)  0<=x<=Largo
%                     u''(x) =  -cr(x)*u(x)/-K0  -(f(x)/K0)

f=@(x) [(0.*x)/K0   (pR(x)/K0)  -fuente(x)/K0];
%           u'          u        term independiente
%          p(x)*u'      q(x)*u        -r(x)
%          -y'' + p(x)*y' + q(x)*y + r(x) = 0

%LEY ENFRIAMIENTO DE NEWTON: -K0*u'(L) = H[u(L)-ue] (tipo robin)
% PVC tipo Robin -K0*u'(L) = H(u(L)-ue);
%                -K0*u'(L) = H*u(L) -H*ue;
%               -0.9*u'(5)-15*u(5)= -15*4
%               -0.9*u'(5)-15*u(5)= -60
rob=[-0.9 -15 -60];

inter=[0 Largo];
h=0.01;
L=(5-0)/h;
[xDFR yDFR]=dif_fin_rob(f,inter,y0,rob,L);


##%PARA QUE DE 4 DIGITOS EXACTOS
##N=4;
##for i=1:100
##  N = N*2;
##  [xDFR,yDFR1]=dif_fin_rob(f,inter,y0,rob,N);
##    if ( abs(yDFR1(end) - yDFR(end) ) < 1e-4)
##      yDFR=yDFR1;
##      break
##    endif
##     yDFR=yDFR1;
##endfor

%============================================================================
% temperatura en el extremo derecho
TempExtDer=yDFR(end);
disp('Temperatura en el extremo derecho:');
disp(TempExtDer)

figure(1)
plot(xDFR,yDFR,'b-*');
title('Temperatura a la largo de la barra calculada por DFinitas con h=0.1')
xlabel('posicion: X')
ylabel('Temperatura')
grid on; grid minor

%===============Temperatura maxima ===================================================================
[TempMax1,posMAX]=max(yDFR);
TempMax1
posMAX
##TempMax2=-1000;
##pos=0;
##for i=1:length(yDFR)
##  if(yDFR(i)>TempMax2)
##  TempMax2=yDFR(i);
##  pos=xDFR(i);
##  end
##end
##disp("La temperatura maxima es ")
##TempMax2
##disp("Y es alcanzada a la altura de la barra")
##pos

%====================Temperatura en el punto medio de la barra================
%punto medio = 2.5
disp("Temperatura en el punto medio de la barra")
yDFR(L/2)


Flujo_ExtDer=Hnewton*(yDFR(end)-ue);
disp('Flujo Extremo Derecho:');
disp(Flujo_ExtDer)
