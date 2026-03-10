%% Valores para evaluación numérica
aNum = 1;
pNum = 1;

%% Definición de funciones de tensión simbólicas
syms a p t r real
%assumptions(a)
assume(a>0)
assumeAlso(r>=a)
%assumeAlso(p>0)
% Tensiones en coordenadas cilíndricas
sr = p/2*(1-a^2/r^2)*(1+(1-3*a^2/r^2)*cos(2*t));
st = p/2*(1+a^2/r^2-(1+3*a^4/r^4)*cos(2*t));
srt = -p/2*(1-a^2/r^2)*(1+3*a^2/r^2)*sin(2*t);
% Derivadas de componente del tensor
dsr_dr = simplify(diff(sr,r));
dsr_dt = simplify(diff(sr,t));
dst_dr = simplify(diff(st,r));
dst_dt = simplify(diff(st,t));
dsrt_dr = simplify(diff(srt,r));
dsrt_dt = simplify(diff(srt,t));
%Derivadas de TauMax
dif_s = simplify(sr-st);
dif_ds_dr = simplify(dsr_dr-dst_dr);
dif_ds_dt = simplify(dsr_dt-dst_dt);
dTMaxdr = simplify(dif_s/4*dif_ds_dr+srt*dsrt_dr);
dTMaxdt = simplify(dif_s/4*dif_ds_dt+srt*dsrt_dt);

%% Puntos de máximo
%Dominio
assume(t>0&2*t<pi)
[soltDom,solrDom,paramtDom,condtDom] = solve([dTMaxdr==0,dTMaxdt==0],[t,r],'ReturnConditions',true);
nSolDom = length(soltDom);
%
%Lado horizontal
assume(t,'real')
[solrHor,paramrHor,condrHor] = solve([simplify(subs(dTMaxdr,t,0))==0,simplify(subs(dTMaxdt,t,0))==0],...
   r,'ReturnConditions',true);
%
%Lado vertical
assume(t,'real')
[solrVer,paramrVer,condrVer] = solve([simplify(subs(dTMaxdr,t,pi/2))==0,simplify(subs(dTMaxdt,t,pi/2))==0],...
   r,'ReturnConditions',true);
%
%En círculo r=a
assume(t>0&2*t<pi)
[soltCir,paramtCir,condtCir] = solve([simplify(subs(dTMaxdr,r,a))==0,simplify(subs(dTMaxdt,r,a))==0],...
   t,'ReturnConditions',true);
%
% Determinación de puntos de máximo válidos
%assume(condtDom)
%solParam = solve([t>=0,t<=pi/2],paramtDom);
%subs(soltDom,paramtDom,solParam)

%% Evaluación de valores máximos
TMax = simplify(sqrt((sr-st)^2/4+srt^2));
%Máximos en el dominio
%assume(condtDom)
TMaxDom = simplify(subs(TMax,{r,t},{solrDom,soltDom}));
%Máximos en theta=0
assume(condrHor)
TMaxHor = simplify(subs(TMax,{r,t},{solrHor,0}));
%Máximos en theta=pi/2
assume(condrVer)
TMaxVer = simplify(subs(TMax,{r,t},{solrVer,pi/2}));
%Máximos en r=a
assume(condtCir)
TMaxCir = simplify(subs(TMax,{r,t},{a,soltCir}));
%Máximo en r=a y theta=0
TMaxEsqInf = simplify(subs(TMax,{r,t},{a,0}));
%Máximo en r=a y theta=pi/2
TMaxEsqSup = simplify(subs(TMax,{r,t},{a,pi/2}));

