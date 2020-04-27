#pragma once

class FJsonObject;

namespace Banana
{
	class BANANA_API Model
	{
	};

	class BANANA_API Request : public Model
	{
	public:
		virtual bool IsValid() const = 0;
		virtual TSharedPtr<FJsonObject> ToJson() const = 0;
	};

	class BANANA_API ErrorDetails : public Model
	{

	};

	class BANANA_API Response : public Model
	{
	public:
		bool IsSuccess() const { return Success;  }
		virtual void FromJson(const TSharedPtr<FJsonObject>& JsonObject) = 0;

	private:
		bool Success;
	};

	class BANANA_API SomeMethodRequest : public Request
	{
	public:
		bool IsValid() const override;
		TSharedPtr<FJsonObject> ToJson() const override;
	};

	class BANANA_API SomeMethodResponse : public Response
	{
	public:
		void FromJson(const TSharedPtr<FJsonObject>& JsonObject) override;

	private:
		class SomeMethodErrorDetails : public ErrorDetails
		{

		};

		SomeMethodErrorDetails* Error;
	};
}