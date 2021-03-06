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

#include "ModelPrefixStoreApiOperations.h"

#include "PetstoreModule.h"
#include "ModelPrefixHelpers.h"

#include "Dom/JsonObject.h"
#include "Templates/SharedPointer.h"
#include "HttpModule.h"
#include "PlatformHttp.h"

namespace CppNamespace 
{

FString ModelPrefixStoreApi::DeleteOrderRequest::ComputePath() const
{
	TMap<FString, FStringFormatArg> PathParams = { 
	{ TEXT("orderId"), ToStringFormatArg(OrderId) } };

	FString Path = FString::Format(TEXT("/store/order/{orderId}"), PathParams);
	
	return Path;
}

void ModelPrefixStoreApi::DeleteOrderRequest::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = {  };
	//static const TArray<FString> Produces = {  };

	HttpRequest->SetVerb(TEXT("DELETE"));

	// Default to Json Body request
	if (Consumes.Num() == 0 || Consumes.Contains(TEXT("application/json")))
	{
	}
	else if (Consumes.Contains(TEXT("multipart/form-data")))
	{
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
	}
	else
	{
		UE_LOG(LogPetstore, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void ModelPrefixStoreApi::DeleteOrderResponse::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 400:
		SetResponseString(TEXT("Invalid ID supplied"));
		break;
	case 404:
		SetResponseString(TEXT("Order not found"));
		break;
	}
}

bool ModelPrefixStoreApi::DeleteOrderResponse::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return true;
}

FString ModelPrefixStoreApi::GetInventoryRequest::ComputePath() const
{
	FString Path(TEXT("/store/inventory"));
	return Path;
}

void ModelPrefixStoreApi::GetInventoryRequest::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = {  };
	//static const TArray<FString> Produces = { TEXT("application/json") };

	HttpRequest->SetVerb(TEXT("GET"));

	// Default to Json Body request
	if (Consumes.Num() == 0 || Consumes.Contains(TEXT("application/json")))
	{
	}
	else if (Consumes.Contains(TEXT("multipart/form-data")))
	{
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
	}
	else
	{
		UE_LOG(LogPetstore, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void ModelPrefixStoreApi::GetInventoryResponse::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 200:
		SetResponseString(TEXT("successful operation"));
		break;
	}
}

bool ModelPrefixStoreApi::GetInventoryResponse::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return TryGetJsonValue(JsonValue, Content);
}

FString ModelPrefixStoreApi::GetOrderByIdRequest::ComputePath() const
{
	TMap<FString, FStringFormatArg> PathParams = { 
	{ TEXT("orderId"), ToStringFormatArg(OrderId) } };

	FString Path = FString::Format(TEXT("/store/order/{orderId}"), PathParams);
	
	return Path;
}

void ModelPrefixStoreApi::GetOrderByIdRequest::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = {  };
	//static const TArray<FString> Produces = { TEXT("application/xml"), TEXT("application/json") };

	HttpRequest->SetVerb(TEXT("GET"));

	// Default to Json Body request
	if (Consumes.Num() == 0 || Consumes.Contains(TEXT("application/json")))
	{
	}
	else if (Consumes.Contains(TEXT("multipart/form-data")))
	{
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
	}
	else
	{
		UE_LOG(LogPetstore, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void ModelPrefixStoreApi::GetOrderByIdResponse::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 200:
		SetResponseString(TEXT("successful operation"));
		break;
	case 400:
		SetResponseString(TEXT("Invalid ID supplied"));
		break;
	case 404:
		SetResponseString(TEXT("Order not found"));
		break;
	}
}

bool ModelPrefixStoreApi::GetOrderByIdResponse::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return TryGetJsonValue(JsonValue, Content);
}

FString ModelPrefixStoreApi::PlaceOrderRequest::ComputePath() const
{
	FString Path(TEXT("/store/order"));
	return Path;
}

void ModelPrefixStoreApi::PlaceOrderRequest::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = {  };
	//static const TArray<FString> Produces = { TEXT("application/xml"), TEXT("application/json") };

	HttpRequest->SetVerb(TEXT("POST"));

	// Default to Json Body request
	if (Consumes.Num() == 0 || Consumes.Contains(TEXT("application/json")))
	{
		// Body parameters
		FString JsonBody;
		JsonWriter Writer = TJsonWriterFactory<>::Create(&JsonBody);

		WriteJsonValue(Writer, Body);
		Writer->Close();

		HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json; charset=utf-8"));
		HttpRequest->SetContentAsString(JsonBody);
	}
	else if (Consumes.Contains(TEXT("multipart/form-data")))
	{
		UE_LOG(LogPetstore, Error, TEXT("Body parameter (body) was ignored, not supported in multipart form"));
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
		UE_LOG(LogPetstore, Error, TEXT("Body parameter (body) was ignored, not supported in urlencoded requests"));
	}
	else
	{
		UE_LOG(LogPetstore, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void ModelPrefixStoreApi::PlaceOrderResponse::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 200:
		SetResponseString(TEXT("successful operation"));
		break;
	case 400:
		SetResponseString(TEXT("Invalid Order"));
		break;
	}
}

bool ModelPrefixStoreApi::PlaceOrderResponse::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return TryGetJsonValue(JsonValue, Content);
}

}
