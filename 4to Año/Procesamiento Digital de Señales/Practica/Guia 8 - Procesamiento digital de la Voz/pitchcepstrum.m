function fpitch=pitchcepstrum(x,fm)

  T=1/fm;

  pmin=100;
  pmax=300;

  Tmin=1/pmax;
  Tmax=1/pmin;

  nmin= floor(Tmin/T);
  nmax= ceil(Tmax/T);
  rceps = ifft(log(abs(fft(x))));

  [~,i]=max(rceps(nmin:nmax));

  npitch=i+nmin-1;
  Tpitch=npitch*T;
  fpitch=1/Tpitch;
