function [x] = w_optimoA(A, metodo)
    format long;

    if metodo == 'ja'
        [rhoA] = RadioEspectral(A, 'ja', 0);
    elseif metodo == 'gs'
        [rhoA] = RadioEspectral(A, 'gs', 0);
    end

    x = 2 / (1 + sqrt(1 - rhoA^2));
end


