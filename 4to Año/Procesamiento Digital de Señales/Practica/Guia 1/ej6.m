function [ti,xi] = ej6(tini,tfin,fm,fs)

 % Generación de la señal discreta original
  [T, sincR] = ej1_b_sync(tini, tfin, fm, fs);

  % Nuevo período de muestreo para la señal sobremuestreada (un cuarto del original)
  #Si la frecuencia es 4 veces mas grande 10Hz->40Hz El periodo es 4 veces mas chico
  Ti=T/4;


  % Vector de tiempo para la señal sobremuestreada
  ti = linspace(tini, tfin, 4*length(T)); % Genera un vector de tiempo con la longitud*4 que la señal original
 # ti= [tini:Ti:length(Ti)];
  xi = zeros(size(ti)); %para recorrer el for

for m = 1:length(ti)
    for n = 1:length(T)
      xi(m) = xi(m) + sincR(n) * sinc((m * Ti - n * T) / T);  % Utilizando directamente la función sinc
   end
end

for m = 1:length(ti)
    for n = 1:length(T)
      xi(m) = xi(m) + sincR(n) * sinc((m * Ti - n * T) / T);  % Utilizando directamente la función sinc
   end
end


% Graficación de las señales
subplot(2,1,1);
plot(T, sincR, 'b', 'LineWidth', 1.5); % Señal original
title('Señal Original');
xlabel('Tiempo (s)');
ylabel('Amplitud');
grid on;

subplot(2,1,2);
stem(ti, xi, 'r', 'LineWidth', 1.5); % Señal sobremuestreada e interpolada
title('Señal Sobremuestreada e Interpolada');
xlabel('Tiempo (s)');
ylabel('Amplitud');
grid on;

endfunction


#x(nT) SEÑAL ORIGINAL MUESTREADA LA QUE ESTABA A 10HZ
#I FUNCION INTERPOLANTE
#Interpolacion: Funcion inversa del muestreo, dada las muestras de la señal muestreada reconstruir la señal continua
#En la compu no podemos trabajr con señales continuas
#I((mTi -nT)/t) -> dividiendo por t para que el ancho valga el periodo del muestreo viejo y vamos desplazando
#Desplazamos con n*t, la primera no desplaza n*0
# y se multiplica por la amplitud que tenia la señal muestreada x(n*T) Amplitud = x[0] , x[1] , x[2] ...
#los nuevos ladrillitos se van muestrenado que Ti partiendo a T
#Es decir vamos acumulando los ladrillitos con una nueva amplitud

#sincR(n) -> x(nT)
#I((mTi -nT)/t) -> sinc

% Parámetros de entrada
##tini = 0;
##tfin = 1;
##fm = 10;  Frecuencia de muestreo original (Hz)
##fs = 0.5; Frecuencia de la función sinc (Hz)

##[ti,xi] = ej6(0,1,10,0.5)
##[ti,xi] = ej6(-1,1,10,0.5)


