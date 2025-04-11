L1=0;
L2=4;
N=40;
dx=(L2-L1)/N;
xnode=L1:dx:L2;

model.rho = 1;
model.cp = 1;
model.k=1/10;
model.c=10;
model.G = 100*ones(length(xnode),1);

cb = [0 0 0; # 1 indica que es de dirlichet, 0 es la temperatura fijada en x=0, -1 no hay valor adicional para dirlichet
      0 0 0]; #2 indica que es de Neumann, 0 no hay flujo de calor, -1 no hay valor adicional para neumann
##
et = [1 1000 1e-05 0.05]; #tipo de analisis, iteraciones, tolerancia,paso del tiempo

T_ini = sin(pi*xnode);
[T] = difFinitas(xnode, model, cb, et,T_ini);


##% Mostrar el resultado:
##plot(xnode, T);
##xlabel('x');
##ylabel('Temperatura');
##title('Solución estacionaria');


#[T] = difFinitasProfe(xnode, model, cb, et)
##[T] = difFinitasSofiesc(xnode,model,cb,et,T_ini)
