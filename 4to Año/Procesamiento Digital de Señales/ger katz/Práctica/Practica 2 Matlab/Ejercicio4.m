1;
%Para resolver este ejercicio tuvimos que implementar la función 
%RespuetaAlImpulso(a,b), donde a es el vector de coeficientes Y, 
%y b es el vector de coeficientes X. 
a1 = [1 0 -1]; b1 = 1; N1= 15;
y1 = respuestaImpulso(a1,b1,N1);
n1=1:N1;
stem(n1,y1);

a2 = 1; b2 = [1 0.5]; N2= 15;
y2 = respuestaImpulso(a2,b2,N2);
n2=1:N2;
%stem(n2,y2);

a3 = [1 0.5 0.25]; b3 = 1; N3= 100;
y3 = respuestaImpulso(a3,b3,N3);
n3=1:N3;
stem(n3,y3);

function x = deltaDirac(t)
    if(t==0)
        x = 1;
    else
        x = 0;
    end 
end

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

