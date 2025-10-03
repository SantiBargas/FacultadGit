% Cargo
x = load ('necg.txt');
##figure(1);
##plot(x);
##title("Señal archivo necg");

N = length(x); %cant de muestras
fm=360;
T=1/fm;
tf=N*T;
t=0:T:tf-T;

%Dominio frecuencial
df=fm/N;
f= -fm/2 : df : fm/2-df

%Transformada
S=fft(x);
figure
stem(f,abs(S));
title("Transformada de Fourier de la señal original");

%cambiamos el orden de las frecuencias para que las frecuencias negativas estén
%en la primera mitad del vector y las frecuencias positivas estén en la segunda mitad.
S=[S(N/2+1:N); S(1:N/2)];#ESTO VER BIEN

##for i = 1:n
##    if i <= n/2 % Si estamos en la primera mitad del vector
##        S_temp(i) = S(i + n/2); % Colocar las frecuencias positivas en la primera mitad
##    else
##        S_temp(i) = S(i - n/2); % Colocar las frecuencias negativas en la segunda mitad
##    end
##end
##S = S_temp;

figure
stem(f,abs(S))
title("Transformada de Fourier con frecuencias negativas ordenadas primero");

%filtramos la señal
%de 40 hz a 180 hz hubo ruido
for i=1:N
  if(abs(f(i)) >= 40 && abs(f(i)) <= 180 ) %Usamos abs de la f ya que tenemos mitad de la señal en la derecha y mitad de la señal en la izquierda
      y(i)=0;
   else
       y(i)=S(i);
   end
endfor

figure
stem(f,abs(y));
title("Transformada de Fourier filtrada");

##y=[y(n/2+1:n) y(1:n/2)];

for i = 1:N
    if i <= N/2 % Si estamos en la primera mitad del vector
        y_temp(i) = y(i + N/2); % Colocar los valores de la segunda mitad al principio
    else
        y_temp(i) = y(i - N/2); % Colocar los valores de la primera mitad al final
    end
end
y = y_temp;


figure
stem(f,abs(y))
title("Transformada de Fourier filtrada con frecuencias negativas ordenadas primero");


xAnti=real(ifft(y));
%Filtrada y ordenada
figure;
plot(t,xAnti);
title("Señal filtrada");
