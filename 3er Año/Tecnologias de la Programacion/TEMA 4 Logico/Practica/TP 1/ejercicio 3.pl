%3. Dado la lista de platos de un restaurante confeccionar los predicados necesarios para declarar los
%menús, y luego realizar las siguientes consultas:
%a. Listado completo de posibles menús que se ofrecen.
%b. ¿En qué menú está incluido el postre 'Dulce de batata'?
%c. ¿En qué menú está incluido el plato principal 'Locro'?
%d. ¿Hay algún menú que contenga como plato principal 'Pato a la naranja'?
%e. ¿Hay algún menú que contenga 'Locro' como entrada?
%Menús existentes:

 menu('Bombones de jamón', 'Locro', 'Dulce de batata').
 menu('Bombones de jamón', 'Locro', 'Alfajor norteño').
 menu('Tarta de Atún', 'Atados de repollo', 'Dulce de batata').
menu( 'Tarta de Atún', 'Pollo romano con hierbas y vino', 'Flan').
 menu('Volovanes de atún', 'Matambre con espinacas y parmesano', 'Torta moka').
 menu('Buñuelos de bacalao', 'Pollo romano con hierbas y vino', 'Alfajor norteño').

%a =menu(X,Y,Z).
%b = menu(X,Y,'Dulce de batata').
%c = menu(X,'Locro',Z).
%d = menu(X,'Pato a la naranja',Z).
%e =menu('Locro',Y,Z).