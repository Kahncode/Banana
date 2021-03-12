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

#include "ModelPrefixPet.h"

#include "PetstoreModule.h"
#include "ModelPrefixHelpers.h"

#include "Templates/SharedPointer.h"

namespace CppNamespace 
{

inline FString ToString(const ModelPrefixPet::StatusEnum& Value)
{
	switch (Value)
	{
	case ModelPrefixPet::StatusEnum::Available:
		return TEXT("available");
	case ModelPrefixPet::StatusEnum::Pending:
		return TEXT("pending");
	case ModelPrefixPet::StatusEnum::Sold:
		return TEXT("sold");
	}

	UE_LOG(LogPetstore, Error, TEXT("Invalid ModelPrefixPet::StatusEnum Value (%d)"), (int)Value);	
	return TEXT("");
}

inline FStringFormatArg ToStringFormatArg(const ModelPrefixPet::StatusEnum& Value)
{
	return FStringFormatArg(ToString(Value));
}

inline void WriteJsonValue(JsonWriter& Writer, const ModelPrefixPet::StatusEnum& Value)
{
	WriteJsonValue(Writer, ToString(Value));
}

inline bool TryGetJsonValue(const TSharedPtr<FJsonValue>& JsonValue, ModelPrefixPet::StatusEnum& Value)
{
	FString TmpValue;
	if (JsonValue->TryGetString(TmpValue))
	{
		static TMap<FString, ModelPrefixPet::StatusEnum> StringToEnum = { 
			{ TEXT("available"), ModelPrefixPet::StatusEnum::Available },
			{ TEXT("pending"), ModelPrefixPet::StatusEnum::Pending },
			{ TEXT("sold"), ModelPrefixPet::StatusEnum::Sold }, };

		const auto Found = StringToEnum.Find(TmpValue);
		if(Found)
		{
			Value = *Found;
			return true;
		}
	}
	return false;
}

void ModelPrefixPet::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (Id.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("id")); WriteJsonValue(Writer, Id.GetValue());	
	}
	if (Category.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("category")); WriteJsonValue(Writer, Category.GetValue());	
	}
	Writer->WriteIdentifierPrefix(TEXT("name")); WriteJsonValue(Writer, Name);
	Writer->WriteIdentifierPrefix(TEXT("photoUrls")); WriteJsonValue(Writer, PhotoUrls);
	if (Tags.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("tags")); WriteJsonValue(Writer, Tags.GetValue());	
	}
	if (Status.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("status")); WriteJsonValue(Writer, Status.GetValue());	
	}
	Writer->WriteObjectEnd();
}

bool ModelPrefixPet::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("id"), Id);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("category"), Category);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("name"), Name);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("photoUrls"), PhotoUrls);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("tags"), Tags);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("status"), Status);

	return ParseSuccess;
}

}
