/**
 * UE4GeneratorTester
 * test
 *
 * OpenAPI spec version: 1.0.0
 * Contact: apiteam@swagger.io
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */
#include "SwaggerBaseModel.h"

namespace Swagger 
{

void Response::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
    ResponseCode = InHttpResponseCode;
    SetSuccessful(EHttpResponseCodes::IsOk(InHttpResponseCode));
    if(InHttpResponseCode == EHttpResponseCodes::RequestTimeout)
    {
        SetResponseString(TEXT("Request Timeout"));
    }
}

}