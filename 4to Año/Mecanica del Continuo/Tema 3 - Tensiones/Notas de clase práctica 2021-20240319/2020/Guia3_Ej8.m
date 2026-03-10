%%
clear

%% Coordenadas del rectángulo
m_CoordX = [-2,2];
m_CoordY = [-2,2];
[m_CoordXGrid,m_CoordYGrid] = meshgrid(m_CoordX,m_CoordY);

%% Tensiones
f_TensXX = @(x,y,a,b,c,d)2*c*x+6*d*y;
f_TensYY = @(x,y,a,b,c,d)6*a*x+2*b*y;
f_TensXY = @(x,y,a,b,c,d)-2*b*x-2*c*y;
f_Tens = @(x,y,a,b,c,d)[f_TensXX,f_TensXY;f_TensXY,f_TensYY];

%% Caso i (se asume que la superficie es un plano)
a = 0;
b = 0;
c = 0;
d = 1;
% Tensión XX
surf(m_CoordXGrid,m_CoordYGrid,f_TensXX(m_CoordXGrid,m_CoordYGrid,a,b,c,d),'FaceColor','r')
% Tensión YY
hold on
surf(m_CoordXGrid,m_CoordYGrid,f_TensYY(m_CoordXGrid,m_CoordYGrid,a,b,c,d),'FaceColor','b')
% Tensión XY
surf(m_CoordXGrid,m_CoordYGrid,f_TensXY(m_CoordXGrid,m_CoordYGrid,a,b,c,d),'FaceColor','g')
hold off
legend('Tensión XX','Tensión YY','Tensión XY')
xlabel('X')
ylabel('Y')
zlabel('Tensiones')

%% Caso ii (se asume que la superficie es un plano)
a = 1;
b = 0;
c = 0;
d = 0;
% Tensión XX
surf(m_CoordXGrid,m_CoordYGrid,f_TensXX(m_CoordXGrid,m_CoordYGrid,a,b,c,d),'FaceColor','r')
% Tensión YY
hold on
surf(m_CoordXGrid,m_CoordYGrid,f_TensYY(m_CoordXGrid,m_CoordYGrid,a,b,c,d),'FaceColor','b')
% Tensión XY
surf(m_CoordXGrid,m_CoordYGrid,f_TensXY(m_CoordXGrid,m_CoordYGrid,a,b,c,d),'FaceColor','g')
hold off
legend('Tensión XX','Tensión YY','Tensión XY')
xlabel('X')
ylabel('Y')
zlabel('Tensiones')

%% Caso iii (se asume que la superficie es un plano)
a = 0;
b = 1;
c = 0;
d = 0;
% Tensión XX
surf(m_CoordXGrid,m_CoordYGrid,f_TensXX(m_CoordXGrid,m_CoordYGrid,a,b,c,d),'FaceColor','r')
% Tensión YY
hold on
surf(m_CoordXGrid,m_CoordYGrid,f_TensYY(m_CoordXGrid,m_CoordYGrid,a,b,c,d),'FaceColor','b')
% Tensión XY
surf(m_CoordXGrid,m_CoordYGrid,f_TensXY(m_CoordXGrid,m_CoordYGrid,a,b,c,d),'FaceColor','g')
hold off
legend('Tensión XX','Tensión YY','Tensión XY')
xlabel('X')
ylabel('Y')
zlabel('Tensiones')
