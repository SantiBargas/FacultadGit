function y = triangulo(x)
  for i=1:length(x)
    if (x(i) < 1 && x(i) >= 0)
      y(i) = -x(i) + 1;
    elseif (x(i) > -1 && x(i) < 0)
      y(i) = x(i) + 1;
    else y(i) = 0
    endif
  endfor

  % Alternativa
##  for i=1:length(x)
##    if abs(x(i))<1
##        y(i) = 1-abs(x(i));
##    else
##        y(i) = 0;
##    endif
##   endfor
endfunction
