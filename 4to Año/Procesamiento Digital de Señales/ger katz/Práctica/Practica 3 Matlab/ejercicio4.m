1;
t=0:1/100:2;
s=zeros(10,length(t));
for i=1:10
    s(i,:)=sin(2*pi*i*t);
end

cl=0;
for i=1:10
    cl=cl+s(i,:)*i;
end

clComp=zeros(10);
for i=1:10
    clComp(i)=dot(cl,s(i,:))
end
bar(clComp)



