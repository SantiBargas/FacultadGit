function[t,y]=ej2_invsenoidal(tini,tfin,fm,fs,A,fi)

 T=1/fm;

 t=tini:T:tfin-T; %Vector de tiempos
 t2=-t;

 y= A.*sin(2*pi*fs*t+fi);

 y2= A.*sin(2*pi*fs*t+fi);

 #y3=-y2;

plot(t,y)
hold on
plot(t2,y2)
legend('Onda normal', 'Onda invertida','Onda invertida2');

## SOLUCION
## [t,y2]=ej2_invsenoidal(0,1,100,2,2,pi/2);


