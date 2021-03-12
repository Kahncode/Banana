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

#include "ModelPrefixUser.h"

#include "PetstoreModule.h"
#include "ModelPrefixHelpers.h"

#include "Templates/SharedPointer.h"

namespace CppNamespace 
{

void ModelPrefixUser::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (Id.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("id")); WriteJsonValue(Writer, Id.GetValue());	
	}
	if (Username.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("username")); WriteJsonValue(Writer, Username.GetValue());	
	}
	if (FirstName.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("firstName")); WriteJsonValue(Writer, FirstName.GetValue());	
	}
	if (LastName.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("lastName")); WriteJsonValue(Writer, LastName.GetValue());	
	}
	if (Email.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("email")); WriteJsonValue(Writer, Email.GetValue());	
	}
	if (Password.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("password")); WriteJsonValue(Writer, Password.GetValue());	
	}
	if (Phone.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("phone")); WriteJsonValue(Writer, Phone.GetValue());	
	}
	if (UserStatus.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("userStatus")); WriteJsonValue(Writer, UserStatus.GetValue());	
	}
	Writer->WriteObjectEnd();
}

bool ModelPrefixUser::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("id"), Id);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("username"), Username);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("firstName"), FirstName);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("lastName"), LastName);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("email"), Email);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("password"), Password);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("phone"), Phone);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("userStatus"), UserStatus);

	return ParseSuccess;
}

}
