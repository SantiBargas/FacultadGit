#Recibo un vector de coordenadas del elemento.
#triangulo = [0 0;1 0;0 1];
function [Ns] = funciones_forma(xnode)
  warning 'off'
  pkg load symbolic
  syms x y;
  if(length(xnode) == 3)
    #Es un triangulo
    aux = [1;1;1];
    m = [aux xnode]
    vector_n1 = [1;0;0];
    vector_n2 = [0;1;0];
    vector_n3 = [0;0;1];

    coef_n1 = m\vector_n1
    coef_n2 = m\vector_n2
    coef_n3 = m\vector_n3

    %N_i = a + b*x + c*y
    N_1 = coef_n1(1) + coef_n1(2)*x + coef_n1(3)*y;
    N_2 = coef_n2(1) + coef_n2(2)*x + coef_n2(3)*y;
    N_3 = coef_n3(1) + coef_n3(2)*x + coef_n3(3)*y;

    Ns = [N_1;N_2;N_3];
  endif

  if(length(xnode) == 4)
    aux = [1;1;1;1];
% Producto de las coordenadas x*y para cada nodo
    aux2 = [xnode(1,1)*xnode(1,2);
            xnode(2,1)*xnode(2,2);
            xnode(3,1)*xnode(3,2);
            xnode(4,1)*xnode(4,2)];
    % Construcción de la matriz M
    m = [aux, xnode(:,1), xnode(:,2), aux2]

    vector_n1 = [1;0;0;0];
    vector_n2 = [0;1;0;0];
    vector_n3 = [0;0;1;0];
    vector_n4 = [0;0;0;1];

    coef_n1 = m\vector_n1;
    coef_n2 = m\vector_n2;
    coef_n3 = m\vector_n3;
    coef_n4 = m\vector_n4;

    % Funciones de forma
    %N_i = a + b*x + c*y + d*x*y
    N_1 = coef_n1(1) + coef_n1(2)*x + coef_n1(3)*y + coef_n1(4)*x*y;
    N_2 = coef_n2(1) + coef_n2(2)*x + coef_n2(3)*y + coef_n2(4)*x*y;
    N_3 = coef_n3(1) + coef_n3(2)*x + coef_n3(3)*y + coef_n3(4)*x*y;
    N_4 = coef_n4(1) + coef_n4(2)*x + coef_n4(3)*y + coef_n4(4)*x*y;

    Ns = [N_1;N_2;N_3;N_4];

  endif

endfunction
