function [PHI_vec, Q_vec] = fdm2d_implicit(K,F,xnode,neighb,model,dt)
    % Pre-calculate matrix K coefficients for implicit time scheme
    I = eye(model.nnodes,model.nnodes);
    K = K + (model.rho*model.cp/dt)*I;
    
    PHI = model.PHI_n;
    PHI_n = model.PHI_n;
    PHI_vec = PHI;
    Q_vec = zeros(model.nnodes,2);
    
    for n = 1 : model.maxit
        F_n = F + (model.rho*model.cp/dt)*PHI_n;
        PHI = K\F_n;
        
        % Error relativo entre las últimas dos iteraciones
        err = norm(PHI-PHI_n,2)/norm(PHI,2);
        
        % actualizo phi(n+1) será phi(n) para el siguiente paso
        PHI_n = PHI;
        PHI_vec = [PHI_vec PHI];
        [Q] = fdm2d_flux(PHI,neighb,xnode,model.k);
        Q_vec = [Q_vec, Q];
        
       % para informar por consola el grado de avance del esquema temporal
        if model.verbose
            [model] = aux_ts_progress(model, n, err);
        end
        
        if err < model.tol
            if model.verbose
                disp('Método terminado por tolerancia de error.');
            end
            
            return;
        end
    end

    if model.verbose
        disp('Método terminado por límite de iteraciones.');
    end
end