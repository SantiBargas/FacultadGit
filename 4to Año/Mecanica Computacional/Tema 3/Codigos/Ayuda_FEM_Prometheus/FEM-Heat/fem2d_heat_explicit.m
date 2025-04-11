function [PHI_vec,Q_vec] = fem2d_heat_explicit(K,C,F,xnode,icone,model,dt)
% Descripci�n: m�dulo para resolver el sistema lineal de ecuaciones utilizando
% esquema temporal expl�cito.

% Entrada:
% * K: matriz del sistema (difusi�n + reacci�n).
% * C: matriz de masa del sistema.
% * F: vector de flujo t�rmico.
% * xnode: matriz de nodos con pares (x,y) representando las coordenadas de 
%   cada nodo de la malla.
% * icone: matriz de conectividad. Indica los 3 � 4 nodos que integran el 
%   elemento, recorridos en cualquier orden pero en sentido antihorario. 
%   En caso de elementos triangulares, la cuarta columna siempre es -1.
% * model: struct con todos los datos del modelo (constantes, esquema num�rico, etc.)
% * dt: paso temporal cr�tico para m�todo expl�cito.

% Salida:
% * PHI: matriz soluci�n. Cada elemento del vector representa un valor 
%   escalar asociado a cada nodo de la malla, y su posici�n dentro del vector 
%   depende de c�mo se especific� cada nodo en xnode. Cada columna representa 
%   una iteraci�n del esquema temporal (en total nit columnas).
% * Q: matriz de flujo de calor. Para cada nodo se halla un vector bidimensional
%   de flujo de calor, representado por un par (Qx,Qy). Cada par de columnas 
%   representa una iteraci�n del esquema temporal (en total 2�nit columnas).

    auxA = dt/(model.rho*model.cp);    
    
    PHI = model.PHI_n;
    PHI_n = model.PHI_n;
    PHI_vec = PHI;
    Q_vec = zeros(model.nnodes,2);
    
    for n = 1 : model.maxit
        PHI = C\(auxA*(F - K*PHI_n) + C*PHI_n);
        
        % Error relativo entre las últimas dos iteraciones
        err = norm(PHI-PHI_n,2)/norm(PHI,2);
        
        % actualizo phi(n+1) será phi(n) para el siguiente paso
        PHI_n = PHI;
        PHI_vec = [PHI_vec PHI];
        [Q] = fem2d_heat_flux(xnode,icone,model,PHI);
        Q_vec = [Q_vec, Q];
        
        if err < model.tol
            disp('Metodo terminado por tolerancia de error.');
            return;
        end
    end
end