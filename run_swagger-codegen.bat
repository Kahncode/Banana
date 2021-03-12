setlocal
@echo off
set BATCHPATH=%~dp0
set SWAGGER_ROOT=%BATCHPATH%\..\swagger-codegen
set executable=%SWAGGER_ROOT%\modules\swagger-codegen-cli\target\swagger-codegen-cli.jar


If Not Exist %executable% (
	pushd %SWAGGER_ROOT%
 	mvn clean package -DskipTests
 	popd
)

rem clean the target folder
del /F /Q %BATCHPATH%\Source\Petstore\*

set JAVA_EXE="C:\Program Files\Java\jdk-14.0.1\bin\java.exe"

rem set JAVA_OPTS=%JAVA_OPTS% -Xdebug -Xnoagent -Djava.compiler=NONE -Xrunjdwp:transport=dt_socket,address=8000,server=y,suspend=y
set ags=generate -i %SWAGGER_ROOT%\modules\swagger-codegen\src\test\resources\2_0\petstore.yaml -l ue4cpp -o %BATCHPATH%\Source\Petstore\ -c %BATCHPATH%\config.json
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%

del /F /Q %BATCHPATH%\Source\SwaggerCodegenTest\*

rem Generate test file
set ags=generate -i %BATCHPATH%\swagger-codegen-test.yaml -l ue4cpp -o %BATCHPATH%\Source\SwaggerCodegenTest\
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%

rem Generate dmarket APIs
del /F /Q %BATCHPATH%\Source\DMarket\*

set ags=generate -i %BATCHPATH%\exchange.json -l ue4cpp -o %BATCHPATH%\Source\DMarket\ -c %BATCHPATH%\config_dmarket.json
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%

set ags=generate -i %BATCHPATH%\marketplace.json -l ue4cpp -o %BATCHPATH%\Source\DMarket\ -c %BATCHPATH%\config_dmarket.json
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%

set ags=generate -i %BATCHPATH%\account.json -l ue4cpp -o %BATCHPATH%\Source\DMarket\ -c %BATCHPATH%\config_dmarket.json
%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%
