pkg load symbolic;

% Verificación de divergencia:
% Si div(v) = 0, entonces el flujo es incompresible

syms x y r theta A n c

% Potenciales y sus divergencias
phi_a = (1/(2*pi))*log(r); % Calculado utilizando coordenadas polares
div_phi_a = diff(diff(phi_a, r), r) + (1/(r^2))*diff(diff(phi_a, theta), theta) + (1/r)*(diff(phi_a, r));

phi_b = x;
div_phi_b = diff(diff(phi_b, x), x) + diff(diff(phi_b, y), y);

phi_c = A*(r^n)*cos(n*theta);
div_phi_c = diff(diff(phi_c, r), r) + (1/(r^2))*diff(diff(phi_c, theta), theta) + (1/r)*(diff(phi_c, r));

phi_d = cos(theta)/r;
div_phi_d = diff(diff(phi_d, r), r) + (1/(r^2))*diff(diff(phi_d, theta), theta) + (1/r)*(diff(phi_d, r));

% Funciones de corriente y sus divergencias
psi_a = c*theta;
div_psi_a = diff(diff(psi_a, r), r) + (1/(r^2))*diff(diff(psi_a, theta), theta) + (1/r)*(diff(psi_a, r));

psi_b = y;
div_psi_b = diff(diff(psi_b, x), x) + diff(diff(psi_b, y), y);

psi_c = A*(r^n)*sin(n*theta);
div_psi_c = diff(diff(psi_c, r), r) + (1/(r^2))*diff(diff(psi_c, theta), theta) + (1/r)*(diff(psi_c, r));

psi_d = -sin(theta)/r;
div_psi_d = diff(diff(psi_d, r), r) + (1/(r^2))*diff(diff(psi_d, theta), theta) + (1/r)*(diff(psi_d, r));

% Mostrar los resultados
disp('div_phi_a =');
disp(div_phi_a);

disp('div_phi_b =');
disp(div_phi_b);

disp('div_phi_c =');
disp(div_phi_c);

disp('div_phi_d =');
disp(div_phi_d);

disp('div_psi_a =');
disp(div_psi_a);

disp('div_psi_b =');
disp(div_psi_b);

disp('div_psi_c =');
disp(div_psi_c);

disp('div_psi_d =');
disp(div_psi_d);

