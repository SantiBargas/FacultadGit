%  Datos
%  =====
%     X0   : posiciones iniciales nodos 1 a nnod
%     mass : masas puntos 1 a nnod
%     conec: tabla de resortes y nodos conectados
%     rig  : constantes de resortes
%     Fext : cargas externas
%     fixa : que posiciones son constantes
clear all
global X0 mass conec rig Fext fixa ;
X0    = [0 0 40 0 5 5 10 5 30 5 35 5 10 10 13.33 10 26.67 10 30 10  20 20]';
#nodos    1    2   3    4    5    6    7        8        9    10      11

mass  = [2 2 2 2 2 2 2 2 2 2 4]'; #Masa de cada nodo

#CONEXIONES DE LA BARRA 1 CON NODO 1 Y 4
#                 BARRA 2 CON NODO 4 Y 5
#                 BARRA 3 CON NODO 5 Y 2....
conec = [1 4;
         4 5;
         5 2;
         4 8;
        11 9;
         4 7;
         1 3;
         5 10;
         2 6;
         7 11;
         10 11;
         7 8;
         9 10;
         4 3;
         5 6;
         8 11;
         9 5;
         6 10;
         3 7
         ];

rig   = [2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2]'; #Constante k de cada barra
fixa  = [1 2 3 4];  %posiciones del vector x0

#Fext  = @(t)[0 0 0 0 0 0 sin(t*pi) 0 sin(t*pi) 0 0 0 0 0 0 0 0 0 0 0 0 sin(t*pi)]';#Fuerza externa de cada nodo FRECUENCIA 1
#Fext  = @(t)[0 0 0 0 0 0 sin(t*pi/5) 0 sin(t*pi/5) 0 0 0 0 0 0 0 0 0 0 0 0 sin(t*pi/5)]';#Fuerza externa de cada nodo FRECUENCIA 5
#Fext  = @(t)[0 0 0 0 0 0 sin(t*pi*2) 0 sin(t*pi*2) 0 0 0 0 0 0 0 0 0 0 0 0 sin(t*pi*2)]';#Fuerza externa de cada nodo FRECUENCIA 1/2
Fext  = @(t)[0 0 0 0 0 0 sin(t*pi/2) 0 sin(t*pi/2) 0 0 0 0 0 0 0 0 0 0 0 0 sin(t*pi/2)]';#Fuerza externa de cada nodo FRECUENCIA 2
#Fext  = @(t)[0 0 0 0 0 0 sin(t*pi*10) 0 sin(t*pi*10) 0 0 0 0 0 0 0 0 0 0 0 0 sin(t*pi*10)]';#Fuerza externa de cada nodo FRECUENCIA 1/10

#nodos        1   2   3    4         5      6    7  8   9  10    11
nnod  = length(X0)/2;
Y0(1       :2*nnod,1) = X0(:,1);
Y0(2*nnod+1:4*nnod,1) = zeros(2*nnod,1); #Y0 Es el vector de condiciones iniciales

[t,Y] = ode15s(@odefunejer6,[0 50],Y0); %0 a 50 seg Y devuelve una posicion y una velocidad


##X  = Y(       1:2*nnod,:); #Posiciones iniciales
##Xp = Y(2*nnod+1:4*nnod,:); #Velocidades

X  = Y(:,1:2*nnod);  % Corrección: No es necesario transponer Y
Xp = Y(:,2*nnod+1:4*nnod);  % Corrección: No es necesario transponer Y


#plot(t,Y(:,44),'-o')
#plot(t,Xp(:,2),'-o')
##grid

filename = 'animacionfuerzasinusoidal-5.gif';
% Time in seconds for each plot in the GIF
FramesPorSegundo = 60;
DelayTime = 1/FramesPorSegundo;

% Create empty figure and assign number
f = figure;

% Tiempo en segundos de la duración total del GIF
GifTime = 1;
TotalFrames = FramesPorSegundo*GifTime;

