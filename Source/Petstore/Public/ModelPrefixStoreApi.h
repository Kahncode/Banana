/**
 * Swagger Petstore
 * This is a sample server Petstore server.  You can find out more about Swagger at [http://swagger.io](http://swagger.io) or on [irc.freenode.net, #swagger](http://swagger.io/irc/).  For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * Contact: apiteam@swagger.io
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */
#pragma once

#include "CoreMinimal.h"
#include "ModelPrefixBaseModel.h"

namespace CppNamespace 
{

class PETSTORE_API ModelPrefixStoreApi
{
public:
	ModelPrefixStoreApi();
	~ModelPrefixStoreApi();

	void SetURL(const FString& Url);
	void AddHeaderParam(const FString& Key, const FString& Value);
	void ClearHeaderParams();

	class DeleteOrderRequest;
	class DeleteOrderResponse;
	class GetInventoryRequest;
	class GetInventoryResponse;
	class GetOrderByIdRequest;
	class GetOrderByIdResponse;
	class PlaceOrderRequest;
	class PlaceOrderResponse;
	
    DECLARE_DELEGATE_OneParam(FDeleteOrderDelegate, const DeleteOrderResponse&);
    DECLARE_DELEGATE_OneParam(FGetInventoryDelegate, const GetInventoryResponse&);
    DECLARE_DELEGATE_OneParam(FGetOrderByIdDelegate, const GetOrderByIdResponse&);
    DECLARE_DELEGATE_OneParam(FPlaceOrderDelegate, const PlaceOrderResponse&);
    
    bool DeleteOrder(const DeleteOrderRequest& Request, const FDeleteOrderDelegate& Delegate = FDeleteOrderDelegate()) const;
    bool GetInventory(const GetInventoryRequest& Request, const FGetInventoryDelegate& Delegate = FGetInventoryDelegate()) const;
    bool GetOrderById(const GetOrderByIdRequest& Request, const FGetOrderByIdDelegate& Delegate = FGetOrderByIdDelegate()) const;
    bool PlaceOrder(const PlaceOrderRequest& Request, const FPlaceOrderDelegate& Delegate = FPlaceOrderDelegate()) const;
    
private:
    void OnDeleteOrderResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteOrderDelegate Delegate) const;
    void OnGetInventoryResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetInventoryDelegate Delegate) const;
    void OnGetOrderByIdResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetOrderByIdDelegate Delegate) const;
    void OnPlaceOrderResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FPlaceOrderDelegate Delegate) const;
    
	bool IsValid() const;
	void HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const;

	FString Url;
	TMap<FString,FString> AdditionalHeaderParams;
};
	
}
