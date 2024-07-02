%Resuelva los siguientes sistemas lineales con el m´etodo de Gauss-Seidel y
%analice lo que sucede en cada caso. Luego intente resolverlos
%mediante el m´etodo directo de eliminacion de Gauss.
%Es necesario aplicar alguna estrategia de pivoteo? Si lo fuera, justifique porqu´e

A1=[3 1 1; 1 3 -1; 3 1 -5]
b1=[5;3;-1]

A2=[3 1 1; 3 1 -5; 1 3 -1]
b2=[5;-1;3]

x0=zeros(3,1)
maxit=1000
tol=10^-4

[x1, r1, it1, t1] = GaussSeidel(A1, b1, x0, maxit, tol)

[x2, r2, it2, t2] = GaussSeidel(A2, b2, x0, maxit, tol)

[x3]=gauss(A1,b1)

[x4] = gauss(A2,b2)

[x5] = gauss_p(A1,b1)

[x6] = gauss_p(A2,b2)


%para la matriz A2, el metodo de gauss seidel converge, y para la eliminacion gausseana sin pivoteo tambien
%para que la matriz A2 nos devuelva un resultado, tuvimos que usarr eliminacion de gauss
%conn pivoteo parcial, ya que uno de sus pivots se hacian 0
