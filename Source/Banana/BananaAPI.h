#pragma once

#include "CoreMinimal.h"

#include "BananaModels.h"

class IHttpRequest;
class IHttpResponse;

typedef TSharedPtr<IHttpRequest> FHttpRequestPtr;
typedef TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> FHttpResponsePtr;

class FJsonObject;

namespace Banana
{
	class BANANA_API BananaAPI
	{
	public:

		BananaAPI();
		~BananaAPI();

		void SetURL(const FString& Url);
		void SetAuthCredentials(const FString& AuthKey, const FString& AuthValue);

		DECLARE_DELEGATE_OneParam(FSomeMethodDelegate, const SomeMethodResponse&);

		/* Doc */
		bool SomeMethod(SomeMethodRequest& Request, const FSomeMethodDelegate& Delegate = FSomeMethodDelegate()) const;
	private:

		void OnSomeMethodResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FSomeMethodDelegate Delegate) const;



		bool IsValid() const;
		TSharedRef<IHttpRequest> SendRequest(const TCHAR* Path, const TSharedPtr<FJsonObject>& Body) const;
		void HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& Respose) const;

		FString Url;
		FString AuthKey;
		FString AuthValue;
	};
}