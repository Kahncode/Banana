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
 * ModelPrefixUser
 *
 * A User who is purchasing from the pet store
 */
class PETSTORE_API ModelPrefixUser : public Model
{
public:
    virtual ~ModelPrefixUser() {}
	bool FromJson(const TSharedPtr<FJsonObject>& JsonObject) final;
	void WriteJson(JsonWriter& Writer) const final;

	TOptional<int64> Id;
	TOptional<FString> Username;
	TOptional<FString> FirstName;
	TOptional<FString> LastName;
	TOptional<FString> Email;
	TOptional<FString> Password;
	TOptional<FString> Phone;
	/* User Status */
	TOptional<int32> UserStatus;
};

}
