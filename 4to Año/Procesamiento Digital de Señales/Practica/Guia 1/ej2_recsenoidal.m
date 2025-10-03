function[t,y2]=ej2_recsenoidal(tini,tfin,fm,fs,A,fi)

 T=1/fm;
 t=tini:T:tfin-T; %Vector de tiempos
 y= A.*sin(2*pi*fs*t-fi);

#ejecutamos la onda sinoidal y la guardamos en y
[t,y]=ej1_a_senoidal(0,1,100,5,2,pi/2);


 % Rectificar la señal (onda completa)
    y_rect_completa = abs(y);

% Rectificar la señal (media onda)
    y_rect_media = y;
    y_rect_media(y_rect_media < 0) = 0;

    % Subgráfico 1: Señal Original
    subplot(3, 1, 1);
    plot(t, y);
     grid on;
    title('Señal Original');
    xlabel('Tiempo');
    ylabel('Amplitud');

    % Subgráfico 2: Rectificación de Onda Completa
    subplot(3, 1, 2);
    plot(t, y_rect_completa, 'r');
     grid on;
    title('Rectificación de Onda Completa');
    xlabel('Tiempo');
    ylabel('Amplitud');

    % Subgráfico 3: Rectificación de Media Onda
    subplot(3, 1, 3);
    plot(t, y_rect_media, 'g');
     grid on;
    title('Rectificación de Media Onda');
    xlabel('Tiempo');
    ylabel('Amplitud');

    % Ajustar el espacio entre los subgráficos
    sgtitle('Señal Original y Rectificaciones');
 endfunction

##SOLUCION
## [t,y2]=ej2_recsenoidal(0,1,100,5,2,pi/2);



## Rectificación de onda completa: En este caso,
## todas las partes negativas de la señal se convierten en su valor absoluto,
## resultando en una señal que siempre es positiva.
