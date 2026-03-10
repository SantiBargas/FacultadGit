%  Datos
%  =====
%     X0   : posiciones iniciales nodos 1 a nnod
%     mass : masas puntos 1 a nnod
%     conec: tabla de resortes y nodos conectados
%     rig  : constantes de resortes
%     Fext : cargas externas
%     fixa : que posiciones son constantes
clear all
global X0 mass conec rig Fext fixa;
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
Fext  = [0 0 0 0 0 0 -1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 -1  ]';#Fuerza externa de cada nodo
#nodos    1   2   3    4   5    6  7   8   9   10  11
nnod  = length(X0)/2;

Y0(1       :2*nnod,1) = X0(:,1);
Y0(2*nnod+1:4*nnod,1) = zeros(2*nnod,1); #Y0 Es el vector de condiciones iniciales

[t,Y] = ode15s(@odefunejer6,[0 50],Y0); %0 a 50 seg Y devuelve una posicion y una velocidad

Y(:, 23:26)

X  = Y(       1:2*nnod,:); #Posiciones iniciales
Xp = Y(2*nnod+1:4*nnod,:); #Velocidades


#plot(t,Y(:,44),'-o')
#plot(t,Xp(:,2),'-o')
##grid

##########################################################################################
################# ANIMACION DEL RETICULADO ################################################
##########################################################################################

   % Configuración para pantalla completa
 #   figure('position', get(0, 'screensize'));

##for i= 1:length(Y)
##  pause(0.01)
##  clf;
##  %PLOT DE BARRAS:
##  set(0, 'defaultfigurevisible', 'off');
##  axis([-2 41 -2 21])
##  hold on; grid on;
##  title('Movimiento del reticulado')
##  xlabel('Posicion(x)');
##  ylabel('Posicion(y)');
##
##  for j = 1:length(conec)
##    n1 = conec(j,1);
##    n2 = conec(j,2);
##    plot([Y(i,n1*2 - 1) , Y(i,n2*2-1)] ,[Y(i,n1*2) , Y(i,n2*2)] , "k");
##  endfor
##
##  filename=sprintf('gif/%05d.png' , i);
##  disp(filename);
## saveas(gcf, filename); % Guarda la figura como un archivo de imagen PNG
##
## endfor
##
##########################################################################################
##########EVOLUCION DEL ESFUERZO DE LA BARRA 2###########################################
##########################################################################################
##
##barra2 = zeros(length(t), 1);
##k=2; #Rigidez
##for i=1:length(t)
##      N4= [Y(i,6),Y(i,7)];
##      N5= [Y(i,8),Y(i,9)];
##      FB= (norm(N5-N4) * k)
##      barra2(i)=FB;
##endfor
##
##% Graficar la evolución de la fuerza en la barra 4-5 con respecto al tiempo
##figure;
##plot(t, barra2, 'b-', 'LineWidth', 2);
##xlabel('Tiempo (s)');
##ylabel('Fuerza (N)');
##title('Evolución de la fuerza en la barra 4-5');
##grid on;
##
#######################################################
#######################################################
#######################################################
##
##


filename = 'FuerzaUniforme.gif';
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
  title('Movimiento del reticulado con fuerza fija')
  xlabel('x');
  ylabel('y');
  text (41, 21, ["t=" num2str(t(i))]);
  for j=1:length(conec)
      n1 = conec(j,1);
      n2 = conec(j,2);
      plot([Y(i,n1*2 - 1) , Y(i,n2*2 -1)] ,[Y(i,n1*2) , Y(i,n2*2)] ,'k');
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



