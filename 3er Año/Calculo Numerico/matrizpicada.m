function [A,b] = matrizpicada(n);
 A= zeros(39);
 A(1,1)=5;
 A(100,100)=6;
 b(1,1)=0;
 for j=1:n
   b= h.^2*20*exp(-10*(x(j)-0.7)^2)
   A(i,i-1)=-1;
   A(i,i)=2;
   A(i,i+1)=-1;
 endfor
endfunction

