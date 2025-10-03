function[t,x]=ej3(fm,fs,A,fi)

    Tm = 1 / fm;
    t = 0:Tm:0.1 - Tm;
    x = A * sin(2 * pi * fs * t + fi);


     stem(t,x,'b')
 end

#  [t,x]=ej3(790,19.268,3,-0.7264);


#La amplitud es 3 se ve facil en el grafico

#Cantidad total de muestras en la grafica Nt=80(cantidad total de muestras)  Nc=41 (cantidad de muestras en 1 ciclo)
#Tiempo total = 0.1 seg

#Tm = TiempoTotal / (Nt)   #Periodo de muestreo
#Tm = 0.1 / (80) -> Tm = 1/790

#fm= 1/Tm -> fm = 1 / (1/800) -> fm=800  #frecuencia de muestreo número de veces que se toma una muestra de una señal analógica por unidad de tiempo

#Para la frecuencia nos fijamos la cantidad de muestras en 1 ciclo
#o regla de 3 para 2 ciclos - 0.1 seg
#                   x ciclos - 1 seg
#fs = fm/Nc  -> fs=800/41 -> fs=19.5   #frecuencia senoidal

## Para hallar fi nos fijamos en que  #T1 retardo temporal en segundos, lo encontramos el primer cruce por 0 de la sinusoidal
## y reemplazamos en la ecuacion
#  t1=0.006;
#  fi=-2*pi*fs*t1;
#  fi = -0.7264



##Tm = 1.2658e-03
##fm = 790
##fs = 19.268



