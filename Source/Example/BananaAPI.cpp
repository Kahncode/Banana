#include "BananaAPI.h"

#include "BananaModels.h"
#include "BananaModule.h"

#include "HTTPModule.h"
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

	auto HttpRequest = SendRequest(TEXT("/Client/AddFriend"), Request.ToJson());
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &BananaAPI::OnSomeMethodResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void BananaAPI::OnSomeMethodResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSomeMethodDelegate Delegate) const
{
	//Note: here if the model contains the error model it can be pretty easy, just read the json of the httpresponse into the model

	/*ClientModels::FAddFriendResult outResult;
	FPlayFabCppError errorResult;
	if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
	{
		SuccessDelegate.ExecuteIfBound(outResult);
	}
	else
	{
		ErrorDelegate.ExecuteIfBound(errorResult);
	}*/
}

}


/*
bool PlayFabRequestHandler::DecodeRequest(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, PlayFab::FPlayFabCppBaseModel& OutResult, PlayFab::FPlayFabCppError& OutError)
{
	FString ResponseStr, ErrorStr;
	if (bSucceeded && HttpResponse.IsValid())
	{
		if (EHttpResponseCodes::IsOk(HttpResponse->GetResponseCode()))
		{
			// Create the Json parser
			ResponseStr = HttpResponse->GetContentAsString();
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<> > JsonReader = TJsonReaderFactory<>::Create(ResponseStr);

			if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
			{
				if (PlayFabRequestHandler::DecodeError(JsonObject, OutError))
				{
					return false;
				}

				const TSharedPtr<FJsonObject>* DataJsonObject;
				if (JsonObject->TryGetObjectField(TEXT("data"), DataJsonObject))
				{
					return OutResult.readFromValue(*DataJsonObject);
				}
			}
		}
		else
		{
			// Create the Json parser
			ResponseStr = HttpResponse->GetContentAsString();
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<> > JsonReader = TJsonReaderFactory<>::Create(ResponseStr);

			if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
			{
				if (PlayFabRequestHandler::DecodeError(JsonObject, OutError))
				{
					return false;
				}
			}
		}
	}

	// If we get here, we failed to connect meaningfully to the server - Assume a timeout
	OutError.HttpCode = 408;
	OutError.ErrorCode = PlayFabErrorConnectionTimeout;
	// For text returns, use the non-json response if possible, else default to no response
	OutError.ErrorName = OutError.ErrorMessage = OutError.HttpStatus = TEXT("Request Timeout or null response");

	return false;
}

bool PlayFabRequestHandler::DecodeError(TSharedPtr<FJsonObject> JsonObject, PlayFab::FPlayFabCppError& OutError)
{
	// check if returned json indicates an error
	if (JsonObject->HasField(TEXT("errorCode")))
	{
		// deserialize the FPlayFabCppError object
		JsonObject->TryGetNumberField(TEXT("errorCode"), OutError.ErrorCode);
		JsonObject->TryGetNumberField(TEXT("code"), OutError.HttpCode);
		JsonObject->TryGetStringField(TEXT("status"), OutError.HttpStatus);
		JsonObject->TryGetStringField(TEXT("error"), OutError.ErrorName);
		JsonObject->TryGetStringField(TEXT("errorMessage"), OutError.ErrorMessage);

		const TSharedPtr<FJsonObject>* obj;
		if (JsonObject->TryGetObjectField(TEXT("errorDetails"), obj))
		{
			auto vals = (*obj)->Values;
			for (auto val : vals)
			{
				if (val.Value->AsArray().Num() > 0)
				{
					OutError.ErrorDetails.Add(val.Key, val.Value->AsArray()[0]->AsString());
				}
				else
				{
					OutError.ErrorDetails.Add(val.Key, val.Value->AsString());
				}
			}
		}

		// TODO: handle global error delegate here

		// We encountered no errors parsing the error
		return true;
	}

	return false;
}
*/