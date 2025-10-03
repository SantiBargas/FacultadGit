1;

function [t,x]=senoidal(ti,tf,fm,fs,phi)
T=1/fm;
t=ti:T:tf-T;
x=sin(2*pi*fs*t+phi);
end

function [t,y]=ondaCuad(ti,tf,fm,fs,fi)
T=1/fm;
t=ti:T:tf-T;
x=mod(2*pi*fs*t+fi,2*pi);
y = -1 * (x>=pi) + 1 * (x<pi);
end

[t1,sen1]=senoidal(0,1,100,2,0);
[t2,cuadrada]=ondaCuad(0,1,100,2,0);
[t3,sen2]=senoidal(0,1,100,4,0);


##########1############################################
#La ortogonalidad entre dos señales x(t) y y(t)
#se verifica si el producto interno es igual a cero:
###a y b no es ortogonal
##ProdPunto1 = dot(sen1,cuadrada)
###a y c es ortogonal
##ProdPunto2 = dot(sen1,sen2)
###b y c es ortogonal
##ProdPunto3 = dot(cuadrada,sen2)
##hold on
##plot(t1,sen1)
##plot(t3,sen2)
##plot(t2,cuadrada)


##########2############################################
sen1T=fft(sen1);
cuadradaT=fft(cuadrada);
sen2T=fft(sen2);

%a y b transformados no son ortogonales
#USAMOS DEFINICION DEL CONJUGADO DEL PRODUCTO INTERNO YA QUE FOURIER TIENE COMPLEJOS
ProdPunto1T = dot(sen1T,conj(cuadradaT))
%a y c transformados son ortogonales
ProdPunto2T = dot(sen1T,conj(sen2T))
%b y c transformados son ortogonales
ProdPunto3T = dot(sen2T,conj(cuadradaT))
figure;
hold on
plot(t1,sen1T)
plot(t2,cuadradaT)
plot(t3,sen2T)

#transformada de fourier es una cambio de base, los objetos son los mismos por lo
#tanto van a ser ortogonales
##
##########3########### 3 ################################
[t3R,sen2R]=senoidal(0,1,100,3.5,0); #sen2 redefinida

#sen1 y sen2 redefinida son ortogonales
ProdPunto3R = dot(sen1,sen2R)

#transformada de sen1 y transformada de sen2 son ortogonales
sen2TR=fft(sen2R);
ProdPunto3TR = dot(sen1T,conj(sen2TR))

figure
hold on
plot(t1,sen1)
plot(t3R,sen2R)
plot(t1,sen2TR)
plot(t1,sen1T)


#EN LA GRAFICA 1 VEMOS QUE SON ORTOGONALES YA QUE EN DONDE ENTRA MEDIO CICLO DE LA NARNJA
#ENTRA 1 CICLO ENTERO DE LA AZUL ENTONCES CON LA PARTE NEGATIVA DE LA NARANJA SE CANCELA


