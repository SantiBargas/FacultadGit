function [t,c]=ej1_c_cuadrada(tini,tfin,fm,fs,A,fi)

 T=1/fm;
 #t=tini:T:tfin-T; %Vector de tiempos
 t = linspace(tini, tfin, fm * (tfin - tini) + 1);

 x=(2*pi*fs*t+fi);
 M=mod(x,2*pi);

 c=-1;
 c(M<pi)=1;

 % Graficar la señal cuadrada
##plot(t, c);
##xlabel('Tiempo');
##ylabel('Amplitud');
##title('Señal Cuadrada Generada');

 endfunction

% [t,c]=ej1_c_cuadrada(tini,tfin,fm,fs,A,fi)
% [t,c]=ej1_c_cuadrada(0  ,  1,  500,3,1,0);
%2fs<fm
