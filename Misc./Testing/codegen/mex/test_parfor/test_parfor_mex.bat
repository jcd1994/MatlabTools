@echo off
set MATLAB=C:\Users\Jonathan\DOWNLO~1\MATHWO~2\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Users\Jonathan\Downloads\Mathworks Matlab R2016a\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=test_parfor_mex
set MEX_NAME=test_parfor_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for test_parfor > test_parfor_mex.mki
echo COMPILER=%COMPILER%>> test_parfor_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> test_parfor_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> test_parfor_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> test_parfor_mex.mki
echo LINKER=%LINKER%>> test_parfor_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> test_parfor_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> test_parfor_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> test_parfor_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> test_parfor_mex.mki
echo BORLAND=%BORLAND%>> test_parfor_mex.mki
echo OMPFLAGS= >> test_parfor_mex.mki
echo OMPLINKFLAGS= >> test_parfor_mex.mki
echo EMC_COMPILER=mingw64>> test_parfor_mex.mki
echo EMC_CONFIG=optim>> test_parfor_mex.mki
"C:\Users\Jonathan\Downloads\Mathworks Matlab R2016a\R2016a\bin\win64\gmake" -B -f test_parfor_mex.mk
