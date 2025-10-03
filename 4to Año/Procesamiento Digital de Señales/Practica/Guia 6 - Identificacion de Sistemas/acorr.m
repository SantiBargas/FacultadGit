#Señal = x
#Cant de retardos = P

function r=acorr(x,P)
  N=length(x);
  r=zeros(P+1,1);
  for k=0:P

      for l=1:N-k
        r(k+1)=r(k+1)+x(l)*x(l+k);
      endfor

  endfor

  r=r/N;

