%% Ploteo de la norma del vector tensión en dirección de la normal al plano donde actúa.
p = -2;
alfa = 3;

%% Versión sin vectorizar
%f_T = @(theta)norm([p,alfa;alfa,p]*[cos(theta);sin(theta)]);

%% Versión vectorizada
f_T = @(m_theta)vecnorm([p,alfa;alfa,p]*[cos(m_theta.');sin(m_theta.')])';

%%
ezpolar(f_T)