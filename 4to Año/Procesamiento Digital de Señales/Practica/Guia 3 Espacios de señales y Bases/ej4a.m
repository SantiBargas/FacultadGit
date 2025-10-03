1;
t=0:1/100:2;
senoidales=zeros(10,length(t));
for i=1:10
    senoidales(i,:)=sin(2*pi*i*t); #guardamos el resultado de cada senoidal con fs = 1,2,3...
end

combLineal=0;
for i=1:10
    combLineal=combLineal+senoidales(i,:); #multiplicamos por i para ponderar
end

clComp=zeros(10);
for i=1:10
    clComp(i)=dot(combLineal,senoidales(i,:)); #producto punto entre cada componente de la comb
end


% Graficar la combinación lineal
figure;
plot(t, combLineal);
hold on
xlabel('Tiempo');
ylabel('Amplitud');
title('Combinación Lineal de Senoidales');

% Graficar el grado de parecido en un gráfico de barras
figure
frequencies = 1:10;
bar(frequencies, clComp);
xlabel('Frecuencia (Hz)');
ylabel('Grado de Parecido');
title('Grado de Parecido con Senoidales Individuales');



#vemos que 1-2 y 9-10 son muy similares, las graficamos
figure
subplot(2,1,1)
plot(t,senoidales(1,:))
hold on
plot(t,senoidales(2,:))
title('Señales Senoidales 2 y 3')
legend('Señal Senoidal 2', 'Señal Senoidal 3')

subplot(2,1,2)
plot(t,senoidales(9,:))
hold on
plot(t,senoidales(10,:))
title('Señales Senoidales 9 y 10')
legend('Señal Senoidal 9', 'Señal Senoidal 10')


#vemos que 1-10 y 2-9 son muy difernetes, las graficamos
figure
subplot(2,1,1)
plot(t,senoidales(1,:))
hold on
plot(t,senoidales(10,:))
title('Señales Senoidales 1 y 10')
legend('Señal Senoidal 1', 'Señal Senoidal 10')

subplot(2,1,2)
plot(t,senoidales(2,:))
hold on
plot(t,senoidales(9,:))
title('Señales Senoidales 4 y 8')
legend('Señal Senoidal 4', 'Señal Senoidal 8')
