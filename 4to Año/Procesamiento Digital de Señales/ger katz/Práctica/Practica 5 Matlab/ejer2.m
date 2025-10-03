% H(z) es la transformada Z de la respuesta al impulso
% H(z) la evaluo sobre el ciruclo unitario se encuentra la transformada
% de fourier de la respuesta al impulso h(n), esa respuesta se llama
% respuesta en frecuencia
% se grafica la magnitud de la transformada de fourier a lo largo de la frecuencia
% para cada avalor de fracuencia que tenga la entrada que es lo que hace
% el sistema
% a h evualuamos a e ^ j w(omega)
% omega lo discretizamos
% graficamos de h en funcion de omega
 % Definimos cada uno de los H
function [H] = h1(z)
    H = zeros(1,length(z));
    for k=1 : length (z)
       H(k) = 1/(1-0.5/z(k)+0.25/(z(k)^2));
    end
end
%---------------------------------------------------------------------
function [H] = h2(z)
    H = zeros(1,length(z));
    for k=1:length(z)
        H(k) = (z(k)^-1)/(1- z(k)^-2-z(k)^-1);
    end
end
%---------------------------------------------------------------------
function [H] = h3(z)
    H = zeros(1,length(z));
    for k=1:length(z)
       H(k) = 7 / (1- 2*z(k)^-1 + 6*(z(k)^-2));
    end
end
%---------------------------------------------------------------------
function [H] = h4(z)
    H = zeros(1,length(z));
    for k=1:length(z)
        suma=0;
        for p=0:7
            suma = suma + (2^(-p))*(z(k)^(-p));
        end
        H(k) = suma;
    end
end


fm = 10000;
tm = 1/fm;
%La transformada de fourier es la transformada z con radio = 1
r = 1;

% omega es el vector con los angulos del circulo unitario
w = 0:tm:(2*pi)-tm;

% z = r.exp (jw)
z = r*exp(1i*w);


% Respuestas en frecuencia
% transforamda de fourier de la respuesta al impulso

subplot(2,2,1);
plot(w,abs(h1(z)));
title('H1')
subplot(2,2,2);
plot(w,abs(h2(z)));
title('H2')
subplot(2,2,3);
plot(w,abs(h3(z)));
title('H3')
subplot(2,2,4);
plot(w,abs(h4(z)));
title('H4')


