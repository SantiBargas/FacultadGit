warning("off");
pkg load symbolic

syms x
syms k #coeficiente difusivo
syms he #ancho del elemento
syms c
##k = 1; #coeficiente difusivo
##he = 1; #ancho del elemento

N1 = x*(x-1);
N2 = (x+1)*(1-x);
N3 = (x*(x+1))/2;

dN1 = diff(N1,x);
dN2 = diff(N2,x);
dN3 = diff(N3,x);

dNs = [dN1,dN2,dN3];
matrizDifusiva = zeros(3)*x;
for i = 1:3
  for j = 1:3
    matrizDifusiva(i,j) = k*int(dNs(i)'*dNs(j)*(2/he),-1,1);
  endfor
endfor
matrizDifusiva = simplify(matrizDifusiva)

#reactivo, está bien remplazar así nomásave??
Ns = [N1,N2,N3];
matrizReactiva = zeros(3)*x;
for i = 1:3
  for j = 1:3
    matrizReactiva(i,j) = c*int(Ns(i)'*Ns(j)*(he/2),-1,1);
  endfor
endfor
matrizReactiva = simplify(matrizReactiva)

simplify(matrizReactiva + matrizDifusiva)
