x0 = 0; xl = 1; numEle = 3;#num nodos, por lo tanto, numEle = numNodos + 1
xnode = linspace(x0, xl, numEle+1)
% Parametros
k = 2; c = 0;
G = 100;
qu = 0;
rho = 0;
Cp = 0;
% CB
DIR = [10 0 ; 50 1];
NEU = [];
ROB = [];
pmt.k = k;
pmt.c = c;
pmt.G = G;
pmt.ts = 2;
pmt.rho       = rho;
pmt.Cp        = Cp;

[xnLin, PhiLin] = FEM_1D(xnode,qu,pmt, DIR, NEU, ROB);
disp(PhiLin)

#-----------------------------------cuadrática-----------------------------------
x0 = 0; xl = 1; numEle = 2;
xnode = linspace(x0, xl, numEle+1)
% Parametros
k = 2; c = 0;
G = 100;
qu = 1;
rho = 0;
Cp = 0;
% CB
DIR = [10 0 ; 50 1];
NEU = [];
ROB = [];

pmt.k = k;
pmt.c = c;
pmt.G = G;
pmt.ts = 2;
pmt.rho       = rho;
pmt.Cp        = Cp;

[xnCuad, PhiCuad] = FEM_1D(xnode,qu,pmt, DIR, NEU, ROB);

xAn = linspace(x0,xl,50);
Tx = -25*xAn.*xAn + 65*xAn + 10;

% ===============================[ Grafica ]====================================
plot(xAn, Tx);
hold on;
grid on

plot(xnLin, PhiLin(:, end),'r'); % Muestra siempre la ultima columna
plot(xnCuad, PhiCuad(:, end),'g'); % Muestra siempre la ultima columna


title("2 elementos cuadráticos vs 3 elementos lineales");
legend("Analitica", "PhiLineal","PhiCuadrática",'location','northwest');

#Se observa que la cuadrática es mejor incluso teniendo menos elementos
