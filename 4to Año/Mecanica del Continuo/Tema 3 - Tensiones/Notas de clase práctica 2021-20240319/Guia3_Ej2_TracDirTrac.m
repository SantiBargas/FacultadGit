%% Ploteo del vector tracción
%(la curva que forma el extremo del vector tracción al ir cambiando el ángulo de la normal al plano dónde
%actúa)
p = -4;
%sx = 2;
%sx = -2;
%sy = p;
sxy = 0;
%
isPlotConec = true;
%isPlotConec = false;
angPasoConec = pi/4;

%%
f_Tx = @(m_theta)sx*cos(m_theta)+sxy*sin(m_theta);
f_Ty = @(m_theta)sxy*cos(m_theta)+sy*sin(m_theta);
fplot(f_Tx,f_Ty,[0,2*pi],'b','Linewidth',1.5)
%
hold on
%
fplot(@cos,@sin,[0,2*pi],'r','Linewidth',1.5)
%
if isPlotConec
   m_ThetaConec = 0:angPasoConec:2*pi;
   m_nxConec = cos(m_ThetaConec);
   m_nyConec = sin(m_ThetaConec);
   m_TxConec = f_Tx(m_ThetaConec);
   m_TyConec = f_Ty(m_ThetaConec);
   for iPlot = 1:length(m_ThetaConec)
      hPlot = plot([m_nxConec(iPlot),m_TxConec(iPlot)],[m_nyConec(iPlot),m_TyConec(iPlot)],...
         'o--');
      hPlot.MarkerFaceColor = hPlot.Color;
   end
end
%
hold off
%
axis equal
xlabel('Componente x')
ylabel('Componente y')
legend('Vector Tensión \bf{T}','Vector Normal \bf{n}','Location','best')
grid on