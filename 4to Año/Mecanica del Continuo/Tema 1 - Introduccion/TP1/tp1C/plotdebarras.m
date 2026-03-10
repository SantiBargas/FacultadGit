%PLOT DE BARRAS:
%ANIMACION:
for i= 1:length(y)
  pause(0.01)
  clf;
  %PLOT DE BARRAS:
  set(0, 'defaultfigurevisible', 'off');
  axis([-2 10 -2 10])
  hold on; grid on;
  title('Movimiento del reticulado')
  xlabel('Posicion(x)');
  ylabel('Posicion(y)');

  for j = 1:length(conec)
    n1 = conec(j,1);
    n2 = conec(j,2);
    plot([y(i,n1*2 - 1) , y(i,n2*2-1)] ,[y(i,n1*2) , y(i,n2*2)] , "k");
  endfor

  filename=sprintf('gif/%05d,png' , i);
  print(filename);

 endfor

