/**
 * UE4GeneratorTester
 * test
 *
 * OpenAPI spec version: 1.0.0
 * Contact: apiteam@swagger.io
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * https://github.com/OpenAPITools/openapi-generator
 * Do not edit the class manually.
 */

#include "OpenAPIDefaultApiOperations.h"

#include "OpenAPIModule.h"
#include "OpenAPIHelpers.h"

#include "Dom/JsonObject.h"
#include "Templates/SharedPointer.h"
#include "HttpModule.h"
#include "PlatformHttp.h"

namespace OpenAPI 
{

inline FString ToString(const OpenAPIDefaultApi::AddPetRequest::StatusEnum& Value)
{
	switch (Value)
	{
	case OpenAPIDefaultApi::AddPetRequest::StatusEnum::Available:
		return TEXT("available");
	case OpenAPIDefaultApi::AddPetRequest::StatusEnum::Pending:
		return TEXT("pending");
	case OpenAPIDefaultApi::AddPetRequest::StatusEnum::Sold:
		return TEXT("sold");
	}

	UE_LOG(LogOpenAPI, Error, TEXT("Invalid OpenAPIDefaultApi::AddPetRequest::StatusEnum Value (%d)"), (int)Value);	
	return TEXT("");
}

inline FString OpenAPIDefaultApi::AddPetRequest::EnumToString(const OpenAPIDefaultApi::AddPetRequest::StatusEnum& EnumValue)
{
	return ToString(EnumValue);
}

inline bool FromString(const FString& EnumAsString, OpenAPIDefaultApi::AddPetRequest::StatusEnum& Value)
{
	static TMap<FString, OpenAPIDefaultApi::AddPetRequest::StatusEnum> StringToEnum = { 
		{ TEXT("available"), OpenAPIDefaultApi::AddPetRequest::StatusEnum::Available },
		{ TEXT("pending"), OpenAPIDefaultApi::AddPetRequest::StatusEnum::Pending },
		{ TEXT("sold"), OpenAPIDefaultApi::AddPetRequest::StatusEnum::Sold }, };

	const auto Found = StringToEnum.Find(EnumAsString);
	if(Found)
		Value = *Found;

	return Found != nullptr;	
}

inline bool OpenAPIDefaultApi::AddPetRequest::EnumFromString(const FString& EnumAsString, OpenAPIDefaultApi::AddPetRequest::StatusEnum& EnumValue)
{
	return FromString(EnumAsString, EnumValue);
}

inline FStringFormatArg ToStringFormatArg(const OpenAPIDefaultApi::AddPetRequest::StatusEnum& Value)
{
	return FStringFormatArg(ToString(Value));
}

inline void WriteJsonValue(JsonWriter& Writer, const OpenAPIDefaultApi::AddPetRequest::StatusEnum& Value)
{
	WriteJsonValue(Writer, ToString(Value));
}

inline bool TryGetJsonValue(const TSharedPtr<FJsonValue>& JsonValue, OpenAPIDefaultApi::AddPetRequest::StatusEnum& Value)
{
	FString TmpValue;
	if (JsonValue->TryGetString(TmpValue))
	{
		if(FromString(TmpValue, Value))
			return true;
	}
	return false;
}

FString OpenAPIDefaultApi::AddPetRequest::ComputePath() const
{
	FString Path(TEXT("/test"));
	TArray<FString> QueryParams;
	QueryParams.Add(FString(TEXT("status=")) + CollectionToUrlString_csv(Status, TEXT("status")));
	Path += TCHAR('?');
	Path += FString::Join(QueryParams, TEXT("&"));

	return Path;
}

void OpenAPIDefaultApi::AddPetRequest::SetupHttpRequest(const FHttpRequestRef& HttpRequest) const
{
	static const TArray<FString> Consumes = { TEXT("application/json"), TEXT("application/xml") };
	//static const TArray<FString> Produces = {  };

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
		UE_LOG(LogOpenAPI, Error, TEXT("Body parameter (body) was ignored, not supported in multipart form"));
	}
	else if (Consumes.Contains(TEXT("application/x-www-form-urlencoded")))
	{
		UE_LOG(LogOpenAPI, Error, TEXT("Body parameter (body) was ignored, not supported in urlencoded requests"));
	}
	else
	{
		UE_LOG(LogOpenAPI, Error, TEXT("Request ContentType not supported (%s)"), *FString::Join(Consumes, TEXT(",")));
	}
}

void OpenAPIDefaultApi::AddPetResponse::SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode)
{
	Response::SetHttpResponseCode(InHttpResponseCode);
	switch ((int)InHttpResponseCode)
	{
	case 405:
		SetResponseString(TEXT("Invalid input"));
		break;
	}
}

bool OpenAPIDefaultApi::AddPetResponse::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	return true;
}

}
