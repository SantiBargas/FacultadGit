#ejemplo
p0 = [0,1];
p1 = [1/2,2];
p2 = [1,0.1];

# FEM 1D:
[coeficientes] = coeficientesFuncionesFormaCuad(p0(1),p1(1),p2(1))

# FEM 2D:
[coef_lin] = coeficientesFuncionesFormaLin(p0,p1,p2)
