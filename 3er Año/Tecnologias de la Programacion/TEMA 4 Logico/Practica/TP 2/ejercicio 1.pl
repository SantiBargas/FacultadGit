factorial(0,1).
factorial(X,R):- X>=0 , Aux is X-1, factorial(Aux,R2), R is X * R2.