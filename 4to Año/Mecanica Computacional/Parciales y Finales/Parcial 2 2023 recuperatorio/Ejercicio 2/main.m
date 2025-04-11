close all; clear all; more off;

xnode = [
  0,0;
  1,0;
  1/2 , sqrt(3)/2;
];

icone = [
1,2,3,-1
];

DIR = [#NODO - VALOR

];

NEU = [ #Nodo1 #Nodo2 #Valor

];

ROB = [#Nodo1 #Nodo2 #H #Valor
    1,2,100,100;
    2,3,100,100;
    3,1,100,100;
];

PUN = [             #valor           coordenada de puntos

];

disp('---------------------------------------------------------------');
disp('Inicializando modelo de datos...');

model.nnodes = size(xnode,1);
model.nelem = size(icone,1);

model.kx = 53 ;
model.ky = 53;
model.c = 0 ;
model.G = 0*ones(size(xnode,1));

% Esquema Temporal: [0] Explícito, [1] Implícito, [X] Estacionario
model.ts = 1 ;

% Parámetros para esquemas temporales
model.rho = 7800 ;
model.cp = 460;

model.tol = 1e-6;

alpha = model.kx / (model.rho * model.cp);  % Coeficiente de difusión térmica
deltax = norm(xnode(2,:) - xnode(1,:)) % Distancia euclidiana
% Cálculo del paso de tiempo dt
#dt = 0.5 * deltax ^2 / alpha %%alpha = k /pcp
disp('el dt para asegurar estabilidad es:')
dt = (0.5 * deltax^2) / alpha

t_final = 1;

model.dt = 0.1;
model.maxit = ceil(t_final / 0.1)



% Condición inicial
##model.PHI_n = mean(DIR(:,2))*ones(model.nnodes,1);
model.PHI_n = zeros(model.nnodes,1); % Inicializar en 0 si no hay DIR

disp('Iniciando el método numérico...');

% Llamada principal al Método de Elementos Finitos
[PHI,Q] = fem2d_heat(xnode,icone,DIR,NEU,ROB,PUN,model);

disp('Finalizada la ejecución del método numérico.');

##disp('---------------------------------------------------------------');
##disp('Iniciando el post-procesamiento...');
##
##% mode ---> modo de visualización:
##%           [0] 2D - Con malla
##%           [1] 3D - Con malla
##%           [2] 2D - Sin malla
##%           [3] 3D - Sin malla
##% graph --> tipo de gráfica:
##%           [0] Temperatura (escalar)
##%           [1] Flujo de Calor (vectorial)
##%           [2] Flujo de Calor eje-x (escalar)
##%           [3] Flujo de Calor eje-y (escalar)
##%           [4] Magnitud de Flujo de Calor (escalar)
##mode = 0;
##graph = 0;
##fem2d_heat_graph_mesh(full(PHI),Q,xnode,icone,mode,graph);
##
##disp('Finalizado el post-procesamiento.');


#############################################
%Para elegir el dt para implicito usamos la ecuacion de estabilidad
#  dt = 0.5 * deltax ^2 / alpha
%% donde alpha = k /pcp
##alpha = model.kx / (model.rho * model.cp);  % Coeficiente de difusión térmica
##deltax = norm(xnode(2,:) - xnode(1,:)); % Distancia euclidiana
##% Cálculo del paso de tiempo dt
###dt = 0.5 * deltax ^2 / alpha %%alpha = k /pcp
##disp('el dt para asegurar estabilidad es:')
##dt = (0.5 * deltax^2) / alpha;


%Para que el codigo vaya hasta T_final = 1s o T_final = 2s

t_final = 2;  % segundos
model.maxit = ceil(t_final / dt); %inciso c



####################################################
##disp("\n Temperatura en x=0 y=0 NODO 1");
##T1=PHI(1,:);
##T2=PHI(2,:);
##T3=PHI(3,:);
##
##% Vector de tiempos
##dt = model.dt;
##times = 0:dt:(length(T1)-1)*dt;
##% Crear la matriz emparejada
##resultadoT1 = [times', T1']
##resultadoT2 = [times', T2']
##resultadoT3 = [times', T3']

