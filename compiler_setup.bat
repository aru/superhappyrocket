Setlocal EnableDelayedExpansion EnableExtensions

if not defined Configuration set Configuration=14 2015

set arch=x86

:: if "%platform%" EQU "x64" ( set arch=x86_amd64 )

if "%Configuration%"=="14 2015" (
	set SET_VS_ENV="C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"
)

if "%Configuration%"=="12 2013" (
	set SET_VS_ENV="C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"
)

:: Visual Studio detected
endlocal & call %SET_VS_ENV% %arch%
goto :eof
