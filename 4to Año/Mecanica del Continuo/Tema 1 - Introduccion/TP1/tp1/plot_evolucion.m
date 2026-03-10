function plot_evolucion()
  global X mass conec rig Fext;

  % Paso 1: Identificar la barra "a" y el nodo "b"
barra_a = 2; % Barra 2
nodo_b = 11; % Nodo 11

% Paso 2: Extraer los datos relevantes de la simulación
nodos_barra_a = conec(barra_a, :); % Nodos que conforman la barra "a"
posicion_nodo_a = nodos_barra_a(1); % Posición del primer nodo de la barra "a"
posicion_nodo_b = nodos_barra_a(2); % Posición del segundo nodo de la barra "a"

% Calculamos la diferencia entre las posiciones de los nodos para obtener la longitud de la barra
longitud_barra = sqrt((X(posicion_nodo_b*2-1, :) - X(posicion_nodo_a*2-1, :)).^2 + (X(posicion_nodo_b*2, :) - X(posicion_nodo_a*2, :)).^2);

% Calculamos el esfuerzo de la barra utilizando la ley de Hooke (F = k * delta_x)
esfuerzo_barra_a = rig(barra_a) .* (longitud_barra - 40);

% Paso 3: Extraer la coordenada actual del nodo "b"
coordenada_nodo_b = X(nodo_b*2-1, :); % Tomamos la coordenada x del nodo b

% Paso 4: Graficar la evolución del esfuerzo de la barra "a" y de la coordenada actual del nodo "b" versus el tiempo
figure;
subplot(2, 1, 1);
plot(t, esfuerzo_barra_a);
title('Evolución del esfuerzo de la barra a');
xlabel('Tiempo (s)');
ylabel('Esfuerzo (N)');

subplot(2, 1, 2);
plot(t, coordenada_nodo_b);
title('Evolución de la coordenada del nodo b');
xlabel('Tiempo (s)');
ylabel('Coordenada (m)');

