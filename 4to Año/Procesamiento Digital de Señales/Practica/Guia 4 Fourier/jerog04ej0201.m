t_ini=0;
t_fin=1;
T_m=100;
t=t_ini:1/T_m:t_fin-1/T_m;

s_a = sin(2*pi*2*t);
x=mod(2*pi*4*t,2*pi);
s_b(x>=pi)=-1;
s_b(x<pi)=1;
s_c = sin(2*pi*4*t);

stem(t,s_a);
  hold on;
  stem(t,s_b,"r");
  stem(t,s_c,"g");

## 1.
  ## Dos señales son ortogonales si su producto interno es cero
    % >> sum(s_a.*s_b)
    % ans = 3.7748e-15 approx 0 -> ES ORTOGONAL.

    % >> sum(s_a.*s_c)
    % ans = -8.0144e-16 approx 0 -> ES ORTOGONAL.

    % >> sum(s_b.*s_c)
    % ans = 63.578 -> NO ES ORTOGONAL.

## 2.
  s_a_Tf = fft(s_a);
  s_b_Tf = fft(s_b);
  s_c_Tf = fft(s_c);

  figure(2);
    stem(0:length(s_a)-1,abs(s_a_Tf));
    hold on;
    stem(0:length(s_b)-1,abs(s_b_Tf),"r");
    stem(0:length(s_c)-1,abs(s_c_Tf),"g");

  % >> abs(sum(s_a_Tf.*s_b_Tf))
  % ans = 5.4804e-13 approx 0 -> ES ORTOGONAL.

  % >> abs(sum(s_a_Tf.*s_c_Tf))
  % ans = 7.7221e-14 approx 0 -> ES ORTOGONAL.

  % >> abs(sum(s_b_Tf.*s_c_Tf))
  % ans = 6357.8 -> NO ES ORTOGONAL.

## 3.
  s_c = sin(2*pi*3.5*t);

  figure(3);
    stem(t,s_a);
    hold on;
    stem(t,s_c,"g");

   s_c_Tf = fft(s_c);

   figure(4);
    stem(0:length(s_a)-1,abs(s_a_Tf));
    hold on;
    stem(0:length(s_c)-1,abs(s_c_Tf),"g");

    % >> sum(s_a.*s_c)
    % ans = -6.4879e-15 approx 0 -> ES ORTOGONAL.

    % >> abs(sum(s_a_Tf.*s_c_Tf))
    % ans = 2.5854e-13 approx 0 -> ES ORTOGONAL.
