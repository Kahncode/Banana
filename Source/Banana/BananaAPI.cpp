#include "BananaAPI.h"

#include "BananaModels.h"
#include "BananaModule.h"

#include "HttpModule.h"
#include "Serialization/JsonSerializer.h"

namespace Banana
{

BananaAPI::BananaAPI()
{

}

BananaAPI::~BananaAPI()
{

}

void BananaAPI::SetURL(const FString& InUrl)
{
	Url = InUrl;
}

void BananaAPI::SetAuthCredentials(const FString& InAuthKey, const FString& InAuthValue)
{
	AuthKey = InAuthKey;
	AuthValue = InAuthValue;
}

bool BananaAPI::IsValid() const
{
	if (Url.IsEmpty())
	{
		UE_LOG(LogBanana, Error, TEXT("BananaAPI: Endpoint Url is not set, request cannot be performed"));
		return false;
	}

	return true;
}

TSharedRef<IHttpRequest> BananaAPI::SendRequest(const TCHAR* Path, const TSharedPtr<FJsonObject>& Body) const
{
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(*FString::Printf(TEXT("%s/%s"), *Url, Path));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json; charset=utf-8"));

	if (!AuthKey.IsEmpty())
		HttpRequest->SetHeader(AuthKey, AuthValue);

	FString JsonString;
	auto Writer = TJsonWriterFactory<>::Create(&JsonString);
	FJsonSerializer::Serialize(Body.ToSharedRef(), Writer);

	HttpRequest->SetContentAsString(JsonString);
	return HttpRequest;
}

bool BananaAPI::SomeMethod(SomeMethodRequest& Request, const FSomeMethodDelegate& Delegate /*= FSomeMethodDelegate()*/) const
{
	if (IsValid() && !Request.IsValid())
		return false;

	auto HttpRequest = SendRequest(TEXT("/SomeMethod"), Request.ToJson());
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &BananaAPI::OnSomeMethodResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void BananaAPI::OnSomeMethodResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSomeMethodDelegate Delegate) const
{
	SomeMethodResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
}

void BananaAPI::HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const
{
	InOutResponse.Success = bSucceeded;

	if (bSucceeded && HttpResponse.IsValid())
	{
		InOutResponse.ResponseCode = (EHttpResponseCodes::Type)HttpResponse->GetResponseCode();
		FString Content = HttpResponse->GetContentAsString();
		TSharedPtr<FJsonObject> JsonObject;
		auto Reader = TJsonReaderFactory<>::Create(Content);
		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			if (EHttpResponseCodes::IsOk(InOutResponse.ResponseCode))
			{
				if (InOutResponse.FromJson(JsonObject))
					return; //Successfully parsed
			}
			else
			{
				if (InOutResponse.ErrorFromJson(JsonObject))
					return; //Successfully parsed
			}
		}

		UE_LOG(LogBanana, Error, TEXT("Failed to deserialize HTTP response content (%s)"), *Content);
		InOutResponse.Success = false;
		return;
	}

	// Assume we failed to reach the server
	InOutResponse.ResponseCode = EHttpResponseCodes::RequestTimeout;
}

}