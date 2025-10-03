function [num,den]=butt(N,f,fm)

  p=polosB(N);
  f=fm*tan(f*pi/fm)/pi; #PARA GARANTIZAR QUE LA BILINEAL CAIGA DONDE QUERAMOS
  [z1,p1,k1]=trf(p,2*pi*f);
  [num,den]=bil(z1,p1,k1,1/fm);
