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

#include "ModelPrefixUserApi.h"

#include "ModelPrefixUserApiOperations.h"
#include "PetstoreModule.h"

#include "HttpModule.h"
#include "Serialization/JsonSerializer.h"

namespace CppNamespace 
{

ModelPrefixUserApi::ModelPrefixUserApi() 
: Url(TEXT("http://petstore.swagger.io/v2"))
{
}

ModelPrefixUserApi::~ModelPrefixUserApi() {}

void ModelPrefixUserApi::SetURL(const FString& InUrl)
{
	Url = InUrl;
}

void ModelPrefixUserApi::AddHeaderParam(const FString& Key, const FString& Value)
{
	AdditionalHeaderParams.Add(Key, Value);
}

void ModelPrefixUserApi::ClearHeaderParams()
{
	AdditionalHeaderParams.Reset();
}

bool ModelPrefixUserApi::IsValid() const
{
	if (Url.IsEmpty())
	{
		UE_LOG(LogPetstore, Error, TEXT("ModelPrefixUserApi: Endpoint Url is not set, request cannot be performed"));
		return false;
	}

	return true;
}

void ModelPrefixUserApi::SetHttpRetryManager(FHttpRetrySystem::FManager& InRetryManager)
{
	if(RetryManager != &GetHttpRetryManager())
	{
		DefaultRetryManager.Reset();
		RetryManager = &InRetryManager;
	}
}

FHttpRetrySystem::FManager& ModelPrefixUserApi::GetHttpRetryManager()
{
	return *RetryManager;
}

FHttpRequestRef ModelPrefixUserApi::CreateHttpRequest(const Request& Request) const
{
	if (!Request.GetRetryParams().IsSet())
	{
		return FHttpModule::Get().CreateRequest();
	}
	else
	{
		if (!RetryManager)
		{
			// Create default retry manager if none was specified
			DefaultRetryManager = MakeUnique<HttpRetryManager>(6, 60);
			RetryManager = DefaultRetryManager.Get();
		}

		const HttpRetryParams& Params = Request.GetRetryParams().GetValue();
		return RetryManager->CreateRequest(Params.RetryLimitCountOverride, Params.RetryTimeoutRelativeSecondsOverride, Params.RetryResponseCodes, Params.RetryVerbs, Params.RetryDomains);
	}
}

void ModelPrefixUserApi::HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const
{
	InOutResponse.SetHttpResponse(HttpResponse);
	InOutResponse.SetSuccessful(bSucceeded);

	if (bSucceeded && HttpResponse.IsValid())
	{
		InOutResponse.SetHttpResponseCode((EHttpResponseCodes::Type)HttpResponse->GetResponseCode());
		FString ContentType = HttpResponse->GetContentType();
		FString Content;

		if (ContentType.IsEmpty())
		{
			return; // Nothing to parse
		}
		else if (ContentType.StartsWith(TEXT("application/json")) || ContentType.StartsWith("text/json"))
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
		else if(ContentType.StartsWith(TEXT("text/plain")))
		{
			Content = HttpResponse->GetContentAsString();
			InOutResponse.SetResponseString(Content);
			return; // Successfully parsed
		}

		// Report the parse error but do not mark the request as unsuccessful. Data could be partial or malformed, but the request succeeded.
		UE_LOG(LogPetstore, Error, TEXT("Failed to deserialize Http response content (type:%s):\n%s"), *ContentType , *Content);
		return;
	}

	// By default, assume we failed to establish connection
	InOutResponse.SetHttpResponseCode(EHttpResponseCodes::RequestTimeout);
}

bool ModelPrefixUserApi::CreateUser(const CreateUserRequest& Request, const FCreateUserDelegate& Delegate /*= FCreateUserDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ModelPrefixUserApi::OnCreateUserResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ModelPrefixUserApi::OnCreateUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateUserDelegate Delegate) const
{
	CreateUserResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

bool ModelPrefixUserApi::CreateUsersWithArrayInput(const CreateUsersWithArrayInputRequest& Request, const FCreateUsersWithArrayInputDelegate& Delegate /*= FCreateUsersWithArrayInputDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ModelPrefixUserApi::OnCreateUsersWithArrayInputResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ModelPrefixUserApi::OnCreateUsersWithArrayInputResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateUsersWithArrayInputDelegate Delegate) const
{
	CreateUsersWithArrayInputResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

bool ModelPrefixUserApi::CreateUsersWithListInput(const CreateUsersWithListInputRequest& Request, const FCreateUsersWithListInputDelegate& Delegate /*= FCreateUsersWithListInputDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ModelPrefixUserApi::OnCreateUsersWithListInputResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ModelPrefixUserApi::OnCreateUsersWithListInputResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateUsersWithListInputDelegate Delegate) const
{
	CreateUsersWithListInputResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

bool ModelPrefixUserApi::DeleteUser(const DeleteUserRequest& Request, const FDeleteUserDelegate& Delegate /*= FDeleteUserDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ModelPrefixUserApi::OnDeleteUserResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ModelPrefixUserApi::OnDeleteUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteUserDelegate Delegate) const
{
	DeleteUserResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

bool ModelPrefixUserApi::GetUserByName(const GetUserByNameRequest& Request, const FGetUserByNameDelegate& Delegate /*= FGetUserByNameDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ModelPrefixUserApi::OnGetUserByNameResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ModelPrefixUserApi::OnGetUserByNameResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetUserByNameDelegate Delegate) const
{
	GetUserByNameResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

bool ModelPrefixUserApi::LoginUser(const LoginUserRequest& Request, const FLoginUserDelegate& Delegate /*= FLoginUserDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ModelPrefixUserApi::OnLoginUserResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ModelPrefixUserApi::OnLoginUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FLoginUserDelegate Delegate) const
{
	LoginUserResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

bool ModelPrefixUserApi::LogoutUser(const LogoutUserRequest& Request, const FLogoutUserDelegate& Delegate /*= FLogoutUserDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ModelPrefixUserApi::OnLogoutUserResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ModelPrefixUserApi::OnLogoutUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FLogoutUserDelegate Delegate) const
{
	LogoutUserResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

bool ModelPrefixUserApi::UpdateUser(const UpdateUserRequest& Request, const FUpdateUserDelegate& Delegate /*= FUpdateUserDelegate()*/) const
{
	if (!IsValid())
		return false;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);
	
	HttpRequest->OnProcessRequestComplete().BindRaw(this, &ModelPrefixUserApi::OnUpdateUserResponse, Delegate);
	return HttpRequest->ProcessRequest();
}

void ModelPrefixUserApi::OnUpdateUserResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdateUserDelegate Delegate) const
{
	UpdateUserResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

}
