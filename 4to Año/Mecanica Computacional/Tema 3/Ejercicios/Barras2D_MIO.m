
##############################################################################
#################VARIABLES DEL PROBLEMA#######################################
##############################################################################

##n_elementos = 3;                                % Numero de elementos
##E(1:n_elementos) = 30*10^6;                     % Modulo de elasticidad por ele/^barra
##area(1:n_elementos) = 2;                        % areas de cada elemento/barra
#### Arreglo bidimensional por ser 2D
##xnod = [0 0 ; 0 120; 120 120; 120 0];    % Coordenadas de cada nodo
##n_nodos = size(xnod,1)
##icone = [1 2;1 3;1 4];                   % Conectividad de los Nodos
#### estos vectores manejan pares de valores por ser 2D
##Desplaz = [1 1 0 0 0 0 0 0];             % Desplazamientos por nodo
##F = [0 -10000 0 0 0 0 0 0 ];       % Fuerzas por nodo


####Problema 3
## n_elementos=3;
## n_nodos = 4;
## #E(1:n_elementos)=10*10^6;
## E = [10*10^6,10*10^6,10*10^6];
## #A(1:n_elementos)=1;
## area=[1,1,1];
## xnod=[0 0 ; -100 100*tand(60); -100  0 ;-100 -100*tand(30)];
## icone=[1 2;1 3;1 4];
## Desplaz = [1 1 0 0 0 0 0 0 ];
#Desplaz = [u1 v1 u2 v2 u3 v3.....]
## F = [1000 1000 0 0 0 0 0 0];

######Problema 4 Apunte teorico practico
##n_elementos = 3;
##n_nodos = 4;                                % Numero de elementos
##E(1:n_elementos) = 70*10^6; %en realidad es 30*10^6 segun el pdf pero el profe resuelve con 70*10^6 asi q resuelvo con eso para chequear resultados  % Modulo de elasticidad por ele/^barra
##area= [3*10^-4 , 3*10^-4,  3*10^-4,  3*10^-4,  3*10^-4, (3/2)*10^-4 ];                      % areas de cada elemento/barra
#### Arreglo bidimensional por ser 2D
##xnod = [0 0 ; 0 120; 120 120; 120 0];    % Coordenadas de cada nodo
##icone = [1 2;1 3;1 4];
#### estos vectores manejan pares de valores por ser 2D
##Desplaz = [1 1 0 0 0 0 0 0];             % Desplazamientos por nodo
###Desplaz = [u1 v1 u2 v2 u3 v3.....]
##F = [0 -10000 0 0 0 0 0 0 ];       % Fuerzas por nodo


####Problema 6 Apunte teorico practico
##n_elementos = 3;
##n_nodos = 3;
##E = [50,50,50]; %E1A1 = 50 E2A2 = 100 E3A3 = 400sqrt(2) buscamos valores arbitrarios para que E*A sea el resultado
##area=[1,2,8*sqrt(2)];
##xnod = [0 0 ; 10 0; 10 10];    % Coordenadas de cada nodo
##icone = [ 1 2; 2 3; 1 3];
##Desplaz =  [0  0  1  0  1  1 ];            % Desplazamientos por nodo
####Desplaz =[u1 v1 u2 v2 u3 v3] # donde ponemos 0 signifca q es = 0 u1 v1 v2 = 0 no se pueden mover
##F =   [0   0   0   0  5   3 ];
###F = [F1x F1y F2x F2y F3x F3y....
##

###Problema 7 (simetria) Apunte teorico practico
##n_elementos = 6;
##n_nodos = 4;                                % Numero de elementos
##E(1:n_elementos) = 70*10^6;                     % Modulo de elasticidad por ele/^barra
##area = [ 3*10^-4, 3*10^-4, 3*10^-4, 3*10^-4, 3*10^-4, (3/2)*10^-4 ];                         % areas de cada elemento/barra
##xnod = [0 0 ; 0 3; 3 0 ; 3 3];    % Coordenadas de cada nodo
##icone = [1 2 ; 1 3 ; 2 3; 2 4 ;1 4 ; 3 4];                % Conectividad de los Nodos
##Desplaz =  [0  0  1  1  0  1  0  1];            % Desplazamientos por nodo
####Desplaz =[u1 v1 u2 v2 u3 v3 u4 v4] # donde ponemos 0 signifca q es = 0 u1 v1 u3 u4 = 0
##F = [0 0 0 -50 0 0 0 -50 ];       % Fuerzas por nodo
###F = [F1x F1y F2x F2y F3x F3y....


