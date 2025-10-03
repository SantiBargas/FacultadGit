#Primer sistema: 1 / (1 - (1/2)*z^-1 + (1/4) *z^-2)
#Segundo sistema: z^-1 / (1 - (z^-1) - (z^-2) )
#Tercer sistema: 7 / (1- (2*z^-1) + (6*z^-2) )
#Cuarto sistema: 1 + (1/2  * z^-1) + (1/4 *  z^-2) + (1/8 *  z^-3) + (1/16 *  z^-4) + (1/32 *  z^-5) + (1/64 *  z^-6) + (1/128 *  z^-7)

% H(z) es la transformada Z de la respuesta al impulso
% H(z) la evaluo sobre el ciruclo unitario se encuentra la transformada
% de fourier de la respuesta al impulso h(n), esa respuesta se llama
% respuesta en frecuencia
% se grafica la magnitud de la transformada de fourier a lo largo de la frecuencia
% para cada avalor de fracuencia que tenga la entrada que es lo que hace
% el sistema
% a h evualuamos a e ^ j w(omega)
% omega lo discretizamos
% graficamos de h en funcion de omega


fm = 10000;
tm = 1/fm;
%La transformada de fourier es la transformada z con radio = 1
r = 1;

% omega es el vector con los angulos del circulo unitario
w = 0:tm:(2*pi)-tm;

% z = r.exp (jw)
z = r*exp(1i*w);

##############################################################################
H1 = zeros(1,length(z));
    for k=1:length(z)
        H1(k) = 1/(1 - (1/2)*(z(k).^-1) + (1/4)*(z(k).^-2) );
    end
##################################################################################
H2 = zeros(1,length(z));
    for k=1:length(z)
        H2(k) = (z(k).^-1) / (1 - (z(k).^-1) - (z(k)^-2) );
    end
##################################################################################
H3 = zeros(1,length(z));
    for k=1:length(z)
       H3(k) = 7 / (1- (2*(z(k).^-1)) + (6*(z(k).^-2)) );
    end
##################################################################################
##    H4 = zeros(1,length(z));
##    for k=1:length(z)
##        suma=0;
##        for p=0:7
##            suma = suma + (2^(-p))*(z(k)^(-p));
##        end
##        H4(k) = suma;
##    end

H4 = zeros(1,length(z));
    for k=1:length(z)
        H4(k) = 1 + (1/2  * z(k)^-1) + (1/4 *  z(k)^-2) + (1/8 *  z(k)^-3) + (1/16 *  z(k)^-4) + (1/32 *  z(k)^-5) + (1/64 *  z(k)^-6) + (1/128 *  z(k)^-7);
    end
####################################################################################################################################################################
subplot(2,2,1);
plot(w,abs(H1));
title('H1')
subplot(2,2,2);
plot(w,abs(H2)); #Hago el abs pq puede dar valores negativos y para mostrar la magnitud de las funciones de transferencia H(z)
title('H2')
subplot(2,2,3);
plot(w,abs(H3));
title('H3')
subplot(2,2,4);
plot(w,abs(H4));
title('H4')

