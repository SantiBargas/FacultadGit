function ej4
% Frecuencia 5Hz y duracion 1 seg

% Frecuencia de muestreo = 100
[t,y1]=ej1_a_senoidal(0,1,100,5,2,0);
figure "1"; % Crear una nueva ventana de gráficos
stem(t,y1);
title('Frecuencia de muestreo = 100');

% Frecuencia de muestreo = 25
[t2,y2]=ej1_a_senoidal(0,1,25,5,2,0);
figure "2"; % Crear una nueva ventana de gráficos
stem(t2,y2);
title('Frecuencia de muestreo = 25');

% Frecuencia de muestreo = 10
[t3,y3]=ej1_a_senoidal(0,1,10,5,2,0);
figure "3"; % Crear una nueva ventana de gráficos
stem(t3,y3);
axis([-0.5 1 -1 1])
title('Frecuencia de muestreo = 10');

#Da valores aproximados a cero pero deberia dar todos 0 ya que evalua cada vez que el periodo*2 vuelve a iniciar

% Frecuencia de muestreo = 4
[t4,y4]=ej1_a_senoidal(0,1,4,5,2,0);
figure "4"; % Crear una nueva ventana de gráficos
stem(t4,y4);
title('Frecuencia de muestreo = 4');

% Frecuencia de muestreo = 1
[t5,y5]=ej1_a_senoidal(0,1,1,5,2,0);
figure "5"; % Crear una nueva ventana de gráficos
stem(t5,y5);
title('Frecuencia de muestreo = 1');

% Frecuencia de muestreo = 0,5
[t6,y6]=ej1_a_senoidal(0,1,0.5,5,2,0);
figure "6"; % Crear una nueva ventana de gráficos
stem(t6,y6);
title('Frecuencia de muestreo = 0,5');

#Frecuencia de 0.5 y el tiempo va de 0 a 1 no grafica

end
#COMO DICE FRECUENCIA DE 5HZ LAS QUE CORRESPONDEN SON LA DE FM=100 Y FM=25 QUE TIENEN 5 0COS

#function[t,y]=ej1_a_senoidal(tini,tfin,fm,fs,A,fi)

##2fs <= fm
