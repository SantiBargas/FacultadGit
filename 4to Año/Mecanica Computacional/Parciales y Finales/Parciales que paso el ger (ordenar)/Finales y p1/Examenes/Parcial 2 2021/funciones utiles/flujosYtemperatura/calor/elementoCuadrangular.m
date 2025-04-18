%ptos de elemento
pkg load symbolic
ptos = [0 0; 2.2 0.5; 2 1; 0 1];
[coeficientes N1 N2 N3 N4]= calcularFuncionesdeFormaCuad(ptos);
p = [0.5 0.5]; T = [100 70 30 50]; k = 1;

phi_p = T(1)*N1(p(1),p(2))+T(2)*N2(p(1),p(2))+...
    T(3)*N3(p(1),p(2))+T(4)*N4(p(1),p(2));

syms x y;
q_p = [
    -k.*[
         subs(diff(N1,x),{x y},{p(1) p(2)}),...
         subs(diff(N2,x),{x y},{p(1) p(2)}),...
         subs(diff(N3,x),{x y},{p(1) p(2)}),...
         subs(diff(N4,x),{x y},{p(1) p(2)})
        ]*T';
    -k.*[
         subs(diff(N1,y),{x y},{p(1) p(2)}),...
         subs(diff(N2,y),{x y},{p(1) p(2)}),...
         subs(diff(N3,y),{x y},{p(1) p(2)}),...
         subs(diff(N4,y),{x y},{p(1) p(2)})
        ]*T';
];
