clc;
clear all;
format long;


inter=[1 4];
a=1;
b=4;

y1=1;
y4=2.9736954;

yc=[y1 y4];

% y'' = p(x)y' + q(x)y + r(x) para x en [a,b]
% y(a)=alpha , y(b)=beta
%f: funcion columnas con las funciones p,q,r
%L: cantidad de subintervalos

f=@(x) [ ((-11/3).*(1./x))  (1./x.^2) ((-log(x)+(8/3))./(x.^2))];
h=0.001;
L=(b-a)/h;

[xDIF,yDIF]=dif_fin_dir(f,inter,yc,L);

##for i=1:100
##  L = L*2;
## [xDIF,yDIF1]=dif_fin_dir(f,inter,yc,L);
##
##     if ( abs(yDFR1(end) - yDFR(end) ) < 1e-5)  %si pide 4 digitos ponemos 1e-5
##      yDIF=yDIF1;
##      break
##    endif
##  yDIF=yDFI1;
##endfor

%Buscamos el valor correspondiente donde x=2.5 y vemos cuanto vale y
valorBus=-10000;
for i=1:size(yDIF)
  if (xDIF(i) == 2.5)
    valorBus=yDIF(i);
    pos=i;
  end
end
disp("El valor es")
valorBus
disp("En la pos:")
pos

##%para hallar y'(x)
deri=(yDIF(pos)-yDIF(pos-1))/h;
disp("El valor estimado de la derivada es")
deri

%Estimamos la integral

##%ENERGIA TOTAL
Q = (SimpsonComp(xDIF,yDIF));
disp("La integral de 1 a 4 es")
Q


