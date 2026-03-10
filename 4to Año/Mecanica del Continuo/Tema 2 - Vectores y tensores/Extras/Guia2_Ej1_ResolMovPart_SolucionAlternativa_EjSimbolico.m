syms t0 tF r0 v0 t theta positive
syms x y z real
%syms ms_r(x,y,x,t) 
syms ms_v0 ms_r0 real

%%
%Instante inicial
t0 = sym(0);
%Para caso de paso variable usar:
%t0 = 0.001*pi;
%Instante final
tF = 6*sym(pi);
%Módulo de la posición inicial (Radio del movimiento).
r0 = sym(1);
%Componentes de la velocidad inicial
u0 = sym(1);
%phiv0 = 0;
%phiv0 = 15*pi/180;
%v0 = u0*tan(phiv0);
h = sym(1);
v0 = h/2/pi*r0;
%
%Se usa coordenadas cartesianas.
%Definición de posición y velocidad inicial.
ms_r0 = r0*[1;0;0];
ms_v0 = [0;u0;v0];
%
%Definición de la función aceleración.
%%Hélice con paso constante.
%Aceleración radial o centrípeta.
ar = u0^2/r0;
theta = u0/r0*(t-t0);
fsm_a(t) = simplify(ar*[-cos(theta);-sin(theta);0]);
%%Hélice con paso variable.
% ar = u0^2/r0;
% theta = u0/r0*(t-t0);
% fsm_a(t) = simplify(ar*[-cos(theta);-sin(theta);0.1]);
%%Hélice cónica descentrada con paso variable
%Para verla bien hay que girar la vista.
% ar = u0^2*t/r0;
% theta = u0/r0*(t-t0);
% fsm_a(t) = simplify(ar*[-cos(theta);-sin(theta);t]);
%
%%Datos de ploteo.
% Radio de esfera para plot
rE = 0.25*double(r0);
% Delta tiempo para 
dt = 0.1;
% Dibujar esfera
dibEsf = true;
dibEjes = true;

%%
fsm_v(t) = simplify(int(fsm_a,t));
fsm_v(t) = simplify(fsm_v(t)-fsm_v(t0)+ms_v0);
fsm_r(t) = simplify(int(fsm_v(t),t));
fsm_r(t) = simplify(fsm_r(t)-fsm_r(t0)+ms_r0);

%%
%Para transformar la función (vectorial) simbólica en una vector simbólico.
ms_r = fsm_r(t);
%ezplot3(ms_r(1),ms_r(t)ms_r(2),ms_r(3),double([t0,tF]))
fplot3(ms_r(1),ms_r(2),ms_r(3),double([t0,tF]))
xlabel('X')
ylabel('Y')
zlabel('Z')
axis equal
%axis square

%% Cálculo de elementos adicionales.
fs_ModVeloc = simplify(norm(fsm_v(t)));
fsm_vTang(t) = simplify(fsm_v(t)/fs_ModVeloc);
fs_AcelTang = diff(fs_ModVeloc,t);
fsm_vNorm(t) = simplify((fsm_a-fs_AcelTang*fsm_vTang(t))/fs_ModVeloc^2);
fs_Curv(t) = simplify(norm(fsm_vNorm(t)));
fsm_vNorm(t) = fsm_vNorm(t)/fs_Curv(t);
fsm_vBiNorm(t) = simplify(cross(fsm_vTang(t),fsm_vNorm(t)));

%% 
[m_CoordXEsf,m_CoordYEsf,m_CoordZEsf] = sphere;
f_Esf = @(m_r){rE*m_CoordXEsf+m_r(1);rE*m_CoordYEsf+m_r(2);rE*m_CoordZEsf+m_r(3)};
hold on
m_r = double(fsm_r(t0));
c_CoordEsf = f_Esf(m_r);
if dibEsf
   h_Esf = surf(c_CoordEsf{:},'EdgeColor','none');
end
if dibEjes
   m_Ejes = double([fsm_vTang(t0)';fsm_vNorm(t0)';fsm_vBiNorm(t0)']);
   h_Ejes = quiver3(m_r(1)*ones(3,1),m_r(2)*ones(3,1),m_r(3)*ones(3,1),...
      m_Ejes(:,1),m_Ejes(:,2),m_Ejes(:,3));
end
hold off
%
axis equal
%Si se usa square por la escala, la esfera se puede ver chata.
%axis square
for ti = t0:dt:tF
   m_r = double(fsm_r(ti));
   if dibEsf
      c_CoordEsf = f_Esf(m_r);
      h_Esf.XData = c_CoordEsf{1};
      h_Esf.YData = c_CoordEsf{2};
      h_Esf.ZData = c_CoordEsf{3};
   end
   if dibEjes
      h_Ejes.XData = m_r(1)*ones(3,1);
      h_Ejes.YData = m_r(2)*ones(3,1);
      h_Ejes.ZData = m_r(3)*ones(3,1);
      m_Ejes = double([fsm_vTang(ti)';fsm_vNorm(ti)';fsm_vBiNorm(ti)']);
      h_Ejes.UData = m_Ejes(:,1);
      h_Ejes.VData = m_Ejes(:,2);
      h_Ejes.WData = m_Ejes(:,3);
   end
   drawnow
   %pause(0.01)
end
% Otra opción
%comet3