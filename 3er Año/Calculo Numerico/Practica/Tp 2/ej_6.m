%Para la siguiente matriz, encuentre la factorizacion de Doolittle (L1)U
%de la matriz A permutada, con intercambio de filas segun lo indica la
%estrategia de pivoteo parcial. Luego verifique que se cumple que P A = L1U.


A=[1 -2 3 0 ; 3 -6 9 3; 2 1 4 1 ;1 -2 2 -2]

[A1,L,U,P,Z,Z1] = doolittle_pivoteo(A)

  PA= P*A
  LU =L*U

