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
#include "ModelPrefixUserApi.h"

#include "ModelPrefixUser.h"

namespace CppNamespace 
{

/* Create user
 *
 * This can only be done by the logged in user.
*/
class PETSTORE_API ModelPrefixUserApi::CreateUserRequest : public Request
{
public:
    virtual ~CreateUserRequest() {}
	void SetupHttpRequest(const TSharedRef<IHttpRequest>& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* Created user object */
	ModelPrefixUser Body;
};

class PETSTORE_API ModelPrefixUserApi::CreateUserResponse : public Response
{
public:
    virtual ~CreateUserResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonObject) final;
    
    
};

/* Creates list of users with given input array

*/
class PETSTORE_API ModelPrefixUserApi::CreateUsersWithArrayInputRequest : public Request
{
public:
    virtual ~CreateUsersWithArrayInputRequest() {}
	void SetupHttpRequest(const TSharedRef<IHttpRequest>& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* List of user object */
	TArray<ModelPrefixUser> Body;
};

class PETSTORE_API ModelPrefixUserApi::CreateUsersWithArrayInputResponse : public Response
{
public:
    virtual ~CreateUsersWithArrayInputResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonObject) final;
    
    
};

/* Creates list of users with given input array

*/
class PETSTORE_API ModelPrefixUserApi::CreateUsersWithListInputRequest : public Request
{
public:
    virtual ~CreateUsersWithListInputRequest() {}
	void SetupHttpRequest(const TSharedRef<IHttpRequest>& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* List of user object */
	TArray<ModelPrefixUser> Body;
};

class PETSTORE_API ModelPrefixUserApi::CreateUsersWithListInputResponse : public Response
{
public:
    virtual ~CreateUsersWithListInputResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonObject) final;
    
    
};

/* Delete user
 *
 * This can only be done by the logged in user.
*/
class PETSTORE_API ModelPrefixUserApi::DeleteUserRequest : public Request
{
public:
    virtual ~DeleteUserRequest() {}
	void SetupHttpRequest(const TSharedRef<IHttpRequest>& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* The name that needs to be deleted */
	FString Username;
};

class PETSTORE_API ModelPrefixUserApi::DeleteUserResponse : public Response
{
public:
    virtual ~DeleteUserResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonObject) final;
    
    
};

/* Get user by user name

*/
class PETSTORE_API ModelPrefixUserApi::GetUserByNameRequest : public Request
{
public:
    virtual ~GetUserByNameRequest() {}
	void SetupHttpRequest(const TSharedRef<IHttpRequest>& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* The name that needs to be fetched. Use user1 for testing. */
	FString Username;
};

class PETSTORE_API ModelPrefixUserApi::GetUserByNameResponse : public Response
{
public:
    virtual ~GetUserByNameResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonObject) final;
    
    ModelPrefixUser Content;
};

/* Logs user into the system

*/
class PETSTORE_API ModelPrefixUserApi::LoginUserRequest : public Request
{
public:
    virtual ~LoginUserRequest() {}
	void SetupHttpRequest(const TSharedRef<IHttpRequest>& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* The user name for login */
	FString Username;
	/* The password for login in clear text */
	FString Password;
};

class PETSTORE_API ModelPrefixUserApi::LoginUserResponse : public Response
{
public:
    virtual ~LoginUserResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonObject) final;
    
    FString Content;
};

/* Logs out current logged in user session

*/
class PETSTORE_API ModelPrefixUserApi::LogoutUserRequest : public Request
{
public:
    virtual ~LogoutUserRequest() {}
	void SetupHttpRequest(const TSharedRef<IHttpRequest>& HttpRequest) const final;
	FString ComputePath() const final;
    
};

class PETSTORE_API ModelPrefixUserApi::LogoutUserResponse : public Response
{
public:
    virtual ~LogoutUserResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonObject) final;
    
    
};

/* Updated user
 *
 * This can only be done by the logged in user.
*/
class PETSTORE_API ModelPrefixUserApi::UpdateUserRequest : public Request
{
public:
    virtual ~UpdateUserRequest() {}
	void SetupHttpRequest(const TSharedRef<IHttpRequest>& HttpRequest) const final;
	FString ComputePath() const final;
    
	/* name that need to be deleted */
	FString Username;
	/* Updated user object */
	ModelPrefixUser Body;
};

class PETSTORE_API ModelPrefixUserApi::UpdateUserResponse : public Response
{
public:
    virtual ~UpdateUserResponse() {}
	void SetHttpResponseCode(EHttpResponseCodes::Type InHttpResponseCode) final;
	bool FromJson(const TSharedPtr<FJsonValue>& JsonObject) final;
    
    
};

}
