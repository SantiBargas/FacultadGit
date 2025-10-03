N=100;
df=2*pi/N;
D=zeros(N);
p=fix(1/df)+1;
D(1:p)=1;
D=[D(1:N/2+1) conj(D(N/2:-1:2))];
size(D);

resp=real(ifft(D));
ideal=sincro(1,1/(2*pi),0,N-1);
subplot(3,1,1)

