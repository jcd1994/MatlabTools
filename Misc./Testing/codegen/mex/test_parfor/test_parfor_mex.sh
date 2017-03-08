MATLAB="/usr/local/MATLAB/R2015a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/coopar7/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for test_parfor" > test_parfor_mex.mki
echo "CC=$CC" >> test_parfor_mex.mki
echo "CFLAGS=$CFLAGS" >> test_parfor_mex.mki
echo "CLIBS=$CLIBS" >> test_parfor_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> test_parfor_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> test_parfor_mex.mki
echo "CXX=$CXX" >> test_parfor_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> test_parfor_mex.mki
echo "CXXLIBS=$CXXLIBS" >> test_parfor_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> test_parfor_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> test_parfor_mex.mki
echo "LD=$LD" >> test_parfor_mex.mki
echo "LDFLAGS=$LDFLAGS" >> test_parfor_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> test_parfor_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> test_parfor_mex.mki
echo "Arch=$Arch" >> test_parfor_mex.mki
echo OMPFLAGS=-fopenmp -DOMPLIBNAME='"\"/usr/local/MATLAB/R2015a/sys/os/glnxa64/libiomp5.so\""' >> test_parfor_mex.mki
echo OMPLINKFLAGS=-fopenmp -L/usr/local/MATLAB/R2015a/sys/os/glnxa64 -liomp5 >> test_parfor_mex.mki
echo "EMC_COMPILER=gcc" >> test_parfor_mex.mki
echo "EMC_CONFIG=optim" >> test_parfor_mex.mki
"/usr/local/MATLAB/R2015a/bin/glnxa64/gmake" -B -f test_parfor_mex.mk
