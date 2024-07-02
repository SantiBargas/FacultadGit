function [A,b] = genMatriz(n);
 A= zeros(n);
 A(1,1)=1;
 A(n,n)=1;
 b= ones(n,1) / n^2;
 b(1,1)=0;
 b(n,1)=0;
 for i=2:n-1
   A(i,i-1)=-1;
   A(i,i)=2;
   A(i,i+1)=-1;
 endfor
 endfunction
