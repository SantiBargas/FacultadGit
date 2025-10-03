##producto_interno1 = sum(y1 .* conj(y2))
##producto_interno2 = dot(y1, y2)
% Calcular el producto interno
##norma_y1 = sqrt(sum(y1.^2));
##norma_y2 = sqrt(sum(y2.^2));
##producto_interno3 = norma_y1 * norma_y2

[t1,y1]=ej1_a_senoidal(0,1,100,5,10,0); #amplitud 10
[t2,y2]=ej1_a_senoidal(0,1,100,5,10,0); #amplitud 10
producto_interno1 = sum(y1 .* conj(y2))  %conjugado cambiarle el signo a la parte imaginaria
figure
plot(t1,y1);
hold on;
plot(t1,y2);

[t1,y1]=ej1_a_senoidal(0,1,1000,5,10,pi/2); #amplitud 10 con fase pi
[t2,y2]=ej1_a_senoidal(0,1,1000,5,10,0); #amplitud 10
producto_interno1 = sum(y1 .* conj(y2))
figure
plot(t1,y1);
hold on;
plot(t1,y2);

##[t,y]=ej1_a_senoidal(tini,tfin,fm,fs,A,fi)


##Si dos señales son idénticas, su producto interno será máximo.

#EN EL PRODUCTO INTERNO INTERFIERE NO SOLO LA FRECUENCIA SINO TAMBIEN LA FASE
#SI LA FASE CAMBIA, EL PRODUCTO INTERNO TAMBIEN



##Amplitud (A): Aumentar o disminuir la amplitud de una señal afectará directamente
##al valor absoluto del producto interno. Si se duplica la amplitud de ambas señales,
##el producto interno se duplicará. Si una señal tiene una amplitud mayor que la otra, el producto interno
##será proporcional a la amplitud de la señal más pequeña.
##Frecuencia (f): Cambiar la frecuencia de las señales no tendrá un efecto directo en el producto interno.
##Sin embargo, si las frecuencias son muy diferentes, las señales pueden parecer muy distintas,
##o que se reflejará en un producto interno más bajo.
##Fase (𝜙): La fase determina el desplazamiento horizontal de la señal. Si las fases son iguales,
##el producto interno será máximo, lo que indica que las señales están completamente alineadas en el tiempo.
##Si las fases son diferentes, el producto interno será menor
##y dependerá de la similitud de las formas de onda en diferentes puntos temporales.
