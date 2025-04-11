
##MAXIMA TEMPERATURA
[max_temp, idx] = max(PHI(:))
[nodo, iteracion] = ind2sub(size(PHI), idx)
maxEstacionario = max(PHI(:,202))

##TEMPERATURA DE NODOS EN UN SEGUNDO ESPECIFICO
t_final = 5;
dt = 0.05;
t_idx = t_final/dt + 1; % Índice de tiempo
nodos_interes = [2, 9, 16, 23, 26, 29, 32,33]; % Nodos de interés
temp_en_nodos_t1s = PHI(nodos_interes, t_idx);% Extracción de temperaturas en esos nodos
% Mostrar los resultados
for i = 1:length(nodos_interes)
    fprintf('Temperatura en el nodo %d a t=5s: %.6f\n', nodos_interes(i), temp_en_nodos_t1s(i));
end
