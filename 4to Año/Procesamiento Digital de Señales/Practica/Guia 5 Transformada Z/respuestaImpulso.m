function y = respuestaImpulso(a,b,N)
% a terminos de y
% b terminos de x
% N número de respuestas

%Valores iniciales
nb = length(b);
na = length(a);

for n = 1:N
    sum = 0;
    sumb = 0;
    for k = 1:nb
        sumb = sumb + b(k)*deltaDirac(n-k);
    end
    suma = 0;
    for k = 2:na
        if(n-k+1>0)
            suma = suma + a(k)*y(n-k+1);
        end
    end
    sum = sumb - suma;
    y(n)= sum/a(1);
end
end
