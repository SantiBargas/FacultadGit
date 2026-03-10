clc;

[x,y]=meshgrid(-4:1:4,-4:1:4);

 % --- 1 ---
 %---ej 1
 u1 = (1/(2*pi))*(x./(x.^(2)+y.^(2)));
 v1 = (1/(2*pi))*(y./(x.^(2)+y.^(2)));
 figure(1);
 quiver(x,y,u1,v1,'b');
 hold on;
 %----ej 2
 % c = 0;
 % u1 = (c/r) = 0/r = 0;
 u2 = zeros(size(x));
 % v1 = 0;
 v2 = zeros(size(x))
 quiver(x,y,u2,v2,'r')
 title('Potencial y Corriente 1');
 axis tight;
 xlabel("x");
 ylabel("y");

  %--- 2 ---
 %----ej 1
 u2 = 1;
 u2 = ones(length(x),length(y));
 v2 = 0;
 v2 = zeros(length(x),length(y));
 figure(2);
 quiver(x,y,u2,v2,'b');
 hold on;
 %----ej 2
 u2 = ones(length(x),length(y));
 v2 = zeros(length(x),length(y));
 quiver(x,y,u2,v2,'r')
 title('Potencial y Corriente 2');
 axis tight;

 % --- 3 ---
%---ej1
%definicion de la funcion
 A = 1;
 n = 2;
 r = x.^(2) + y.^(2);
 theta = atan2(y,x);
 u_r = A*n*(r.^(n-1))*cos(n*theta);
 u_theta = -A*n*(r.^(n-1))*sin(n*theta);
 u = u_r*cos(theta) - u_theta*sin(theta);
 v = u_r*sin(theta) + u_theta*cos(theta);
 figure 3;
 quiver(x,y,u,v,'b');
 hold on
 title('Potencial y Corriente 3');
axis tight;

%---ej2
 u_r = A*n*(r.^(n-1))*cos(n*theta);
 u_theta = -A*n*(r.^(n-1))*sin(n*theta);

 u = u_r*cos(theta) - u_theta*sin(theta);
 v = u_r*sin(theta) + u_theta*cos(theta);
 quiver(x,y,u,v,'r');

## % --- 4 ---
%---ej1
 u_r = -cos(theta)./(r^(2));
 u_theta = -sin(theta)./(r^(2));
 u = u_r*cos(theta) - u_theta*sin(theta);
 v = u_r*sin(theta) + u_theta*cos(theta);
 figure 4;
 quiver(x,y,u,v,'b');
 hold on;
 title('Potencial y Corriente 4');
 axis tight;

 %--ej2
 u_r = -cos(theta)./(r^(2));
 u_theta = -sin(theta)./(r^(2));
 u = u_r*cos(theta) - u_theta*sin(theta);
 v = u_r*sin(theta) + u_theta*cos(theta);
 quiver(x,y,u,v,'r');

