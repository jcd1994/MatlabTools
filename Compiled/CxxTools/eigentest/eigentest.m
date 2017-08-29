function eigentest
%EIGENTEST 

currentpath = cd;
cd(fileparts(mfilename('fullpath')));

build_eigentest;
eigentest();

cd(currentpath);

end

function build_eigentest

p = what('Eigen');
libincludes = {['-I"',p(1).path,'"']};
flags = '-O3 -mavx -mfma -DNDEBUG';

% CFLAGS = 'CFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -pthread -fopenmp"';
% COPTIMFLAGS = 'COPTIMFLAGS="-march=native -msse2 -msse3 -Ofast -flto -DNDEBUG"';
% LDOPTIMFLAGS = 'LDOPTIMFLAGS="-Ofast -flto"';

CFLAGS = ['CFLAGS="',flags,'"'];
COPTIMFLAGS = ['COPTIMFLAGS="',flags,'"'];
LDOPTIMFLAGS = ['LDOPTIMFLAGS="',flags,'"'];

mex(CFLAGS,COPTIMFLAGS,LDOPTIMFLAGS,libincludes{:},'infnorm.cpp');

end