1;
%cantCol -> de a cuantos valores de muestra vamos a tomar
%cantAngulos=8 -> circulo en 8
angulos=0:pi/100:2*pi-pi/100;
frecFila=[697 770 852 941];
frecCol=[1209 1336 1477];
cantAngulos=length(angulos);
tm=1/11025;
t=0:tm:tm*5001-tm;
% i->frecuencias   j -> angulos
% En la tercer posicion guardo cada señal
for i=1:4
    for j=1:cantAngulos
        matriz(i,j,:)=sin(2*pi*frecFila(i)*t+angulos(j));
    end
end
for i=5:7
    for j=1:cantAngulos
        matriz(i,j,:)=sin(2*pi*frecCol(i-4)*t+angulos(j));
    end
end

archivo = fopen ( 'te.txt' , 'r' );
x = fscanf (archivo, '%e' );
muestra(1,:) = x(16000:21000);
muestra(2,:) = x(29000:34000);
muestra(3,:) = x(39000:44000);
muestra(4,:) = x(48000:53000);
muestra(5,:) = x(58000:63000);
muestra(6,:) = x(69000:74000);
muestra(7,:) = x(80000:85000);

for i=1:7 %Por cada frecuencia
    for k=1:7 %Por cada muestra
        for j=1:cantAngulos % Por cada fase
        %i -> muestras  j -> fase
        %Si no hago esto, el dot no anda (!= dimensiones??)
        matrAux(:) = matriz(i,j,:);
        muestrAux(:) = muestra(k,:);
        pPunto(i,k,j)=dot(muestrAux(:),matrAux(:));
        end
        pMax(i,k)=max(pPunto(i,k,:));
    end
end


telefono = ['1' '2' '3'; '4' '5' '6'; '7' '8' '9'; '*' '0' '#'];
for i=1:7 % por muestra
    [a(i),posFila(i)]=max(pMax(1:4,i));
    [a(i),posCol(i)]=max(pMax(5:7,i));

    telfinal(i) = telefono(posFila(i), posCol(i));
end

%HACER ESTO PARA CADA SENIAL fi
%[pPuntof1Final,posPuntof1Final]=max(pPuntof1);
%f1Final=matrizf1[posPuntof1Final,:];

%COMPARO LOS MAXIMOS POR FILA Y EN OTRO POR COLUMNA
%[maxFila]=max(pPuntof1Final,pPuntof2Final,pPuntof3Final,pPuntof4Final];
%[maxCol]=max(pPuntof5Final,pPuntof6Final,pPuntof7Final);



