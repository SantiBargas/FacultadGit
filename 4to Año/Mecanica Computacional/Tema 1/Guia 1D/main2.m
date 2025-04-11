close all; clear all;

######EJERCICIO 1###################
#################################
################################
##L1=0;
##L2=1;
##N=40;
##dx=(L2-L1)/N;
##xnode=L1:dx:L2;
##
##model.rho = 1;
##model.cp = 1;
##model.k=1;
##model.c=0; #No hay reaccion ni fuente interna
##model.G=100*(1-xnode)
##
##cb = [1 0 -1; # 1 indica que es de dirlichet, 0 es la temperatura fijada en x=0, -1 no hay valor adicional para dirlichet
##      2 0 -1]; #2 indica que es de Neumann, 0 no hay flujo de calor, -1 no hay valor adicional para neumann
####
##et = [0 0 0 0]; # Estado estacionario A)
##T_ini = 5.*xnode.*(2-xnode); #No se usa pero lo pasamos para q no de error
###[T] = difFinitas(xnode, model, cb, et,T_ini)
###[T] = difFinitasProfe(xnode, model, cb, et)
##[T] = difFinitasSofiesc(xnode,model,cb,et)
##
####% Mostrar el resultado:#INCISO A
##plot(xnode, T);
##xlabel('x');
##ylabel('Temperatura');
##title('Solución estacionaria');

##INCISO B)

##T_ini = 5.*xnode.*(2-xnode);
##k=0.01
##lambda=4;
##h=0.01
##dt=(lambda * dx.^2)/k
##
##et=[2,1000,0.01,dt] #2: esquema implícito , 1000 iteraciones max, tolerancia, deltaTiempo
##[T2] = difFinitasSofiesc(xnode, model, cb, et,T_ini);
##
##### lambda = k*deltaT / h^2 -> deltaT = (lambda * h^2)/k
#####k = K0 / cp
####
#########INCISO C)
####
##print('La temperatura en la mitad de la barra es : ');
##T(xnode==1/2)
##

######EJERCICIO 2###################
#################################
################################

###item A)
##L1=0;L2=1;
##N=100;
##dx=(L2-L1)/N;
##xnode=L1:dx:L2;
##cb=[1 10 -1; 1 50 -1];
##
##model.rho = 1;
##model.cp = 1;
##model.k=2;
##model.c=0; #No hay reaccion ni fuente interna
##model.G = 100*ones(length(xnode),1)
##T_ini=0;
##et = [0 0 0 0]; # estado estacionario o es lo mismo et = [0 -1 -1 -1];
##
##[T] = difFinitasSofiesc(xnode, model, cb, et,T_ini);
##hold on
##Tex = -25*(xnode.*xnode)+65*xnode+10; #T exacta


###item B)
##L1=0;L2=2;
##N=100;
##dx=(L2-L1)/N;
##xnode=L1:dx:L2;
##cb=[1 100 -1; 2 0 -1]; #Ponemos 2 pq es de neuman ya que hay q que es el flujo de calor(derivada)
##
##model.rho = 1;
##model.cp = 1;
##model.k=1;
##model.c=1;
##model.G = zeros(length(xnode),1)
##T_ini=0;
##et = [0 0 0 0]; # estado estacionario o es lo mismo et = [0 -1 -1 -1];
##[T] = difFinitas(xnode, model, cb, et,T_ini);
##Tex = (100*exp(-xnode).*(exp(2*xnode)+exp(4)))/(1+exp(4));
##

##
###item C)
##L1=1;L2=5;
##N=100;
##dx=(L2-L1)/N;
##xnode=L1:dx:L2;
##cb=[2 0 -1; 1 0 -1]; #Ponemos 2 = neuman 1=dirlichet
##
##model.rho = 1;
##model.cp = 1;
##model.k=1;
##model.c=0; #No hay reaccion ni fuente interna
##model.G = 100*((xnode-3).^2);
##T_ini=0;
##et = [0 0 0 0]; # estado estacionario o es lo mismo et = [0 -1 -1 -1];
##[T] = difFinitas(xnode, model, cb, et,T_ini);
##Tex = (-25*(xnode.^4)+300*(xnode.^3)-1350*(xnode.^2)+1906*xnode+2345)/3;
##

###item D)
##L1=0;L2=1;
##N=100;
##dx=(L2-L1)/N;
##xnode=L1:dx:L2;
##cb=[1 10 -1; 3 0.2 50]; #[neumann u(0)=10 -1 ; robin h=coef de conveccion fi=temp externa]
##
##model.rho = 1;
##model.cp = 1;
##model.k=1;
##model.c=1;
##model.G = 50*ones(length(xnode),1);
##T_ini=0;
##et = [0 0 0 0]; # estado estacionario o es lo mismo et = [0 -1 -1 -1];
##[T] = difFinitas(xnode, model, cb, et,T_ini);
##Tex = -36.6897*exp(-xnode)-3.3103*exp(xnode)+50;

