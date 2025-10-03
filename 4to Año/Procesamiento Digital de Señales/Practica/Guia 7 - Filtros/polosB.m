function p=polosB(N)

  p=zeros(1,N);
  for k=0:N-1
    tita=(2*k+N+1)*pi/(2*N);
    p(k+1)=exp(j*tita)
  endfor

