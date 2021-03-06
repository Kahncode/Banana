/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * https://github.com/OpenAPITools/openapi-generator
 * Do not edit the class manually.
 */

#pragma once

#include "ModelPrefixBaseModel.h"
#include "ModelPrefixStoreApi.h"

#include "ModelPrefixOrder.h"

namespace CppNamespace 
{

/* Delete purchase order by ID
 *
 * For valid response try integer IDs with value &lt; 1000. Anything above 1000 or nonintegers will generate API errors
*/
class PETSTORE_API ModelPrefixStoreApi::DeleteOrderRequest : public Request
{
public:
    virtual ~DeleteOrderRequest() {}
	void SetupHttpRequest(const FHttpRequestRef& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* ID of the order that needs to be deleted */
	FString OrderId;
};

class PETSTORE_API ModelPrefixStoreApi::DeleteOrderResponse : public Response
{
public:
    virtual ~DeleteOrderResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
    
    
};

/* Returns pet inventories by status
 *
 * Returns a map of status codes to quantities
*/
class PETSTORE_API ModelPrefixStoreApi::GetInventoryRequest : public Request
{
public:
    virtual ~GetInventoryRequest() {}
	void SetupHttpRequest(const FHttpRequestRef& HttpRequest) const final;
	FString ComputePath() const final;
    
};

class PETSTORE_API ModelPrefixStoreApi::GetInventoryResponse : public Response
{
public:
    virtual ~GetInventoryResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
    
    TMap<FString, int32> Content;
};

/* Find purchase order by ID
 *
 * For valid response try integer IDs with value &lt;&#x3D; 5 or &gt; 10. Other values will generated exceptions
*/
class PETSTORE_API ModelPrefixStoreApi::GetOrderByIdRequest : public Request
{
public:
    virtual ~GetOrderByIdRequest() {}
	void SetupHttpRequest(const FHttpRequestRef& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* ID of pet that needs to be fetched */
	int64 OrderId = 0;
};

class PETSTORE_API ModelPrefixStoreApi::GetOrderByIdResponse : public Response
{
public:
    virtual ~GetOrderByIdResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
    
    ModelPrefixOrder Content;
};

/* Place an order for a pet

*/
class PETSTORE_API ModelPrefixStoreApi::PlaceOrderRequest : public Request
{
public:
    virtual ~PlaceOrderRequest() {}
	void SetupHttpRequest(const FHttpRequestRef& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* order placed for purchasing the pet */
	ModelPrefixOrder Body;
};

class PETSTORE_API ModelPrefixStoreApi::PlaceOrderResponse : public Response
{
public:
    virtual ~PlaceOrderResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
    
    ModelPrefixOrder Content;
};

}
