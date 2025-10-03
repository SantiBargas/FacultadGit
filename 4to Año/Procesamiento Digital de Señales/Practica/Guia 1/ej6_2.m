function [ti,xi] = ej6_2(t,x)


  muestrasx=length(t);
  % Nuevo período de muestreo para la señal sobremuestreada (un cuarto del original)
  #Si la frecuencia es 4 veces mas grande 10Hz->40Hz El periodo es 4 veces mas chico

 T=t(2)-t(1); #Periodo de muestreo original La diferencia de tiempo entre una muestra y la siguiente es el periodo

 Ti=T/4;

  ti = [t(1):Ti:t(muestrasx)];
  xi = zeros(size(ti));

  for m=1:length(ti)
    for n=1:muestrasx
      xi(m) = xi(m) + x(n) * triangulo(((m-1)*Ti/T - (n-1))); %equivalente a ((m-1)*Ti - (n-1)*T)/T
    endfor
  endfor

 #nT Desplazamiento temporal
 #Expande o contrae el ladrillito para que entre en el periodo de muestreo original

% Visualizar los resultados
plot(t, x, 'o', ti, xi, '-');
legend('Datos originales', 'Interpolación por sinc');
xlabel('Tiempo');
ylabel('Amplitud');
title('Interpolación por sinc');

endfunction


##% Definir t y x
##t = 0:0.1:10;
##x = sin(t);
##
##% Llamar a la función ejercicio6
##[ti, xi] = ej6_2(t, x);



#x(nT) SEÑAL ORIGINAL MUESTREADA LA QUE ESTABA A 10HZ
#I FUNCION INTERPOLANTE
#Interpolacion: Funcion inversa del muestreo, dada las muestras de la señal muestreada reconstruir la señal continua
#En la compu no podemos trabajr con señales continuas
#I((mTi -nT)/t) -> dividiendo por t para que el ancho valga el periodo del muestreo viejo y vamos desplazando
#Desplazamos con n*t, la primera no desplaza n*0
# y se multiplica por la amplitud que tenia la señal muestreada x(n*T) Amplitud = x[0] , x[1] , x[2] ...
#los nuevos ladrillitos se van muestrenado que Ti partiendo a T
#Es decir vamos acumulando los ladrillitos con una nueva amplitud
