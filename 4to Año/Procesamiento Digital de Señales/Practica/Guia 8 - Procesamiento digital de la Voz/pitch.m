pkg load signal
%cargar la señal de interes
%femenina
[s,fs]=audioread('mic_F01_sa2.wav');
[lar,fs]=audioread('lar_F01_sa2.wav');

%masculina
[s,fs]=audioread('mic_M01_sa1.wav');
[lar,fs]=audioread('lar_M01_sa1.wav');

%Femenina
ref=load('ref_F01_sa2.f0');
%Masculina
ref=load('ref_M01_sa1.f0');

fm=20000;
s1=resample(s,fm,fs);
lar1=resample(lar,fm,fs);
b=fir1(2000,[50/10000 500/10000],'high',kaiser(2001,4));
lar1=filter(b,1,lar1);
lar1=lar1(1001:end);
lar1(end+1000)=0;

figure
subplot(4,1,1);
plot(s1); axis tight

subplot(4,1,2);
plot(lar1); axis tight

subplot(4,1,3);
plot(ref(:,1)); axis tight

subplot(4,1,4);
plot(ref(:,2)); axis tight

tvent=0.032;
tstep=0.010;

nvent=tvent*fm;
nstep=tstep*fm;

nframes=size(ref,1);

snr=50;
x=s1;
x=ensucia(s1,snr);

pceps=zeros(nframes,1);
pcorr=zeros(nframes,1);
ini=nvent/2;
vent=boxcar(nvent);

for k=1:nframes
  if(ref(k,2)>0)
    pceps(k) = pitchcepstrum(x(ini:ini + nvent - 1) .* vent, fm);
    pcorr(k)=pitchcorr(x(ini:ini+nvent-1).*vent,fm);
  endif
  ini=ini+nstep;
end

figure
plot(ref(:,1));
hold on
plot(pceps,'r');
plot(pcorr,'k');


