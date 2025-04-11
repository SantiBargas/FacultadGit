function [] = fem2d_pstr_post_process(mode,graph,scale)
%% mode --->  visualization mode:
%             [0] 2D - With mesh (default)
%             [1] 2D - Without mesh
%% graph ---> graph selection: 
%             [0] Initial state vs. displacement
%             [1] Von Misses (scalar)
%             [2] Reactions (vectorial)


    load('results.mat');
    
    U = scale * U; %#ok<*NODEF>
    reaction = scale * reaction;
    Ten_VM = scale * Ten_VM;
    
    fem2d_pstr_graph_mesh(U,reaction,Ten_VM,xnode,icone,mode,graph);
    
    disp('---------------------------------------------------------------');
    disp('Finalizado el post-procesamiento.');
end