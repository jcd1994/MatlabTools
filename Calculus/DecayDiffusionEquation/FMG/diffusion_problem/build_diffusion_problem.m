%==========================================================================
% periodic decay diffusion operator
%==========================================================================

% complex double version
mex CFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -pthread -fopenmp" ...
    COPTIMFLAGS="-march=native -msse2 -msse3 -Ofast -flto -DNDEBUG" ...
    LDOPTIMFLAGS="-Ofast -flto" ...
    -lgomp fmg_diffuse_cd.c

% %==========================================================================
% % Gauss-Siedel for periodic decay diffusion operator
% %==========================================================================
% 
% % complex double version
% mex CFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -pthread -fopenmp" ...
%     COPTIMFLAGS="-march=native -msse2 -msse3 -Ofast -flto -DNDEBUG" ...
%     LDOPTIMFLAGS="-Ofast -flto" ...
%     -lgomp fmg_relax_gs_diffuse_cd.c
