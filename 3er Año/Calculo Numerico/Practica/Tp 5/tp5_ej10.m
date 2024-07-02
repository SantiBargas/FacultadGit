clc
clear

x=[-1 0 1 2]' %o x=[1:2]
y=[-1.1 -0.4 -0.9 -2.7]'

%y=-exp( (a*x^2) + b*x + c );

%hay q transformar f con ln(-y) para aplicar el metodo de cuadrados minimos
ly=log(-y);
[coef2,A,b]=minimoscuadrados(x,ly,2);

r2=@(x) -exp(coef2(1).*x.^2 + coef2(2).*x + coef2(3));
        %-exp(    (ax^2)    +      b*x       + c );

# lo vemos graficamente:
xx = linspace(-1.5,2.5,201);

figure(1)
plot(x,y,'o',xx,r2(xx),'3')
grid on

# Medimos el error

errf = norm(y -r2(x)) # error cuadratico usando la funcion norm
ErrRelat = (f(0) + 0.4)/(-0.4)
# error realtivo en el punto 0
