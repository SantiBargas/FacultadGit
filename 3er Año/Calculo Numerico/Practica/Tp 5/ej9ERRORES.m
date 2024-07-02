# Ej9TP05
clear all
clc
clf
# datos
x = [0 1 2 3 4 5 6]'
y = [432 599 1012 1909 2977 4190 5961]'

xx=linspace(-1,10.5,201);


# interpolamos con lagrange
[PL, L] = Lagrange(x,y);
plag = @(x) polyval(PL,x);

figure(1)
 plot(x,y,'ro', xx,plag(xx),'k')
 grid on
 hold on
 xlabel ('X')
 ylabel('Y')
 legend('datos', 'Lagrange')
 
# Ajuste de datos

# Lineal

cp = polyfit(x,y,1);
p1 = @(x) polyval(cp,x);

plot(xx,p1(xx),'b')

legend('datos', 'Lagrange', 'Lineal')

# Cuadratico

cp4 = polyfit(x,y,4);
p4 = @(x) polyval(cp4,x);

plot(xx,p4(xx),'g')

legend('datos', 'Lagrange', 'Lineal','Cuadratico')

# Newton
[PN, c, N] = PolIntNewton(x, y);
pnew = @(x) polyval(PN,x);

plot(xx,pnew(xx),'y')
legend('datos', 'Lagrange', 'Lineal','Cuadratico', 'Newton')
y10=14900
ErrLag = norm(y10-plag(10))
ErrNew = norm(y10-pnew(10))
ErrLineal = norm(y10-p1(10))
Error_y10 = norm(y10-p4(10))
ErrorRelativo = abs((y10-p4(10))/y10)
ErrorCuadratico= norm(y - p4(x))