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
	//TODO: optimize using JSON Writer ?
/*
	writer->WriteObjectStart();

	if (FriendEmail.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("FriendEmail")); writer->WriteValue(FriendEmail); }

	if (FriendPlayFabId.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("FriendPlayFabId")); writer->WriteValue(FriendPlayFabId); }

	if (FriendTitleDisplayName.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("FriendTitleDisplayName")); writer->WriteValue(FriendTitleDisplayName); }

	if (FriendUsername.IsEmpty() == false) { writer->WriteIdentifierPrefix(TEXT("FriendUsername")); writer->WriteValue(FriendUsername); }

	writer->WriteObjectEnd();*/

		auto JsonObject = MakeShared<FJsonObject>();
		JsonObject->SetNumberField("Banana1", Banana1);
		JsonObject->SetNumberField("Banana2", Banana2);
		JsonObject->SetStringField("Banana3", Banana3);
		//JsonObject->SetArrayField()
		return JsonObject;
	}

	bool SomeMethodResponse::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
	{
		bool ParseSuccess = true;

		ParseSuccess &= JsonObject->TryGetNumberField("Banana1", Banana1);

		double Value = Banana2;
		ParseSuccess &= JsonObject->TryGetNumberField("Banana2", Value);
		Banana2 = Value;

		ParseSuccess &= JsonObject->TryGetStringField("Banana3", Banana3);

		return ParseSuccess;
	}

	bool SomeMethodResponse::ErrorFromJson(const TSharedPtr<FJsonObject>& JsonObject)
	{
		_Error = MakeUnique<SomeMethodErrorDetails>();
		return _Error->FromJson(JsonObject);
	}

	bool SomeMethodResponse::SomeMethodErrorDetails::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
	{
		//TODO :!
		return true;
	}

}
