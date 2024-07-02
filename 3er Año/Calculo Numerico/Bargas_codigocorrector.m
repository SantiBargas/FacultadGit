function[x] =eliminacionGauss(A,b)
n = length(A);  %POSIBLE ERROR
  r = 1:n;
  for k=1:n
    [~,p] = max(abs(A(k:n,k)));  %error deberia ser max(abs(A(r(k:n),k)))
    p = p + k - 1;
    r( [k,p] ) = r( [p,k] );
    m = A(r(k+1:n),k)/A(k,k);  %error deberia ser A(r(k),k);
    b(r(k+1:n)) = b(r(k+1:n)) - m*b(k);
    A(r(k+1:n),k+1:n) -= A(r(k),k+1:n)*m;  %error deberia ser - m*A(r(k),k:n);
  end
  x = sustitucionAtras(A,b,r);
endfunction


function [x] = elim_gaussIndice(A,b)

n = length(A(1,:));
r = [1:n];

for k=1:n
    [~,p] = max(abs(A(r(k:n),k))); % busca el maximo valor absoluto
                                  % incluyendo el pivot sobrre todos los
                                  % valores de la columna k debajo del
                                  % pivote
    p = p(1) + k-1; % actualizo posicion del pivote
    % Ahora intercambiamos filas con el vector r
    r([k,p]) = r([p,k]); % Intercambio en el vector r
    m = A(r(k+1:n),k)/A(r(k),k);
    A(r(k+1:n),k:n) = - m*A(r(k),k:n);
    b(r(k+1:n)) = b(r(k+1:n)) - m*b(r(k));


end

x = sust_atras_r(A,b,r,n);

%tiempo = toc();
