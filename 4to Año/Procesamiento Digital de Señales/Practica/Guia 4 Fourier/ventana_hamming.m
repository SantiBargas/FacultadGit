function w = ventana_hammging(n,N)
    % Genera una ventana de Hamming de la longitud especificada.


    w = 0.54 - 0.46 * cos(2 * pi * n / N);
endfunction
