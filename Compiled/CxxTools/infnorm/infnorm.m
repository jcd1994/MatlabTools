function c=infnorm(x)
%INFNORM

currentpath = cd;
cd(fileparts(mfilename('fullpath')));

build_infnorm;
c=infnorm(x);

cd(currentpath);

end

function build_infnorm

pEigen = what('Eigen');
pBlaze = what('blaze-3.2');
libincludes = {['-I"',pEigen(1).path,'"'],['-I"',pBlaze(1).path,'"']};
flags = '-O3 -mavx -mfma -DNDEBUG';
if isunix; flags = [flags,' -lgomp -fopenmp -std=c++14']; end

if ispc
    CFLAGS = ['CFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -pthread ',flags,'"'];
    COPTIMFLAGS = ['COPTIMFLAGS="-march=native -msse2 -msse3 -Ofast -flto -DNDEBUG ',flags,'"'];
    CXXFLAGS = ['CXXFLAGS="\$CXXFLAGS ',flags,'"'];
    LDOPTIMFLAGS = ['LDOPTIMFLAGS="-Ofast -flto ',flags,'"'];
elseif isunix
    CFLAGS = ['CFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -pthread -fopenmp ',flags,'"'];
    COPTIMFLAGS = ['COPTIMFLAGS="-march=native -msse2 -msse3 -Ofast -flto -DNDEBUG ',flags,'"'];
    CXXFLAGS = ['CXXFLAGS="\$CXXFLAGS -std=c++14"'];
    LDOPTIMFLAGS = ['LDOPTIMFLAGS="-Ofast -flto ',flags,'"'];
end

mex(CFLAGS,COPTIMFLAGS,CXXFLAGS,LDOPTIMFLAGS,libincludes{:},'infnorm.cpp');
%'OMP_NUM_THREADS=4',
end