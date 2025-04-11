function [reaction] = fem2d_pstr_reaction(K,F,U,Fixnodes)
% Descripci�n: m�dulo para calcular las reacciones presentes en nodos con condici�n
% de borde Dirichlet.

% Entrada:
% * K: matriz del sistema.
% * F: vector de fuerzas.
% * U: vector soluci�n (desplazamientos). Cada elemento del vector representa un
%   valor vectorial (dos grados de libertad) asociado a cada nodo de la malla, y
%   su posici�n dentro del vector depende de c�mo se especific� cada nodo en xnode.
% * Fixnodes: matriz con la informaci�n sobre la frontera de tipo Dirchlet.
%   - Columna 1: �ndice de nodo
%   - Columna 2: valor del desplazamiento en x.
%   - Columna 3: valor del desplazamiento en y.

% Salida:
% * reaction: vector de reacciones. Por cada nodo se computan las componentes x e y 
%   de la reacci�n en dicho nodo.

    if isempty(Fixnodes)
        disp('************');
        disp('El problema ha sido mal condicionado. Se espera al menos una condicion Dirichlet');
        disp('************');
        reaction = [];
    else
        reaction = sparse(size(U,1),1);
        fix = 2*Fixnodes(:,1)+Fixnodes(:,2)-2;
        reaction(fix) = K(fix,:) * U - F(fix);
    end

end