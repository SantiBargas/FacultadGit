function[t,p]=ej2_cuantificada(tini,tfin,fm,fs,A,fi,N)
 % N: Numero de niveles
    % H: Magnitud del cuanto

    T = 1 / fm;
    t = tini:T:tfin-T;
    H = (2 * A) / N; % Cuanto de altura tiene cada escalon
    y = A * (sin(2 * pi * fs * t + fi));

    % Subgráfico 1: Señal Original
    subplot(2, 1, 1);
    plot(t, y, 'r');
    grid on;
    title('Señal Original');
    xlabel('Tiempo');
    ylabel('Amplitud');
    hold on;

    % Ajuste para manejar señales negativas
    y2 = y - min(y);

    % Aplicamos la formula de cuantización
    p = zeros(size(y2));

    for i = 1:length(y2)
        if y2(i) < (N - 1) * H
            p(i) = H * floor(y2(i) / H);
        else
            p(i) = (N - 1) * H;
        end
    end

    % Restauramos la parte negativa
    p2 = p + min(y);

    % Subgráfico 1: Señal Original
    subplot(2, 1, 2);
    plot(t, p2, 'b');
    grid on;
    title('Señal Cuantificada');
    xlabel('Tiempo');
    ylabel('Amplitud');
    ylim([min(y) max(y)]); % Ajustar el eje y al rango original de la señal
endfunction


#[t,y]=ej2_cuantificada(0,1,1000,5,2,pi/2,8);

