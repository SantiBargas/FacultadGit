function o_Resu = f_PlacaAgujPDE(dima,dimb,dimc,P,E,po,hMaxEF)
   
   % Datos fijos
   nGdl = 2;
   m_Origen = [0,0];
   %
   % Inicialización de objeto PDE
   o_ModelPDE = createpde(nGdl);
   %
   % Definición de la geometría
   m_Rec = [3;4;m_Origen(1)+[0;dimb;dimb;0];m_Origen(2)+[0;0;dimc;dimc]];
   m_Cir = [1;m_Origen';dima];
   m_DatGeom = zeros(max([length(m_Rec);length(m_Cir)]),2);
   m_DatGeom(1:length(m_Rec),1) = m_Rec;
   m_DatGeom(1:length(m_Cir),2) = m_Cir;
   s_NomGeom = char('Dominio','Agujero')';
   s_FormGeom = 'Dominio-Agujero';
   [m_DesGeom,m_BoolGeom] = decsg(m_DatGeom,s_FormGeom,s_NomGeom);
   %pdegplot(m_DesGeom,'EdgeLabels','on','SubdomainLabels','on')
   %No es necesario borrar ninguna geometría.
   %[m_DesGeom,m_BoolGeom] = csgdel(m_DesGeom,m_BoolGeom);
   %
   geometryFromEdges(o_ModelPDE,m_DesGeom);
   %pdegplot(o_ModelPDE,'EdgeLabels','on','SubdomainLabels','on')
   %xlim([m_Origen(1)-0.5,m_Origen(1)+dimb+0.5])
   %ylim([m_Origen(2)-0.5,m_Origen(2)+dimc+0.5])
   %axis equal
   %
   % Definición de las condiciones de borde
   %Se debe conocer el número de cada lado.
   %Por defecto tiene condiciones de borde Neumann nulas.
   %Lado inferior
   applyBoundaryCondition(o_ModelPDE,'edge',3,'u',0,'EquationIndex',2);
   %Lado izquierdo
   applyBoundaryCondition(o_ModelPDE,'edge',4,'u',0,'EquationIndex',1);
   %Lado derecho
   applyBoundaryCondition(o_ModelPDE,'edge',1,'g',[P,0]);
   %
   % Definición de los coeficientes de la ecuación diferencial
   %Tensor tangente constitutivo (deformación plana) - Notación de Voigt.
   %m_C  = E/(1+po)/(1-2*po)*[1-po,po,0;po,1-po,0;0,0,(1-2*po)/2];
   %Tensor tangente constitutivo (tensión plana) - Notación de Voigt.
   %m_C  = E/(1-po^2)*[1,po,0;po,1,0;0,0,(1-po)/2];
   %Tensión Plana
   %Se usa uno de los esquemas reducido para ingresar el tensor constitutivo C (2x2x2x2) que permite la
   %toolbox PDE .
   specifyCoefficients(o_ModelPDE,'m',0,'d',0,'c',E/(1-po^2)*[1;0;po;0;(1-po)/2;(1-po)/2;0;po;0;1],...
      'a',0,'f',[0;0]);
   %
   % Generación de la malla
   %Por defecto usa elementos triangulares lineales
   generateMesh(o_ModelPDE,'Hmax',hMaxEF);
   %generateMesh(o_ModelPDE,'Hmax',hMaxEF,'GeometricOrder','quadratic');
   %pdeplot(o_ModelPDE)
   %xlim([m_Origen(1)-0.5,m_Origen(1)+dimb+0.5])
   %ylim([m_Origen(2)-0.5,m_Origen(2)+dimc+0.5])
   %axis equal
   %
   % Solución del problema
   o_Resu = solvepde(o_ModelPDE);
   %pdeplot(o_ModelPDE,'xydata',o_Resu.NodalSolution,'mesh','on')
   %pdeplot(o_ModelPDE,'flowdata',o_Resu.NodalSolution)
   
end