#item E)
##L1=5;L2=10;
##N=100;
##dx=(L2-L1)/N;
##xnode=L1:dx:L2;
##cb=[3 2 100;1 50 0]; #[]
##
##model.rho = 1;
##model.cp = 1;
##model.k=2;
##model.c=0;
##model.G = (xnode).^3;
##T_ini=0;
###et = [0 0 0 0]; # estado estacionario o es lo mismo et = [0 -1 -1 -1];
##et = [2 500 1e-11 1]; #tipo de analisis, iteraciones, tolerancia,paso del tiempo
###[T] = difFinitas(xnode, model, cb, et,T_ini);
##[T] = difFinitasProfe(xnode, model, cb, et);
##
##Tex = -(xnode.^5)./40+(1225*xnode)./3-4600/3;


###item F)
## L1=0; L2=1;
## N = 100;
## dx = (L2-L1)/N;
## xnode = L1:dx:L2;
## cb = [1 0 -1;3 2 10];
## model.rho = 1; model.cp = 2;
## model.k = 2; model.c = 2;
## model.G = 75*ones(length(xnode),1);
## et = [0 0 0 0 ];
## Tex = (-5/4) .* exp(-(xnode+1)) .* (exp(xnode)-1) .* (11*exp(xnode)+11-30*exp(1));
## T = difFinitas(xnode, model, cb, et,0);

#####item G)
## L1=0; L2=1;
## N = 100;
## dx = (L2-L1)/N;
## xnode = L1:dx:L2;
## cb = [1 50 -1;2 5 -1];
## model.rho = 1; model.cp = 1;
## model.k = 2; model.c = -2;
## model.G = zeros(length(xnode),1);
## et = [0 0 0 0 ];
## Tex = 73.2433*sin(xnode)+50*cos(xnode);
## T = difFinitas(xnode, model, cb, et,0);
##
##
##
### Graficar ambas soluciones
##hold on;
##plot(xnode, Tex, 'r', 'LineWidth', 2);  # Solución exacta
####plot(xnode, T, 'b--', 'LineWidth', 2);  # Solución numérica
##xlabel('x');
##ylabel('Temperatura');
##legend('Diferencias Finitas','Solución exacta');
##title('Comparación de Soluciones Numérica y Exacta');
##grid on;

############################################
#######EJERCICIO 4##########################
############################################

##
##L1=0;
##L2=1;
##N=40;
##dx=(L2-L1)/N;
##xnode = L1:dx:L2;
##
##model.rho = 1;
##model.cp = 1;
##model.k = 1;
##model.c = 0;
##model.G = 0*xnode + 100; #Primer parte para t < 2
##
####T_ini = (-10 * xnode.^2 + 20*xnode)'; #para sofiesc poner apostrofe
##T_ini = (-10 * xnode.^2 + 20*xnode);
##cb=[1 0 -1 ; 2 0 -1];
##
##et=[2 100 0.0001 0.02]; #aca va hasta t<2
##
####[T] = difFinitasSofiesc(xnode, model, cb, et, T_ini);
##[T] = difFinitas(xnode, model, cb, et, T_ini);
##
##T(:,end) #'La temperatura al final de t=2 es: '
##
##T_ini = T(:,end); #Asignamos la temperatura final ahora a la inicial para t>2
##
##et = [2 100 0.0001 0.02]; # Estado estacionario
##model.G = 0*xnode; #segunda parte para t>2
####[T] = difFinitasSofiesc(xnode, model, cb, et, T_ini);
##[T] = difFinitas(xnode, model, cb, et, T_ini');
##plot(xnode,T)

##########################
##########################
##########################Ejercicio parcial

L1 = 0;
L2 = 1;
N=40;
dx=0.25;
xnode = L1:dx:L2

model.rho = 1;
model.cp = 1;
model.k = 2;
model.c = 0;
model.G = 100*(1-xnode);
et = [0 0 0 0 ];
cb=[1 10 -1; 2 1 -1];
[T] = difFinitas(xnode, model, cb, et, 0)

Te paso un pdf analizalo y resolveme este enunciado paso por paso detallado:
k * a^2T/ax^2 + G(x) = 0 para todo x [0 , 1] k = 2 G(x)=100*(1-x)
T=10|x=0   ;   -kaT/ax = 1 para x =1


Determinar el valor de la temperatura en cada nodo considerando una malla equispaciada con deltax = 0.25
Resolver el problema SIN USAR NODOS FICTICIOS manteniendo un error de 2do orden
en todas las aproximaciones utilizadas



