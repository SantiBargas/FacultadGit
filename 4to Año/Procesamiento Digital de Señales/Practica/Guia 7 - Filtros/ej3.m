fm=300; %frecuencia de muestreo
fr=50; %frecuencia de rechazo

%N=11; %longitud de filtro deseado
N=500;
M=10*N %Longitud de la respuesta en frecuencia deseada para frecuencias positivas
MTot= 2*M+1; %M para frecuencias positivas, Mpara frecuencias negativas , 1 para frecuencia 0
df=fm/(MTot); %deltaf para la resolucion frecuencial

%Construccion de la respuesta de magnitud
MD=ones(1,M+1);
n1=fix(fr/df); %calculo a que muestra corresponde la frecuencia fr
np=n1+1; %le sumo 1 para compensar el indexado desde 1
%nn=M-n1+1; %calculo la muestra en la que aparaece en la parte de frecuencias negativas

nm=ceil(2/df) %numero de muestras para cada lado correspondiente a 2Hz para cada lado

MD(np-nm:np+nm)=0; %Pongo ceros en la frecuencia deseada y una muestra para cada lado (ancho de banda de rechazo =4 HZ)
%MD(nn-nmnn+nm)=0; %lo mismo pero para frecuencias negativas

figure
plot(MD) #todos 1 menos en el rango que definimos 0


%Respuesta de fase: incluye un retarde de (N-1)/2 muestras
ph=exp(-j*2*pi*((N-1)/2)*[0:M]/(MTot));
%ph=[ph conj/fliplr(ph(2:end))];


%Respuesta deseada completa
R=MD.*ph;

%Parte de frecuencias negativas
R=[R conj(R(end:-1:2))];

h=real(ifft(R));
figure
plot(h)

figure
%hf=h(1:N).*hamming(N).';
%hf=h(1:N).*hanning(N).';
%hf=h(1:N).*boxcar(N).';
hf=h(1:N).*blackman(N).';

stem(hf)
hold on
freqz(hf,1,1000,fm);

