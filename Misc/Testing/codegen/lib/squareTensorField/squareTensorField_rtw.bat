@echo off

set MATLAB=C:\Users\Jonathan\Downloads\Mathworks Matlab R2016a\R2016a

cd .

if "%1"=="" (C:\Users\Jonathan\DOWNLO~1\MATHWO~2\R2016a\bin\win64\gmake -f squareTensorField_rtw.mk all) else (C:\Users\Jonathan\DOWNLO~1\MATHWO~2\R2016a\bin\win64\gmake -f squareTensorField_rtw.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
