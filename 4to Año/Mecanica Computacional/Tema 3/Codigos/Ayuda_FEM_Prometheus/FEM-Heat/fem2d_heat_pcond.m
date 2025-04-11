function [F] = fem2d_heat_pcond(F,xnode,icone,PUN)
% Descripci�n: m�dulo para calcular y ensamblar las contribuciones producidas
% por fuentes puntuales aplicadas en posiciones (x,y) dentro del dominio. Estos
% pares (x,y) tambi�n pueden ubicarse en los bordes del elemento, incluso en 
% alguno de sus v�rtices.

% Entrada:
% * F: vector de flujo t�rmico.
% * xnode: matriz de nodos con pares (x,y) representando las coordenadas de 
%   cada nodo de la malla.
% * icone: matriz de conectividad. Indica los 3 � 4 nodos que integran el 
%   elemento, recorridos en cualquier orden pero en sentido antihorario. 
%   En caso de elementos triangulares, la cuarta columna siempre es -1.
% * PUN: matriz con la informaci�n sobre las fuentes puntuales aplicadas a 
%   elementos del dominio. 
%   - Columna 1: n�mero de elemento al que se aplica la fuente.
%   - Columna 2: valor de la fuente aplicada (G). 
%   - Columnas 3-4: posici�n absoluta (x,y) donde se aplica la fuente 
%     (cualquier parte del dominio).

% Salida:
% * F: vector de flujo t�rmico con modificaciones luego de aplicar la condici�n
%   de borde.

    for n = 1 : size(PUN,1)
        e = PUN(n,1);
        G = PUN(n,2);
        xp = PUN(n,3);
        yp = PUN(n,4);
        if icone(e,4) == -1 % triangular element
            ele = icone(e,1:3);
        else
            ele = icone(e,:);
        end
        nodes = xnode(ele,:);
        N = fem2d_heat_blerp(nodes,xp,yp); % evaluaci�n de las funciones de forma en coordenadas naturales
        f = N*G;
        F(ele) = F(ele) + f;
    end

end