function [x]=gaussSINFOR(A,b)
  n=length(b);
  A=[A b];
  for k=1:n-1
      %for i=k+1:n Se sustituye por lo de abajo
        %m=A(i,k)/A(k,k)
        %A(i,k)=0;
        m=A(k+1:n,k)A(k,k);%vector columna

        %for j=k+1:n+1 Se sustituye por lo de abajo
        %A(i,j)=A(i,j)-m*A(k,j);
        A(k+1:n,k+1:n+1)=A(k+1:n,k+1:n+1)-m*A(k,k+1:n+1);
  endfor
  if(A(n,n)==0) disp('no hay sol')
endif
x=sust_atras1(A);
endfunction

