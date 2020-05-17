/**
 * Swagger Petstore
 * This is a sample server Petstore server.  You can find out more about Swagger at [http://swagger.io](http://swagger.io) or on [irc.freenode.net, #swagger](http://swagger.io/irc/).  For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * Contact: apiteam@swagger.io
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
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
		static TMap<FString, ModelPrefixPet::StatusEnum> StringToEnum = {  };

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

bool ModelPrefixPet::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
{
	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("id"), Id);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("category"), Category);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("name"), Name);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("photoUrls"), PhotoUrls);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("tags"), Tags);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("status"), Status);

	return ParseSuccess;
}
}