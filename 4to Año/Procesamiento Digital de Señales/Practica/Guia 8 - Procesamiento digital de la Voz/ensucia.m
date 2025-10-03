function y=ensucia(x,snr)

  r=randn(size(x));
  Px=sum(x.*x);
  Pr=sum(r.*r);

  alfa=sqrt(Px/(Pr*10^(snr/10)));
  y=x+alfa*r;
