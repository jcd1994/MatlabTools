@echo off
set MATLAB=C:\Users\Jonathan\DOWNLO~1\MATHWO~2\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Users\Jonathan\Downloads\Mathworks Matlab R2016a\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=squareTensorField_mex
set MEX_NAME=squareTensorField_mex
set MEX_EXT=.mexw64
call "C:\Users\Jonathan\DOWNLO~1\MATHWO~2\R2016a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for squareTensorField > squareTensorField_mex.mki
echo COMPILER=%COMPILER%>> squareTensorField_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> squareTensorField_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> squareTensorField_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> squareTensorField_mex.mki
echo LINKER=%LINKER%>> squareTensorField_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> squareTensorField_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> squareTensorField_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> squareTensorField_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> squareTensorField_mex.mki
echo BORLAND=%BORLAND%>> squareTensorField_mex.mki
echo OMPFLAGS= >> squareTensorField_mex.mki
echo OMPLINKFLAGS= >> squareTensorField_mex.mki
echo EMC_COMPILER=lcc64>> squareTensorField_mex.mki
echo EMC_CONFIG=optim>> squareTensorField_mex.mki
"C:\Users\Jonathan\Downloads\Mathworks Matlab R2016a\R2016a\bin\win64\gmake" -B -f squareTensorField_mex.mk