for i=1:4:length(t);
  pause(DelayTime);
  clf;
  axis([0 45 -10 22]);
  hold on;
  grid on;
  title('Movimiento del reticulado con fuerza senoidal y frecuencia 2 ')
  xlabel('x');
  ylabel('y');
  text (41, 21, ["t=" num2str(t(i))]);
  for j=1:length(conec)
      n1 = conec(j,1);
      n2 = conec(j,2);
      plot([Y(i,n1*2 - 1) , Y(i,n2*2 -1)] ,[Y(i,n1*2) , Y(i,n2*2)] , 'k');
  endfor
  drawnow;
      % Image Processing
      % Assign plot to a frame
      frame = getframe(f);
      % Convert frame to RGB image (3 dimensional)
      im = frame2im(frame);
      % Transform RGB samples to 1 dimension with a color map "cm".
      [imind,cm] = rgb2ind(im);
      if t == 0;
          % Create GIF file
          imwrite(imind,cm,filename,'gif','DelayTime', DelayTime , 'Compression' , 'lzw');
      else
          % Add each new plot to GIF
          imwrite(imind,cm,filename,'gif','WriteMode','append','DelayTime', DelayTime , 'Compression' , 'lzw');
      end
endfor





##########################################################################################
##########EVOLUCION DEL NODO 4 5 y 11###########################################
##########################################################################################
figure;
##Obtener las coordenadas del nodo 4 en X e Y
nodo_B_X = Y(:, 7); % Coordenada X del nodo B
nodo_B_Y = Y(:, 8); % Coordenada Y del nodo B

## Graficar la evolución de las coordenadas del nodo 4 en función del tiempo

##plot(t, nodo_B_X, 'b-', 'LineWidth', 2); % Coordenada X
##hold on;
##plot(t, nodo_B_Y, 'r-', 'LineWidth', 2); % Coordenada Y
##plot(nodo_B_X, nodo_B_Y, 'k-', 'LineWidth', 2); % Trayectoria XY
##xlabel('Tiempo (s)');
##ylabel('Coordenadas');
##title('Evolución de las coordenadas del nodo 4 ');
##legend('Coordenada X', 'Coordenada Y','Coordenada X Y');
##grid on;
##
##
##figure;
####Obtener las coordenadas del nodo 5 en X e Y
##nodo_B_X = Y(:,9 ); % Coordenada X del nodo B
##nodo_B_Y = Y(:, 10); % Coordenada Y del nodo B
##
#### Graficar la evolución de las coordenadas del nodo 5 en función del tiempo
##
##plot(t, nodo_B_X, 'b-', 'LineWidth', 2); % Coordenada X
##hold on;
##plot(t, nodo_B_Y, 'r-', 'LineWidth', 2); % Coordenada Y
##plot(nodo_B_X, nodo_B_Y, 'k-', 'LineWidth', 2); % Trayectoria XY
##xlabel('Tiempo (s)');
##ylabel('Coordenadas');
##title('Evolución de las coordenadas del nodo 5');
##legend('Coordenada X', 'Coordenada Y','Coordenada X Y');
##grid on;
##
##figure;
####Obtener las coordenadas del nodo 11 en X e Y
##nodo_B_X = Y(:, 21); % Coordenada X del nodo B
##nodo_B_Y = Y(:, 22); % Coordenada Y del nodo B
##
#### Graficar la evolución de las coordenadas del nodo 11 en función del tiempo
##plot(t, nodo_B_X, 'b-', 'LineWidth', 2); % Coordenada X
##hold on;
##plot(t, nodo_B_Y, 'r-', 'LineWidth', 2); % Coordenada Y
##plot(nodo_B_X, nodo_B_Y, 'k-', 'LineWidth', 2); % Trayectoria XY
##xlabel('Tiempo (s)');
##ylabel('Coordenadas');
##title('Evolución de las coordenadas del nodo 11');
##legend('Coordenada X', 'Coordenada Y','Coordenada X Y');
##grid on;
##
##



