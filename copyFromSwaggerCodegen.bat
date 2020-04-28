SETLOCAL

SET ORIGIN=C:\workspace\swagger-codegen\samples\client\petstore\ue4cpp\client
SET TARGET=%CD%\Source\Petstore

mkdir %TARGET%
Robocopy.exe %ORIGIN% %TARGET% /mir
