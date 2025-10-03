clc; clear all;

##Ventana de Hamming
N = 100;
n = 0:N-1;

wH = 27/50 - 23/50 * cos(2*pi*n/N);100

figure();
stem(n,wH);

