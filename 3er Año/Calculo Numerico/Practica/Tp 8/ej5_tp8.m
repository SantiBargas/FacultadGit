clc;clear all;


%DETERMINAMOS LA TEMPERATURA EN EL EXTREMO DERECHO DE LA BARRA.
K0=1;  %Conductividad termica
Largo = 3 %por tanto el intervalo es de 0 a 3
inter=[0 3];
y0=21;   %temperatura extremo izquierdo
Hnewton = 0; %no da informacion acerca de Hnewton
ue=0;  %no da informacion acerca de ue
fuente= @(x) 20 * sin(5*(x-1));  %Fuente de calor "r"
pR= @(x) 0.*x ;  %proceso reactivo, no hay por eso 0


%DIFUSION REACCION : -K0*u''(x) + cr(x)*u(x) = f(x)  0<=x<=Largo
%                     u''(x) =  -cr(x)*u(x)/-K0  -(f(x)/K0)
f=@(x) [(1/K0)*0.*x  (1/K0)*pR(x)  -(1/K0)*fuente(x)];
h=0.01;
L=(3-0)/0.05;

%ARMADO DE ROB : A*y'(b) + B*y(b) = C donde b es el extremo del intervalo
             %  -K0*u'(L) = H*u(L) -H*ue;
             %  -K0*u'(L) -H*u(L) =  -H*ue;
             %   -1*u'(L) -0*u(L) = 0 ;
rob=[-K0 0 0];



[xDFR,yDFR]=dif_fin_rob(f,inter,y0,rob,L);
yDFR(end)

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
% temperatura en el extremo derecho
TempExtDer=yDFR(end);
disp('Temperatura en el extremo derecho con dos digitos exactos:');
disp(TempExtDer)



%=====================================================================================
figure(1)
xx=linspace(0,300,201);
plot(xx,fuente(xx),'r-')
title('Funcion Fuente de calor')
xlabel('posicion: X')
ylabel('Fuente')
%=====================================================================================
figure(2)
plot(xDFR,yDFR,'b-*');
title('Temperatura a la largo de la barra calculada por DFinitas con h=0.1')
xlabel('posicion: X')
ylabel('Temperatura')
grid on;
grid minor




%===============Temperatura maxima ===================================================================
TempMax1=max(yDFR)

TempMax2=-1000;
pos=0;

for i=1:length(yDFR)
  if(yDFR(i)>TempMax2)
  TempMax2=yDFR(i);
  pos=xDFR(i);
  end
end
disp("La temperatura maxima es ")
TempMax2
disp("Y es alcanzada a la altura de la barra")
pos


