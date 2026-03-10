syms a P t r real
% Tensiones en coordenadas cilíndricas
sr = P/2*(1-a^2/r^2)*(1+(1-3*a^2/r^2)*cos(2*t));
st = P/2*(1+a^2/r^2-(1+3*a^4/r^4)*cos(2*t));
srt = -P/2*(1-a^2/r^2)*(1+3*a^2/r^2)*sin(2*t);
% Matriz de rotación desde coordenadas x-y a coordenadas cilíndricas
ms_B = [cos(t),sin(t);-sin(t),cos(t)];
% Tensiones en coordenadas x-y (se pasa de coordenadas cilíndricas a coordenadas cartesianas x-y).
ms_TensCilind2D = [sr,srt;srt,st];
ms_Tensxy2D = simplify(ms_B'*ms_TensCilind2D*ms_B);

%% Dibujo de las tensiones 
% Datos de gráficoc
%view(2),axis equal
%Se aprovecha la simetría del problema
aNum = 1;
bNum = 20;
cNum = 20;
PNum = 1;
%Cantidad de divisiones en cada dirección
nX = 1000;
nY = 1000;
% Se obtiene las funciones de cada componente de las tensiones en coordenadas cilíndricas.
f_sr = matlabFunction(subs(sr,{a,P},{aNum,PNum}),'Vars',{r,t});
f_st = matlabFunction(subs(st,{a,P},{aNum,PNum}),'Vars',{r,t});
f_srt = matlabFunction(subs(srt,{a,P},{aNum,PNum}),'Vars',{r,t});
% Se obtiene las funciones de cada componente de las tensiones en coordenadas cartesianas.
f_Sx = matlabFunction(subs(ms_Tensxy2D(1,1),{a,P},{aNum,PNum}),'Vars',{r,t});
f_Sy = matlabFunction(subs(ms_Tensxy2D(2,2),{a,P},{aNum,PNum}),'Vars',{r,t});
f_Sxy = matlabFunction(subs(ms_Tensxy2D(1,2),{a,P},{aNum,PNum}),'Vars',{r,t});
% Grilla en coordenadas cartesianas
[m_X,m_Y] = meshgrid(linspace(0,bNum,nX+1),linspace(0,cNum,nY+1));
%se pone NaN en las posiciones en el interior del círculo donde no se quiere graficar.
m_IndDenCirc = m_X.^2+m_Y.^2<aNum^2;
m_X(m_IndDenCirc) = NaN;
m_Y(m_IndDenCirc) = NaN;
% Grilla en coordenadas cilíndricas
m_R = sqrt(m_X.^2+m_Y.^2);
m_Theta = atan2(m_Y,m_X);
% Tensiones evaluadas en la grilla
m_Sr = f_sr(m_R,m_Theta);
m_St = f_st(m_R,m_Theta);
m_Srt = f_srt(m_R,m_Theta);
%Gráficas
figure(1)
surf(m_X,m_Y,m_Sr,'EdgeColor','none')
title('Tensión \sigma_r')
xlabel('X')
ylabel('Y')
% axis equal
figure(2)
surf(m_X,m_Y,m_St,'EdgeColor','none')
title('Tensión \sigma_\theta')
xlabel('X')
ylabel('Y')
figure(3)
surf(m_X,m_Y,m_Srt,'EdgeColor','none')
title('Tensión \tau_{r \theta}')
xlabel('X')
ylabel('Y')

%% Tensiones principales y tensión máxima de corte
m_SumS = (m_Sr+m_St)/2;
m_DifS = (m_Sr-m_St)/2;
%m_Tmax = sqrt(m_DifS.^2+m_Srt.^2);
m_Smax = m_SumS+sqrt(m_DifS.^2+m_Srt.^2);
m_Smin = m_SumS-sqrt(m_DifS.^2+m_Srt.^2);
m_Tmax = (m_Smax-m_Smin)/2;
%Gráficas
figure(4)
surf(m_X,m_Y,m_Smax,'EdgeColor','none')
title('Tensión \sigma_{max}')
xlabel('X')
ylabel('Y')
figure(5)
surf(m_X,m_Y,m_Smin,'EdgeColor','none')
title('Tensión \sigma_{min}')
xlabel('X')
ylabel('Y')
figure(6)
surf(m_X,m_Y,m_Tmax,'EdgeColor','none')
title('Tensión \tau_{max}')
xlabel('X')
ylabel('Y')

%% Evaluación de las tensiones en la frontera
% Evaluación de tensiones en la frontera vertical con x=b
m_bNum = [aNum*2,aNum*4,aNum*6,aNum*10,aNum*20,aNum*50,aNum*1000];
%Frontera vertical
m_X = m_bNum';
m_Y = 0:cNum/100:cNum;
%Para evaluación de las tensiones
m_R = sqrt(bsxfun(@plus,m_X.^2,m_Y.^2));
m_Theta = bsxfun(@atan2,m_Y,m_X);
% Tensiones en coordenadas cilíndricas
m_SrFr = f_sr(m_R,m_Theta);
%m_StFr = f_st(m_R,m_Theta);
m_SrtFr = f_srt(m_R,m_Theta);
% Gráficas
figure(7)
plot(m_Y,m_SrFr)
grid on
legend({'2a','4a','6a','10a','20a','50a','1000a'},'Location','SouthEast')
title('Tensión \sigma_r en la frontera vertical')
figure(8)
plot(m_Y,m_SrtFr)
grid on
legend({'2a','4a','6a','10a','20a','50a','1000a'},'Location','SouthEast')
title('Tensión \sigma_{r \theta} en la frontera vertical')
% Tensiones en coordenadas X-Y
%Permite calcular exactamente cuál es la componente Tx del vector tracción
m_Sx = f_Sx(m_R,m_Theta);
% Gráficas
figure(9)
plot(m_Y,m_Sx)
grid on
legend({'2a','4a','6a','10a','20a','50a','1000a'},'Location','SouthEast')
title('Tensión \sigma_x en la frontera vertical')
