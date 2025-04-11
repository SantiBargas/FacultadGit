pkg load symbolic

% Parámetros del problema
n_elementos = 3; % Número total de elementos
n_nodos = 4; % Número total de nodos
E = [20*10^9 20*10^9 10*10^9]; % Módulos de elasticidad para cada elemento [Pa]
area = [0.0006, 0.0006, 0.0012]; % Áreas de cada elemento [m^2]
xnod = [0 ; 700 ; 1400 ; 2100];
icone = [1 2 ; 2 3 ; 3 4];
Desplaz = [0 1 1 0];
Fuerzas = [0 13500 0 0];
L = [700 700 700];

##Nele = 3;                             % Número de elementos
##E = [20*10^9 20*10^9 10*10^9];        % Módulo de elasticidad por barra/elemento
##area = [0.0006 0.0006 0.0012];        % Areas de cada elemento
##xnod = [0 ; 700 ; 1400 ; 2100];       % Coordenadas de cada nodo
##icone = [1 2 ; 2 3 ; 3 4];            % icone de cada barra
##Desplaz = [0 1 1 0];                  % Desplazamientos por nodo s cond. borde
##Fuerzas = [0 13500 0 0];              % Fuerzas aplicadas por nodo
##L = [700 700 700];                    % Longitud de cada barra en un vector.



% Inicialización de la matriz de rigidez global
K_global = zeros(n_nodos);
K_global_coef = [1 -1 0 0; -1 2 -1 0; 0 -1 2 -1; 0 0 -1 1];
%Construccion de la matriz de rigidez global [K]
for i = 1:n_elementos
    %Obtener nodos de cada elemento
    nodo_inicio = icone(i,1);
    nodo_fin = icone(i,2);

    %Calcular rigidez del elemento
    k_e = (E(i) * area(i)) / L(i);

    % Matriz de rigidez del elemento local
    K_e = k_e * [1 -1; -1 1];

        % Ensamblaje en la matriz de rigidez global
    K_global(nodo_inicio, nodo_inicio) += K_e(1, 1);
    K_global(nodo_inicio, nodo_fin) += K_e(1, 2);
    K_global(nodo_fin, nodo_inicio) += K_e(2, 1);
    K_global(nodo_fin, nodo_fin) += K_e(2, 2);

end
K_global


% Modificar el sistema para aplicar las condiciones de borde (u1 = 0, u4 = 0)
% Eliminamos las filas y columnas correspondientes a u1 y u4
% Nodos con desplazamiento fijo (condiciones de borde)
nodos_fijos = find(Desplaz==0)
% Identificar los grados de libertad que no están restringidos
grados_libres = setdiff(1:n_nodos, nodos_fijos)

% Reducir el sistema de ecuaciones para los grados de libertad libres
K_reducido = K_global(grados_libres, grados_libres);
F_reducido = Fuerzas(grados_libres).';

% Resolver el sistema reducido
U_reducido = K_reducido \ F_reducido;

% Reconstruir el vector de desplazamientos completo
U = zeros(n_nodos, 1);
U(grados_libres) = U_reducido;

% Calcular las reacciones en los nodos fijos
R = K_global * U ;

% Mostrar resultados
disp('Desplazamientos en cada nodo:')
disp(U)
disp('Reacciones en los nodos fijos:')
disp(R(nodos_fijos))
disp(' ')
disp('Reacciones en todos los nodos:')
disp(R)

%~~~~~~~~~~~~~~~~~~~~~~~~~~~~Resultados Pedidos~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~%
% Esfuerzos (tensiones)
Esfuerzos =zeros(1,n_elementos);
for i=1:n_elementos     %Calcular los esfuerzos por barra/elemento
    indice = icone(i,:);
    Esfuerzos(i)=(E(i)./L(i))*[-1 1]*[U(indice(1,1));U(indice(1,2))];
end

Esfuerzos


%~~~~~~~~~~~~~~~~~~~~Gráficamos el dominio con resultados~~~~~~~~~~~~~~~~~~~~~~%

figure(1)
line([xnod(1) xnod(end)],[0 0],'Color','k','LineWidth',2);
hold on
plot(xnod',zeros(1,length(xnod)),'or','MarkerSize',6,'MarkerFaceColor','r');
grid on
grid minor

NodosDesp = xnod' + U';
Nocero = find(U~=0);
hold on

plot(NodosDesp(Nocero),zeros(1,length(Nocero)),'og','MarkerSize',6,'MarkerFaceColor','g');
axis([xnod(1)-10 xnod(end)+10 -1 1]);
title('Ejercicio Resuelto(Hacer zoom en cada nodo hasta ver el desplazamiento');

legend({'Barra';'Nodos empotrados y originales' ; 'Nodos desplazados'});



