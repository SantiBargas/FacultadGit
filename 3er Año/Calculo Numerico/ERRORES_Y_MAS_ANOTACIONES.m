%clc;
%clear all;
%%Todos los errores:
%ErrLagREAL = norm(y10-plag(10))  y10 es cuanto vale 10 en la funcion original
%ErrNew = norm(y10-pnew(10))  y10 es cuanto vale 10 en la funcion original
%ErrLineal = norm(y10-p1(10))
%Error_y10 = norm(y10-p4(10))
%ErrorRelativo = abs((y10-p4(10))/y10)   y10 es cuanto vale 10 en la funcion original, y p4(10) cuanto vale 10 en el polinomio interpolado
%ErrorCuadratico= norm(y - p4(x))    siendo "y" un vector con puntos y "x" un vector con los puntos correspondientes p4 un polinomio
%Error maximo teorico( lagrange ) =abs((x-x0)(x-x1)(x-x2)(x-xn) / factorial(n+1)) * max(ddddf(x));

%% Cosas a tener en cuenta:
  %*Cuando llamamos a la funcion Lagrange o Polinw, para crear el polinomio tenemos que llamar a polyval(P,x) en caso de Lagrange
  %Y cuando tenemos una cierta cantidad de puntos hacemos ##x=[0 1 2 3 4 5 6]';
                                                          ##y=[432 599 1012 1909 2977 4190 5961]';
                                                          ##cp = polyfit(x,y,grado);
                                                          ##f = @(x) polyval(cp,x);     //aca tambien podemos ponerle el @(x) para hacerlo "funcion"

