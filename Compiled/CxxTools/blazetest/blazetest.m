function blazetest
%BLAZETEST

currentpath = cd;
cd(fileparts(mfilename('fullpath')));

build_blazetest;
blazetest();

cd(currentpath);

end

function build_blazetest

p = what('blaze-3.2');
libincludes = {['-I"',p(1).path,'"']};
flags = '-O3 -mavx -mfma -DNDEBUG -openmp';

CFLAGS = ['CFLAGS="',flags,'"'];
COPTIMFLAGS = ['COPTIMFLAGS="',flags,'"'];
LDOPTIMFLAGS = ['LDOPTIMFLAGS="',flags,'"'];

mex(CFLAGS,COPTIMFLAGS,LDOPTIMFLAGS,libincludes{:},'blazetest.cpp');

end