###Problema 8 Apunte teorico practico
##n_elementos = 3;
##n_nodos = 4;                                % Numero de elementos
##E(1:n_elementos) = 1 ;                   % Modulo de elasticidad por ele/^barra
##area(1:n_elementos)=1;                        % areas de cada elemento/barra
##xnod = [(-sqrt(3)/2) -1/2 ;  (-sqrt(3)/2) 1/2 ; 0 1; 0 0];   % Coordenadas de cada nodo
##icone = [1 4 ; 2 4; 3 4];                % Conectividad de los Nodos
##Desplaz =  [0  0  0  0  0  0  1  1 ];            % Desplazamientos por nodo
####Desplaz =[u1 v1 u2 v2 u3 v3 u4 v4] # donde ponemos 0 signifca q es = 0 u1 v1 u2 v2 u3 v3 = 0
##F = [ 0   0    0   0   0    0  1  0 ];       % Fuerzas por nodo
###F = [F1x F1y F2x F2y F3x F3y F4x F4y


##############################################################################
##############################################################################
##############################################################################

##############################################################################
####################### CÁLCULO DE LAS LONGITUDES L Y ANGULOS ################
##############################################################################
L = zeros(1, n_elementos);     % Longitud de cada barra
grados = zeros(1, n_elementos); % Ángulo de cada barra con la horizontal

for i=1:n_elementos
    indice = icone(i,:);      % generamos indices para las barras
    b = xnod(indice(2),:);    % Tomamos los valores de Y2 y Y1
    a = xnod(indice(1),:);    % Tomamos los valores de X2 y X1
    % calculamos la longitud de cada barra como norma Euclideana
    % usando la distancia entre dos puntos

    L(i)=norm(b-a);

    % Determinamos el angulo del elemento con respecto a la horizontal
    % por convencion
    dx = xnod(indice(2),1) - xnod(indice(1),1);
    dy = xnod(indice(2),2) - xnod(indice(1),2);
    % Importante:
    % Determinamos en que cuadrante se encuentra el elemento/barra

    grados(i) = atand(dy/dx);        % Cuadrante 1
    if sign(dy)==1 && sign(dx)==-1   % Cuadrante 2
        grados(i) = 180 + grados(i);
    elseif dy==0 && sign(dx)==-1 % Sobre la horizontal pero en el cuadrante 2
        grados(i)=180;
    elseif sign(dy)==-1 && sign(dx)==-1   %Cuadrante 3
        grados(i) = 180 + grados(i);
    elseif sign(dy)==-1 && sign(dx)==1    %Cuadrante 4
        grados(i) = 360 + grados(i);
    end
end
disp('Longitudes de cada barra:');
disp(L);
disp('Ángulos de cada barra con la horizontal:');
disp(grados);
disp(' ')

##############################################################################
#######CONSTRUCCION DE LA MATRIZ DE RIGIDEZ GLOBAL############################
##############################################################################

% Inicialización de la matriz de rigidez global
K_global = zeros(2 * n_nodos);
k_elementos = zeros(4, 4, n_elementos); % Array para almacenar las matrices de rigidez de cada elemento

for i = 1:n_elementos
    nodo_inicio = icone(i,1);
    nodo_fin = icone(i,2);

    % Coordenadas de los nodos del elemento
    x1 = xnod (nodo_inicio, 1);
    y1 = xnod (nodo_inicio, 2);
    x2 = xnod (nodo_fin, 1);
    y2 = xnod (nodo_fin, 2);

    % Cálculo de cos(θ) y sin(θ) a partir del ángulo en grados
    cos_theta = cosd(grados(i));
    sin_theta = sind(grados(i));

    % Matriz de rigidez del elemento en coordenadas globales
    k_e = (E(i) * area(i) / L(i)) * [
        cos_theta^2, cos_theta * sin_theta, -cos_theta^2, -cos_theta * sin_theta;
        cos_theta * sin_theta, sin_theta^2, -cos_theta * sin_theta, -sin_theta^2;
        -cos_theta^2, -cos_theta * sin_theta, cos_theta^2, cos_theta * sin_theta;
        -cos_theta * sin_theta, -sin_theta^2, cos_theta * sin_theta, sin_theta^2;
    ];

    % Almacenar la matriz de rigidez del elemento en el arreglo k_elementos
    k_elementos(:,:,i) = k_e;

    % Imprimir matriz de rigidez de cada elemento para verificar
    printf("Matriz de rigidez del elemento %d:\n", i);
    disp(k_e);
    disp(' ')

    % Ensamblaje en la matriz de rigidez global
    indices = [2*nodo_inicio-1, 2*nodo_inicio, 2*nodo_fin-1, 2*nodo_fin];
    K_global(indices, indices) += k_e;

