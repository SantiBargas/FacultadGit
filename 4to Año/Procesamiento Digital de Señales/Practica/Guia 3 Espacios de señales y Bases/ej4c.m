1;

[toc, onda_cuadrada] = ondaCuad(0,2,100,5.5,0);


clComp3=zeros(10);
for i=1:10
    clComp3(i)=dot(onda_cuadrada,s(i,:));
end

bar(clComp3);
##plot(t,s);
##hold on;
##plot(t,onda_cuadrada);



