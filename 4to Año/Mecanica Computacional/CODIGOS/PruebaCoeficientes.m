

##FORMA LINEAL PARA UN TRIANGULO
p0 =[0,0];
p1=[1,0];
p2=[0,1];
[coeficientesTriangulo] = coeficientesFuncionesFormaTriangulo(p0,p1,p2)

##FORMA CUADRATICA PARA UN ELEMENTO 1D
p0 =[0];
p1=[1];
p2=[2];
[coeficientesBarra] = coeficientesFuncionesFormaCuadratica(p0,p1,p2)

##FORMA LINEAL PARA UN CUADRANGULO
p0 =[0,0];
p1=[1,0];
p2=[0,1];
p3 =[1,1];
[coeficientesCuadrangulo] = coeficientesFuncionesFormaCuadrangulos(p0,p1,p2,p3)