%% Evaluación numérica de los valores del dominio
condtNumDom = subs(condtDom,{a,p},{aNum,pNum});
soltNumDom = subs(soltDom,{a,p},{aNum,pNum});
solrNumDom = subs(solrDom,{a,p},{aNum,pNum});
TMaxNumDom = subs(TMaxDom,{a,p},{aNum,pNum});
for iSolDom = 1:nSolDom
   if symvar(condtNumDom(iSolDom))=='x'
      assume(condtNumDom(iSolDom))
      solParamNum = solve([soltNumDom(iSolDom)>0,soltNumDom(iSolDom)<pi/2],paramtDom);
      %Coordenadas t máximas
      soltNumDom(iSolDom) = subs(soltNumDom(iSolDom),paramtDom,solParamNum);
      %Coordenadas r máximas
      solrNumDom(iSolDom) = subs(solrNumDom(iSolDom),paramtDom,solParamNum);
      %Soluciones máximas
      TMaxNumDom(iSolDom) = subs(TMaxNumDom(iSolDom),paramtDom,solParamNum);
   end
end
%Se asume que todos los resultados son válidos y no quedan ninguna expresión en forma simbólica.
%Coordenadas t máximas
m_tTMaxNumDom = double(soltNumDom);
%Coordenadas r máximas
m_rTMaxNumDom = double(solrNumDom);
%Soluciones máximas
m_TMaxNumDom = double(TMaxNumDom);

%% Evaluación numérica de los máximos en las fronteras
m_TMaxNumHor = double(subs(TMaxHor,{a,p},{aNum,pNum}));
m_rTMaxNumHor = double(subs(solrHor,{a,p},{aNum,pNum}));
m_tTMaxNumHor = zeros(size(m_rTMaxNumHor));
%
m_TMaxNumVer = double(subs(TMaxVer,{a,p},{aNum,pNum}));
m_rTMaxNumVer = double(subs(solrVer,{a,p},{aNum,pNum}));
m_tTMaxNumVer = pi/2*ones(size(m_rTMaxNumVer));
%
if ~isempty(paramtCir)
   assume(subs(condtCir,{a,p},{aNum,pNum}))
   solParam = solve([t>=0,t<=pi/2],paramtCir);
   m_tTMaxNumCir = double(subs(subs(soltCir,paramtCir,solParam),{a,p},{aNum,pNum}));
else
   m_tTMaxNumCir = double(subs(soltCir,{a,p},{aNum,pNum}));
end
m_TMaxNumCir = double(subs(TMaxCir,{a,p},{aNum,pNum}));
m_rTMaxNumCir = double(subs(a,{a,p},{aNum,pNum})*ones(size(m_TMaxNumCir)));
%
m_TMaxNumEsqInf = double(subs(TMaxEsqInf,{a,p},{aNum,pNum}));
m_rTMaxNumEsqInf = double(subs(a,{a,p},{aNum,pNum}));
m_tTMaxNumEsqInf = double(subs(0,{a,p},{aNum,pNum}));
%
m_TMaxNumEsqSup = double(subs(TMaxEsqSup,{a,p},{aNum,pNum}));
m_rTMaxNumEsqSup = double(subs(a,{a,p},{aNum,pNum}));
m_tTMaxNumEsqSup = double(subs(pi/2,{a,p},{aNum,pNum}));

%% Valores máximos
m_valTMax = [m_TMaxNumDom;m_TMaxNumHor;m_TMaxNumVer;m_TMaxNumCir;m_TMaxNumEsqInf;m_TMaxNumEsqSup];
m_valrTMax = [m_rTMaxNumDom;m_rTMaxNumHor;m_rTMaxNumVer;m_rTMaxNumCir;m_rTMaxNumEsqInf;m_rTMaxNumEsqSup];
m_valtTMax = [m_tTMaxNumDom;m_tTMaxNumHor;m_tTMaxNumVer;m_tTMaxNumCir;m_tTMaxNumEsqInf;m_tTMaxNumEsqSup];

%% Plot
figure(6)
hold on
scatter3(m_valrTMax.*cos(m_valtTMax),m_valrTMax.*sin(m_valtTMax),m_valTMax)
hold off