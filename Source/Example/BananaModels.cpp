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

	void SomeMethodResponse::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
	{

	}

}