##
############################################################################################
############EVOLUCION DEL NODO B###########################################
############################################################################################
##
##% Obtener las coordenadas del nodo B en X e Y
##nodo_B_X = Y(:, 21); % Coordenada X del nodo B
##nodo_B_Y = Y(:, 22); % Coordenada Y del nodo B
##
##% Graficar la evolución de las coordenadas del nodo B en función del tiempo
##figure;
##plot(t, nodo_B_X, 'b-', 'LineWidth', 2); % Coordenada X
##hold on;
##plot(t, nodo_B_Y, 'r-', 'LineWidth', 2); % Coordenada Y
##plot(nodo_B_X, nodo_B_Y, 'k-', 'LineWidth', 2); % Trayectoria XY
##xlabel('Tiempo (s)');
##ylabel('Coordenadas');
##title('Evolución de las coordenadas del nodo B');
##legend('Coordenada X', 'Coordenada Y','Coordenada X Y');
##grid on;

##########################################################################################
##########################################################################################
##########################################################################################

##########################################################################################
######### MAXIMO DESPLAZAMIENTO ##########################################################
##########################################################################################
##

#Sacamos todos los desplazamientos pero acordarse que esta en x e y por eso da 22 columnas
#X0 Contiene las posiciones iniciales de cada nodo
# Y(:, 21:44)


for i = 1 : length(X0)
  desp(:,i) = abs(Y(:,i) - X0(i));
endfor


for i=1 :2: length(X0)
  for j = 1 :length(desp(:,i))
    magnitud_desplazamiento(j,(i+1)/2) = norm([desp(j,i) desp(j,i+1)]);
  endfor
endfor

max_por_nodo = zeros(size(magnitud_desplazamiento, 2), 2); % Inicializar matriz para
                                                           % almacenar máximo desplazamiento y
                                                            %tiempo 2 col 11 filas

for i = 1:size(magnitud_desplazamiento, 2)
    [max_valor, indice_tiempo] = max(magnitud_desplazamiento(:, i)); % Encontrar máximo desplazamiento
                                                                      %y su índice de tiempo
    tiempo_maximo = t(indice_tiempo); % Obtener el tiempo correspondiente al índice de tiempo
    max_por_nodo(i, :) = [max_valor, tiempo_maximo]; % Almacenar máximo desplazamiento y tiempo en la matriz
endfor

max_por_nodo
[vMax vMaxFilas] = max(magnitud_desplazamiento)
[vMax vMaxColumna] = max(vMax)
iMax = vMaxFilas(vMaxColumna) % nro_fila del desplazamiento maximo
jMax = vMaxColumna          % nro_columna del desplazamiento maximo.

% Gráfico de barras para los máximos desplazamientos de cada nodo
figure;
bar(max_por_nodo(:, 1));
xlabel('Nodo');
ylabel('Máximo desplazamiento');
title('Máximos desplazamientos por nodo');

% Gráfico de líneas para el desplazamiento máximo de cada nodo en función del tiempo
figure;
for i = 1:size(magnitud_desplazamiento, 2)
    plot(t, magnitud_desplazamiento(:, i), 'DisplayName', sprintf('Nodo %d', i));
    hold on;
endfor
xlabel('Tiempo');
ylabel('Desplazamiento máximo');
title('Desplazamiento máximo por nodo en función del tiempo');
legend('Location', 'northeast');

% Gráfico de dispersión para los tiempos de los máximos desplazamientos por nodo
% Colores para cada nodo
colores = hsv(size(max_por_nodo, 1));

% Gráfico de dispersión para los tiempos de los máximos desplazamientos por nodo
figure;
for i = 1:size(max_por_nodo, 1)
    scatter(i, max_por_nodo(i, 2), 50, colores(i, :), 'filled', 'DisplayName', sprintf('Nodo %d', i));
    hold on;
endfor
xlabel('Nodo');
ylabel('Tiempo del máximo desplazamiento');
title('Tiempo del máximo desplazamiento por nodo');
xlim([0.5, size(max_por_nodo, 1) + 0.5]); % Ajustar límites del eje x para que los nodos se muestren de forma discreta
set(gca, 'xtick', 1:size(max_por_nodo, 1)); % Establecer marcas de los ejes x en valores enteros
legend('Location', 'northeast');





