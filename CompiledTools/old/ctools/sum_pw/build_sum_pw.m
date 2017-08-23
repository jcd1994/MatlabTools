x_CURRENT_PATH_x = cd;
[x_PATHSTR_x,~,~] = fileparts(which(mfilename));
cd(x_PATHSTR_x);

%==========================================================================
% Summing by Pairwise summation (treats ND arrays as 1D)
%==========================================================================

% Optimizations on
mex CFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -lpthread -fopenmp" ...
    COPTIMFLAGS="-march=native -msse2 -msse3 -Ofast -flto -DNDEBUG" ...
    LDOPTIMFLAGS="-Ofast -flto" ...
    -lgomp sum_pw.c

cd(x_CURRENT_PATH_x);
clear x_CURRENT_PATH_x x_PATHSTR_x