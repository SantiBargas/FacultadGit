fm=2000;
fc=500;

%Orden 2
[num1,den1]=butt(2,500,2000);
[h1,w1]=freqz(num1,den1);

%Orden 4
[num1,den1]=butt(4,500,2000);
[h2,w2]=freqz(num1,den1);

%Orden 6
[num1,den1]=butt(6,500,2000);
[h3,w3]=freqz(num1,den1);

plot(fm*w1/(2*pi),abs(h1).^2);
hold on
plot(fm*w2/(2*pi),abs(h2).^2);
plot(fm*w3/(2*pi),abs(h3).^2);
legend('Orden 2' , 'Orden 4', 'Orden 6');

