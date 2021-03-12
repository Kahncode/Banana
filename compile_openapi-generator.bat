setlocal
@echo off
set BATCHPATH=%~dp0
set SWAGGER_ROOT=%BATCHPATH%\..\openapi-generator
set executable=%SWAGGER_ROOT%\modules\openapi-generator-cli\target\openapi-generator-cli.jar

pushd %SWAGGER_ROOT%
mvn clean package -DskipTests
popd