%===============================================================================================%

 flujo = zeros(3,1); % Tres caras en el triángulo

    % Obtener coordenadas de los nodos del triángulo
    x = xnode(icone(1,1:3),1);
    y = xnode(icone(1,1:3),2);

    % Calcular matriz B para obtener gradiente de temperatura
    Area = 0.5 * abs(x(1)*(y(2)-y(3)) + x(2)*(y(3)-y(1)) + x(3)*(y(1)-y(2)));
    B = (1/(2*Area)) * [
        y(2)-y(3), y(3)-y(1), y(1)-y(2);
        x(3)-x(2), x(1)-x(3), x(2)-x(1)
    ];

    % Gradiente de temperatura
grad_T = B * PHI(icone(1,1:3), end); % Tomamos la última iteración


    % Normal en cada lado del triángulo
    normales = [
        y(2)-y(1), -(x(2)-x(1)); % Cara 1-2
        y(3)-y(2), -(x(3)-x(2)); % Cara 2-3
        y(1)-y(3), -(x(1)-x(3)); % Cara 3-1
    ];

    % Normalizar vectores normales
    for i = 1:3
        normales(i,:) = normales(i,:) / norm(normales(i,:));
    end

    % Calcular flujo de calor en cada cara
    for i = 1:3
        flujo(i) = -model.kx * (grad_T' * normales(i,:)');
    end


##
##% ====================[ Cálculo del flujo de calor para un elemento]======================
##x_p = 0  ; y_p = 0;
##elemento = 1;
##
##nodos_aux = icone(elemento, icone(elemento, :) > 0);
##coords_aux = xnode(nodos_aux, :);
##[Ns] = funciones_forma(coords_aux);
##
##% Calcular las derivadas simbólicas de las funciones de forma
##pkg load symbolic;
##syms x y;
##dNs_dx = diff(Ns, x); % Derivada respecto a x
##dNs_dy = diff(Ns, y); % Derivada respecto a y
##
##disp('Derivadas de las funciones de forma respecto a x:');
##disp(dNs_dx);
##disp('Derivadas de las funciones de forma respecto a y:');
##disp(dNs_dy);
##
##% Evaluar las derivadas en el punto (x_p, y_p)
##dNs_dx_eval = double(subs(dNs_dx, [x, y], [x_p, y_p]));
##dNs_dy_eval = double(subs(dNs_dy, [x, y], [x_p, y_p]));
##
##disp('Derivadas evaluadas en el punto (x_p, y_p):');
##disp('dNs_dx_eval:');
##disp(dNs_dx_eval);
##disp('dNs_dy_eval:');
##disp(dNs_dy_eval);
##
##% Gradiente de temperatura en el punto
##T_elem = PHI(nodos_aux); % Temperaturas nodales
##grad_T = [dNs_dx_eval, dNs_dy_eval]' * T_elem;
##
##disp('Gradiente de temperatura en el punto (x_p, y_p):');
##disp(grad_T);
##
##% Calcular el flujo de calor
##q = -diag([model.kx, model.ky]) * grad_T; % q = -[kx, 0; 0, ky] * grad_T
##
##disp('Flujo de calor en el punto (x_p, y_p):');
##disp(['q_x: ', num2str(q(1)), ' W/m^2']);
##disp(['q_y: ', num2str(q(2)), ' W/m^2']);
##
##% Calcular el flujo resultante (magnitud)
##q_resultante = sqrt(q(1)^2 + q(2)^2);
##disp(['Flujo de calor resultante en el punto (x_p, y_p): ', num2str(q_resultante), ' W/m^2']);
####%===============================================================================================%



##%===================== Cálculo de interpolacion de temperatura ========================%
##x_p = 0.6  ; y_p = 0.01;
##elemento = 5;
##
##% Obtener los nodos asociados al elemento
##nodos_aux = icone(elemento, icone(elemento, :) > 0);
##disp('Coordenadas a evaluar en las funciones de forma')
##coords_aux = xnode(nodos_aux, :)
##
##disp('Funciones de forma de coords aux:')
##[Ns] = funciones_forma(coords_aux)
##
##pkg load symbolic;
##syms x y;
##disp('Funciones de forma evaluadas en las coordenadas x y:')
##Ns_eval = double(subs(Ns, [x, y], [x_p, y_p]))
##
##% Interpolación de temperatura
##disp('Temperatura en los nodos del elemento')
##T_elem = PHI(nodos_aux) % Temperaturas en los nodos del elemento
##
##disp('La temperatura interpolada sera Tp= N1*T1 + N2*T2 + N3*T3 ...')
##T_p = Ns_eval' * T_elem
##
##% Mostrar resultado
##disp(['La temperatura interpolada en el punto (' num2str(x_p) ', ' num2str(y_p) ') es: ' num2str(T_p)]);

