#pragma once

#include "Interfaces/IHttpResponse.h"

class FJsonObject;

namespace Banana
{
	//TODO: remove base class model if not necessary + remove unnecessary virtual calls but without making template hell
	class BANANA_API Model
	{ 
	public:
		virtual ~Model() {}
	};

	class BANANA_API Request : public Model
	{
	public:
		virtual ~Request() {}
		virtual bool IsValid() const = 0;
		virtual TSharedPtr<FJsonObject> ToJson() const = 0;
	};

	class BANANA_API ErrorDetails : public Model
	{
	public:
		virtual ~ErrorDetails() {}
		virtual bool FromJson(const TSharedPtr<FJsonObject>& JsonObject) = 0;
	};

	class BANANA_API Response : public Model
	{
	public:
		virtual ~Response() {}
		virtual bool FromJson(const TSharedPtr<FJsonObject>& JsonObject) = 0;
		virtual bool ErrorFromJson(const TSharedPtr<FJsonObject>& JsonObject) = 0;
		bool IsSuccessful() { return _Success; }
		EHttpResponseCodes::Type GetHttpResponseCode() { return _ResponseCode; }

	private:
		friend class BananaAPI;

		bool _Success;
		EHttpResponseCodes::Type _ResponseCode;
	};

	class BANANA_API SomeMethodRequest : public Request
	{
	public:
		virtual ~SomeMethodRequest() {}
		bool IsValid() const override;
		TSharedPtr<FJsonObject> ToJson() const override;

		int32 Banana1;
		float Banana2;
		FString Banana3;
		TArray<int32> Banana4;
	};

	class BANANA_API SomeMethodResponse : public Response
	{
	public:
		virtual ~SomeMethodResponse() {}
		bool FromJson(const TSharedPtr<FJsonObject>& JsonObject) override;
		bool ErrorFromJson(const TSharedPtr<FJsonObject>& JsonObject) override;

		class SomeMethodErrorDetails : public ErrorDetails
		{
		public:
			virtual ~SomeMethodErrorDetails() {}
			bool FromJson(const TSharedPtr<FJsonObject>& JsonObject) override;
		};
		const SomeMethodErrorDetails& GetError() const { check(_Error); return *_Error.Get(); }

		int32 Banana1;
		float Banana2;
		FString Banana3;
		TArray<int32> Banana4;

	private:

		TUniquePtr<SomeMethodErrorDetails> _Error;
	};
}