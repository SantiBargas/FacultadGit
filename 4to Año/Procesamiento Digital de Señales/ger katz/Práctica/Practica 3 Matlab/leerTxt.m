%Leemos el archivo
fm = 11025 ;
tmuestreo = 1 /fm;
archivo = fopen ( 'te.txt' , 'r' );
v = fscanf (archivo, '%e' );
v = v'; % Vector horizontal
n = length (v); % numero de muestras.
% Vector muestras
t= 0 :tmuestreo:(tmuestreo*n)-tmuestreo;
plot (v);
plot (t,v);
%---------------------------------------------------------