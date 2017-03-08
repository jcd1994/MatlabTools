MATLAB="/usr/local/MATLAB/R2015a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/coopar7/.matlab/R2015a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for refineGrid3D_conv" > refineGrid3D_conv_mex.mki
echo "CC=$CC" >> refineGrid3D_conv_mex.mki
echo "CFLAGS=$CFLAGS" >> refineGrid3D_conv_mex.mki
echo "CLIBS=$CLIBS" >> refineGrid3D_conv_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> refineGrid3D_conv_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> refineGrid3D_conv_mex.mki
echo "CXX=$CXX" >> refineGrid3D_conv_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> refineGrid3D_conv_mex.mki
echo "CXXLIBS=$CXXLIBS" >> refineGrid3D_conv_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> refineGrid3D_conv_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> refineGrid3D_conv_mex.mki
echo "LD=$LD" >> refineGrid3D_conv_mex.mki
echo "LDFLAGS=$LDFLAGS" >> refineGrid3D_conv_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> refineGrid3D_conv_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> refineGrid3D_conv_mex.mki
echo "Arch=$Arch" >> refineGrid3D_conv_mex.mki
echo OMPFLAGS= >> refineGrid3D_conv_mex.mki
echo OMPLINKFLAGS= >> refineGrid3D_conv_mex.mki
echo "EMC_COMPILER=gcc" >> refineGrid3D_conv_mex.mki
echo "EMC_CONFIG=optim" >> refineGrid3D_conv_mex.mki
"/usr/local/MATLAB/R2015a/bin/glnxa64/gmake" -B -f refineGrid3D_conv_mex.mk
