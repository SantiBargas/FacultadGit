pkg load symbolic
h_menos = 0.1;
h_mas = 1.1 * h_menos;

x=0.5;
x_menos = x - h_menos; % Corregido el signo
x_mas = x + h_mas;

f = @(x) exp(-x^2);

phi_i_mas = f(x_mas);
phi_i = f(x);
phi_i_menos = f(x_menos);

derivada2 = (2 * phi_i_mas) / (h_mas * (h_mas + h_menos)) ...
            - (2 * phi_i) / (h_mas * h_menos) ...
            + (2 * phi_i_menos) / (h_menos * (h_mas + h_menos));

fprintf("Segunda derivada aproximada = %.5f\n", derivada2);

syms x_sym
f_sym = exp(-x_sym^2);
f_second_derivative_sym = diff(f_sym, x_sym, 2);
f_second_derivative = matlabFunction(f_second_derivative_sym);
true_value = f_second_derivative(x);

fprintf("Valor real = %.5f\n", true_value);

###################################################################
########REFINAMOS MAS LA MALLA PARA VERIFICAR QUE SE ACHICA EL ERROR#####
###################################################################

h_menos = 0.01;
h_mas = 1.1 * h_menos;

x=0.5;
x_menos = x - h_menos; % Corregido el signo
x_mas = x + h_mas;

f = @(x) exp(-x^2);

phi_i_mas = f(x_mas);
phi_i = f(x);
phi_i_menos = f(x_menos);

derivada2 = (2 * phi_i_mas) / (h_mas * (h_mas + h_menos)) ...
            - (2 * phi_i) / (h_mas * h_menos) ...
            + (2 * phi_i_menos) / (h_menos * (h_mas + h_menos));

fprintf("Segunda derivada aproximada = %.5f\n", derivada2);

syms x_sym
f_sym = exp(-x_sym^2);
f_second_derivative_sym = diff(f_sym, x_sym, 2);
f_second_derivative = matlabFunction(f_second_derivative_sym);
true_value = f_second_derivative(x);

fprintf("Valor real = %.5f\n", true_value);
