function p=akaike(E,N)

  T=log2(E(2:end))'+2*[1:length(E)-1]/N;

  [~,p]=min(T);
  plot(T);

end
