
displacements = [1];
max_order = 4;

result = taylor_expansion3(displacements, max_order);

% Mostrar resultados
for i = 1:length(displacements)
    fprintf('Expansión para phi_{i%+d}:\n', displacements(i));
    for n = 0:max_order
        fprintf('Término de orden %d: %s\n', n, char(result{i, n + 1}));
    end
    fprintf('\n');
end



