function demotf
close all
senal=atoms(256,[50,0.1,10,1;120,0.3,10,1]);
disp('Press any key to continue');
pause;

%Descomentar esto para probar con la señal real (no analitica)
%senal=real(senal);

figure;
wignerdist(senal);
disp('Press any key to continue');
pause;

figure;
cohendist(senal,0.1);
disp('Press any key to continue');
pause;

figure;
cohendist(senal,10);
disp('Press any key to continue');
pause;

figure;
cohendist(senal,100);
disp('Press any key to continue');
pause;

figure;
windowft(senal,32,1,'Hanning','STFT Hamming');
disp('Press any key to continue');
pause;

figure;
windowft(senal,32,1,'Blackman','STFT Blackman');
disp('Press any key to continue');
pause;

figure;
windowft(senal,32,1,'Gaussian','STFT Gaussiana');
disp('Press any key to continue');
pause;

figure;
spectrogram(senal,32,1,'Espectrograma (usa ventana cuadrada)');
disp('Press any key to continue');
pause;

figure;
tocon(senal,1,20,1);  
disp('Press any key to continue');
pause;

figure;
[a, d]=todd(senal,ondita('daubechies',6),8);
escalogramad(a,d,length(senal),8); 
disp('Press any key to continue');
pause;

%Para ver una ondita y la funcion de escala (solo funciona con 'daubechies'
%orden 1,2,4,5,6
%viewwave('daubechies',4);
% POR ALGUNA RAZON ESTA SE CUELGA PARA OCTAVE WINDOWS!