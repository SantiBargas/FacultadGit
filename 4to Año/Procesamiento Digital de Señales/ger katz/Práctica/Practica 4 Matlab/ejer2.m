1;
%1
function [t,x]=senoidal(ti,tf,fm,fs,phi)
T=1/fm;
t=ti:T:tf-T;
x=sin(2*pi*fs*t+phi);
end

function [t,y]=ondaCuad(ti,tf,fm,fs,fi)
T=1/fm;
t=ti:T:tf-T;
x=mod(2*pi*fs*t+fi,2*pi);
y = -1 * (x>=pi) + 1 * (x<pi);
end

[t1,s1]=senoidal(0,1,100,2,0);
[t2,s2]=ondaCuad(0,1,100,2,0);
[t3,s3]=senoidal(0,1,100,4,0);

%a y b no son ortogonales
ProdPunto1 = dot(s1,s2)
%a y c son ortogonales
ProdPunto2 = dot(s1,s3)
%b y c son ortogonales
ProdPunto3 = dot(s2,s3)
##
##%2
##s1T=fft(s1);
##s2T=fft(s2);
##s3T=fft(s3);
##
##%a y b transformados no son ortogonales
##ProdPunto1T = dot(s1T,s2T);
##%a y c transformados son ortogonales
##ProdPunto2T = dot(s1T,s3T);
##%b y c transformados son ortogonales
##ProdPunto3T = dot(s2T,s3T);
##
##%3
##[t3R,s3R]=senoidal(0,1,100,3.5,0);
##ProdPunto3R = dot(s1,s3R);
##s3TR=fft(s3R);
##ProdPunto3TR = dot(s1T,s3TR);


