function [r1, r2, tipo_raiz] = baskara(coefs)
  a = coefs(1);
  b = coefs(2);
  c = coefs(3);

  discriminante = b^2 - 4*a*c;

  if discriminante > 0
    tipo_raiz = "raices reales y diferentes";
    r1 = (-b + sqrt(discriminante))/(2*a);
    r2 = (-b - sqrt(discriminante))/(2*a);
  elseif discriminante == 0
    tipo_raiz = "raices reales e iguales";
    r1 = -b/(2*a);
    r2 = r1;
  else
    tipo_raiz = "raices complejas conjugadas";
    r1 = (-b + sqrt(-discriminante)*1i)/(2*a);
    r2 = (-b - sqrt(-discriminante)*1i)/(2*a);
  endif

endfunction

  %llamar como [r1, r2, tipo_raiz] = baskara([2, 5, -3]);
