

clc;

[x,y]=meshgrid(-4:1:4,-4:1:4);

 % --- 1 ---
## u1 = (1/(2*pi))*(x./(x.^(2)+y.^(2)));
## v1 = (1/(2*pi))*(y./(x.^(2)+y.^(2)));
## figure(1);
## quiver(x,y,u1,v1,'b');
## hold on;
## u1 = zeros(size(x));
## v1 = zeros(size(x))
## quiver(x,y,u1,v1,'r')
#### title('Potencial 1');
## axis tight;


 % --- 2 ---
## u2 = 1;
## u2 = ones(length(x),length(y));
## v2 = 0;
## v2 = zeros(length(x),length(y));
## figure(2);
## quiver(x,y,u2,v2,'b');
## hold on;
#### u2 = ones(length(x),length(y));
#### v2 = zeros(length(x),length(y));
#### quiver(x,y,u2,v2,'r')
#### title('Potencial 2');
## axis tight;

## % --- 3 ---
##%definicion de la funcion
## A = 1;
## n = 2;
## r = x.^(2) + y.^(2);
## theta = atan2(y,x);
## u_r = A*n*(r.^(n-1))*cos(n*theta);
## u_theta = -A*n*(r.^(n-1))*sin(n*theta);
## u = u_r*cos(theta) - u_theta*sin(theta);
## v = u_r*sin(theta) + u_theta*cos(theta);
####
## figure 3;
## quiver(x,y,u,v,'b');
## title('Potencial 3');
##axis tight;

## % --- 4 ---

 u_r = -cos(theta)./(r^(2));
 u_theta = -sin(theta)./(r^(2));

 u = u_r*cos(theta) - u_theta*sin(theta);
 v = u_r*sin(theta) + u_theta*cos(theta);
 figure 4;
 quiver(x,y,u,v,'b');
 hold on;
 title('Potencial 4)');
 axis tight;