end
disp(' ')
disp(' ')
disp('Matriz de Rigidez Global:');
disp(K_global);

##############################################################################
##################### CONDICIONES DE BORDE Y FUERZAS #########################
##############################################################################

restricciones = find(Desplaz==0) % Nodos restringidos
grados_libres = setdiff(1:2 * n_nodos, restricciones)  % Nodos libre

K_reducido = K_global(grados_libres, grados_libres)
F_reducido = F(grados_libres).'

% Resolver el sistema de ecuaciones para desplazamientos
U_reducido = K_reducido \ F_reducido

% Reconstruir el vector de desplazamientos completo
U = zeros(2 * n_nodos, 1);
U(grados_libres) = U_reducido;

% Calcular las reacciones en los nodos fijos
% Modificación en la línea de cálculo de R
#R = K_global * U - F; #Teniendo en cuenta fuerzas externas
R = K_global * U; #Sin tener en cuenta fuerzas externas
Reacciones_fijas = R(restricciones);

% Mostrar los resultados
disp('Desplazamientos en cada nodo (en x y y):')
disp(U)
disp(' ')

disp('Reacciones en los nodos fijos:')
disp(Reacciones_fijas)
disp(' ')

disp('Reacciones en todos los nodos :')
disp(R)
disp(' ')

################################################################################
#########CALCULO DE LAS TENSIONES ##############################################
################################################################################

% Inicialización del vector de tensiones
tensiones = zeros(n_elementos, 1);
Fuerzas = zeros(n_elementos, 1);

