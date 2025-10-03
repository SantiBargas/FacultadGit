% Leer el archivo de audio
[y, f_m] = audioread('escala.wav');

%Definir el tiempo
t_ini=0;
t_fin=length(y)/f_m;
T_m=1/f_m;
t=t_ini:T_m:t_fin-T_m;

%Fijarse la cantidad de notas en el audio
n_notas=round((length(y)/f_m)/0.5);
T_notas=round(f_m*0.5);


%Armar la señal de comparacion (nota La)
f_la=440;
s_la=sin(2*pi*f_la*t);

% Lazo para calcular el producto interno de cada nota con la señal LA
for i=0:n_notas-1
  i_ini = i*T_notas + 1;
  i_fin = i_ini + T_notas - 1;
  in_prod(i+1) = sum(y(i_ini:i_fin) .* s_la(i_ini:i_fin)');
endfor


% Gráfico de barras para verificar los tamaños
bar(in_prod)
in_prod

% Encontrar el índice de la máxima correlación
[~, max_index] = max(in_prod)

% Calcular el tiempo correspondiente al índice de la máxima correlación
tiempo_nota_LA = (max_index - 1) * 0.5

