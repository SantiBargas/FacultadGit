function Fext = FuerzaExterna(t)
    % Aquí defines cómo varía la fuerza externa en función del tiempo
    A = 1; % Amplitud de la fuerza externa
    omega = 0.1; % Frecuencia angular de la fuerza externa
    Fext = A * sin(omega * t); % Fuerza externa sinusoidal
end
