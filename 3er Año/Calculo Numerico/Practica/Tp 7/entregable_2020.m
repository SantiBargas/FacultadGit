
clc;
clear all;
f = @(t,x) ([-t.*x(2); t.*x(1)-t.*x(2)]);
t0=0;
tf=20;
h=0.05;
L=(tf-t0)/h;
y0=[-1;1];
[t,x] = euler_adelante_multi(f,0,20,y0,L);

##figure(1);
## plot(x(1,:), x(2,:), "linewidth", 2);
##

h=0.1;
Lk=(tf-t0)/h;
[tk,yk]=rk4(f, [t0,tf], y0, Lk);
%--------------------------------------Grafica de pos en t=3 y velocidad en t=3---------------------------

for i=1:length(tk)
  if(tk(i)==3)
    pos=i;
    break
    endif
  endfor
yk=yk';
figure(1);
plot(yk(1,:), yk(2,:), "linewidth", 2);
 hold on
 plot(yk(1,pos),yk(2,pos),'o-r');
 rap=norm(f(tk(pos),[yk(1,pos),yk(2,pos)]));


