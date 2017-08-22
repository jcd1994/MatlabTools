x_CURRENT_PATH_x = cd;
[x_PATHSTR_x,~,~] = fileparts(which(mfilename));
cd(x_PATHSTR_x);

%==========================================================================
% infinity norm of array (treats ND arrays as 1D)
%==========================================================================

mex CFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -pthread -fopenmp" ...
    COPTIMFLAGS="-march=native -msse2 -msse3 -Ofast -flto -DNDEBUG" ...
    LDOPTIMFLAGS="-Ofast -flto" ...
    -lgomp infnorm.c

cd(x_CURRENT_PATH_x);
clear x_CURRENT_PATH_x x_PATHSTR_x