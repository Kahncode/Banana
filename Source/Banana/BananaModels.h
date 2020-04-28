#pragma once

#include "Interfaces/IHttpResponse.h"

class FJsonObject;

namespace Banana
{
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
		bool IsSuccess() const { return Success;  }
		virtual bool FromJson(const TSharedPtr<FJsonObject>& JsonObject) = 0;
		virtual bool ErrorFromJson(const TSharedPtr<FJsonObject>& JsonObject) = 0;

		bool Success;
		EHttpResponseCodes::Type ResponseCode;

	private:
	};

	class BANANA_API SomeMethodRequest : public Request
	{
	public:
		virtual ~SomeMethodRequest() {}
		bool IsValid() const override;
		TSharedPtr<FJsonObject> ToJson() const override;

	};

	class BANANA_API SomeMethodResponse : public Response
	{
	public:
		virtual ~SomeMethodResponse() {}
		bool FromJson(const TSharedPtr<FJsonObject>& JsonObject) override;
		bool ErrorFromJson(const TSharedPtr<FJsonObject>& JsonObject) override;

	private:
		class SomeMethodErrorDetails : public ErrorDetails
		{
		public:
			virtual ~SomeMethodErrorDetails() {}
			bool FromJson(const TSharedPtr<FJsonObject>& JsonObject) override;
		};

		TUniquePtr<SomeMethodErrorDetails> Error;
	};
}