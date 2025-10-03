function ej1(tiempo,funcion)


    % Calcular el valor medio
    valor_medio2=valor_medio(funcion)

  % Calcular el máximo y el mínimo
    maximo = max(funcion)
    minimo = min(funcion)

    % Calcular la amplitud
    amplitud = maximo - minimo;

    % Calcular la energía  # (||x||2)^2
    %p=2 norma 2 representa la energia
    energia = energia(funcion)

    % Calcular la acción %sum(abs(x))
    accion2=accion(funcion)

    % Calcular la potencia media
    pot_media=potencia_media(funcion)

    % Calcular la raíz cuadrada del valor cuadrático medio (RMS)
     RMS = sqrt(pot_media)

endfunction
########SENOIDAL##################################
##[tiempo,funcion]=ej1(0,1,100,1,1,0);
##ej1(tiempo,funcion)
##
##VALOR MEDIO: Se esperaria 0 si la señal esta balanceada al rededor de un eje, es decir si tiene misma cantidad de area positiva y negativa
##

##############CUADRADA#############################
##[tiempo,funcion]=ej1_c_cuadrada(0  ,  1,  500,3,1,0);
##ej1(tiempo,funcion)
