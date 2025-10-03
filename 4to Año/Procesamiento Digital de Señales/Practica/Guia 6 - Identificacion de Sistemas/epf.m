function p=epf(E,r,gamma)
  V=E/r(1);
  est=1-(V(2:end)./V(1:end-1));

  for k=1:length(est)
    if(est(k) < gamma)
      break;
    endif
  endfor
p=k;
plot(est)
