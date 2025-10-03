function [y_1,y_2] = ej0301(a,N)
  n=0:N-1;
  h_A = sin(8*n);
  h_B = a.^n;

  x(n==0) = 1 - 0;
  x(n==1) = 0 - a*1;

  w_1 = conv(x,h_A);
  y_1 = conv(w_1,h_B);

  w_2 = conv(x,h_B);
  y_2 = conv(w_2,h_A);

  figure(1);
  subplot (2, 3, 1);
    stem(h_A);
    title("h_A");
  subplot (2, 3, 4);
    stem(h_B);
    title("h_B");
  subplot (2, 3, 2);
    stem(1:length(w_1),w_1);
    title("w_1");
  subplot (2, 3, 5);
    stem(1:length(y_1),y_1);
    title("y_1");

  subplot (2, 3, 3);
    stem(1:length(w_2),w_2);
    title("w_2");
  subplot (2, 3, 6);
    stem(1:length(y_2),y_2);
    title("y_2");
endfunction

