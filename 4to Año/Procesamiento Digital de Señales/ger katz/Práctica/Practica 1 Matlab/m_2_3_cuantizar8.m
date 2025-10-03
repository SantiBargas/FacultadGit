%2-3)
function xCuant8=m_2_3_cuantizar8(x,N,t)
xMin=min(x);
x=x-xMin;
H=abs(xMin)*2/N;
xCuant8 = 0 .* (x<0) + (H.*fix(x./H)) .* ((x>=0) & (x<(N-1)*H)) + ((N-1)*H) .* (x>=(N-1)*H);
xCuant8=xCuant8+xMin;
plot(t,xCuant8);
end