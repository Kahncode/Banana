setlocal
@echo off
set BATCHPATH=%~dp0
set SWAGGER_ROOT=%BATCHPATH%\..\swagger-codegen
set executable=%SWAGGER_ROOT%\modules\swagger-codegen-cli\target\swagger-codegen-cli.jar


If Not Exist %executable% (
  mvn clean package
)

rem clean the target folder
del /F /Q %BATCHPATH%\Source\Petstore\*

set JAVA_EXE="C:\Program Files\Java\jdk-14.0.1\bin\java.exe"

rem set JAVA_OPTS=%JAVA_OPTS% -Xdebug -Xnoagent -Djava.compiler=NONE -Xrunjdwp:transport=dt_socket,address=8000,server=y,suspend=y
set ags=generate -i %SWAGGER_ROOT%\modules\swagger-codegen\src\test\resources\2_0\petstore.yaml -l ue4cpp -o %BATCHPATH%\Source\Petstore\ -c %BATCHPATH%\config.json

%JAVA_EXE% %JAVA_OPTS% -jar %executable% %ags%
