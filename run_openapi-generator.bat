setlocal
@echo off
set BATCHPATH=%~dp0
set SWAGGER_ROOT=%BATCHPATH%\..\openapi-generator
set executable=%SWAGGER_ROOT%\modules\openapi-generator-cli\target\openapi-generator-cli.jar

If Not Exist %executable% (
  mvn clean package -DskipTests
)

set JAVA_EXE="C:\Program Files\Java\jdk-14.0.1\bin\java.exe"
rem set JAVA_OPTS=%JAVA_OPTS% -agentlib:jdwp=transport=dt_socket,server=y,suspend=y,address=8008

del /F /Q %BATCHPATH%\Source\CodegenTest\*

rem Generate test file
set ags=generate -i %BATCHPATH%\codegen-test.yaml -g cpp-ue4 -o %BATCHPATH%\Source\CodegenTest\
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%

rem clean the target folder
del /F /Q %BATCHPATH%\Source\Petstore\*

set ags=generate -i %SWAGGER_ROOT%\modules\openapi-generator\src\test\resources\2_0\petstore.yaml -g cpp-ue4 -o %BATCHPATH%\Source\Petstore\ -c %BATCHPATH%\config.json
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%

rem Generate dmarket APIs
del /F /Q %BATCHPATH%\Source\DMarket\*

set ags=generate -i %BATCHPATH%\exchange.json -g cpp-ue4 -o %BATCHPATH%\Source\DMarket\ -c %BATCHPATH%\config_dmarket.json
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%

set ags=generate -i %BATCHPATH%\marketplace.json -g cpp-ue4 -o %BATCHPATH%\Source\DMarket\ -c %BATCHPATH%\config_dmarket.json
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%

set ags=generate -i %BATCHPATH%\account.json -g cpp-ue4 -o %BATCHPATH%\Source\DMarket\ -c %BATCHPATH%\config_dmarket.json
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%
