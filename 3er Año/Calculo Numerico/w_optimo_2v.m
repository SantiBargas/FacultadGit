function [w] = w_optimo_2v(A)
  [rhoA] = RadioEspectral(A,'ja',0);
  w=2/(1+sqrt( 1- (rhoA)^2));
  endfunction
