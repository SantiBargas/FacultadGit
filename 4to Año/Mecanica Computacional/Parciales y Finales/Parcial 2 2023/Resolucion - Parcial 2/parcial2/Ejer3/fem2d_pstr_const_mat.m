function [D] = fem2d_pstr_const_mat(model)
    young = model.young;
    poiss = model.poiss;
    pstrs = model.pstrs;
   if (pstrs==1) %  Plane Sress
       aux1 = young/(1-poiss^2);
       aux2 = poiss*aux1;
       aux3 = (1-poiss)*aux1/2;
   else %  Plane Strain
       aux1 = young*(1-poiss)/(1+poiss)/(1-2*poiss);
       aux2 = aux1*poiss/(1-poiss);
       aux3 = young/2/(1+poiss);
   end
   D = [aux1, aux2,  0;
          aux2,  aux1,  0;
          0,     0,  aux3];
end