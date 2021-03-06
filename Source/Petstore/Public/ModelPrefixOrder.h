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

#pragma once

#include "ModelPrefixBaseModel.h"

namespace CppNamespace 
{

/*
 * ModelPrefixOrder
 *
 * An order for a pets from the pet store
 */
class PETSTORE_API ModelPrefixOrder : public Model
{
public:
    virtual ~ModelPrefixOrder() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	TOptional<int64> Id;
	TOptional<int64> PetId;
	TOptional<int32> Quantity;
	TOptional<FDateTime> ShipDate;
	enum class StatusEnum
	{
		Placed,
		Approved,
		Delivered,
  	};
	
	static FString EnumToString(const StatusEnum& EnumValue);
	static bool EnumFromString(const FString& EnumAsString, StatusEnum& EnumValue);
	/* Order Status */
	TOptional<StatusEnum> Status;
	TOptional<bool> Complete;
};

}
