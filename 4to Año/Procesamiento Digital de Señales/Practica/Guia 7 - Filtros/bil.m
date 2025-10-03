function [num,den] = bil(z,p,k,T);

zz=[];
pp=[];
kk=k;

  for l=1:length(z)
    zz= [zz (2/T+z(l)) / (2/T-z(l))];
    kk=kk*(2/T-z(l));
  endfor

   for l=1:length(z)
    pp= [pp (2/T+p(l)) / (2/T-p(l))];
    kk=kk/(2/T-p(l));
  endfor

  num=real(kk*poly(zz));
  den=real(poly(pp));
