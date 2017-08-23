function c=infnorm(x)
%INFNORM 

build_infnorm;
c=infnorm(x);

end

function build_infnorm

p = what('Eigen');
libincludes = {['-I"',p(1).path,'"']};
flags = '-O3 -mavx -mfma -DNDEBUG -std=c++14';

% CFLAGS = 'CFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -pthread -fopenmp"';
% COPTIMFLAGS = 'COPTIMFLAGS="-march=native -msse2 -msse3 -Ofast -flto -DNDEBUG"';
% LDOPTIMFLAGS = 'LDOPTIMFLAGS="-Ofast -flto"';

CFLAGS = ['CFLAGS="',flags,'"'];
COPTIMFLAGS = ['CFLAGS="',flags,'"'];
LDOPTIMFLAGS = ['CFLAGS="',flags,'"'];

mex(CFLAGS,COPTIMFLAGS,LDOPTIMFLAGS,libincludes{:},'infnorm.cpp');

end