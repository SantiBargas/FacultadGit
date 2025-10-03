a = 0.5;
N = 20; % 0 <= n <= 19
n = 0:N-1;
% vectorial
hA = sin(8*n);
hB = a.^(n);
x = (n==0) - a * ((n-1)==0);
w = convLineal(x,hA);
y = convLineal(w,hB);

w1 = convLineal(x,hB);
y2 = convLineal(w1,hA);

%Obtenemos el mismo resultado, se ve que la convulucion lineal es
%conmutativa