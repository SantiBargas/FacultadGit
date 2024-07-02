#Ej8_TP05.m
clear all, clc; clf;
%DATOS:
x1 = [0,2,6];
y1 = [0,4,6];
t1 = [0,1,2];
x2 = [6,3,0];
y2 = [6,2,0];
t2 = [2,3,4];

% GRAFICA Tiempo vs X
figure (1)
plot(t1,x1,'bo','MarkerEdgeColor','k','MarkerFaceColor',[0.49 1 0.63],'MarkerSize',10,...
t2,x2,'bo','MarkerEdgeColor','k','MarkerFaceColor',[0.49 1 0.63],'MarkerSize',10);
grid on
grid minor
xlabel("Tiempo");
ylabel("Posicion en X");
title('Grafica Tiempo vs X');
hold on;

% GRAFICA T vs Y
figure (2);
plot(t1,y1,'o','MarkerEdgeColor','k','MarkerFaceColor',[0.49 1 0.63],'MarkerSize',10,...
t2,y2,'o','MarkerEdgeColor','k','MarkerFaceColor',[0.49 1 0.63],'MarkerSize',10);
grid on
grid minor
xlabel("Tiempo");
ylabel("Posicion en Y");
title('Grafica Tiempo vs Y');
hold on;

% GRAFICA X vs Y
figure (3);
plot(x1,y1,'o','MarkerEdgeColor','k','MarkerFaceColor',[0.49 1 0.63],'MarkerSize',10,...
x2,y2,'o','MarkerEdgeColor','k','MarkerFaceColor',[0.49 1 0.63],'MarkerSize',10);
grid on
grid minor
xlabel("X");
ylabel("Y");
title('Grafica X vs Y');
hold on;

% TRAYECTORIA EN X:
[Sx,dSx,ax,bx,cx,dx]=funcion_spline(t1,x1,0,0);
[Sx2,dSx2,ax2,bx2,cx2,dx2]=funcion_spline(t2,x2,0,0);

% TRAYECTORIA EN Y
[Sy,dSy,ay,by,cy,dy]=funcion_spline(t1,y1,0,0);
[Sy2,dSy2,ay2,by2,cy2,dy2]=funcion_spline(t2,y2,0,0);

tt1 = linspace(0,2,201);
tt2 = linspace(2,4,201);

figure (1);
plot(tt1,Sx(tt1),'b-',"linewidth",3);
hold on;
plot(tt2,Sx2(tt2),'r-',"linewidth",3);

figure (2);
plot(tt1,Sy(tt1),'b-',"linewidth",3);
hold on;
plot(tt2,Sy2(tt2),'r-',"linewidth",3);

figure(3);
plot(Sx(tt1),Sy(tt1),'b-',"linewidth",3)
hold on;
plot(Sx2(tt2),Sy2(tt2),'r-',"linewidth",3)


