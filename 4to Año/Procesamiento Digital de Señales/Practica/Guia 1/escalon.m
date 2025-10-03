function y = escalon(x)
  for i =1:length(x)
    if(x(i) >= 0 && x(i) < 1)
      y(i)=1;
    else
      y(i)=0;
    endif
  endfor
endfunction
