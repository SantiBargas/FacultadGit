clear all; clc; warning('off','all');
pkg load symbolic

# Se plantea una discretización de 4 ptos: [i-1, i, i+1 i+2]
# h: distancia entre u(i-1) y u(i)
# h1=1.1*h -> distancia entre u(i) y u(i+1)
# h2=1.1*h+1.1*h1=1.1(h+1.1*h)=2.31*h -> distancia entre u(i) y u(i+1)

syms h
h1 = 1.1*h;
h2 = 2.31*h;
uno = sym(1);
K = [ uno,       uno, uno,       uno;
      -h,        0,   h1,        h2;
      (h^2)/2,   0,   (h1^2)/2,  (h2^2)/2;
      -(h^3)/6,  0,   (h1^3)/6,  (h2^3)/6
    ];
F = [0; 0; 1; 0]; # 1 en la derivada segunda
a = K\F;
coef = double(subs(a,h,1));
# El resultado de la aproximación de la d2u_dx2 es:
# (coef(1)*u(i-1)+coef(2)*u(i)+coef(3)*u(i+1)+coef(4)*u(i+2))/h^2

# DEMOSTRACIÓN NUMÉRICA
# Dato exacto
u_ex = @(x) exp(-x^2);
d2u_dx2_ex = @(x) 2*exp(-x^2)*(2*x^2-1);
pto = 0.5;
d2u_dx2_ex_pto = d2u_dx2_ex(pto);

res = [];
h_num = 2;
for i=1:10 # 10 refinamientos sucesivos
  h1_num = 1.1*h_num;
  h2_num = 2.31*h_num;
  a_num = double(subs(a,h,h_num));

  # evaluación numérica de la derivada segunda en el pto 0.5
  d2u_dx2_ap = a_num(1)*u_ex(pto-h_num)+a_num(2)*u_ex(pto)+...
               a_num(3)*u_ex(pto+h1_num)+a_num(4)*u_ex(pto+h2_num);
  err = abs(d2u_dx2_ex_pto - d2u_dx2_ap);
  res = [res; h_num err];
  h_num = h_num/2;
endfor

subplot(1,2,1)
plot(res(:,1), res(:,2), '-x')
title('h vs error')

x = log(res(:,1)); y = log(res(:,2));
subplot(1,2,2)
plot(x,y)
title('log(h) vs log(error)')

p = polyfit(x,y,1)(1);
fprintf('Pendiente de la recta: %f \n', p);

m = mean(res(1:9,2)./res(2:10,2));
fprintf('Media de err(h)/err(h/2): %f \n', m);
