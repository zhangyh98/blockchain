::git fetch --all
::git reset --hard origin/release/1.0.0.0
::git reset --hard origin/develop

set ORIGINAL_DATE=%date% 

set YEAR=%date:~0,4%
set MONTH=%date:~5,2%
set DAY=%date:~8,2%
set CURRENT_DATE=%YEAR%-%MONTH%-%DAY%


set HOUR=%time:~0,2%
set MINUTE=%time:~3,2%
set SECOND=%time:~6,2%


set TMP_HOUR=%time:~1,1%
set NINE=9
set ZERO=0

set CURRENT_DATE_TIME_STAMP=%YEAR%_%MONTH%%DAY%_%HOUR%%MINUTE%
echo %CURRENT_DATE_TIME_STAMP%

cd ../../
	

cd build/win32
rd /s /Q ".\pack\"
del output.log

"D:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\IDE\devenv.exe" /Clean "Release|Win32" Chain.vs12.sln

"D:\Program Files (x86)\Microsoft Visual Studio 12.0\Common7\IDE\devenv.exe" Chain.vs12.sln  /rebuild RELEASE /out output.log

mkdir pack
cd pack
mkdir bubichain
mkdir bubichain\bin
mkdir bubichain\config
mkdir bubichain\data
mkdir bubichain\jslib
mkdir bubichain\log

copy ..\bin\Chain.exe bubichain\bin
copy ..\bin\*.bin bubichain\bin
copy ..\bin\*.dat bubichain\bin
copy ..\bin\*.dll bubichain\bin
copy ..\config\config-mainnet.json bubichain\config\
copy ..\config\config-testnet.json bubichain\config\
copy ..\config\config-single.json  bubichain\config\
copy ..\config\ReadMe.txt  bubichain\config\
copy ..\jslib\jslint.js bubichain\jslib\

..\zip.exe -r bubichain-win-%CURRENT_DATE_TIME_STAMP%.zip bubichain

rd /s /Q ".\bubichain\"

cd ../
	
