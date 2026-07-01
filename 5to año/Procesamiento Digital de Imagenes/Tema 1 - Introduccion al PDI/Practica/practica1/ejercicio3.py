import numpy as np
import cv2 as cv
import matplotlib.pyplot as plt

botellas = cv.imread(r"C:\Users\santi\Desktop\Procesamiento Digital de Imagenes\imagenes\botellas.tif ", cv.IMREAD_GRAYSCALE)
plt.figure()
plt.imshow(botellas,cmap='gray')
plt.plot([0,botellas.shape[1]],[(botellas.shape[0] / 2),(botellas.shape[0] / 2)])
plt.figure()
plt.plot(botellas[int((botellas.shape[0] / 2)),:])


##IDENTIFICAR POSICIONES DE LAS BOTELLLAS (POSICIONES PICOS)
linea = botellas[int((botellas.shape[0] / 2)),:]
picos = [] #Arreglo que tiene col donde empieza y termina cada botella
flag = True

for i in range(len(linea)):
    if flag and linea[i] != 0:
        picos.append(i)
        flag = False
    elif not flag and linea[i] == 0:
        picos.append(i)
        flag = True
picos = np.append(picos, botellas.shape[1])

#Calculo altura de botella
linea = botellas[: , int((picos[1]-picos[0])/2)]
altura = []
for i in range(len(linea)):
    if linea[i] != 0:
        altura.append(i+1)
        break
altura.append(botellas.shape[0])

llenado = []
for i in range(0,10,2):
    col = picos[i]+ int((picos[i+1]-picos[i])/2)
    linea = botellas[altura[0]: , col]
    for i in range(len(linea)):
        if linea[i] < 200 and linea[i] > 50:
            llenado.append(i)
            break

alt = (altura[1] - altura[0])
for i in range(5):
    print(f"La Botella {i+1} tiene un llenado de { (alt - llenado[i]) / alt :.2f}")
plt.show()