function [A]=matrizParcial(n)
    A=zeros(n,n);
   for j=2:n
        A(j-1,j)=-1; %-1 arriba
         A(j,j)=2; %dos en la diagonal
         A(j+1,j)=-1; %-1 abajo
      endfor
