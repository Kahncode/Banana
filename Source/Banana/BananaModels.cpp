#include "BananaModels.h"

#include "Dom/JsonObject.h"
#include "Templates/SharedPointer.h"

namespace Banana
{
	bool SomeMethodRequest::IsValid() const
	{
		return true;
	}

	TSharedPtr<FJsonObject> SomeMethodRequest::ToJson() const
	{
		return MakeShared<FJsonObject>();
	}

	bool SomeMethodResponse::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
	{
		return true;
	}

	bool SomeMethodResponse::ErrorFromJson(const TSharedPtr<FJsonObject>& JsonObject)
	{
		return true;
	}

	bool SomeMethodResponse::SomeMethodErrorDetails::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
	{
		return true;
	}

}