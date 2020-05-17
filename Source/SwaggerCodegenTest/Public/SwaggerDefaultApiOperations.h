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
#pragma once

#include "SwaggerBaseModel.h"
#include "SwaggerDefaultApi.h"

#include "SwaggerAllTypes.h"

namespace Swagger 
{

/* Add a new pet to the store
 *
 * 
*/
class SWAGGER_API SwaggerDefaultApi::AddPetRequest : public Request
{
public:
    virtual ~AddPetRequest() {}
	void SetupHttpRequest(const TSharedRef<IHttpRequest>& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* Pet object that needs to be added to the store */
	SwaggerAllTypes Body;
	enum class StatusEnum
	{
		Available,
		Pending,
		Sold,
  	};
	/* Status values that need to be considered for filter */
	TArray<StatusEnum> Status;
};

class SWAGGER_API SwaggerDefaultApi::AddPetResponse : public Response
{
public:
    virtual ~AddPetResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonObject) final;
    
    
};

}
