function [ui Ri] = Barra_2D(xnode, icone, F_ex, ke, nudo_empot)

    % Cantidad de nudos
    n_nudos = length(unique(icone(:, [1 2])));

    % Las matrices con doble del tamanio
    Klm = sparse(zeros(2*n_nudos));
    Fl = sparse(zeros(2*n_nudos, 1));

    for i = 1:size(F_ex, 1)
      nudo = F_ex(i, 1);
      % siendo ui = 2*nudo-1, vi = 2*nudo
      Fl([2*nudo-1, 2*nudo]) = F_ex(i, [2 3]);
    endfor

    for i = 1:size(icone, 1)
        % los pares de nudos de cada barra
        nudos = icone(i, [1 2]);

        % cos(ang) = x2-x1/L, sin(ang) = y2-y1/L
        L = norm(xnode(nudos(2), :) - xnode(nudos(1), :));
        dx = xnode(nudos(2), 1) - xnode(nudos(1), 1);
        dy = xnode(nudos(2), 2) - xnode(nudos(1), 2);
        % Las funciones trigonometricas
        C = dx/L; S = dy/L;
##        rad = (icone(i, end)*pi)/180;
##        C = cos(rad); S = sin(rad);

        % Construir la matriz k'
        sK = [C*C C*S; C*S S*S];
        disp(cstrcat("Barra ", num2str(i)));

        K = [sK -sK; -sK sK];

        % Si el par de nudos = [2 5], sus correspondientes indices en
        % la matriz global es idx_uv = [3 4 , 9 10]
        ui = 2*nudos - 1;
        vi = 2*nudos;

        idx_uv = [ui(1) vi(1) ui(2) vi(2)];
        Klm(idx_uv, idx_uv) += ke(i)*K;
    endfor

##    % Se considera solo aquellos no empotrados
##    uv_empot = sort([2*nudo_empot-1, 2*nudo_empot]);
##    sub_sist = setdiff(1: 2*n_nudos, uv_empot);

    sub_sist = zeros(1, 2*n_nudos);

    full(Klm)

    % uv empotrados
    for i = 1:size(nudo_empot, 1)
        idx = nudo_empot(i, 1);
        sub_sist([2*idx-1, 2*idx]) = nudo_empot(i, [2, 3]);
    endfor

    sub_sist = !sub_sist;

    K_reduc = Klm(sub_sist, sub_sist);
    F_reduc = Fl(sub_sist);
    ui_reduc = K_reduc\F_reduc;

    % Reconstruir el vector de desplazamiento con los empotrados
    ui = sparse(zeros(2*n_nudos, 1));

    ui(sub_sist) = ui_reduc;
    Ri = Klm * ui;


endfunction

