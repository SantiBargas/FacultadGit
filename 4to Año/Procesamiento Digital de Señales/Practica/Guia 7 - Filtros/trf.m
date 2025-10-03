function [z,p,k] = trf(p0,wc)

z=[];
p=[];
k=1;

for l=1:length(p0)
  z= [z 0];
  p=[p wc/p0(l)]
  k=k*(-1/p0(l));
 end
