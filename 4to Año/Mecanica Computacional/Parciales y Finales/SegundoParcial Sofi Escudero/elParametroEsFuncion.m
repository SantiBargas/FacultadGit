function esFuncion = elParametroEsFuncion(valor)
    if isa(valor, 'function_handle')
        esFuncion = 1;
    elseif isscalar(valor) || isnumeric(valor)
        esFuncion = -1;
    end
end
