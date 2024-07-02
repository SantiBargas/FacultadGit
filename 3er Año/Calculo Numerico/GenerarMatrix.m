function [A,b] = GenerarMatrix(n);
 A= zeros(n);
 A(1,1)=1;
 A(100,100)=1;
 b= ones(n,1) / n^2;
 b(1,1)=0;
 b(100,1)=0;
 for i=2:n-1
   A(i,i-1)=-1;
   A(i,i)=2;
   A(i,i+1)=-1;
 endfor
 endfunction
