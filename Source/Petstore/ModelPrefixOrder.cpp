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

#include "ModelPrefixOrder.h"

#include "ModelPrefixHelpers.h"

#include "Templates/SharedPointer.h"

namespace CppNamespace 
{

	void ModelPrefixOrder::WriteJson(JsonWriter& Writer) const
	{
		Writer->WriteObjectStart();
		if (Id.IsSet())
		{
			Writer->WriteIdentifierPrefix(TEXT("id")); WriteJsonValue(Writer, Id.GetValue());	
		}
		if (PetId.IsSet())
		{
			Writer->WriteIdentifierPrefix(TEXT("petId")); WriteJsonValue(Writer, PetId.GetValue());	
		}
		if (Quantity.IsSet())
		{
			Writer->WriteIdentifierPrefix(TEXT("quantity")); WriteJsonValue(Writer, Quantity.GetValue());	
		}
		if (ShipDate.IsSet())
		{
			Writer->WriteIdentifierPrefix(TEXT("shipDate")); WriteJsonValue(Writer, ShipDate.GetValue());	
		}
		if (Status.IsSet())
		{
			Writer->WriteIdentifierPrefix(TEXT("status")); WriteJsonValue(Writer, Status.GetValue());	
		}
		if (Complete.IsSet())
		{
			Writer->WriteIdentifierPrefix(TEXT("complete")); WriteJsonValue(Writer, Complete.GetValue());	
		}
		Writer->WriteObjectEnd();
	}

	bool ModelPrefixOrder::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
	{
		bool ParseSuccess = true;

		ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("id"), Id);
		ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("petId"), PetId);
		ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("quantity"), Quantity);
		ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("shipDate"), ShipDate);
		ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("status"), Status);
		ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("complete"), Complete);

		return ParseSuccess;
	}
}
