%Componentes del tensor de tensión.
sx = 3;
sy = 5;
sz = 3;
sxy = 0;
sxz = 0;
syz = 0;

%Vector normal al plano que me interesa obtener el vector tensión.
%(se normaliza después)
nx = 1;
ny = 0;
nz = 0;
%
isPlotVecNorm = true;

% Centro de acción de la carga.
x0 = 1;
y0 = -1;
z0 = 0;

% Datos del círculo que marca el plano normal.
radioMin = 0.5;
pasoCirc = pi/100;
fRadio = 1.2;

%%
m_x0 = [x0;y0;z0];
%
m_vn = [nx;ny;nz];
m_vn = m_vn/norm(m_vn);
%
m_S = [sx,sxy,sxz;sxy,sy,syz;sxz,syz,sz];
%
m_vT = m_S*m_vn;
Tn = m_vT'*m_vn;
m_vTn = Tn*m_vn;
m_vTt = m_vT-m_vTn;
Tt = norm(m_vTt);

%%
m_Theta = 0:pasoCirc:2*pi;
%Devuelve dos vectores normales al vector normal.
m_vNormn = null(m_vn');
radioCirc = fRadio*Tt;
if radioCirc<radioMin
   radioCirc = radioMin;
end
%Se usa expansión automática de arrays (ML2016b+)
m_CoordCirc = m_x0+radioCirc*(m_vNormn(:,1)*cos(m_Theta)+m_vNormn(:,2)*sin(m_Theta));
%Gráfico del círculo
fill3(m_CoordCirc(1,:),m_CoordCirc(2,:),m_CoordCirc(3,:),'g','EdgeColor','none','FaceAlpha',0.9)
%
%Vector tensión
hold on
h_T = quiver3(m_x0(1),m_x0(2),m_x0(3),m_vT(1),m_vT(2),m_vT(3),0,'Linewidth',1.5);
h_Tn = quiver3(m_x0(1),m_x0(2),m_x0(3),m_vTn(1),m_vTn(2),m_vTn(3),0,'Linewidth',1.5);
h_Tt = quiver3(m_x0(1),m_x0(2),m_x0(3),m_vTt(1),m_vTt(2),m_vTt(3),0,'Linewidth',1.5);
if isPlotVecNorm
   h_n = quiver3(m_x0(1),m_x0(2),m_x0(3),m_vn(1),m_vn(2),m_vn(3),0,'k','Linewidth',1.5);
end
hold off
m_hLey = [h_T;h_Tn;h_Tt];
m_cLey = {'Vector tension \bf{T}','Vector tensión normal \bf{T_n}','Vector tensión tangencial \bf{T_t}'};
if isPlotVecNorm
   m_hLey = [m_hLey;h_n];
   m_cLey = [m_cLey,{'Vector normal \bf{n}'}];
end
legend(m_hLey,m_cLey,'Location','best')
xlabel('X')
ylabel('Y')
zlabel('Z')
grid on
axis equal


