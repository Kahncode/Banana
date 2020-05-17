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
#include "SwaggerPetApi.h"

#include "SwaggerPetApiOperations.h"
#include "SwaggerModule.h"

#include "HttpModule.h"
#include "Serialization/JsonSerializer.h"

namespace Swagger 
{

SwaggerPetApi::SwaggerPetApi() 
: Url(TEXT("http://petstore.swagger.io"))
{
}

SwaggerPetApi::~SwaggerPetApi() {}

void SwaggerPetApi::SetURL(const FString& InUrl)
{
	Url = InUrl;
}

void SwaggerPetApi::AddHeaderParam(const FString& Key, const FString& Value)
{
	AdditionalHeaderParams.Add(Key, Value);
}

void SwaggerPetApi::ClearHeaderParams()
{
	AdditionalHeaderParams.Reset();
}

bool SwaggerPetApi::IsValid() const
{
	if (Url.IsEmpty())
	{
		UE_LOG(LogSwagger, Error, TEXT("SwaggerPetApi: Endpoint Url is not set, request cannot be performed"));
		return false;
	}

	return true;
}

void SwaggerPetApi::HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const
{
	InOutResponse.SetHttpResponse(HttpResponse);
	InOutResponse.SetSuccessful(bSucceeded);

	if (bSucceeded && HttpResponse.IsValid())
	{
		InOutResponse.SetHttpResponseCode((EHttpResponseCodes::Type)HttpResponse->GetResponseCode());
		FString ContentType = HttpResponse->GetContentType();
		FString Content;

		if (ContentType == TEXT("application/json"))
		{
			Content = HttpResponse->GetContentAsString();

			TSharedPtr<FJsonValue> JsonValue;
			auto Reader = TJsonReaderFactory<>::Create(Content);

			if (FJsonSerializer::Deserialize(Reader, JsonValue) && JsonValue.IsValid())
			{
				if (InOutResponse.FromJson(JsonValue))
					return; // Successfully parsed
			}
		}
		else if(ContentType == TEXT("text/plain"))
		{
			Content = HttpResponse->GetContentAsString();
			InOutResponse.SetResponseString(Content);
			return; // Successfully parsed
		}

		// Report the parse error but do not mark the request as unsuccessful. Data could be partial or malformed, but the request succeeded.
		UE_LOG(LogSwagger, Error, TEXT("Failed to deserialize Http response content (type:%s):\n%s"), *ContentType , *Content);
		return;
	}

	// By default, assume we failed to establish connection
	InOutResponse.SetHttpResponseCode(EHttpResponseCodes::RequestTimeout);
}

bool SwaggerPetApi::UpdatePet(const UpdatePetRequest& Request, const FUpdatePetDelegate& Delegate /*= FUpdatePetDelegate()*/) const
{
	if (!IsValid())
		return false;

	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &SwaggerPetApi::OnUpdatePetResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void SwaggerPetApi::OnUpdatePetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdatePetDelegate Delegate) const
{
	UpdatePetResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

}