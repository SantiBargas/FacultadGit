function [y_1 , y_2]= conv_ej3(a,N)
% Definición de las respuestas al impulso hA[n] y hB[n]
N = 10; % Definimos un valor arbitrario para N
a = 0.5; % Supongamos un valor para 'a' tal que a < 1


n = 0:N-1;
hA = sin(8*n);
hB = a.^n;

% Definición de la entrada x[n] = delta[n] + delta[n-1]
x = zeros(1, N);
x(1) = 1; % Impulso en n = 0
x(2) = -a; % Impulso en n = 1

w_1 = conv(x,hA);
y_1 = conv(w_1,hB);

w_2 = conv(x,hB);
y_2 = conv(w_2,hA);

  figure(1);
  subplot (2, 3, 1);
    stem(hA);
    title("hA");
  subplot (2, 3, 4);
    stem(hB);
    title("hB");
  subplot (2, 3, 2);
    stem(1:length(w_1),w_1);
    title("w_1");
  subplot (2, 3, 5);
    stem(1:length(y_1),y_1);
    title("y_1");

  subplot (2, 3, 3);
    stem(1:length(w_2),w_2);
    title("w_2");
  subplot (2, 3, 6);
    stem(1:length(y_2),y_2);
    title("y_2");

endfunction
