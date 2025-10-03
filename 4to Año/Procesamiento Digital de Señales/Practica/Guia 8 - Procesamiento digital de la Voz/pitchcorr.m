function fpitch=pitchcorr(x,fm)

  T=1/fm;

  pmin=100;
  pmax=300;

  Tmin=1/pmax;
  Tmax=1/pmin;

  nmin=floor(Tmin/T);
  nmax=ceil(Tmax/T);

  xc=xcorr(x);
  xc=xc(length(x):end);

  [~,i]=max(xc(nmin:nmax));

  npitch=i+nmin-1;
  Tpitch=npitch*T;
  fpitch=1/Tpitch;