% Cálculo de tensiones en cada barra
for i = 1:n_elementos
    nodo_inicio = icone(i,1);
    nodo_fin = icone(i,2);

    % Desplazamientos en x e y de los nodos
    ux_i = U(2*nodo_inicio - 1);
    uy_i = U(2*nodo_inicio);
    ux_j = U(2*nodo_fin - 1);
    uy_j = U(2*nodo_fin);

    % Cálculo de C y S para cada barra
    cos_theta = cosd(grados(i));
    sin_theta = sind(grados(i));

    % Vector de desplazamientos en coordenadas globales para el elemento
    d = [ux_i; uy_i; ux_j; uy_j];

    % Matriz [C'] para el elemento
    C_matriz = (E(i) / L(i)) * [-cos_theta, -sin_theta, cos_theta, sin_theta];

    tensiones(i) = C_matriz * d; % Cálculo de la tensión
    Fuerzas(i) = tensiones(i) * area(i); % Cálculo de la fuerza como tensión por área
   # printf("Tensión en el elemento %d: %.2f psi\n", i, tensiones(i));
   # printf("Fuerza en el elemento %d: %.2f N\n", i, Fuerzas(i));

end
tensiones
Fuerzas

% Vector de coeficientes [-C -S C S] para calcular los esfuerzos (teoria)
Ve = @(x) [-cosd(x)  -sind(x)  cosd(x)  sind(x)];
Ve(1);
esfuerzosC = zeros(n_elementos,4);

for i=1:n_elementos
  esfuerzosC(i,:) = Ve(grados(i));
end
esfuerzosC;

U2 = mat2cell(U,2*ones(1,size(xnod ,1)),1); %Dividimos los desplazamientos en paquetes de 2x1
Esfuerzos=zeros(1,n_elementos);
Flocal=zeros(n_elementos,4);
j=1;

for i=1:n_elementos
    indice= icone(i,:);
    Esfuerzos(i)= (E(i)./L(i))*esfuerzosC(i,:)*[U2{indice(1,1)};U2{indice(1,2)}];
    Flocal(i,:)=k_elementos(:,:,i)*[U2{indice(1,1)};U2{indice(1,2)}];
    j=j+2;
end
#Fila 1 : Fuerzas internas del elemento 1
#Fila 2 : Fuerzas internas del elemento 2
#Fila 3 : Fuerzas internas del elemento 3
#Columna: cómo se distribuyen esas fuerzas entre los nodos conectados por el elemento. Nodo 1 a Nodo 2 a Nodo 3 a Nodo4

disp('Flocal representa las fuerzas internas en cada barra (elemento) calculadas a partir de los desplazamientos en los nodos.');
disp('Cada fila de Flocal corresponde a un elemento, y cada columna muestra la fuerza interna en los nodos conectados por ese elemento.');
disp(' ');
disp(Flocal);

% Ejemplo específico para el primer elemento, mostrando el desglose de las componentes de fuerza
disp('Ejemplo para el elemento 1:');
disp(['Fx inicial (nodo 1): ', num2str(Flocal(1,1)), ' N']);
disp(['Fy inicial (nodo 1): ', num2str(Flocal(1,2)), ' N']);
disp(['Fx final (nodo 2): ', num2str(Flocal(1,3)), ' N']);
disp(['Fy final (nodo 2): ', num2str(Flocal(1,4)), ' N']);
disp(' ');

################################################################################
#########CHEQUEO DE EQUILIBRIO #################################################
################################################################################

% Inicialización de sumas de fuerzas en x e y
suma_Fx = 0;
suma_Fy = 0;

for i = 1:n_elementos
    % Tensión y ángulo de la barra
    sigma = tensiones(i);
    cos_theta = cosd(grados(i));
    sin_theta = sind(grados(i));

    % Fuerzas en x e y para el elemento
    Fx = sigma * area(i) * cos_theta;
    Fy = sigma * area(i) * sin_theta;

    % Sumar fuerzas a las componentes globales
    suma_Fx = suma_Fx + Fx;
    suma_Fy = suma_Fy + Fy;
end

% Añadir fuerzas externas en x e y usando el vector F
suma_Fx = suma_Fx + sum(F(1:2:end)); % Componentes en x
suma_Fy = suma_Fy + sum(F(2:2:end)) ;% Componentes en y

% Mostrar el resultado del chequeo de equilibrio
disp('Chequeo de equilibrio:')
disp(['Suma de Fx = ', num2str(suma_Fx), ' (debe ser 0)'])
disp(['Suma de Fy = ', num2str(suma_Fy), ' (debe ser 0)'])

################################################################################
#########PLOTEO #################################################
################################################################################
##
% Desplazamientos en coordenadas nodales
d3 = reshape(U, [2, n_nodos])'; % Reshape para obtener los desplazamientos en formato de coordenadas
NodosDesp = xnod  + d3;   % Nuevas posiciones de los nodos

% Crear figura
figure;

% Subgráfico 1: Estructura original
subplot(1, 2, 1); % 1 fila, 2 columnas, gráfico 1
hold on; % Mantener la figura actual para graficar
for j = 1:n_elementos
    indice = icone(j,:);
   line([xnod(indice(1),1), xnod(indice(2),1)], [xnod(indice(1),2), xnod(indice(2),2)], 'LineWidth', 1.5, 'Color', 'k');  % Estructura original
end
% Graficar los nodos
for i = 1:size(xnod ,1)
    plot(xnod (i,1), xnod (i,2), 'ro', 'MarkerSize', 6, 'MarkerFaceColor', 'r');
end
axis equal;
grid on;
xlabel('X (in)');
ylabel('Y (in)');
title('Estructura Original');

% Subgráfico 2: Estructura deformada
subplot(1, 2, 2); % 1 fila, 2 columnas, gráfico 2
hold on; % Mantener la figura actual para graficar
for j = 1:n_elementos
    indice = icone(j,:);
    line([NodosDesp(indice(1),1), NodosDesp(indice(2),1)], ...
         [NodosDesp(indice(1),2), NodosDesp(indice(2),2)], ...
         'LineWidth', 1, 'Color', 'b');  % Estructura deformada
end
% Graficar los nodos
for i = 1:size(NodosDesp, 1)
    plot(NodosDesp(i,1), NodosDesp(i,2), 'ro', 'MarkerSize', 6, 'MarkerFaceColor', 'r');
end
axis equal;
grid on;
xlabel('X (in)');
ylabel('Y (in)');
title('Estructura Deformada');

% Ajustes finales
title('Comparación de la Estructura Original y Deformada'); % Título general


